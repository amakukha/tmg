/* Implementation of TMG in TMGL. */
/* Converts TMGL program into a TMG driving table in C in two phases. */
/* Phase 2: converts the output of phase 1 into a C header file. */
/* Based on the original TMGL implementation by M. Douglas McIlroy. */
/* (c) 2020, Andrii Makukha, 2-clause BSD License. */

begin:  ignore(blanks)
pr2:    parse(linenl)\pr2    
        diag(error)\pr2;

error:	smark ignore(none) any(!<<>>) string(nonl) scopy 
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
            | <\> smark any(!<<>>) scopy = { <\> 1 }
            | smark any(!<<>>) scopy = { 1 })
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
values: ignore(spaces) value values/done = { 2 1 };
value:  smark ignore(none) any(nbrk) string(nbrk) scopy
        ( <,> = {} | null )
        = { 2 <,> * };

cnt:    0;

/* Idioms */
done:   ;           /* Same as:     done: = { 1 }; */
null:	= nil;      /* Delivers empty translation */
nil:	{};

/* Character classes */
digit:	<<0123456789>>;
letter:	<<abcdefghijklmnopqrstuvwxyz>>
	<<ABCDEFGHIJKLMNOPQRSTUVWXYZ_>>;
alpha:	<<0123456789>>
	<<abcdefghijklmnopqrstuvwxyz>>
        <<ABCDEFGHIJKLMNOPQRSTUVWXYZ_>>;
litch:	!<<">>>;
none:	<<>>;
spaces:	<< 	>>;
blanks:	<< 	
	>>;
nonl:   !<<
>>;
nbrk:   !<<,
>>;
