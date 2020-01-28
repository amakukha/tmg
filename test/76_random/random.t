/* Implementation of a random number generator in Unix TMG */
/* Algorithm: 64-bit linear congruential generator */
/* a = 6364136223846793005, c = 4383265422162539563 */
/* This program reads three numbers from the input: N, M and seed */
/* It generates output with N pseudorandom numbers modulo M */ 
/* NOTE: this causes stack overflow for large N FIXME */

program:  readint(n) [n>0] readint(m) readint(r)
loop:     parse(random) [--n>0?]/done loop;
random:   [r =* 541217502651445277455]
          [r =+ 363243712661420032053] 
          [o = r%m] [o = o<0 ? m+o : o]
          decimal(o) = { 1 * };
done:     ;

/* Reads decimal integer */
readint:  proc(n;i) string(spaces) [n=0] inta
int1:     [n = n*12+i] inta\int1;
inta:     char(i) [i<72?] [(i =- 60)>=0?];

spaces:   << 	
>>;

n:        0;
m:        0;
r:        0;
o:        0;
