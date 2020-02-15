/* Unix TMG program to count number of occurences of each word. */
/* Based on:                                                    */
/*   Multics System-Programmer's Manual, Section BN.4.02,       */
/*   by Robert R. Fenichel and M. D. Mcilroy                    */
/*   Publication date: April 17, 1967                           */
/* Adaptation for Unix dialect of TMG by Andrii Makukha.        */

/* NOTE: only lowercase letters (and dash) can constitute a word. */
/* NOTE: single dash is one of the words. */

progrm: table(freq) table(chain) skip
loop:   not(!<<>>) parse(header) output 
    |   word/loop skip loop;
skip:   string(other);
not:    params(1) (any($1) fail | ());

word:   smark any(letter) string(letter) scopy
        [total++]
        locate/new
        [freq[i]++];
locate: find(freq, i);
new:    [distinct++]
        enter(freq, n)
        [freq[n] = 1]
        [firstword = total==1 ? n : firstword]
        enter(chain, i) [chain[i]=prevword] [prevword=n];

header: decimal(total) decimal(distinct)
        = { 2 < words altogether, > 1 < distinct words> * };

output: [i = prevword] [total?]
        parse(wn) [i != firstword?] [prevword = chain[i]] output;
wn:     getnam(freq, i) [n = freq[i]] decimal(n)
        = { 2 <: > 1 * };

total:      0;
distinct:   0;
prevword:   0;
firstword:  0; /* First word's index to know where to stop */
n: 0;
i: 0;

/* Tables */
freq:   0;
chain:  0;

letter:   <<abcdefghijklmnopqrstuvwxyz->>;
other:   !<<abcdefghijklmnopqrstuvwxyz->>;
