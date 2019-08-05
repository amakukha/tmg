/* "99 Bottles of Beer" program for Unix TMG */

loop: parse(line1) [--n] parse(line2) [n>=1?]/done loop;
line1: beer = { 1 < on the wall, > 1 <.> * };
line2: beer = { <If one of those bottles should happen to fall, > 1 < on the wall.> * };
beer: left plural = { 2 < bottle> 1 < of beer> };
left: ( [n>=1?] decimal(n) = { 1 } | = { <no more> } );
plural: ( [n!=1?] = { <s> } | = { } );
done:;
n: 143;
