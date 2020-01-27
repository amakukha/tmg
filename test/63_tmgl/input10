/* Recognizes an octal integer and outputs it in decimal form */
/* Based on: "A Manual for the Tmg Compiler-writing Language" by McIlroy */

program: parse(oct2dec);
oct2dec: integer(n) decimal(n) = { 1 * };
integer: proc(n;i) [n=0] inta
int1:    [ n = n*10+i] inta\int1;
inta:    char(i) [i<70?] [ (i =- 60)>=0?];

n:       0;
i:       0;
