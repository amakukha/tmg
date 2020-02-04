/* Language: Unix TMG */
/* Author: Andrii Makukha */
/* Prefix to postfix translation */
/* Code Golf Stack Exchange problem */
/* https://codegolf.stackexchange.com/questions/119754/ */

p:parse(b) parse((={*}));
b:<->b b={2 1<->}|<0>={<0>}|<1>={<1>};
