/* The original implementation of TMG compiler in TMGL by M. Douglas McIlroy
 * with a single modification to account for different word sizes (see wordsz).
 * The resulting translator program converts TMG program into the TMG driving
 * table for PDP-11 (which is written in Unix assembly). */

#define SRC_LANGUAGE "TMGL"
#define DST_LANGUAGE "TMG driving table for PDP-11"

const tword labels[];

// Driving table for the program in C

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __begin    (tword)&start[1]
	(tword)&ignore,
#define __blanks   (tword)&labels[1]
	__blanks,
	(tword)&_l,
#define __wordsz   (tword)&labels[2]
	__wordsz,
	(tword)&_l,
#define __classes  (tword)&labels[3]
	__classes,
	(tword)&_lv,
	(tword)&_l,
#define __nclass   (tword)&labels[4]
	__nclass,
	(tword)&_lv,
	(tword)&_s,
	(tword)&_st,
	(tword)&_p,
#define __pr1      (tword)&start[14]
#define __comment  (tword)&labels[5]
	__comment,
	(tword)&salt,
	__pr1,
	(tword)&parse,
#define __first    (tword)&labels[6]
	__first,
	(tword)&salt,
#define __pr2      (tword)&labels[7]
	__pr2,
	(tword)&diag,
#define __error    (tword)&labels[8]
	__error,
// __pr2:
	__comment,
	(tword)&salt,
	__pr2,
	(tword)&parse,
#define __line     (tword)&labels[9]
	__line,
	(tword)&salt,
	__pr2,
	(tword)&diag,
	__error,
	(tword)&salt,
	__pr2,
#define __putcharcl (tword)&labels[10]
	__putcharcl,
	1 + (tword)&parse,
#define __last     (tword)&labels[11]
	__last,
#undef _3
#define _3         (tword)&start[37]
	(tword)"1 ",
#undef _2
#define _2         (tword)&start[38]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
#define _tn        (tword)&labels[12]
	1 + _tn,
#undef _1
#define _1         (tword)&start[43]
#define __fref     (tword)&labels[13]
	__fref,
	1 + (tword)&trans,
	1 + _2,
#undef _4
#define _4         (tword)&start[46]
	(tword)&_tp,
	2,
	(tword)&_txs,
	(tword)':',
	1 + (tword)&_tp,
	1,
// __first:
	(tword)&parse,
	_1,
#define __getfref  (tword)&labels[14]
	__getfref,
	__line,
	1 + (tword)&trans,
	1 + _4,
#undef _1
#define _1         (tword)&start[58]
	1,
#undef _2
#define _2         (tword)&start[59]
	2,
#undef _3
#define _3         (tword)&start[60]
	1 + (tword)&_txs,
	(tword)';',
#undef _5
#define _5         (tword)&start[62]
	(tword)"??? ",
#undef _4
#define _4         (tword)&start[63]
	_tn,
	(tword)&_tx,
	_5,
	(tword)&_tp,
	2,
	(tword)&_tp,
	1,
	1 + _tn,
// __error:
	(tword)&smark,
	(tword)&ignore,
#define __none     (tword)&labels[15]
	__none,
	(tword)&any,
	_1,
	(tword)&string,
	_2,
	(tword)&scopy,
	(tword)&_pxs,
	(tword)';',
	(tword)&alt,
#define __3        (tword)&labels[16]
	__3,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __2        (tword)&labels[17]
	__2,
// __3:
#define __null     (tword)&labels[18]
	__null,
// __2:
	1 + (tword)&trans,
	1 + _4,
#undef _1
#define _1         (tword)&start[90]
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tp,
	1,
	1 + _tn,
// __line:
#define __labels   (tword)&labels[19]
	__labels,
#define __charcl   (tword)&labels[20]
	__charcl,
	(tword)&alt,
#define __7        (tword)&labels[21]
	__7,
	(tword)&_pxs,
	(tword)';',
	(tword)&tgoto,
#define __4        (tword)&labels[22]
	__4,
// __7:
#define __statement (tword)&labels[23]
	__statement,
	(tword)&salt,
#define __5        (tword)&labels[24]
	__5,
#define __numbers  (tword)&labels[25]
	__numbers,
	(tword)&salt,
#define __6        (tword)&labels[26]
	__6,
#define __trule    (tword)&labels[27]
	__trule,
	(tword)&_pxs,
	(tword)';',
// __6:
// __5:
// __4:
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[115]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __numbers:
#define __number   (tword)&labels[28]
	__number,
	(tword)&_pxs,
	(tword)';',
	__numbers,
	(tword)&alt,
#define __done     (tword)&labels[29]
	__done,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[128]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __labels:
#define __label    (tword)&labels[30]
	__label,
	__labels,
	(tword)&alt,
	__done,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[139]
	(tword)&_tp,
	1,
	1 + (tword)&_txs,
	(tword)':',
// __label:
#define __name     (tword)&labels[31]
	__name,
	(tword)&_pxs,
	(tword)':',
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[148]
	(tword)".pn:1 .pxs;12",
#undef _3
#define _3         (tword)&start[149]
	(tword)".tn:1 .txs;12",
#undef _1
#define _1         (tword)&start[150]
	(tword)&_tx,
	_2,
	_tn,
	(tword)&_tx,
	_3,
	1 + _tn,
// __last:
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[158]
	(tword)"/*",
#undef _2
#define _2         (tword)&start[159]
	4,
// __comment:
	(tword)&_px,
	_1,
#define __co1      (tword)&start[162]
	(tword)&ignore,
	_2,
	(tword)&_pxs,
	(tword)'*',
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'/',
	1 + (tword)&alt,
	__co1,
#undef _1
#define _1         (tword)&start[172]
	0,
#undef _2
#define _2         (tword)&start[173]
	(tword)&gpar,
	1,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
#undef _3
#define _3         (tword)&start[179]
	(tword)&gpar,
	1,
	1 + (tword)&generate,
#undef _4
#define _4         (tword)&start[182]
	(tword)&gpar,
	1,
	(tword)&_tp,
	2,
#define __nil      (tword)&labels[32]
	__nil,
	_tn,
	1 + (tword)&_tp,
	1,
#define __q1       (tword)&labels[33]
	__q1,
#undef _5
#define _5         (tword)&start[191]
	1 + (tword)&_tp,
	1,
#define __xbit     (tword)&labels[34]
	__xbit,
#undef _7
#define _7         (tword)&start[194]
	(tword)"1 succ",
#undef _6
#define _6         (tword)&start[195]
	(tword)&_tp,
	1,
	__nil,
	_tn,
	1 + (tword)&_tx,
	_7,
// __statement:
	(tword)&_l,
#define __csym     (tword)&labels[35]
	__csym,
	(tword)&_l,
	_1,
	(tword)&_st,
	(tword)&_p,
#define __oldtab   (tword)&labels[36]
	__oldtab,
#define __dtt      (tword)&labels[37]
	__dtt,
	__oldtab,
#define __pat      (tword)&labels[38]
	__pat,
#define __proc     (tword)&labels[39]
	__proc,
	(tword)&alt,
#define __11       (tword)&labels[40]
	__11,
#define __plst     (tword)&labels[41]
	__plst,
#define __tlst     (tword)&labels[42]
	__tlst,
	(tword)&_pxs,
	(tword)')',
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __10       (tword)&labels[43]
	__10,
// __11:
	(tword)&trans,
	1 + _3,
#define __noelem   (tword)&labels[44]
	__noelem,
// __10:
#define __stt1     (tword)&start[225]
	(tword)&bundle,
#define __frag     (tword)&labels[45]
	__frag,
	(tword)&alt,
#define __15       (tword)&labels[46]
	__15,
	(tword)&trans,
	1 + _4,
	(tword)&salt,
	__stt1,
	(tword)&tgoto,
#define __12       (tword)&labels[47]
	__12,
// __15:
	(tword)&_pxs,
	(tword)';',
#define __ifelem   (tword)&labels[48]
	__ifelem,
	(tword)&alt,
#define __14       (tword)&labels[49]
	__14,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __13       (tword)&labels[50]
	__13,
// __14:
	(tword)&trans,
	1 + _6,
// __13:
// __12:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[247]
	(tword)"proc(",
// __proc:
	(tword)&smark,
	(tword)&ignore,
	__none,
	1 + (tword)&_px,
	_1,
#undef _1
#define _1         (tword)&start[253]
	1 + (tword)&octal,
#define __npa      (tword)&labels[51]
	__npa,
#undef _3
#define _3         (tword)&start[255]
	(tword)"params;",
#undef _2
#define _2         (tword)&start[256]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __plst:
#define __list     (tword)&labels[52]
	__list,
