/* Translates fully parenthesized infix expression to Polish postfix */
/* Based on: "A Manual for the Tmg Compiler-writing Language" by McIlroy */

program: [alpha = letter | digit] parse(expr);
expr: <(>/exp1 expr operator expr <)> = { 3 1 2 };
exp1: ident = { <LOAD > 1 < > };
operator:
op0: <+>/op1 = { <ADD > };
op1: <->/op2 = { <SUB > };
op2: <*>/op3 = { <MPY > };
op3: </>     = { <DIV > };

ident: smark any(letter) string(alpha) scopy = { 1 };

letter: <<abcdefghijklmnopqrstuvwxyz>>
        <<ABCDEFGHIJKLMNOPQRSTUVWXYZ>>;
digit:  <<0123456789>>;
alpha:  0;
