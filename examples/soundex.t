/* Unix TMG program for Soundex algorithm */
/* Author: Andrii Makukha */

prog:   ignore(spaces)
line:   word line;
word:   peek/done
        [ch = ch>140 ? ch-40 : ch ]
      ( [ch==12?] done
      | [ch<110?] ( [ch==101?] vow
                  | [ch==102?] r1
                  | [ch==103?] r2
                  | [ch==104?] r3
                  | [ch==105?] vow
                  | [ch==106?] r1
                  | [ch==107?] r2 
                  | error )
      | [ch<120?] ( [ch==110?] hw
                  | [ch==111?] vow
                  | [ch==112?] r2
                  | [ch==113?] r2
                  | [ch==114?] r4
                  | [ch==115?] r5
                  | [ch==116?] r5
                  | [ch==117?] vow )
      | [ch<130?] ( [ch==120?] r1
                  | [ch==121?] r2
                  | [ch==122?] r6
                  | [ch==123?] r2
                  | [ch==124?] r3
                  | [ch==125?] vow
                  | [ch==126?] r1
                  | [ch==127?] hw )
      | [ch<140?] ( [ch==130?] r2
                  | [ch==131?] vow
                  | [ch==132?] r2 
                  | error )
      | error )
        [n>0?]\word done;

vow:    [ch=0] out;
r1:     [ch=1] out;
r2:     [ch=2] out;
r3:     [ch=3] out;
r4:     [ch=4] out;
r5:     [ch=5] out;
r6:     [ch=6] out;
hw:     [ch=7] out;
error:  [ch=0] diag(( scopy = {<Unexpected character: "> 1 <"> * } ));

out:    [n==4?] [--n] parse(( scopy ))
   |    ( [(l1!=10) & ((ch==l1) | (ch==7) | (!ch)) ?]
        | [(l1==7) & (ch==l2) ?]
        | [--n] parse(( octal(ch) )) );
done:   [n==4?]\eof
        ([ch!=12?] string(nonl) string(nl) | ()) 
        [l1=10] [ch=0]
loop:   [n>0?] out loop
    |   parse((={*})) [n=4] [ch=0] [l1=0] [l2=0];
eof:    fail;

peek:   adv ord/read;
ord:    char(ch) fail;
read:   smark any(!<<>>);
adv:    [l2=l1] [l1=ch];

spaces:	<< 	>>;
nonl:   !<<
>>;
nl:     <<
>>;

n:  4;
ch: 0;
l1: 0;
l2: 0;