#define __pident   (tword)&labels[53]
	__pident,
	(tword)&alt,
	__null,
#define __remote   (tword)&labels[54]
	__remote,
	_1,
	1 + (tword)&trans,
	1 + _2,
// __pident:
#define __ident    (tword)&labels[55]
	__ident,
#define __newtab   (tword)&labels[56]
	1 + __newtab,
	__pat,
	__npa,
#undef _1
#define _1         (tword)&start[273]
	0,
#undef _2
#define _2         (tword)&start[274]
	__name,
	(tword)&_l,
#define __i        (tword)&labels[57]
	__i,
	(tword)&_ia,
	1 + (tword)&_p,
#undef _3
#define _3         (tword)&start[279]
	1 + (tword)&octal,
	__i,
#undef _5
#define _5         (tword)&start[281]
	(tword)"push;",
#undef _4
#define _4         (tword)&start[282]
	(tword)&_tx,
	_5,
	(tword)&_tp,
	1,
	_tn,
	(tword)&_tp,
	2,
	1 + _tn,
// __tlst:
	(tword)&_pxs,
	(tword)';',
	(tword)&alt,
	__null,
	(tword)&_l,
	__i,
	(tword)&_l,
	_1,
	(tword)&_st,
	(tword)&_p,
	__list,
	_2,
	__remote,
	_3,
	1 + (tword)&trans,
	1 + _4,
#undef _1
#define _1         (tword)&start[306]
	(tword)&gpar,
	1,
	1 + (tword)&_tp,
	1,
	__nil,
	__q1,
#undef _2
#define _2         (tword)&start[312]
	(tword)&gpar,
	1,
	1 + (tword)&_tp,
	1,
// __frag:
#define __prule    (tword)&labels[58]
	__prule,
	(tword)&alt,
#define __17       (tword)&labels[59]
	__17,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __16       (tword)&labels[60]
	__16,
// __17:
	__labels,
	__noelem,
	(tword)&trans,
	1 + _2,
// __16:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[328]
	(tword)"salt;",
#undef _1
#define _1         (tword)&start[329]
	(tword)&gpar,
	2,
	(tword)&_tp,
	3,
	__nil,
	__nil,
	_tn,
	(tword)&_tx,
	_2,
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tp,
	1,
#define __q2       (tword)&labels[61]
	__q2,
	__q1,
	_tn,
	(tword)&_tp,
	2,
	1 + (tword)&_txs,
	(tword)':',
#undef _5
#define _5         (tword)&start[350]
	(tword)"alt;",
#undef _4
#define _4         (tword)&start[351]
	_tn,
	(tword)&_tx,
	_5,
	1 + (tword)&_tp,
	1,
#undef _6
#define _6         (tword)&start[356]
	(tword)"goto;",
#undef _3
#define _3         (tword)&start[357]
	(tword)&gpar,
	2,
	(tword)&_tp,
	4,
	_4,
	__q1,
	_tn,
	(tword)&_tx,
	_6,
	(tword)&_tp,
	3,
	_tn,
	(tword)&_tp,
	1,
	(tword)&_txs,
	(tword)':',
	(tword)&_tp,
	2,
	__q2,
	__q1,
	_tn,
	(tword)&_tp,
	3,
	1 + (tword)&_txs,
	(tword)':',
// __prule:
	(tword)&_l,
#define __sndt     (tword)&labels[62]
	__sndt,
	(tword)&_l,
#define __ndt      (tword)&labels[63]
	__ndt,
	(tword)&_st,
	(tword)&_p,
#define __disj     (tword)&labels[64]
	__disj,
	(tword)&_pxs,
	(tword)'|',
	(tword)&alt,
#define __23       (tword)&labels[65]
	__23,
	(tword)&_l,
	__ndt,
	(tword)&_l,
	__sndt,
	(tword)&_st,
	(tword)&_p,
	__fref,
#define __ifeasy   (tword)&labels[66]
	__ifeasy,
	(tword)&alt,
#define __21       (tword)&labels[67]
	__21,
	__prule,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __20       (tword)&labels[68]
	__20,
// __21:
	__prule,
	__fref,
	(tword)&trans,
	1 + _3,
// __20:
	__noelem,
	(tword)&tgoto,
#define __22       (tword)&labels[69]
	__22,
// __23:
// __22:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[416]
	(tword)&gpar,
	2,
	(tword)&_tp,
	2,
	__q2,
	__nil,
	_tn,
	1 + (tword)&_tp,
	1,
	__nil,
	__q1,
// __disj:
#define __pelem    (tword)&labels[70]
	__pelem,
#define __pdot     (tword)&labels[71]
	__pdot,
	__disj,
	(tword)&alt,
#define __25       (tword)&labels[72]
	__25,
	(tword)&trans,
	1 + _1,
	__ifelem,
	(tword)&alt,
	__done,
#define __ishard   (tword)&labels[73]
	__ishard,
	(tword)&tgoto,
#define __24       (tword)&labels[74]
	__24,
// __25:
// __24:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[441]
	(tword)&gpar,
	2,
	(tword)&_tp,
	1,
	__q1,
	1 + (tword)&_tq,
	2,
#undef _2
#define _2         (tword)&start[448]
	1,
#undef _3
#define _3         (tword)&start[449]
	(tword)&gpar,
	2,
	1 + (tword)&generate,
// __pelem:
#define __pprim    (tword)&labels[75]
	__pprim,
	(tword)&alt,
#define __31       (tword)&labels[76]
	__31,
	(tword)&trans,
	1 + _1,
#define __iseasy   (tword)&labels[77]
	__iseasy,
	(tword)&tgoto,
#define __26       (tword)&labels[78]
	__26,
// __31:
	(tword)&_pxs,
	(tword)'(',
	(tword)&push,
	_2,
	__sndt,
	__prule,
	(tword)&alt,
#define __30       (tword)&labels[79]
	__30,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __27       (tword)&labels[80]
	__27,
// __30:
	(tword)&_pxs,
	(tword)')',
	(tword)&trans,
	1 + _3,
	__noelem,
// __27:
// __26:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[478]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
#undef _2
#define _2         (tword)&start[487]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	1 + (tword)&_tp,
	1,
#undef _4
#define _4         (tword)&start[493]
	(tword)"alt;",
#undef _3
#define _3         (tword)&start[494]
	1 + (tword)&_tx,
	_4,
#undef _5
#define _5         (tword)&start[496]
	(tword)"\\",
#undef _7
#define _7         (tword)&start[497]
	(tword)"salt;",
#undef _6
#define _6         (tword)&start[498]
	1 + (tword)&_tx,
	_7,
#undef _10
#define _10        (tword)&start[500]
	(tword)&gpar,
	1,
	(tword)&_tp,
	3,
	__nil,
	_tn,
	(tword)&_tq,
	1,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
// __pprim:
#define __special  (tword)&labels[81]
	__special,
	(tword)&salt,
#define __32       (tword)&labels[82]
	__32,
#define __rname    (tword)&labels[83]
	__rname,
	(tword)&_pxs,
	(tword)':',
	(tword)&alt,
#define __37       (tword)&labels[84]
	__37,
	(tword)&fail,
	(tword)&tgoto,
#define __33       (tword)&labels[85]
	__33,
// __37:
#define __spdot    (tword)&labels[86]
	__spdot,
	(tword)&salt,
#define __34       (tword)&labels[87]
	__34,
// __34:
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __36       (tword)&labels[88]
	__36,
	(tword)&ignore,
	__blanks,
	__list,
#define __parg     (tword)&labels[89]
	__parg,
	(tword)&_pxs,
	(tword)')',
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __35       (tword)&labels[90]
	__35,
// __36:
	(tword)&trans,
	1 + _2,
// __35:
// __33:
// __32:
	(tword)&_pxs,
	(tword)'/',
	(tword)&alt,
#define __41       (tword)&labels[91]
	__41,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __40       (tword)&labels[92]
	__40,
// __41:
	(tword)&_px,
	_5,
	(tword)&alt,
#define __43       (tword)&labels[93]
	__43,
	(tword)&trans,
	1 + _6,
// __40:
	__rname,
	(tword)&trans,
	1 + _10,
	(tword)&tgoto,
#define __42       (tword)&labels[94]
	__42,
// __43:
// __42:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[564]
	0,
// __pdot:
	(tword)&_pxs,
	(tword)'.',
	(tword)&alt,
	__done,
	(tword)&ignore,
	__none,
	__ident,
	(tword)&salt,
#define __alias    (tword)&labels[95]
	__alias,
	(tword)&_l,
	__dtt,
	(tword)&_t,
	(tword)&salt,
#define __44       (tword)&labels[96]
	__44,
	(tword)&table,
	__dtt,
	(tword)&_l,
	__ndt,
	(tword)&_l,
	_2,
	(tword)&_st,
	(tword)&_p,
