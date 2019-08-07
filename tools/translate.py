#!/usr/bin/env python3

'''
Translates Unix TMG driving table from PDP-11 assembly to C arrays.
Assumptions: 
 - string literals are single line
 - byte directive has two octal values
'''

from sys import argv

def statements(fn):
    cum = ''
    string = False
    for line in open(fn):
        for s in line.split(';'):
            s = s.lstrip()
            while s and s[0]=='<':
                if '>' not in s:
                    raise ValueError(s)
                p = s.index('>')
                literal, s = s[:p+1], s[p+1:]
                if s and s[0]=='>':
                    literal += s[0]
                    s = s[1:]
                s = s.lstrip()
                yield literal
            while ':' in s:
                label, s = s.split(':',1)
                yield label.strip() + ':'
            ls = s.lstrip()
            yield ls.rstrip() if ls and ls[0]!="'" else ls[:2]+ls[2:].rstrip()

class Translator:

    KNOWN_LIST = [
        '.l', '.p', '.t', '.u', '.st',
        '.ge','.ne','.eq',
        '.da', '.ia', '.db', '.ib',
        '.a', '.s', '.n', '.o', '.x',
        'parse', 'trans', '.tx', '.txs', '.px', '.pxs',
        'octal', '.tp', 'decimal',
        'alt', 'salt', 'generate', 'succ', 'fail',
    ]

    KNOWN_DICT = { 'goto': 'tgoto' }

    def __init__(self):
        self.cur = 0
        self.known = {}         # known labels, defined where they appeared
        self.labels = {}        # each value contains a tuple: how to translate in `start` and how to appear in `labels`

    def start(self):
        print('const tword labels[];\n')
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
            s = '(tword)&' + s.replace('.','_')

        elif s in self.KNOWN_DICT:
            s = '(tword)&' + self.KNOWN_DICT[s].replace('.','_')

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
        elif len(s)>1 and s[-1]==':':
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

        # Translate character literal
        elif len(s)==2 and s[0]=="'":
            s = "(tword)'%c'" % s[1]

        # - Label usage: everything unknown must be a global label
        elif s:
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
            print('const tword labels[] = {')
            for n,s,t in sorted(self.labels.values()):
                if t is None: continue
                print('\t{tran:<24s}// {name}'.format(tran=t+',', name=s))
            print('};')
            for n,s,t in sorted(self.labels.values()):
                if t is None:
                    print('// Undefined: {name}'.format(name=s))

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
    for s in statements(argv[1]):
        t.translate(s)
    t.end()
