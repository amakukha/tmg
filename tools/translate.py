#!/usr/bin/env python3

'''
Translates Unix TMG driving table from PDP-11 assembly to C arrays.
Assumptions: 
 - string literals are single line
 - byte directive has two octal values
'''

from sys import argv

def line_statements(line, cnt):
    line = line.lstrip()
    while line:
        if line and line[0]=='<':
            # Yield string statement
            p = line.index('>')
            literal, line = line[:p+1], line[p+1:]
            while literal[-2:-1] == '\\':
                p = line.index('>')
                literal, line = literal + line[:p+1], line[p+1:]
            if line and line[0]=='>':
                literal, line = literal + line[0], line[1:]
            yield literal.replace("\\>",">")
        elif line and line[0]=="'":
            # Single character constant
            s, line = line, ''
            yield s[:2]+s[2:].rstrip() 
        else:
            # Split statements on semicolon
            if ';' in line:
                s, line = line.split(';', 1)
            else:
                s, line = line, ''
            # Yield all the labels
            while ':' in s:
                label, s = s.split(':', 1)
                yield label.strip() + ':'
            # Yield the rest of the statement (may be empty string)
            yield s.strip()
        line = line.lstrip()

def file_statements(fn):
    cnt = 0
    for line in open(fn):
        cnt += 1
        for s in line_statements(line, cnt):
            if s:
                yield s

class Translator:

    KNOWN_LIST = [
        '.l', '.p', '.t', '.u', '.st',
        '.eq','.ne','.le','.lt','.ge','.gt',
        '.da', '.ia', '.db', '.ib',
        '.a', '.s', '.m', '.n', '.o', '.x',
        '.sl', '.sr', '.lv', '.rv',
        '.cm', '.ng', '.nt',
        '.tx', '.txs', '.px', '.pxs',
        '.r', '.q',
        'parse', 'diag', 'trans', 
        'octal', '.tp', 'decimal', 'ignore',
        'alt', 'salt', 'generate', 'succ', 'fail',
        'smark', 'any', 'string', 'scopy',
        'bundle', 'reduce', 'params', 'push',
        'find', 'enter', 'table', 'discard', '.f',
        'gpar', '.tq',
    ]

    KNOWN_DICT = { 'goto': 'tgoto', 'char': 'tchar' }

    def __init__(self):
        self.cur = 0
        self.known = {}         # known labels, defined where they appeared
        self.labels = {}        # each value contains a tuple: how to translate in `start` and how to appear in `labels`
        self.builtins = set()   # list of all builtins used

    def start(self):
        print('//#define SRC_LANGUAGE "input language"')
        print('//#define DST_LANGUAGE "output language"\n')
        print('const tword labels[];\n')
        print('// Driving table for the program\n')
        print('tword start[] = {')

    def translate(self, s):
        if not s: return
        if s in ['.even', '.globl classtab']: return

        # Strip exit bit
        exit_bit = s.startswith("1 ")
        if exit_bit:
            s = s[2:].lstrip()

        # Translate known literals
        if s in self.KNOWN_LIST:
            s = s.replace('.','_')
            self.builtins.add(s)
            s = '(tword)&' + s

        elif s in self.KNOWN_DICT:
            s = self.KNOWN_DICT[s].replace('.','_')
            self.builtins.add(s)
            s = '(tword)&' + s

        # Defined label usage
        elif self.label(s) in self.known:
            s = self.label(s)

        # Translate special words
        elif s.startswith('.byte '):
            s = s[6:]
            if ',' not in s:
                raise ValueError('.byte '+s)
            if '.' in s:
                raise ValueError('.byte '+s)
            lo,hi = s.split(',')
            s = str(int(lo,base=8) + int(hi,base=8)*256)

        # Translate global labels:
        # - Label definition
        elif len(s)>1 and s[0]!="'" and s[-1]==':':     # Don't confuse for the ': character literal!
            l = self.label(s[:-1])
            if l in self.labels:
                # Add reference to the labels array
                t = '(tword)&start[{cur:d}]'.format(cur=self.cur)
                self.labels[l][2] = t
                print('// ' + l + ':')
                s = ''
            else:
                # Define label locally
                self.known[l] = 1
                print('#define {label:<10s} (tword)&start[{cur:d}]'.format(label=l, cur=self.cur))
                s = ''

        # Translate local labels
        # - Local label definition
        elif s and s[0]=='.' and s[-2:]=='=.' and s[1:-2].isdigit():
            num = int(s[1:-2])
            name = '_' + str(num)
            print("#undef {name}\n#define {name:<10s} (tword)&start[{cur:d}]".format(name=name, cur=self.cur))
            s = ''

        # - Local label usage
        elif s and s[0]=='.' and s[1:].isdigit():
            num = int(s[1:])
            s = '_{num:d}'.format(num=num)

        # Translate string literal
        elif len(s)>3 and s[0] == '<' and s[-3:] == '\\0>':
            s = '(tword)"%s"' % s[1:-3]

        # Translate numeric literals
        elif len(s)>2 and s[-1] == '.' and s[:-1].isdigit():
            s = s[:1].lstrip('0')
        elif s.isdigit():
            if len(s)!=1 and s[0]!='0':
                s = '0' + s   # octal
            if s=='012':
                s = "(tword)'\\n'"
        elif s and s[0]=='[' and s[-1]==']':
            # Constant expressions
            s = {
                '[-1\<1]': '(tword)((tuword)-1<<1)',
                '[-2\<1]': '(tword)((tuword)-2<<1)',
            }[s]

        # Translate character literal
        elif len(s)==2 and s[0]=="'":
            s = "(tword)'%c'" % s[1]

        # - Label usage: everything unknown must be a global label
        elif s:
            if s[0]=="'":
                raise ValueError(s+' '+repr(s))
            s = self.label(s)
            if s not in self.labels:
                # Never met before -> define via labels array
                n = len(self.labels)
                d = '#define {label:<10s} (tword)&labels[{n:d}]'.format(label=s, n=n)
                print(d)
                self.labels[s] = [n, s, None]

        # Add exit bit
        if exit_bit:
            s = '1 + ' + s

        if s:
            print('\t' + s + ',') 
            self.cur += 1

    def end(self):
        print('};\n')
        if self.labels:
            print('// Global label addresses inside the driving table\n')
            print('const tword labels[] = {')
            for n,s,t in sorted(self.labels.values()):
                if t is None: continue
                print('\t{tran:<24s}// {name}'.format(tran=t+',', name=s))
            print('};')
            for n,s,t in sorted(self.labels.values()):
                if t is None:
                    print('// Undefined: {name}'.format(name=s))
        if self.builtins:
            print('\n// Used builtins:')
            for x in sorted(list(self.builtins)):
                print('//  ',x)

    @staticmethod
    def label(s):
        # program: -> __program
        # ..1: -> __1
        # .tn: -> _tn
        l = s.replace('.','_')
        if l[0] != '_':
            l = '__' + l
        return l

if __name__=='__main__':
    t = Translator()
    t.start()
    for s in file_statements(argv[1]):
        t.translate(s)
    t.end()