// __44:
	(tword)&_l,
	__ndt,
	(tword)&_ia,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[591]
	1 + (tword)&any,
#define __letter   (tword)&labels[97]
	__letter,
// __spdot:
	(tword)&_pxs,
	(tword)'.',
	(tword)&ignore,
	__none,
#define __not      (tword)&labels[98]
	__not,
	_1,
// __alias:
	1 + __newtab,
	__dtt,
	__ndt,
// __parg:
	__rname,
	(tword)&salt,
#define __45       (tword)&labels[99]
	__45,
	__remote,
#define __specparg (tword)&labels[100]
	__specparg,
// __45:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[608]
	(tword)"\\n\\0",
#undef _1
#define _1         (tword)&start[609]
	1 + (tword)&_tx,
	_2,
#undef _4
#define _4         (tword)&start[611]
	(tword)"1 succ",
#undef _3
#define _3         (tword)&start[612]
	1 + (tword)&_tx,
	_4,
#undef _5
#define _5         (tword)&start[614]
	3,
#undef _6
#define _6         (tword)&start[615]
	0,
#undef _7
#define _7         (tword)&start[616]
	1 + (tword)&_tp,
	1,
	__nil,
	__xbit,
#undef _11
#define _11        (tword)&start[620]
	(tword)"1 succ",
#undef _10
#define _10        (tword)&start[621]
	(tword)&_tp,
	1,
	__nil,
	__nil,
	_tn,
	1 + (tword)&_tx,
	_11,
// __specparg:
	__number,
	(tword)&salt,
#define __46       (tword)&labels[101]
	__46,
	__charcl,
	(tword)&salt,
#define __47       (tword)&labels[102]
	__47,
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __57       (tword)&labels[103]
	__57,
#define __longlit  (tword)&labels[104]
	__longlit,
	(tword)&tgoto,
#define __50       (tword)&labels[105]
	__50,
// __57:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __56       (tword)&labels[106]
	__56,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __51       (tword)&labels[107]
	__51,
// __56:
	(tword)&_pxs,
	(tword)'(',
	(tword)&_pxs,
	(tword)')',
	(tword)&alt,
#define __55       (tword)&labels[108]
	__55,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __52       (tword)&labels[109]
	__52,
// __55:
	(tword)&push,
	_5,
	__dtt,
	__ndt,
	__sndt,
	(tword)&_l,
	__dtt,
	(tword)&_l,
	_6,
	(tword)&_st,
	(tword)&_p,
	__prule,
	(tword)&_pxs,
	(tword)')',
	__oldtab,
	__dtt,
	__ifelem,
	(tword)&alt,
#define __54       (tword)&labels[110]
	__54,
	(tword)&trans,
	1 + _7,
	(tword)&tgoto,
#define __53       (tword)&labels[111]
	__53,
// __54:
	(tword)&trans,
	1 + _10,
// __53:
// __52:
// __51:
// __50:
// __47:
// __46:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[685]
	1,
// __iseasy:
	(tword)&_l,
#define __easy     (tword)&labels[112]
	__easy,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[692]
	0,
// __ishard:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[699]
	2,
// __noelem:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[706]
	2,
// __ifelem:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_1,
	(tword)&_ne,
	1 + (tword)&_t,
#undef _2
#define _2         (tword)&start[713]
	1,
// __ifeasy:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_2,
	(tword)&_eq,
	1 + (tword)&_t,
#undef _2
#define _2         (tword)&start[720]
	(tword)"trans;1 ",
#undef _1
#define _1         (tword)&start[721]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
#undef _4
#define _4         (tword)&start[729]
	(tword)".px",
#undef _3
#define _3         (tword)&start[730]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	(tword)&_tx,
	_4,
	1 + (tword)&_tp,
	1,
#undef _6
#define _6         (tword)&start[738]
	(tword)".pn",
#undef _5
#define _5         (tword)&start[739]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	1 + (tword)&_tx,
	_6,
#undef _10
#define _10        (tword)&start[745]
	(tword)".t",
#undef _7
#define _7         (tword)&start[746]
	1 + (tword)&_tx,
	_10,
#undef _12
#define _12        (tword)&start[748]
	(tword)".p",
#undef _11
#define _11        (tword)&start[749]
	1 + (tword)&_tx,
	_12,
#undef _13
#define _13        (tword)&start[751]
	(tword)&gpar,
	1,
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tq,
	1,
	1 + (tword)&_tp,
	1,
// __special:
	(tword)&_pxs,
	(tword)'=',
	(tword)&alt,
#define __70       (tword)&labels[113]
	__70,
	__rname,
	(tword)&salt,
#define __60       (tword)&labels[114]
	__60,
	__remote,
	__trule,
// __60:
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __61       (tword)&labels[115]
	__61,
// __70:
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __67       (tword)&labels[116]
	__67,
#define __literal  (tword)&labels[117]
	__literal,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __62       (tword)&labels[118]
	__62,
// __67:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __66       (tword)&labels[119]
	__66,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __63       (tword)&labels[120]
	__63,
// __66:
	(tword)&_pxs,
	(tword)'[',
#define __expr     (tword)&labels[121]
	__expr,
	(tword)&_pxs,
	(tword)'?',
	(tword)&alt,
#define __65       (tword)&labels[122]
	__65,
	(tword)&trans,
	1 + _7,
	(tword)&tgoto,
#define __64       (tword)&labels[123]
	__64,
// __65:
	(tword)&trans,
	1 + _11,
// __64:
	(tword)&_pxs,
	(tword)']',
	(tword)&trans,
	1 + _13,
// __63:
// __62:
// __61:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[808]
	(tword)"[-",
#undef _3
#define _3         (tword)&start[809]
	(tword)"\\<1]",
#undef _1
#define _1         (tword)&start[810]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	1 + (tword)&_tx,
	_3,
// __rname:
	__name,
	(tword)&alt,
#define __72       (tword)&labels[124]
	__72,
#define __tabval   (tword)&labels[125]
	__tabval,
	__pat,
	__npa,
	(tword)&alt,
	__done,
	(tword)&tgoto,
#define __71       (tword)&labels[126]
	__71,
// __72:
	(tword)&_pxs,
	(tword)'$',
	__number,
// __71:
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[831]
	(tword)"gpar;",
#undef _1
#define _1         (tword)&start[832]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __trule:
	__oldtab,
#define __ptt      (tword)&labels[127]
	__ptt,
#define __tbody    (tword)&labels[128]
	__tbody,
	(tword)&salt,
#define __73       (tword)&labels[129]
	__73,
	(tword)&_pxs,
	(tword)'(',
	__number,
	(tword)&salt,
#define __74       (tword)&labels[130]
	__74,
#define __tra      (tword)&labels[131]
	__tra,
// __74:
	(tword)&_pxs,
	(tword)')',
	__tbody,
	(tword)&trans,
	1 + _1,
// __73:
	1 + (tword)&succ,
// __tra:
	__list,
#define __tident   (tword)&labels[132]
	__tident,
	1 + (tword)&octal,
#define __npt      (tword)&labels[133]
	__npt,
// __tident:
	__ident,
	1 + __newtab,
	__ptt,
	__npt,
#undef _2
#define _2         (tword)&start[864]
	(tword)"1 generate",
#undef _1
#define _1         (tword)&start[865]
	1 + (tword)&_tx,
	_2,
// __tbody:
	(tword)&_pxs,
	(tword)'{',
	(tword)&_pxs,
	(tword)'}',
	(tword)&alt,
#define __76       (tword)&labels[134]
	__76,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __75       (tword)&labels[135]
	__75,
// __76:
#define __trb      (tword)&labels[136]
	__trb,
// __75:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[879]
	__xbit,
	1 + (tword)&_tp,
	1,
#undef _2
#define _2         (tword)&start[882]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __trb:
#define __telem    (tword)&labels[137]
	__telem,
	(tword)&_pxs,
	(tword)'}',
	(tword)&alt,
#define __100      (tword)&labels[138]
	__100,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __77       (tword)&labels[139]
	__77,
// __100:
	__trb,
	(tword)&trans,
	1 + _2,
// __77:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[900]
	(tword)".tx",
#undef _1
#define _1         (tword)&start[901]
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
#undef _4
#define _4         (tword)&start[905]
	(tword)".tn",
#undef _3
#define _3         (tword)&start[906]
	1 + (tword)&_tx,
	_4,
#undef _6
#define _6         (tword)&start[908]
	(tword)".tq;",
#undef _5
#define _5         (tword)&start[909]
	(tword)&_tx,
	_6,
	1 + (tword)&_tp,
	1,
