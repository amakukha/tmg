/* Parses strings of a certain form: abc, aabbcc, aaabbbccc, ... */
/* Based on: "A Manual for the Tmg Compiler-writing Language" by McIlroy */

program: parse(detect);
detect:  anbncn = { <Good> * }
      |         = { <Bad> * };
anbncn:  <a> recurs((<b>)) <c>;
recurs:  proc(x) <a> recurs((<b> x)) <c> | x;
