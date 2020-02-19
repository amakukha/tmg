/* Unix TMG program to translate Brainfuck to C/C++.            */
/* Based on a "simple, non-optimizing" C program:               */
/*           https://gist.github.com/Ricket/939687              */
/* Original author:  Cory Burgett, https://github.com/baguette  */
/* Unlike the original, adds proper indentations and checks for */
/* brackets balance.                                            */

tran:   parse(intro)
        parse(bf) chk
        parse(outro);
bf:     sqn bf/done = { 2 1 };
sqn:    ops | loop;
ops:    op ops/done = { 2 1 };
done:   ;

op: <>> ind = { 1 <--ptr;> * }
  | <<> ind = { 1 <++ptr;> * } 
  | <+> ind = { 1 <++*ptr;> * }
  | <-> ind = { 1 <--*ptr;> * }
  | <.> ind = { 1 <putchar(*ptr);> * }
  | <,> ind = { 1 <*ptr = getchar();> * }
  | any(!<<[]>>) = {};

loop:   <[> [lvl++] bf <]> [lvl--] ind 
        = { 1 <while (*ptr) {> * 2 1 <}> * };
chk:    any(!<<>>) diag(( ={ <BF error: unbalanced brackets> * } )) fail
   |    succ;

ind: [i=lvl]
rep: tab [--i>0?]/done rep = { 2 1 };
tab: = { <	> };

lvl: 1;     /* Indentation level */
i:   0;

intro: tab = {  <#include <stdio.h> <>> *
                <#include <stdlib.h> <>> * * 
                <int main(int argc, char **argv)> * <{> *
                1 <unsigned char *array = (unsigned char *)calloc(30000, 1);> *
                1 <unsigned char *ptr = array;> *
                1 <if (!array) {> *
                1 1 <fprintf(stderr, "Error allocating memory.\n");> *
                1 1 <return 1;> *
                1 <}> * * 
        };

outro: tab = {  * 1 <free(array);> 
                * 1 <return 0;> 
                * <}> * 
        }; 