// __telem:
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __110      (tword)&labels[140]
	__110,
	__literal,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __101      (tword)&labels[141]
	__101,
// __110:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __107      (tword)&labels[142]
	__107,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __102      (tword)&labels[143]
	__102,
// __107:
	(tword)&_pxs,
	(tword)'$',
	(tword)&alt,
#define __106      (tword)&labels[144]
	__106,
	__number,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __103      (tword)&labels[145]
	__103,
// __106:
	__number,
	(tword)&alt,
#define __105      (tword)&labels[146]
	__105,
#define __tdot     (tword)&labels[147]
	__tdot,
	(tword)&trans,
#define __tpt      (tword)&labels[148]
	1 + __tpt,
	(tword)&tgoto,
#define __104      (tword)&labels[149]
	__104,
// __105:
	__name,
#define __te1      (tword)&labels[150]
	__te1,
	(tword)&salt,
	__done,
#define __te2      (tword)&labels[151]
	__te2,
	(tword)&salt,
	__done,
// __104:
// __103:
// __102:
// __101:
	1 + (tword)&succ,
// __te1:
	__tabval,
	__dtt,
	__ndt,
	__tdot,
	1 + (tword)&trans,
	1 + __tpt,
#undef _2
#define _2         (tword)&start[961]
	(tword)".tq;",
#undef _1
#define _1         (tword)&start[962]
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
// __te2:
	__tabval,
	__ptt,
	__npt,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[971]
	1 + (tword)&_txs,
	(tword)'0',
#undef _2
#define _2         (tword)&start[973]
	(tword)&_tp,
	2,
	(tword)&_txs,
	(tword)';',
	1 + (tword)&_tp,
	1,
// __tdot:
	(tword)&_pxs,
	(tword)'.',
	(tword)&alt,
#define __112      (tword)&labels[152]
	__112,
	__number,
	(tword)&tgoto,
#define __111      (tword)&labels[153]
	__111,
// __112:
	(tword)&trans,
	1 + _1,
// __111:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __114      (tword)&labels[154]
	__114,
	__list,
#define __targ     (tword)&labels[155]
	__targ,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __113      (tword)&labels[156]
	__113,
// __114:
	__null,
// __113:
	1 + (tword)&trans,
	1 + _2,
// __targ:
	__name,
	(tword)&salt,
#define __115      (tword)&labels[157]
	__115,
	__remote,
	__tbody,
// __115:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[1007]
	(tword)".tp;.byte ",
// __tpt:
	(tword)&_tx,
	_1,
	(tword)&_tp,
	2,
	(tword)&_txs,
	(tword)',',
	1 + (tword)&_tp,
	1,
#undef _1
#define _1         (tword)&start[1016]
	(tword)&_txs,
	(tword)';',
	1 + (tword)&_tp,
	1,
// __literal:
#define __shortlit (tword)&labels[158]
	__shortlit,
	(tword)&salt,
#define __116      (tword)&labels[159]
	__116,
	__remote,
	__longlit,
	(tword)&trans,
	1 + _1,
// __116:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[1028]
	(tword)">",
#undef _3
#define _3         (tword)&start[1029]
	(tword)"s;'",
#undef _2
#define _2         (tword)&start[1030]
	(tword)&_tx,
	_3,
	1 + (tword)&_tp,
	1,
// __shortlit:
	(tword)&ignore,
	__none,
	(tword)&smark,
	(tword)&any,
#define __litch    (tword)&labels[160]
	__litch,
	(tword)&_px,
	_1,
	(tword)&scopy,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[1044]
	(tword)">",
#undef _3
#define _3         (tword)&start[1045]
	(tword)"\\",
#undef _4
#define _4         (tword)&start[1046]
	(tword)">",
#undef _2
#define _2         (tword)&start[1047]
	(tword)&_tx,
	_3,
	1 + (tword)&_tx,
	_4,
#undef _5
#define _5         (tword)&start[1051]
	(tword)">",
#undef _7
#define _7         (tword)&start[1052]
	(tword)"\\0",
#undef _10
#define _10        (tword)&start[1053]
	(tword)">;.even",
#undef _6
#define _6         (tword)&start[1054]
	(tword)&_txs,
	(tword)'<',
	(tword)&_tp,
	2,
	(tword)&_tp,
	1,
	(tword)&_tx,
	_7,
	1 + (tword)&_tx,
	_10,
// __longlit:
	(tword)&ignore,
	__none,
	(tword)&_px,
	_1,
	(tword)&alt,
#define __120      (tword)&labels[161]
	__120,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __117      (tword)&labels[162]
	__117,
// __120:
	__null,
// __117:
#define __litb     (tword)&labels[163]
	__litb,
	(tword)&_px,
	_5,
	1 + (tword)&trans,
	1 + _6,
#undef _1
#define _1         (tword)&start[1080]
	(tword)"\\",
#undef _3
#define _3         (tword)&start[1081]
	(tword)"\\\\",
#undef _2
#define _2         (tword)&start[1082]
	(tword)&_tp,
	2,
	(tword)&_tx,
	_3,
	1 + (tword)&_tp,
	1,
// __litb:
	(tword)&smark,
	(tword)&string,
	__litch,
	(tword)&scopy,
	(tword)&_px,
	_1,
	(tword)&alt,
	__done,
	__litb,
	1 + (tword)&trans,
	1 + _2,
// __expr:
#define __assignment (tword)&labels[164]
	__assignment,
	(tword)&salt,
#define __121      (tword)&labels[165]
	__121,
#define __rv       (tword)&labels[166]
	__rv,
// __121:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[1104]
	(tword)&_tp,
	3,
	_tn,
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
// __assignment:
#define __lv       (tword)&labels[167]
	__lv,
#define __assign   (tword)&labels[168]
	__assign,
	__expr,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[1117]
	(tword)&_tp,
	3,
	_tn,
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
#undef _2
#define _2         (tword)&start[1125]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __rv:
#define __prime    (tword)&labels[169]
	__prime,
#define __rv1      (tword)&start[1131]
	(tword)&bundle,
#define __infix    (tword)&labels[170]
	__infix,
	(tword)&alt,
#define __125      (tword)&labels[171]
	__125,
	__prime,
	(tword)&trans,
	1 + _1,
	(tword)&salt,
	__rv1,
	(tword)&tgoto,
#define __122      (tword)&labels[172]
	__122,
// __125:
#define __rva      (tword)&labels[173]
	__rva,
	(tword)&alt,
#define __124      (tword)&labels[174]
	__124,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __123      (tword)&labels[175]
	__123,
// __124:
// __123:
// __122:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[1150]
	(tword)".t;alt;",
#undef _3
#define _3         (tword)&start[1151]
	(tword)"salt;",
#undef _1
#define _1         (tword)&start[1152]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tp,
	4,
	_tn,
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	_tn,
	(tword)&_tp,
	2,
	(tword)&_txs,
	(tword)':',
	(tword)&_tp,
	3,
	_tn,
	(tword)&_tp,
	1,
	1 + (tword)&_txs,
	(tword)':',
// __rva:
	(tword)&_pxs,
	(tword)'?',
	__rv,
	(tword)&_pxs,
	(tword)':',
	__rv,
	__fref,
	__fref,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[1186]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
#undef _2
#define _2         (tword)&start[1191]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
#undef _3
#define _3         (tword)&start[1196]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
#undef _5
#define _5         (tword)&start[1201]
	(tword)".l;",
#undef _4
#define _4         (tword)&start[1202]
	(tword)&_tx,
	_5,
	1 + (tword)&_tp,
	1,
// __prime:
	__lv,
	(tword)&alt,
#define __135      (tword)&labels[176]
	__135,
#define __suffix   (tword)&labels[177]
	__suffix,
	(tword)&alt,
	__done,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __126      (tword)&labels[178]
	__126,
// __135:
#define __prefix   (tword)&labels[179]
	__prefix,
	(tword)&alt,
#define __134      (tword)&labels[180]
	__134,
	__lv,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __127      (tword)&labels[181]
	__127,
// __134:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __133      (tword)&labels[182]
	__133,
	__expr,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __130      (tword)&labels[183]
	__130,
// __133:
#define __unary    (tword)&labels[184]
	__unary,
	(tword)&alt,
#define __132      (tword)&labels[185]
	__132,
	__prime,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __131      (tword)&labels[186]
	__131,
// __132:
	__remote,
	__number,
	(tword)&trans,
	1 + _4,
// __131:
// __130:
// __127:
// __126:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[1246]
	(tword)".l;",
#undef _1
#define _1         (tword)&start[1247]
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
#undef _4
#define _4         (tword)&start[1251]
	(tword)".rv",
#undef _3
#define _3         (tword)&start[1252]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tx,
	_4,
