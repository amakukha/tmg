/* Implementation of TMG in TMGL. */
/* Converts TMGL program into a TMG driving table in C in two phases. */
/* Phase 2: converts the output of phase 1 into a C header file. */
/* Based on the original TMGL implementation by M. Douglas McIlroy. */
/* (c) 2020, Andrii Makukha, 2-clause BSD License. */

begin:  ignore(blanks)
        table(ltab)
        parse(intro)
pr2:    parse(linenl)\pr2    
        diag(error)\pr2
        parse(outro);

intro:  = { <//#define SRC_LANGUAGE "input language"> *
            <//#define DST_LANGUAGE "output language"> * *
            <const tword labels[];> * *
            <// Driving table for the program> * *
            <tword start[] = {> * };

outro:  labelarray = { 
            <};> * *
            <// Global label addresses inside the driving table> * *
            <const tword labels[] = {> * 1 <};> * };

error:	smark ignore(none) any(ascii) string(nonl) scopy ( * | () )
	= { * <??? err: > 1 * };

linenl: ignore(spaces) line *;
line:   strlit
    |   chrlit
    |   loclbl
    |   labels ( values | null ) = { 2 1 }
    |   values
    |   = {};

                                           /* Translation of local labels */
loclbl: <_> number <=.> ( <,> | () ) decimal(cnt)
        = { <#undef  _> 2 *
            <#define _> 2 <	(tword)&start[> 1 <]> * };

                                        /* Translation of string literals */
strlit: <<> ignore(none) ( litesc | null )
        litb <>> ( <,> | () ) [cnt++]
        = { <	(tword)"> 2 1 <",> * };
litesc: <\> ( <>> = { <>> } | = { <\> } );
litb:	smark string(litch) scopy stresc/done 
        litb = { 3 2 1 };
stresc: <"> = { <\"> };

                                     /* Translation of character literals */
chrlit: <'> ( <'> = { <\'> }
            | <\> smark any(ascii) scopy = { <\> 1 }
            | smark any(ascii) scopy )
        <'> ( <,> = {} | null ) [cnt++]
        = { <	(tword)'> 2 <',> * };

                                                 /* Translation of labels */
labels: label labels/done = { 2 1 };
label:  lblnam tabval(ltab, lcnt)/newlbl
        = { <// > 2 <:> * };
newlbl: decimal(cnt) [k = -1] tabput(ltab, k)
        = { <#define > 2 <	(tword)&start[> 1 <]> * };
lblnam: ( <__> number | name ) <:> = { <__> 1 };

                                  /* Translation of statements and values */
values: ignore(spaces) extval values/done = { 2 1 };
extval: extbit valsep = { 1({2}) }
      |        valsep = { 1(nil) };
extbit: <1 + > = { <1 + > };
valsep: value ( <,> = {} | null ) = (1){ 2({$1}) };
value: vallit [cnt++] = (1){ <	> $1 1 <,> * }
     | valbtn [cnt++] = (1){ <	> $1 <(tword)&> 1 <,> * }
     | vallbl tabval(ltab, lcnt)/nuvlbl [cnt++] 
       = (1){ <	> $1 2 <,> * };
nuvlbl: decimal(lcnt) tabput(ltab, lcnt) [cnt++] = (1){ 
            <#define > 2 <	(tword)&labels[> 1 <]> * 
            <	> $1 2 <,> *
        };
vallit: ( <_> = { <_> } | null ) number = { 2 1 };
vallbl: <__> smark num scopy = { <__> 1 }
      |      smark usrdef scopy = { <__> 1 };
valbtn: <_> wrd = { <_> 1 }
      | builtn;

tabput: params(2) enter($2,i) [$2[i] = $1++];
tabval: params(2)  find($2,i) [i=$1-$2[i]] decimal(i);

                                     /* Recognition of builtin references */
builtn: built1 | built2;
built1: <a> ( <ccept>   = { <accept> }
            | <lt>      = { <alt> }
            | <ny>      = { <any> }
            | <ppend>   = { <append> } )
      | <d> ( <ecimal>  = { <decimal> }
            | <iag>     = { <diag> }
            | <iscard>  = { <discard> } )
      | <e> ( <mit>     = { <emit> }
            | <nter>    = { <enter> } )
      | <f> ( <ail>     = { <fail> }
            | <ind>     = { <find> } )
      | <g> ( <enerate> = { <generate> }
            | <etnam>   = { <getnam> }
            | <oto>     = { <goto> }
            | <otab>    = { <gotab> }
            | <par>     = { <gpar> } )
      | <p> ( <arse>    = { <parse> }
            | <arams>   = { <params> }
            | <roc>     = { <proc> }
            | <ush>     = { <push> } )
      | <s> ( <copy>    = { <scopy> }
            | <alt>     = { <salt> }
            | <ize>     = { <size> }
            | <mark>    = { <smark> }
            | <tack>    = { <stack> }
            | <tring>   = { <string> }
            | <top>     = { <stop> }
            | <ucc>     = { <succ> } )
      | <t> ( <able>    = { <table> }
            | <rans>    = { <trans> } );
built2: <bundle>      = { <bundle> }
      | <char>        = { <char> }
      | <ignore>      = { <ignore> }
      | <octal>       = { <octal> }
      | <reduce>      = { <reduce> }
      | <unstack>     = { <unstack> };

                                         /* Rendering of the labels array */
labelarray: = nil;

                                                               /* Lexemes */
name:   ident scopy;
ident:  smark ignore(none) any(letter) string(alpha);
number: smark num scopy;
num:    ignore(none) any(digit) string(digit);

wrd:    smark ignore(none) any(lowup) string(lowup) scopy;
usrdef: ignore(none) any(nbrk) string(nbrk);

                                                             /* Variables */
i:      0;
k:      0;
cnt:    0;          /* Word counter */
lcnt:   0;          /* Label counter */
ltab:   0;          /* Labels dictionary */ 

                                                                /* Idioms */
done:   ;           /* Same as:     done: = { 1 }; */
null:	= nil;      /* Delivers empty translation */
nil:	{};

                                                     /* Character classes */
under:  <<_>>;
digit:	<<0123456789>>;
lowup:	<<abcdefghijklmnopqrstuvwxyz>>
	<<ABCDEFGHIJKLMNOPQRSTUVWXYZ>>;
letter:	<<abcdefghijklmnopqrstuvwxyz>>
	<<ABCDEFGHIJKLMNOPQRSTUVWXYZ_>>;
alpha:	<<0123456789>>
    	<<abcdefghijklmnopqrstuvwxyz>>
	<<ABCDEFGHIJKLMNOPQRSTUVWXYZ_>>;
litch:	!<<">>>;
none:	<<>>;
ascii:  !<<>>;
spaces:	<< 	>>;
blanks:	<< 	
	>>;
nonl:   !<<
>>;
nbrk:   !<<,;
>>;
