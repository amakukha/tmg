/* Convert integer from decimal to another base (2..8) */ 
/* Based on: "A Manual for the Tmg Compiler-writing Language" by McIlroy */

program:  parse(int2base);
int2base: readint(n) readint(b) 
          decimal(n) decimal(b) tobase(n)
          = { 3 < in base > 2 < is > 1 * };

/* Reads decimal integer */
readint:  proc(n;i) string(space) [n=0] inta
int1:     [n = n*12+i] inta\int1;
inta:     char(i) [i<72?] [(i =- 60)>=0?];

/* Converts n into base b representation */
tobase:   proc(n;m,i) [i = (m=n) % b]
          ( [i==0?] = {<0>}
          | [i==1?] = {<1>}
          | [i==2?] = {<2>}
          | [i==3?] = {<3>}
          | [i==4?] = {<4>}
          | [i==5?] = {<5>}
          | [i==6?] = {<6>}
          | [i==7?] = {<7>} )
          [m =/ b?]/done
          tobase(m) = { 1 2 };
done:     ;

n:        0;
b:        0;
i:        0;
m:        0;

space:    << >>;