#undef _6
#define _6         (tword)&start[1257]
	(tword)".f",
#undef _5
#define _5         (tword)&start[1258]
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tx,
	_6,
// __lv:
	__rname,
	(tword)&alt,
#define __141      (tword)&labels[187]
	__141,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __136      (tword)&labels[188]
	__136,
// __141:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __140      (tword)&labels[189]
	__140,
	__lv,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __137      (tword)&labels[190]
	__137,
// __140:
	(tword)&_pxs,
	(tword)'*',
	__prime,
	(tword)&trans,
	1 + _3,
// __137:
// __136:
#define __lv1      (tword)&start[1287]
	(tword)&_pxs,
	(tword)'[',
	(tword)&alt,
	__done,
	(tword)&bundle,
	__expr,
	(tword)&_pxs,
	(tword)']',
	(tword)&trans,
	1 + _5,
	1 + (tword)&salt,
	__lv1,
#undef _2
#define _2         (tword)&start[1299]
	(tword)".u",
#undef _1
#define _1         (tword)&start[1300]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tx,
	_2,
#undef _4
#define _4         (tword)&start[1305]
	(tword)".st",
#undef _3
#define _3         (tword)&start[1306]
	1 + (tword)&_tx,
	_4,
// __assign:
	(tword)&_pxs,
	(tword)'=',
	(tword)&ignore,
	__none,
	__infix,
	(tword)&alt,
#define __143      (tword)&labels[191]
	__143,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __142      (tword)&labels[192]
	__142,
// __143:
	(tword)&trans,
	1 + _3,
// __142:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[1322]
	1 + (tword)&_pxs,
	(tword)'+',
#undef _1
#define _1         (tword)&start[1324]
	(tword)&_pxs,
	(tword)'+',
	1 + __not,
	_2,
#undef _4
#define _4         (tword)&start[1328]
	(tword)".a",
#undef _3
#define _3         (tword)&start[1329]
	1 + (tword)&_tx,
	_4,
#undef _6
#define _6         (tword)&start[1331]
	(tword)".s",
#undef _5
#define _5         (tword)&start[1332]
	1 + (tword)&_tx,
	_6,
#undef _10
#define _10        (tword)&start[1334]
	(tword)".m",
#undef _7
#define _7         (tword)&start[1335]
	1 + (tword)&_tx,
	_10,
#undef _12
#define _12        (tword)&start[1337]
	(tword)".q",
#undef _11
#define _11        (tword)&start[1338]
	1 + (tword)&_tx,
	_12,
#undef _14
#define _14        (tword)&start[1340]
	(tword)".r",
#undef _13
#define _13        (tword)&start[1341]
	1 + (tword)&_tx,
	_14,
#undef _16
#define _16        (tword)&start[1343]
	(tword)".o",
#undef _15
#define _15        (tword)&start[1344]
	1 + (tword)&_tx,
	_16,
#undef _20
#define _20        (tword)&start[1346]
	(tword)".x",
#undef _17
#define _17        (tword)&start[1347]
	1 + (tword)&_tx,
	_20,
#undef _22
#define _22        (tword)&start[1349]
	(tword)".n",
#undef _21
#define _21        (tword)&start[1350]
	1 + (tword)&_tx,
	_22,
#undef _23
#define _23        (tword)&start[1352]
	(tword)"==",
#undef _25
#define _25        (tword)&start[1353]
	(tword)".eq",
#undef _24
#define _24        (tword)&start[1354]
	1 + (tword)&_tx,
	_25,
#undef _26
#define _26        (tword)&start[1356]
	(tword)"!=",
#undef _30
#define _30        (tword)&start[1357]
	(tword)".ne",
#undef _27
#define _27        (tword)&start[1358]
	1 + (tword)&_tx,
	_30,
#undef _31
#define _31        (tword)&start[1360]
	(tword)"<=",
#undef _33
#define _33        (tword)&start[1361]
	(tword)".le",
#undef _32
#define _32        (tword)&start[1362]
	1 + (tword)&_tx,
	_33,
#undef _34
#define _34        (tword)&start[1364]
	(tword)">=",
#undef _36
#define _36        (tword)&start[1365]
	(tword)".ge",
#undef _35
#define _35        (tword)&start[1366]
	1 + (tword)&_tx,
	_36,
#undef _37
#define _37        (tword)&start[1368]
	(tword)"<<",
#undef _41
#define _41        (tword)&start[1369]
	(tword)".sl",
#undef _40
#define _40        (tword)&start[1370]
	1 + (tword)&_tx,
	_41,
#undef _43
#define _43        (tword)&start[1372]
	(tword)".lt",
#undef _42
#define _42        (tword)&start[1373]
	1 + (tword)&_tx,
	_43,
#undef _44
#define _44        (tword)&start[1375]
	(tword)">",
#undef _45
#define _45        (tword)&start[1376]
	(tword)">",
#undef _47
#define _47        (tword)&start[1377]
	(tword)".sr",
#undef _46
#define _46        (tword)&start[1378]
	1 + (tword)&_tx,
	_47,
#undef _51
#define _51        (tword)&start[1380]
	(tword)".gt",
#undef _50
#define _50        (tword)&start[1381]
	1 + (tword)&_tx,
	_51,
// __infix:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'+',
	(tword)&alt,
#define __201      (tword)&labels[193]
	__201,
	__not,
	_1,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __144      (tword)&labels[194]
	__144,
// __201:
	(tword)&_pxs,
	(tword)'-',
	(tword)&alt,
#define __200      (tword)&labels[195]
	__200,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __145      (tword)&labels[196]
	__145,
// __200:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __177      (tword)&labels[197]
	__177,
	(tword)&trans,
	1 + _7,
	(tword)&tgoto,
#define __146      (tword)&labels[198]
	__146,
// __177:
	(tword)&_pxs,
	(tword)'/',
	(tword)&alt,
#define __176      (tword)&labels[199]
	__176,
	(tword)&trans,
	1 + _11,
	(tword)&tgoto,
#define __147      (tword)&labels[200]
	__147,
// __176:
	(tword)&_pxs,
	(tword)'%',
	(tword)&alt,
#define __175      (tword)&labels[201]
	__175,
	(tword)&trans,
	1 + _13,
	(tword)&tgoto,
#define __150      (tword)&labels[202]
	__150,
// __175:
	(tword)&_pxs,
	(tword)'|',
	(tword)&alt,
#define __174      (tword)&labels[203]
	__174,
	(tword)&trans,
	1 + _15,
	(tword)&tgoto,
#define __151      (tword)&labels[204]
	__151,
// __174:
	(tword)&_pxs,
	(tword)'^',
	(tword)&alt,
#define __173      (tword)&labels[205]
	__173,
	(tword)&trans,
	1 + _17,
	(tword)&tgoto,
#define __152      (tword)&labels[206]
	__152,
// __173:
	(tword)&_pxs,
	(tword)'&',
	(tword)&alt,
#define __172      (tword)&labels[207]
	__172,
	(tword)&trans,
	1 + _21,
	(tword)&tgoto,
#define __153      (tword)&labels[208]
	__153,
// __172:
	(tword)&_px,
	_23,
	(tword)&alt,
#define __171      (tword)&labels[209]
	__171,
	(tword)&trans,
	1 + _24,
	(tword)&tgoto,
#define __154      (tword)&labels[210]
	__154,
// __171:
	(tword)&_px,
	_26,
	(tword)&alt,
#define __170      (tword)&labels[211]
	__170,
	(tword)&trans,
	1 + _27,
	(tword)&tgoto,
#define __155      (tword)&labels[212]
	__155,
// __170:
	(tword)&_px,
	_31,
	(tword)&alt,
#define __167      (tword)&labels[213]
	__167,
	(tword)&trans,
	1 + _32,
	(tword)&tgoto,
#define __156      (tword)&labels[214]
	__156,
// __167:
	(tword)&_px,
	_34,
	(tword)&alt,
#define __166      (tword)&labels[215]
	__166,
	(tword)&trans,
	1 + _35,
	(tword)&tgoto,
#define __157      (tword)&labels[216]
	__157,
// __166:
	(tword)&_px,
	_37,
	(tword)&alt,
#define __165      (tword)&labels[217]
	__165,
	(tword)&trans,
	1 + _40,
	(tword)&tgoto,
#define __160      (tword)&labels[218]
	__160,
// __165:
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __164      (tword)&labels[219]
	__164,
	(tword)&trans,
	1 + _42,
	(tword)&tgoto,
#define __161      (tword)&labels[220]
	__161,
// __164:
	(tword)&_px,
	_44,
	(tword)&_px,
	_45,
	(tword)&alt,
#define __163      (tword)&labels[221]
	__163,
	(tword)&trans,
	1 + _46,
	(tword)&tgoto,
