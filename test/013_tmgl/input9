/* Multiplication test: outputs ASCII value of the first character multiplied
 * by different constants */

program: parse(mult);
mult:    char(i)/empty
         [ j = i*23 ] [ k = i*777 ] [ l = 7654*i ] [ i =* 11 ]
         decimal(i) decimal(j) decimal(k) decimal(l) = { 4 * 3 * 2 * 1 * };
empty:   ;

i:       0;
j:       0;
k:       0;
l:       0;
