/* Unix TMG example: Interbundle references */
/* Based on: "A Manual for the Tmg Compiler-writing Language" by McIlroy */

prog:   parse(doble)\prog
        parse(error)\prog;
error:  ignore(<<>>) smark string(nonl) scopy *
        = { <error: > 1 * };

doble:  dbla. * = { dbla.1 <|> dbla.0 * };

dbla:   ident.
        ( <,> dbla. = {ident </> dbla.1}. = {ident <\> dbla.0}
        | = { ident }. = { ident } );

ident:  ignore(<<>>) smark any(anum) string(anum) scopy;

anum:	<<0123456789>>
    	<<abcdefghijklmnopqrstuvwxyz>>
	<<ABCDEFGHIJKLMNOPQRSTUVWXYZ>>;
nonl:	!<<
>>;