#define __162      (tword)&labels[222]
	__162,
// __163:
	(tword)&trans,
	1 + _50,
// __162:
// __161:
// __160:
// __157:
// __156:
// __155:
// __154:
// __153:
// __152:
// __151:
// __150:
// __147:
// __146:
// __145:
// __144:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[1513]
	(tword)".lv",
#undef _1
#define _1         (tword)&start[1514]
	1 + (tword)&_tx,
	_2,
#undef _3
#define _3         (tword)&start[1516]
	(tword)"++",
#undef _5
#define _5         (tword)&start[1517]
	(tword)".ib",
#undef _4
#define _4         (tword)&start[1518]
	1 + (tword)&_tx,
	_5,
#undef _6
#define _6         (tword)&start[1520]
	(tword)"--",
#undef _10
#define _10        (tword)&start[1521]
	(tword)".db",
#undef _7
#define _7         (tword)&start[1522]
	1 + (tword)&_tx,
	_10,
// __prefix:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'&',
	(tword)&alt,
#define __205      (tword)&labels[223]
	__205,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __202      (tword)&labels[224]
	__202,
// __205:
	(tword)&_px,
	_3,
	(tword)&alt,
#define __204      (tword)&labels[225]
	__204,
	(tword)&trans,
	1 + _4,
	(tword)&tgoto,
#define __203      (tword)&labels[226]
	__203,
// __204:
	(tword)&_px,
	_6,
	(tword)&trans,
	1 + _7,
// __203:
// __202:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[1548]
	(tword)"++",
#undef _3
#define _3         (tword)&start[1549]
	(tword)".ia",
#undef _2
#define _2         (tword)&start[1550]
	1 + (tword)&_tx,
	_3,
#undef _4
#define _4         (tword)&start[1552]
	(tword)"--",
#undef _6
#define _6         (tword)&start[1553]
	(tword)".da",
#undef _5
#define _5         (tword)&start[1554]
	1 + (tword)&_tx,
	_6,
// __suffix:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&_px,
	_1,
	(tword)&alt,
#define __207      (tword)&labels[227]
	__207,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __206      (tword)&labels[228]
	__206,
// __207:
	(tword)&_px,
	_4,
	(tword)&trans,
	1 + _5,
// __206:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[1572]
	(tword)".nt",
#undef _1
#define _1         (tword)&start[1573]
	1 + (tword)&_tx,
	_2,
#undef _4
#define _4         (tword)&start[1575]
	(tword)".ng",
#undef _3
#define _3         (tword)&start[1576]
	1 + (tword)&_tx,
	_4,
#undef _6
#define _6         (tword)&start[1578]
	(tword)".cm",
#undef _5
#define _5         (tword)&start[1579]
	1 + (tword)&_tx,
	_6,
// __unary:
	(tword)&_pxs,
	(tword)'!',
	(tword)&alt,
#define __213      (tword)&labels[229]
	__213,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __210      (tword)&labels[230]
	__210,
// __213:
	(tword)&_pxs,
	(tword)'-',
	(tword)&alt,
#define __212      (tword)&labels[231]
	__212,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __211      (tword)&labels[232]
	__211,
// __212:
	(tword)&_pxs,
	(tword)'~',
	(tword)&trans,
	1 + _5,
// __211:
// __210:
	1 + (tword)&succ,
// __charcl:
	(tword)&_pxs,
	(tword)'!',
	(tword)&alt,
#define __215      (tword)&labels[233]
	__215,
#define __ccla     (tword)&labels[234]
	__ccla,
#define __cclb     (tword)&labels[235]
	__cclb,
	(tword)&tgoto,
#define __214      (tword)&labels[236]
	__214,
// __215:
	__ccla,
// __214:
	1 + (tword)&octal,
#define __classmask (tword)&labels[237]
	__classmask,
#undef _1
#define _1         (tword)&start[1613]
	(tword)"<<",
#undef _2
#define _2         (tword)&start[1614]
	1,
#undef _4
#define _4         (tword)&start[1615]
	(tword)"<<",
// __ccla:
	(tword)&_px,
	_1,
	(tword)&_l,
	__classmask,
	(tword)&_l,
	_2,
	(tword)&_l,
	__nclass,
	(tword)&_ia,
	(tword)&_sl,
	(tword)&_st,
	(tword)&_p,
	(tword)&_l,
	__classmask,
	(tword)&_t,
	(tword)&alt,
#define __cherr    (tword)&labels[238]
	__cherr,
#define __ccl1     (tword)&start[1633]
#define __cclc     (tword)&labels[239]
	__cclc,
	(tword)&_px,
	_4,
	1 + (tword)&salt,
	__ccl1,
#undef _1
#define _1         (tword)&start[1638]
	(tword)">",
// __cclc:
	(tword)&ignore,
	__none,
#define __ccl3     (tword)&start[1641]
	(tword)&_px,
	_1,
	(tword)&salt,
#define __ccl4     (tword)&labels[240]
	__ccl4,
#define __ccle     (tword)&labels[241]
	__ccle,
	1 + (tword)&salt,
	__ccl3,
#undef _1
#define _1         (tword)&start[1648]
	(tword)">",
#undef _3
#define _3         (tword)&start[1649]
	(tword)">",
#undef _2
#define _2         (tword)&start[1650]
	1 + (tword)&_px,
	_3,
// __ccl4:
	(tword)&_px,
	_1,
	(tword)&salt,
#define __216      (tword)&labels[242]
	__216,
#define __cclx     (tword)&labels[243]
	__cclx,
	(tword)&fail,
// __216:
	__not,
	_2,
	(tword)&salt,
#define __217      (tword)&labels[244]
	__217,
	__ccle,
// __217:
	1 + (tword)&succ,
// __ccle:
	(tword)&tchar,
#define __n        (tword)&labels[245]
	__n,
	(tword)&_l,
	__wordsz,
	(tword)&_l,
	__n,
	(tword)&_m,
	(tword)&_l,
	__classes,
	(tword)&_lv,
	(tword)&_a,
	(tword)&_rv,
	(tword)&_l,
	__classmask,
	(tword)&_o,
	(tword)&_u,
	1 + (tword)&_p,
// __cclb:
#define __zeron    (tword)&labels[246]
	__zeron,
#define __ccl5     (tword)&start[1682]
	(tword)&_l,
	__wordsz,
	(tword)&_l,
	__n,
	(tword)&_m,
	(tword)&_l,
	__classes,
	(tword)&_lv,
	(tword)&_a,
	(tword)&_rv,
	(tword)&_l,
	__classmask,
	(tword)&_x,
	(tword)&_u,
	(tword)&_p,
#define __testn    (tword)&labels[247]
	__testn,
	1 + (tword)&salt,
	__ccl5,
// __cclx:
	(tword)&_l,
	__nclass,
	(tword)&_da,
	(tword)&_p,
	__zeron,
#define __ccl6     (tword)&start[1705]
	(tword)&_l,
	__wordsz,
	(tword)&_l,
	__n,
	(tword)&_m,
	(tword)&_l,
	__classes,
	(tword)&_lv,
	(tword)&_a,
	(tword)&_rv,
	(tword)&_l,
	__classmask,
	(tword)&_cm,
	(tword)&_n,
	(tword)&_u,
	(tword)&_p,
	__testn,
	1 + (tword)&salt,
	__ccl6,
#undef _3
#define _3         (tword)&start[1724]
	(tword)"too many char classes",
#undef _2
#define _2         (tword)&start[1725]
	1 + (tword)&_tx,
	_3,
#undef _1
#define _1         (tword)&start[1727]
	1 + (tword)&trans,
	1 + _2,
// __cherr:
	1 + (tword)&diag,
	_1,
#undef _1
#define _1         (tword)&start[1731]
	0,
// __zeron:
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[1738]
	0200,
// __testn:
	(tword)&_l,
	__n,
	(tword)&_ib,
	(tword)&_l,
	_1,
	(tword)&_lt,
	1 + (tword)&_t,
#undef _1
#define _1         (tword)&start[1746]
	0,
#undef _4
#define _4         (tword)&start[1747]
	(tword)".globl classtab",
#undef _5
#define _5         (tword)&start[1748]
	(tword)"classtab:",
#undef _3
#define _3         (tword)&start[1749]
	_tn,
	(tword)&_tx,
	_4,
	_tn,
	(tword)&_tx,
	_5,
	1 + _tn,
#undef _2
#define _2         (tword)&start[1756]
	1 + (tword)&trans,
	1 + _3,
#undef _7
#define _7         (tword)&start[1758]
	(tword)&_tp,
	1,
	1 + _tn,
#undef _6
#define _6         (tword)&start[1761]
	(tword)&octal,
