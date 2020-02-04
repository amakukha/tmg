/* Recognizes correct sequences of opening and closing brackets */
/* RosettaCode: http://rosettacode.org/wiki/Balanced_brackets */
/* Author: Andrii Makukha */

loop:   parse(corr)\loop parse(incorr)\loop;
corr:   brkts * = { <    OK: > 1 * };
brkts:  brkt/null brkts = { 2 1 };
brkt:   <[> brkts <]> = { <[> 1 <]> };
null:   = {};

incorr: smark ignore(<<>>) any(!<<>>) string(nonl) scopy ( * | () )
	= { <NOT OK: > 1 * };

nonl:   !<<
>>;
