/* FASTA format reader in Unix TMG */
/* RosettaCode task: http://rosettacode.org/wiki/FASTA_format */
/* Author: Andrii Makukha */

prog:   ignore(spaces)
loop:   parse(line)\loop 
        diag(error)\loop
        parse(( = {*} ));
line:   ( name | * = {} | seqns );
name:   <>> ignore(none) smark string(nonl) scopy *
        ( [f>0?] = {} | = {*} ) [f=0]
        = { 1 2 <: > };
seqns:  smark string(nonl) scopy * [f=0];
error:	smark ignore(none) any(ascii) string(nonl) scopy ( * | () )
	= { * <??? err: > 1 * };

f:      1;

none:   <<>>;
ascii:  !<<>>;
nonl:   !<<
>>;
spaces:	<< 	>>;
