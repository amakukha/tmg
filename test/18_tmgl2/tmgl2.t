/* Implementation of TMG in TMGL. */
/* Converts TMGL program into a TMG driving table in C in two phases. */
/* Phase 2: converts the output of phase 1 into a C header file. */
/* Based on the original TMGL implementation by M. Douglas McIlroy. */
/* (c) 2020, Andrii Makukha, 2-clause BSD License. */

begin:  ignore(blanks)
pr2:    parse(linenl)\pr2    
        diag(error)\pr2;

error:	smark ignore(none) any(ascii) string(nonl) scopy
	( * = {} | null )
	= { * <??? err: > 2 1 * };

linenl: ignore(spaces) line *;
line:   strlit
    |   chrlit
    |   loclbl
    |   labels ( values | null ) = { 2 1 }
    |   values
    |   = {};

                                           /* Translation of local labels */
loclbl: <_> ignore(none) 
        smark any(digit) string(digit) scopy 
        <=.> ( <,> = {} | null ) decimal(cnt)
        = { <#undef  _> 2 *
            <#define _> 2 <  (tword)&start[> 1 <]> * };

                                        /* Translation of string literals */
strlit: <<> ignore(none) ( litesc | null )
        litb <>> ( <,> = {} | null ) [cnt++]
        = { <(tword)"> 3 2 <",> * };
litesc: <\> ( <>> = { <>> } | = { <\> } ) = { 1 };
litb:	smark string(litch) scopy stresc/done 
        litb = { 3 2 1 };
stresc: <"> = { <\"> };

                                     /* Translation of character literals */
chrlit: <'> ( <'> = { <\'> }
            | <\> smark any(ascii) scopy = { <\> 1 }
            | smark any(ascii) scopy = { 1 })
        <'> ( <,> = {} | null ) [cnt++]
        = { <(tword)'> 2 <',> * };

                                                 /* Translation of labels */
labels: label labels/done = { 2 1 };
label:  ( <__> number | name ) <:> decimal(cnt)
        = { <#define __> 2 <  (tword)&start[> 1 <]> * };
name:   ident scopy;
ident:  smark ignore(none) any(letter) string(alpha);
number: smark ignore(none) any(digit) string(digit) scopy;

                                  /* Translation of statements and values */
values: ignore(spaces) extval values/done = { 2 1 };
extval: ( extbit | null ) value ( <,> = {} | null ) = { 3 2 <,> * };
extbit: <1 + > = { <1 + > };
value:  number
     |  <_> ( number        = {  <_> 1 }
            | <_> number    = { <__> 1 }
            | wrd           = {  <_> 1 } ) = { 1 }
     |  builtn
     |  other;
wrd:    smark ignore(none) any(lowup) string(lowup) scopy;
other:  smark ignore(none) any(nbrk) string(nbrk) scopy
        = { <__> 1 };       /* Label name */

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

cnt:    0;

/* Idioms */
done:   ;           /* Same as:     done: = { 1 }; */
null:	= nil;      /* Delivers empty translation */
nil:	{};

/* Character classes */
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
nbrk:   !<<,
>>;
