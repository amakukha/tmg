/* Unix TMG didactic program to reverse letters in words.   */
/* This is the first sample program in TMG from the         */
/*   Multics System-Programmer's Manual, Section BN.4.02,   */
/*   by Robert R. Fenichel and M. D. Mcilroy                */
/*   Publication date: April 17, 1967                       */
/* Translation to Unix dialect of TMG by Andrii Makukha.    */

/* NOTE! It's not advisable to write programs like this. */
/* Bug 1: Punctuation is required after a word. */
/* Bug 2: Requirement for "***" in the end of input is outdated. */
/* Bug 3: Three character classes seem unnecessary. It's better to */
/*        reverse words and leave all other characters unmodified. */
/* Bug 4: wouldn't -> ndluow't */

/* ----------- (Almost) original program follows ---------- */

/* Here is the super sentence. It looks for "***" to
 * stop on. If it doesnt get "***", it peels a word or string of
 * punctuation marks off the input.
 */
flipper: flipper3;
flipper3: <***>/flipper1 parse(lastline);
/* If the "***" had been found, we would have moved on to
 * parse(lastline) and to a halt. But getting to flipper1 means 
 * no "***" yet.
 */
flipper1: parse(word)/flipper2 flipper2;
/* Whether or not we have peeled off a word, we drop from flipper1
 * to flipper2
 */
flipper2: parse(punctuation)/flipper4 fail/flipper3;
/* And if we find any punctuation, back we go to look for "***".
 * We use flipper4 to plow through illegal characters. 
 */
flipper4: diag(( smark any(garbage) string(garbage) scopy = 
                 { <illegal characters: > 1 * } ))
          fail/flipper3;

/* To handle a word, we split off the first letter and
 * put this out after the flipped version of the "word" which is left.
 * If there is nothing left, the flipped version of the original
 * word is just the first (only) letter.
 */
word: smark any(letter) scopy word/done = { 1 2 };

/* Notice that in the detour to the "word" component, we use
 * the abbreviation "done" which we must define below.
 * The punctuation copier picks up either a string of graphics or 
 * a newline character each time it succeeds.
 */
punctuation: smark any(puncts)/punct2 string(puncts) scopy;
punct2: * = { * };
lastline: = { * };

/* Here is that definition we needed */
done: = { 1 };

/* Name useful character classes */
puncts: << .,"():;'?[]->>;
letter: <<ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz>>; 
garbage:!<<ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz .,"():;'?[]-
>>; 
