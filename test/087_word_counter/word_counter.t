/* Didactic TMG program to count words.                     */
/* This is the third sample program in TMG from the         */
/*   Multics System-Programmer's Manual, Section BN.4.02,   */
/*   by Robert R. Fenichel and M. D. Mcilroy                */
/*   Publication date: April 17, 1967                       */
/* Translation to Unix dialect of TMG by Andrii Makukha.    */

/* NOTES: */
/* Bug 1: Only lowercase letters are accepted. */
/* Bug 2: Requirement for "***" in the end of input is outdated. */

/* ----------- (Almost) original program follows ---------- */

/* This compiler accepts an English text. From this, it
 * produces a table showing which words occurred in the text, and 
 * how frequently each occurred.
 */

progrm:   count;
letter:   <<abcdefghijklmnopqrstuvwxyz->>;
garbage: !<<abcdefghijklmnopqrstuvwxyz-*>>;

/* We will be doing a fair amount of computing in this compiler. 
 * "Total-words" will grow by one for every word in the input text;
 * "distinct-wrords" will only grow when new words are found. Each 
 * distinct word will be labeled with a pointer to the previous such
 * word ("chain") and an occurrence-count ("occurrences").
 */

totalwords:     0;
distinctwords:  0;

/* Tables */
chain:          0; /* NOTE: flag exists removed */
occurrences:    0;

/* Scratch cells */
n: 0;
previousword: 0;
i: 0;

/* The "chain" pointers will be used when we run back through all the 
 * words, printing tham and their occurrence-counts. A flag ("first-word")
 * will be set on the first word in, so that we will know where to stop
 * our run. Also, each word will be given an "exists" flag so that the
 * first appearance of the word may be easily distinguished.
 */
firstword: 0;

/* Now we just pull in words until one of them is "***". When that
 * happens, we print a summary.
 */
count:  table(chain) table(occurrences) 
count1: <***>/count2 parse(header) output;
count2: count3 word/count1 count3 count1;
count3: string(garbage);

/* When a new word comes in, we (1) set a pointer to the previous word,
 * and (2) start an occurrence count. Old words we just count.
 * NOTE: in Unix TMG we exploit the fact that tables "chain" and
 *       "occurrences" will have exact same structure. So even though
 *       tables provide only a single word per entry for user data, 
 *       we build two identical tables to store two words per entry:
 *       number of occurrences and a pointer to the previous word.
 *       (Yes, it's wasteful to have two trees, but it is the price 
 *       you pay for Unix TMG simplicity... On 64-bit machine you could 
 *       also split the user data word in two for user data.)
 */
word: smark any(letter) string(letter) scopy
      [totalwords++]
      newword\again
      [distinctwords++]
      enter(chain, i) [chain[i]=previousword] [previousword=i]
      enter(occurrences, i)
      [firstword = totalwords==1 ? i : firstword]
      [occurrences[i] = 1] = {};
newword: find(occurrences, i);
again:   [occurrences[i] = occurrences[i]+1];

/* So much for the words. When they are all read in, we start producing
 * our summary:
 */
header: decimal(totalwords) decimal(distinctwords)
        = { 2 < words altogether, > 1 < distinct words> * };

/* "Output" does not accumulate a giant, multi-line output structure.
 * Instead, "output" produces its lines as part of the matching process.
 */
output: [i = previousword] [totalwords?]
out1:   parse(outputline) [i != firstword?] [previousword = chain[i]] output;
outputline: getnam(occurrences, i) [n = occurrences[i]] decimal(n)
            = { 2 <: > 1 * };
