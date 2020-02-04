/* Replaces all identifiers with an alias of the form x<NUM> */
/* Based on: "A Manual for the Tmg Compiler-writing Language" by McIlroy */

program: table(t) parse(text);
text:    space = { 1 }
text1:   ident/done space = { 3 2 1 } bundle\text1;
done:    ;
ident:   smark any(letter) string(alpha) install;
space:   smark string(noletter) scopy = { 1 };
install: enter(t,i)
         ([temp=t[i]?] | [temp=t[i]=++count])
         octal(temp) = { <x> 1 };
count:   0;
temp:    0;
t:       0;
i:       0;

letter:  <<abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ>>;
alpha:   <<0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ>>;
noletter:!<<abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ>>;