#define __w        (tword)&labels[248]
	__w,
	1 + (tword)&trans,
	1 + _7,
// __putcharcl:
	__zeron,
	(tword)&_l,
	__classes,
	(tword)&_l,
	_1,
	(tword)&_st,
	(tword)&_p,
	(tword)&parse,
	_2,
#define __ptc1     (tword)&start[1774]
	(tword)&_l,
	__w,
	(tword)&_l,
	__wordsz,
	(tword)&_l,
	__n,
	(tword)&_m,
	(tword)&_l,
	__classes,
	(tword)&_lv,
	(tword)&_a,
	(tword)&_rv,
	(tword)&_st,
	(tword)&_p,
	(tword)&parse,
	_6,
	(tword)&bundle,
	__testn,
	1 + (tword)&salt,
	__ptc1,
// __classmask:
	0,
// __nclass:
	0,
// __classes:
#define __cl1      (tword)&start[1796]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define __cl2      (tword)&start[1812]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define __cl3      (tword)&start[1828]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define __cl4      (tword)&start[1844]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define __cl5      (tword)&start[1860]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define __cl6      (tword)&start[1876]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define __cl7      (tword)&start[1892]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define __cl8      (tword)&start[1908]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
// __done:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[1925]
	(tword)&_txs,
	(tword)'.',
	1 + (tword)&_tp,
	1,
#define __create   (tword)&start[1929]
	(tword)&_l,
	__csym,
	(tword)&_ia,
	(tword)&_p,
#define __getcsym  (tword)&start[1933]
	(tword)&octal,
	__csym,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[1937]
	(tword)"..",
#undef _1
#define _1         (tword)&start[1938]
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
// __fref:
	(tword)&_l,
#define __fsym     (tword)&labels[249]
	__fsym,
	(tword)&_ia,
	(tword)&_p,
// __getfref:
	(tword)&octal,
	__fsym,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[1950]
	1,
// __not:
	(tword)&params,
	_1,
	(tword)((tuword)-1<<1),
	(tword)&alt,
	__done,
	1 + (tword)&fail,
#undef _1
#define _1         (tword)&start[1957]
	1,
#undef _2
#define _2         (tword)&start[1958]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __list:
	(tword)&params,
	_1,
	(tword)((tuword)-1<<1),
#define __list1    (tword)&start[1966]
	(tword)&bundle,
	(tword)&_pxs,
	(tword)',',
	(tword)&alt,
	__done,
	(tword)((tuword)-1<<1),
	(tword)&trans,
	1 + _2,
	1 + (tword)&salt,
	__list1,
#undef _1
#define _1         (tword)&start[1976]
	1,
// __remote:
	(tword)&params,
	_1,
	__create,
	1 + (tword)&parse,
#define __rem1     (tword)&labels[250]
	__rem1,
	(tword)((tuword)-1<<1),
#undef _1
#define _1         (tword)&start[1983]
	1,
#undef _3
#define _3         (tword)&start[1984]
	(tword)"=.",
#undef _2
#define _2         (tword)&start[1985]
	(tword)&_tp,
	2,
	(tword)&_tx,
	_3,
	_tn,
	(tword)&_tp,
	1,
	1 + _tn,
// __rem1:
	(tword)&params,
	_1,
	__getcsym,
	(tword)((tuword)-1<<1),
	1 + (tword)&trans,
	1 + _2,
// __number:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&any,
#define __digit    (tword)&labels[251]
	__digit,
	(tword)&string,
	__digit,
	1 + (tword)&scopy,
// __name:
	__ident,
	1 + (tword)&scopy,
// __ident:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&any,
	__letter,
	1 + (tword)&string,
#define __alpha    (tword)&labels[252]
	__alpha,
#undef _1
#define _1         (tword)&start[2016]
	1,
#undef _3
#define _3         (tword)&start[2017]
	0,
// __oldtab:
	(tword)&params,
	_1,
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_t,
	(tword)&alt,
	__done,
	(tword)&discard,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	_3,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[2033]
	2,
#undef _3
#define _3         (tword)&start[2034]
	0,
// __newtab:
	(tword)&params,
	_1,
	(tword)&_l,
	(tword)((tuword)-2<<1),
	(tword)&_t,
	(tword)&salt,
#define __220      (tword)&labels[253]
	__220,
	(tword)&table,
	(tword)((tuword)-2<<1),
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	_3,
	(tword)&_st,
	(tword)&_p,
// __220:
	(tword)&enter,
	(tword)((tuword)-2<<1),
	__i,
	(tword)&_l,
	(tword)((tuword)-2<<1),
	(tword)&_l,
	__i,
	(tword)&_f,
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_ia,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[2063]
	2,
// __tabval:
	(tword)&params,
	_1,
	(tword)&_l,
	(tword)((tuword)-2<<1),
	(tword)&_t,
	(tword)&find,
	(tword)((tuword)-2<<1),
	__i,
	(tword)&_l,
	__i,
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	(tword)((tuword)-2<<1),
	(tword)&_l,
	__i,
	(tword)&_f,
	(tword)&_s,
	(tword)&_st,
	(tword)&_p,
	1 + (tword)&octal,
	__i,
// __null:
	1 + (tword)&trans,
	1 + __nil,
#undef _1
#define _1         (tword)&start[2088]
	(tword)"1 ",
// __xbit:
	1 + (tword)&_tx,
	_1,
// __q1:
	1 + (tword)&_tq,
	1,
// __q2:
	1 + (tword)&_tq,
	2,
// __nil:
	1 + (tword)&generate,
// __blanks:
	010,
// __digit:
	020,
// __letter:
	040,
// __alpha:
	0100,
// __litch:
	0200,
// __none:
	0400,
// __csym:
	0,
// __fsym:
	0,
// __easy:
	0,
// __w:
	0,
// __n:
	0,
// __dtt:
	0,
// __ndt:
	0,
// __sndt:
	0,
// __pat:
	0,
// __npa:
	0,
// __ptt:
	0,
// __npt:
	0,
// __i:
	0,
// __wordsz:
	0,
#define __classtab (tword)&start[2116]
	0,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0217,
	0217,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0217,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0207,
	0203,
	0207,
	0207,
	0207,
	0207,
	0207,
	0327,
	0327,
	0327,
	0327,
	0327,
	0327,
	0327,
	0327,
	0327,
	0327,
	0207,
	0205,
	0207,
	0207,
	7,
	0207,
	0207,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0207,
	7,
	0207,
	0207,
	0207,
	0207,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0347,
	0207,
	0207,
	0207,
	0207,
	0207,
