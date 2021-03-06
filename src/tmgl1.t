/* Implementation of TMG in TMGL. */
/* Converts TMGL program into a TMG driving table in C in two phases. */
/* Phase 1: based on the original implementation by M. Douglas McIlroy. */
/* It simplifies further translation by: */
/* - putting the string and character literals on separate lines */
/* - using underscores instead of dots in names and labels */
/* - removing .even and .globl directives */
/* - removing zero-byte from the end of strings */
/* - adding exit bit instead of juxtaposing */
/* - finishing the output with a newline */
/* (c) 2020, Andrii Makukha, 2-clause BSD License. */

begin:	ignore(blanks) [wordsz = &classes - &nclass]
pr1:	comment\pr1
	parse(first)\pr2
	diag(error)
pr2:	comment\pr2
	parse(line)\pr2
	diag(error)\pr2
	putcharcl
	parse(last);

first:	parse(( fref = { <1 + > 1 *}))
	getfref line = { 2 <:> 1 };

error:	smark ignore(none) any(!<<>>) string(!<<;>>) scopy 
	( <;> = {<;>} | null )
	= { * <??? error: > 2 1 * };

line:
	labels
	( charcl <;>
	| statement
	| numbers
	| trule <;> )
	= { 2 * 1 * };

numbers: number <;> numbers/done = { 2 * 1 };

labels:	label labels/done = { 2 * 1 };

label:	name <:> = { 1 <:> };

last:	= {	<_pn:1 + _pxs;> * <'\n'> *
		<_tn:1 + _txs;> * <'\n'> * };

comment: </*>
co1:	ignore(!<<*>>) <*> ignore(none) </>/co1;

statement: [csym=0] oldtab(dtt) oldtab(pat)
	( prc plst tlst <)> = (1){2 1 }
	| = (1){} noelem )
stt1:	bundle	( frag = (1){ 2(nil) * 1(q1) }\stt1
		| <;>	( ifelem = { 1(xbit) }
			| ={ 1(nil) * <1 + succ;> }
		)	);

prc:	smark ignore(none) <proc(>;

plst:	list(pident)/null remote((octal(npa)))
	= { <params;> * 1 * };

pident:	ident newtab(pat,npa);

tlst:	<;>/null [i=0] list((name [i++])) remote((octal(i)))
	= { <push;> * 1 * 2 * };

frag:	prule = (1){ 1(nil,q1) }
	| labels noelem = (1){ 1 };

/*in sequel q2 is where to go on fail,q1 is exit bit*/

prule:	[sndt=ndt] disj
	( <|> [ndt=sndt] fref
		( ifeasy prule = (2){ 3(nil,nil) * <salt;> * 2 *
				 1(q2,q1) * 2 <:> }
		| prule fref = (2){ 4({ * <alt;> * 1},q1) * <goto;> * 3 *
				1 <:> 2(q2,q1) * 3 <:>} )
		noelem
	| () );

disj:	pelem pdot
	( disj = (2){2(q2,nil) * 1(nil,q1)} ifelem/done ishard
	| () );

pelem:	pprim = (2){1(q1)$2} iseasy
	| <(>	push(1,sndt)
		( prule <)>
		| <)> = (2){} noelem );

pprim:	( special
	| rname	( <:> fail
		| (spdot|()) ignore(none)
			( <(> ignore(blanks) list(parg) <)>
				= (1){$1 2 * 1}
			| = (1){$1 1}  )))
	( (</> = { <alt;> * } | <\> = { <salt;> * })
		rname = (1){3(nil)*$1 2 1}
	| () );

pdot:	<.>/done ignore(none) ident\alias
	([dtt?] | table(dtt) [ndt=0]) [ndt++];
spdot:	<.> ignore(none) not(( any(letter) ))
alias:	newtab(dtt,ndt);

parg:	rname | remote(specparg);

