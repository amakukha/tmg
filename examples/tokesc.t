/* Unix TMG program to tokenize a string with escaping */
/* RosettaCode task: http://rosettacode.org/wiki/Tokenize_a_string_with_escaping */
/* Variant 1: constant separator '|' and escape '^' characters */
/* Author: Andrii Makukha */

str:    smark
token:  string(alph) 
        ( <^> any(!<<>>) token
        | <|> outp str 
        | outp );
outp:   parse(( scopy = { 1 * } ));

alph:   !<<^|>>;