#define _pn        (tword)&start[2244]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[2096],    // __blanks
	(tword)&start[2115],    // __wordsz
	(tword)&start[1796],    // __classes
	(tword)&start[1795],    // __nclass
	(tword)&start[160],     // __comment
	(tword)&start[52],      // __first
	(tword)&start[23],      // __pr2
	(tword)&start[71],      // __error
	(tword)&start[96],      // __line
	(tword)&start[1765],    // __putcharcl
	(tword)&start[156],     // __last
	(tword)&start[2246],    // _tn
	(tword)&start[1942],    // __fref
	(tword)&start[1946],    // __getfref
	(tword)&start[2101],    // __none
	(tword)&start[87],      // __3
	(tword)&start[88],      // __2
	(tword)&start[2086],    // __null
	(tword)&start[133],     // __labels
	(tword)&start[1602],    // __charcl
	(tword)&start[104],     // __7
	(tword)&start[113],     // __4
	(tword)&start[201],     // __statement
	(tword)&start[113],     // __5
	(tword)&start[120],     // __numbers
	(tword)&start[113],     // __6
	(tword)&start[839],     // __trule
	(tword)&start[1999],    // __number
	(tword)&start[1924],    // __done
	(tword)&start[143],     // __label
	(tword)&start[2007],    // __name
	(tword)&start[2095],    // __nil
	(tword)&start[2091],    // __q1
	(tword)&start[2089],    // __xbit
	(tword)&start[2102],    // __csym
	(tword)&start[2018],    // __oldtab
	(tword)&start[2107],    // __dtt
	(tword)&start[2110],    // __pat
	(tword)&start[248],     // __proc
	(tword)&start[222],     // __11
	(tword)&start[261],     // __plst
	(tword)&start[290],     // __tlst
	(tword)&start[225],     // __10
	(tword)&start[700],     // __noelem
	(tword)&start[316],     // __frag
	(tword)&start[235],     // __15
	(tword)&start[246],     // __12
	(tword)&start[707],     // __ifelem
	(tword)&start[244],     // __14
	(tword)&start[246],     // __13
	(tword)&start[2111],    // __npa
	(tword)&start[1963],    // __list
	(tword)&start[269],     // __pident
	(tword)&start[1977],    // __remote
	(tword)&start[2009],    // __ident
	(tword)&start[2035],    // __newtab
	(tword)&start[2114],    // __i
	(tword)&start[382],     // __prule
	(tword)&start[323],     // __17
	(tword)&start[327],     // __16
	(tword)&start[2093],    // __q2
	(tword)&start[2109],    // __sndt
	(tword)&start[2108],    // __ndt
	(tword)&start[427],     // __disj
	(tword)&start[415],     // __23
	(tword)&start[714],     // __ifeasy
	(tword)&start[408],     // __21
	(tword)&start[412],     // __20
	(tword)&start[415],     // __22
	(tword)&start[452],     // __pelem
	(tword)&start[565],     // __pdot
	(tword)&start[440],     // __25
	(tword)&start[693],     // __ishard
	(tword)&start[440],     // __24
	(tword)&start[512],     // __pprim
	(tword)&start[460],     // __31
	(tword)&start[686],     // __iseasy
	(tword)&start[477],     // __26
	(tword)&start[472],     // __30
	(tword)&start[477],     // __27
	(tword)&start[760],     // __special
	(tword)&start[544],     // __32
	(tword)&start[816],     // __rname
	(tword)&start[523],     // __37
	(tword)&start[544],     // __33
	(tword)&start[593],     // __spdot
	(tword)&start[526],     // __34
	(tword)&start[542],     // __36
	(tword)&start[602],     // __parg
	(tword)&start[544],     // __35
	(tword)&start[552],     // __41
	(tword)&start[558],     // __40
	(tword)&start[563],     // __43
	(tword)&start[563],     // __42
	(tword)&start[599],     // __alias
	(tword)&start[587],     // __44
	(tword)&start[2098],    // __letter
	(tword)&start[1951],    // __not
	(tword)&start[607],     // __45
	(tword)&start[628],     // __specparg
	(tword)&start[684],     // __46
	(tword)&start[684],     // __47
	(tword)&start[641],     // __57
	(tword)&start[1064],    // __longlit
	(tword)&start[684],     // __50
	(tword)&start[649],     // __56
	(tword)&start[684],     // __51
	(tword)&start[659],     // __55
	(tword)&start[684],     // __52
	(tword)&start[682],     // __54
	(tword)&start[684],     // __53
	(tword)&start[2104],    // __easy
	(tword)&start[773],     // __70
	(tword)&start[769],     // __60
	(tword)&start[807],     // __61
	(tword)&start[782],     // __67
	(tword)&start[1020],    // __literal
	(tword)&start[807],     // __62
	(tword)&start[790],     // __66
	(tword)&start[807],     // __63
	(tword)&start[1099],    // __expr
	(tword)&start[801],     // __65
	(tword)&start[803],     // __64
	(tword)&start[826],     // __72
	(tword)&start[2064],    // __tabval
	(tword)&start[829],     // __71
	(tword)&start[2112],    // __ptt
	(tword)&start[867],     // __tbody
	(tword)&start[855],     // __73
	(tword)&start[850],     // __74
	(tword)&start[856],     // __tra
	(tword)&start[860],     // __tident
	(tword)&start[2113],    // __npt
	(tword)&start[877],     // __76
	(tword)&start[878],     // __75
	(tword)&start[887],     // __trb
	(tword)&start[913],     // __telem
	(tword)&start[896],     // __100
	(tword)&start[899],     // __77
	(tword)&start[922],     // __110
	(tword)&start[954],     // __101
	(tword)&start[930],     // __107
	(tword)&start[954],     // __102
	(tword)&start[939],     // __106
	(tword)&start[954],     // __103
	(tword)&start[947],     // __105
	(tword)&start[979],     // __tdot
	(tword)&start[1008],    // __tpt
	(tword)&start[954],     // __104
	(tword)&start[955],     // __te1
	(tword)&start[966],     // __te2
	(tword)&start[986],     // __112
	(tword)&start[988],     // __111
	(tword)&start[998],     // __114
	(tword)&start[1001],    // __targ
	(tword)&start[999],     // __113
	(tword)&start[1006],    // __115
	(tword)&start[1034],    // __shortlit
	(tword)&start[1027],    // __116
	(tword)&start[2100],    // __litch
	(tword)&start[1074],    // __120
	(tword)&start[1075],    // __117
	(tword)&start[1088],    // __litb
	(tword)&start[1112],    // __assignment
	(tword)&start[1103],    // __121
	(tword)&start[1130],    // __rv
	(tword)&start[1266],    // __lv
	(tword)&start[1308],    // __assign
	(tword)&start[1206],    // __prime
	(tword)&start[1383],    // __infix
	(tword)&start[1142],    // __125
	(tword)&start[1149],    // __122
	(tword)&start[1176],    // __rva
	(tword)&start[1149],    // __124
	(tword)&start[1149],    // __123
	(tword)&start[1216],    // __135
	(tword)&start[1556],    // __suffix
	(tword)&start[1245],    // __126
	(tword)&start[1524],    // __prefix
	(tword)&start[1224],    // __134
	(tword)&start[1245],    // __127
	(tword)&start[1233],    // __133
	(tword)&start[1245],    // __130
	(tword)&start[1581],    // __unary
	(tword)&start[1241],    // __132
	(tword)&start[1245],    // __131
	(tword)&start[1273],    // __141
	(tword)&start[1287],    // __136
	(tword)&start[1282],    // __140
	(tword)&start[1287],    // __137
	(tword)&start[1319],    // __143
	(tword)&start[1321],    // __142
	(tword)&start[1396],    // __201
	(tword)&start[1512],    // __144
	(tword)&start[1404],    // __200
	(tword)&start[1512],    // __145
	(tword)&start[1412],    // __177
	(tword)&start[1512],    // __146
	(tword)&start[1420],    // __176
	(tword)&start[1512],    // __147
	(tword)&start[1428],    // __175
	(tword)&start[1512],    // __150
	(tword)&start[1436],    // __174
	(tword)&start[1512],    // __151
	(tword)&start[1444],    // __173
	(tword)&start[1512],    // __152
	(tword)&start[1452],    // __172
	(tword)&start[1512],    // __153
	(tword)&start[1460],    // __171
	(tword)&start[1512],    // __154
	(tword)&start[1468],    // __170
	(tword)&start[1512],    // __155
	(tword)&start[1476],    // __167
	(tword)&start[1512],    // __156
	(tword)&start[1484],    // __166
	(tword)&start[1512],    // __157
	(tword)&start[1492],    // __165
	(tword)&start[1512],    // __160
	(tword)&start[1500],    // __164
	(tword)&start[1512],    // __161
	(tword)&start[1510],    // __163
	(tword)&start[1512],    // __162
	(tword)&start[1535],    // __205
	(tword)&start[1547],    // __202
	(tword)&start[1543],    // __204
	(tword)&start[1547],    // __203
	(tword)&start[1567],    // __207
	(tword)&start[1571],    // __206
	(tword)&start[1589],    // __213
	(tword)&start[1601],    // __210
	(tword)&start[1597],    // __212
	(tword)&start[1601],    // __211
	(tword)&start[1610],    // __215
	(tword)&start[1616],    // __ccla
	(tword)&start[1681],    // __cclb
	(tword)&start[1611],    // __214
	(tword)&start[1794],    // __classmask
	(tword)&start[1729],    // __cherr
	(tword)&start[1639],    // __cclc
	(tword)&start[1652],    // __ccl4
	(tword)&start[1664],    // __ccle
	(tword)&start[1658],    // __216
	(tword)&start[1700],    // __cclx
	(tword)&start[1663],    // __217
	(tword)&start[2106],    // __n
	(tword)&start[1732],    // __zeron
	(tword)&start[1739],    // __testn
	(tword)&start[2105],    // __w
	(tword)&start[2103],    // __fsym
	(tword)&start[1993],    // __rem1
	(tword)&start[2097],    // __digit
	(tword)&start[2099],    // __alpha
	(tword)&start[2050],    // __220
};

// Used builtins:
//   _a
//   _cm
//   _da
//   _eq
//   _f
//   _ia
//   _ib
//   _l
//   _lt
//   _lv
//   _m
//   _n
//   _ne
//   _o
//   _p
//   _px
//   _pxs
//   _rv
//   _s
//   _sl
//   _st
//   _t
//   _tp
//   _tq
//   _tx
//   _txs
//   _u
//   _x
//   alt
//   any
//   bundle
//   diag
//   discard
//   enter
//   fail
//   find
//   generate
//   gpar
//   ignore
//   octal
//   params
//   parse
//   push
//   salt
//   scopy
//   smark
//   string
//   succ
//   table
//   tchar
//   tgoto
//   trans