specparg: number
	| charcl
	| <<> longlit
	| <*> = { <\n> }
	| <(> ( <)> = { <1 + succ;> }
		| push(3,dtt,ndt,sndt) [dtt=0]
			prule <)> oldtab(dtt)
			( ifelem = {1(nil,xbit) }
			| = {1(nil,nil) * <1 + succ;>} 
		)	);

iseasy:	[easy = 1];
ishard:	[easy = 0];
noelem:	[easy = 2];
ifelem:	[easy!=2?];
ifeasy:	[easy==1?];

special: <=> (rname | remote(trule))
		= (1){ $1 <trans;> * <1 + > 1 }
	| <<> literal = (1){ $1 <_px> 1 }
	| <*> = (1){ $1 <_pn> }
	| <[> expr
		( <?> = {<_t>}
		| = {<_p>} )
		<]> = (1){ 2 * $1 1 };

rname:	( name tabval(pat,npa)/done
	| <$> number )
	= { <[-> 1 <\<1]> };

trule:	oldtab(ptt)
	( tbody
	| <(> (number|tra) <)> tbody = {<gpar;> * 2 * 1 } );
tra:	list(tident) octal(npt);

tident:	ident newtab(ptt,npt);

tbody: <{>	( <}> = { <1 + generate> }
		| trb);
trb:	telem	( <}> = {  xbit 1 }
		| trb = { 2 * 1 } );

telem:	<<> literal = { <_tx> 1 }
	| <*> = { <_tn> }
	| <$> number = { <_tq;> * 1 }
	| number tdot = tpt
	| name te1\done te2\done;

te1:	tabval(dtt,ndt) tdot = tpt;
te2:	tabval(ptt,npt) = { <_tq;> * 1 };

tdot:	(<.> number | ={<0>})
	( <(> list(targ) <)> | null)
	= { 2 <;> 1 };

targ:	name|remote(tbody);

tpt:	{ <_tp;.byte > 2 <,> 1 };

literal: ( shortlit
	 | remote(longlit) = { <;> 1 } );

shortlit: ignore(none) smark any(litch) <>> scopy = { <s;> * <'> 1 <';> };

longlit: ignore(none) (<>> = { <\> <>> } | null) litb <>>
	 = { <<> 2 1 <>;> };

litb:	smark string(litch) scopy <\>/done
	litb = { 2 <\\> 1 };

expr:	assignment | rv ;

assignment: lv assign expr = { 3 * 1 * 2 };

rv:	prime
rv1:	bundle	( infix prime = { 3 * 1 * 2 }\rv1
		| rva = { 2 * 1 }
		| () );
rva:	<?> rv <:> rv fref fref 
	= { <_t;> * <alt;> * 2 * 4 * <salt;> * 1 * 2 <:> 3 * 1 <:> };

prime:
	lv suffix/done = { 2 * 1 }
	| prefix lv = { 1 * 2 }
	| <(> expr <)> 
	| unary prime = { 1 * 2 }
	| remote(number) = { <_l;> * 1 };

lv:	( rname = { <_l;> * 1 }
	| <(> lv <)>
	| <*> prime = { 1 * <_rv> } )
lv1:	<[>/done bundle expr <]> = { 2 * 1 * <_f> }\lv1;

assign:	<=> ignore(none) ( infix = { 1 * <_u> }
			| = { <_st> } );

infix:	smark ignore(none)
	( <+> not((<+> not((<+>)) )) = {<_a>}
	| <-> = {<_s>}
	| <*> = {<_m>}
	| </> = {<_q>}
	| <%> = {<_r>}
	| <|> = {<_o>}
	| <^> = {<_x>}
	| <&> = {<_n>}
	| <==> = {<_eq>}
	| <!=> = {<_ne>}
	| <<=> = {<_le>}
	| <>=> = {<_ge>}
	| <<<> = {<_sl>}
	| <<> = {<_lt>}
	| <>>	(  <>> = {<_sr>}
		| = {<_gt>} )
	);

