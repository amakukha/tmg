/* Translates infix expression with operator precedence to Polish postfix */
/* Based on: "A Manual for the Tmg Compiler-writing Language" by McIlroy */

program: ignore(space) [alpha = letter | digit] parse(expr);
expr:    term
expr1:   addop/done term = { 3 1 2 } bundle\expr1;
term:    factor
term1:   mulop/done factor = { 3 1 2 } bundle\term1;
factor:  primary <^>/done factor = { 2 1 <EXP > };
primary: value = { <LOAD > 1 < > }
       | <(> expr <)>;
value:   ident  = { 1 }
       | number = { 1 };
done:    ;
addop:   <+> = { <ADD > }
       | <-> = { <SUB > };
mulop:   <*> = { <MUL > }
       | </> = { <DIV > };

ident:   smark any(letter) string(alpha) scopy = { 1 };
number:  smark any(digit)  string(digit) scopy = { 1 };

space:   << >>;
letter:  <<abcdefghijklmnopqrstuvwxyz>>
         <<ABCDEFGHIJKLMNOPQRSTUVWXYZ>>;
digit:   <<0123456789>>;
alpha:   0;
