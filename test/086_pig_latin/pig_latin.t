/* Didactic TMG program to translate English to Pig-Latin.     */
/* This is the second sample program in TMG from the           */
/*   Multics System-Programmer's Manual, Section BN.4.02,      */
/*   by Robert R. Fenichel and M. D. Mcilroy                   */
/*   Publication date: April 17, 1967                          */
/* Translation to Unix dialect of TMG by Andrii Makukha.       */

/* NOTES: */
/* Bug 1: Only lowercase letters are accepted. */
/* Bug 2: Requirement for "***" in the end of input is outdated. */

/* ------------- (Almost) original program follows ----------- */

/* Syntax for English-to-Pig-Latin */

/* Pig Latin is probably the nearest approximation to cant 
 * (e.g., Cockney rhyming slang) that the United States has ever
 * produced. Several dialects exist, and this compiler may be
 * described as follows: 
 * 
 * 1. Single-letter words are unchanged, as is punctuation.
 * 
 * 2. Each word beginning with a vowel has "YAY" appended. Words
 * beginning with "Y" immediately followed by a consonant ("yclept," for 
 * example) are considered to fall into this category.
 * 
 * 3. Each word beginning with a consonant string is altered by 
 * rotating that consonant string to the end and then appending "AY".
 * If a "q" is moved, as in "quid" or "squid", its "u" moves with it.
 * The letter "y" is not part of the initial consonant string in "scythe,"
 * although it is in "yaws".
 * 
 * For the purists, we here acknowledge that Pig Latin is really an
 * aurally constructed language. Our rules would be rejected by any 
 * nine-year-old, who would know that the Pig Latin for "once"
 * is "unsway", not "onceyay"; "hour" should become "ouryay," and so on.
 *
 * There is another peculiarity to written Pig Latin, or rather to
 * the written-English-to-written-Pig-Latin translator. The transformation
 * is expansive, possibly by a factor of two. Accordingly, this compiler
 * maintains an output column counter, and a new-line character is
 * emitted whenever this output column counter gets large. New-line
 * characters in the input file are ignored unless they precede paragraph
 * indentation.
 */

/* Here is that super-sentence */
pigger: 
pigger1: <***>/pigger2 parse(lastline);
pigger2: parse(testwidth) parse(word)/pigger3
pigger3: parse(punctuation)/pigger5 pigger1;
pigger5: parse(pigger4) pigger1;
pigger4: diag(( smark any(garbage) string(garbage) scopy
                = { <mess: > 1 * } ));

/* "test-width" is a modest little routine which always succeeds
 * and which emits new-line characters as needed. */
testwidth: [columncount < rightmargin?] = {}
         | string(blanks) [columncount=0] lastline;
lastline: = { * };

/* The "word" routine is not trivial.. First, it sorts out the
 * easy case of one-letter words. */
word: oneletterword | bigword;
oneletterword: smark any(letter) scopy 
               peek [columncount++] = { 1 };

/* Additional lookforward routine, instead of "not()" */
peek:       nonletter/peek2;
nonletter:  (any(letter) [nlet=0] | [nlet=1] ) fail;
peek2:      [nlet?];

/* Now comes the monster. It will be put down first, then explained */
bigword: [wordlen=0] smark avowel/bigword1 bigword4;
bigword1: anyy/bigword2 bigword3;
bigword2: notqys (qu | ()) [wordlen?] scopy 
          smark letters scopy
          [columncount =+ wordlen + 2]
          porker = { 1({3},{2}) };
bigword3: anycons/ycons bigword4;
ycons:    smark [columncount--]
bigword4: letters scopy
          [columncount =+ wordlen + 3]
          porker = { 1({<y>},{2}) };
porker:   porcify;

/* NOTE: additional parsing rules to count word length */
anycons: any(consonant) [wordlen++];
anyy:    any(<<y>>) [wordlen++];
qu:      any(<<q>>) any(<<u>>) [wordlen =+ 2];
avowel:  any(vowel) [wordlen++];
notqys:  any(consnotqy) [wordlen++] notqys | ();
letters: any(letter) [wordlen++] letters | ();
puncies: any(puncts) [wordlen++] puncies | ();

/* Here we go. You should know that "porcify" is a definition which
 * takes a split word (say, "squid," split into "squ" and "id") and
 * produces Pig Latin. So the point of "bigword" is mainly just to split 
 * words into pieces for "porcify".
 * We start by noting the input scan pointer, J. [NOTE: Unix TMG doesn't
 * have this feature, so we are forced to count word length manually]
 * We will use J to compute the quantity of output which we have produced;
 * in the case of words starting with consonants, for example, the output
 * produced is as long as the input (ending j minus starting j)
 * plus two for the added "ay".
 * Now we use "mark" [smark] and we start collecting letters.
 * Suppose the first letter is a vowel. In this case, the detour of
 * the "vowel" component is irrelevant, and we proceed to "big-word-4".
 * The "letter*" [letters] component collects the rest of the word and
 * the "compute" [NOTE: replaced with expression in brackets in Unix TMG] 
 * ups the column-count to show the word and the coming "yay".
 * Now we go to "porcify" with an imaginary word, 
 * split into a leading "y" and a trailing string which is the 
 * word we really found.
 * Suppose the first letter of the word is not a vowel ("big-word-1"),
 * but rather it is "y". Then we skip the detour of the "y" component, and
 * we continue with big-word-3. If a consonant follows the "y", then we
 * drop immediately to the next line, which is exactly where we were a
 * minute ago when the word began with a vowel. If a non-consonant follows
 * the "y", however, we slyly reinitialize the letter-collector with a new
 * "marks" component. Only then do we drift down to the next line, where
 * the code which thinks it is converting "am" into "amyay" is actually
 * converling "yam".
 * Finally, suppose the word begins with some letter not one of
 * [a,e,i,o,u,y]. We collect its initial string, collect the remainder,
 * and porcify the word split into this pair.
 */

/* The punctuation-handler is rather an anticlimax. */
/* NOTE: fixed it to not add second newline after the one in textwidth */
punctuation: [wordlen=0] smark 
             any(puncts)/punctuation2 [wordlen++]
             puncies scopy [columncount =+ wordlen];
punctuation2: * ([columncount?] ={*} | ={}) [columncount=5]
              = { 1 <     > };

/* Finally, the definitions */
porcify: = (2){ $1 $2 <ay> };

/* A paragraph begins with five spaces */
paragraph: = { <     > };

/* Declare variables for column-counting */
wordlen: 0;     /* Replaced startword with wordlen */
columncount: 0;

/* If column-count gets here, we generate a new-line */
rightmargin: 60;

/* Additional flag to peek at non-letters */
nlet: 0;

/* Character classes */
blanks:     <<      >>;
vowel:      <<aeiou>>;
consonant:  <<bcdfghjklmnpqrstvwxyz>>;
letter:     <<abcdefghijklmnopqrstuvwxyz->>;
notletter:  !<<abcdefghijklmnopqrstuvwxyz->>;
consnotqy:  <<bcdfghjklmnprstvwxz>>;
puncts:     << .,'"():;!?[]>>; /* Some characters added */
garbage:    !<<
>>;     /* NOTE: changed it to "not newline" for reliability */