prefix:	smark ignore(none)
	( <&> = {<_lv>}
	| <++> = {<_ib>}
	| <--> = {<_db>}
	);

suffix:	smark ignore(none)
	( <++> = {<_ia>}
	| <--> = {<_da>}
	);

unary:	( <!> = {<_nt>}
	| <-> = {<_ng>}
	| <~> = {<_cm>}
	);

charcl:
	( <!> ccla cclb | ccla )
	octal(classmask);
ccla:	(<<<>) [classmask = 1<<nclass++] [classmask?]/cherr
ccl1:	cclc <<<>\ccl1;
cclc:	ignore(none)

ccl3:	<>>\ccl4 ccle\ccl3;
ccl4:	(<>> | cclx fail) (not((<>>)) | ccle);
ccle:	char(n) [*(wordsz*n+&classes) =| classmask];
cclb:	zeron
ccl5:	[*(wordsz*n+&classes) =^ classmask] testn\ccl5;
cclx:	[nclass--] zeron
ccl6:	[*(wordsz*n+&classes) =& ~classmask] testn\ccl6;
cherr:	diag(( ={<too many char classes>} ));

zeron:	[n=0];
testn:	[++n<400?];

putcharcl: zeron [classes=0] 
	parse(( = { * <classtab:> * } ))
ptc1:	[w = *(wordsz*n+&classes)] parse((octal(w) = {1*}))
	bundle testn\ptc1;

classmask: 0;
nclass:	0;
classes:
cl1:	0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl2:	0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl3:	0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl4:	0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl5:	0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl6:	0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl7:	0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl8:	0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
/* More classes added to avoid issues with UTF-8 or Unicode */
cl9:	0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl10:   0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl11:   0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl12:   0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl13:   0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl14:   0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl15:   0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;
cl16:   0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;0;

done:	;

create:	[csym++]
getcsym: octal(csym) = { <_> 1 };

fref:	[fsym++]
getfref: octal(fsym) = { <__> 1 };

not:	params(1) $1/done fail;

list:	params(1) $1
list1:	bundle <,>/done $1 = { 2 * 1 }\list1;

remote:	params(1) create parse(rem1,$1);
rem1:	params(1) getcsym $1 = { 2 <=.> * 1 * };

number: smark ignore(none) any(digit) string(digit) scopy;

name:	ident scopy;

ident:	smark ignore(none) any(letter) string(alpha);

oldtab:	params(1) [$1?]/done discard($1) [$1=0];

newtab:	params(2) ([$2?] | table($2) [$1=0])
	enter($2,i) [$2[i] = $1++];

tabval:	params(2) [$2?] find($2,i) [i=$1-$2[i]] octal(i);

null:	= nil;

xbit:	{<1 + >};

q1:	{ $1 };
q2:	{ $2 };

nil:	{};

blanks:	<< 	
	>>;
digit:	<<0123456789>>;
letter:	<<abcdefghijklmnopqrstuvwxyz>>
	<<ABCDEFGHIJKLMNOPQRSTUVWXYZ>>;
alpha:	<<0123456789>>
	<<abcdefghijklmnopqrstuvwxyz>>
	<<ABCDEFGHIJKLMNOPQRSTUVWXYZ>>;
litch:	!<<\>>>;
none:	<<>>;

csym:	0;
fsym:	0;
easy:	0;
w:	0;
n:	0;
dtt:	0;	/*delivered translation table*/
ndt:	0;	/*numb of delivered translations*/
sndt:	0;	/*saved ndt at beginning of disjunctive term*/
pat:	0;	/*parsing rule parameter table*/
npa:	0;	/*number of parsing rule params*/
ptt:	0;	/*table of params of translation*/
npt:	0;	/*number of params of translation*/
i:	0;
wordsz: 0;      /* word size on the current architecture */
