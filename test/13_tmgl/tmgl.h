#define SRC_LANGUAGE "TMGL"
#define DST_LANGUAGE "TMG driving table for PDP-11"

const tword labels[];

// Driving table for the program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __begin    (tword)&start[1]
	(tword)&ignore,
#define __blanks   (tword)&labels[1]
	__blanks,
#define __pr1      (tword)&start[3]
#define __comment  (tword)&labels[2]
	__comment,
	(tword)&salt,
	__pr1,
	(tword)&parse,
#define __first    (tword)&labels[3]
	__first,
	(tword)&salt,
#define __pr2      (tword)&labels[4]
	__pr2,
	(tword)&diag,
#define __error    (tword)&labels[5]
	__error,
// __pr2:
	__comment,
	(tword)&salt,
	__pr2,
	(tword)&parse,
#define __line     (tword)&labels[6]
	__line,
	(tword)&salt,
	__pr2,
	(tword)&diag,
	__error,
	(tword)&salt,
	__pr2,
#define __putcharcl (tword)&labels[7]
	__putcharcl,
	1 + (tword)&parse,
#define __last     (tword)&labels[8]
	__last,
#undef _3
#define _3         (tword)&start[26]
	(tword)"1 ",
#undef _2
#define _2         (tword)&start[27]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
#define _tn        (tword)&labels[9]
	1 + _tn,
#undef _1
#define _1         (tword)&start[32]
#define __fref     (tword)&labels[10]
	__fref,
	1 + (tword)&trans,
	1 + _2,
#undef _4
#define _4         (tword)&start[35]
	(tword)&_tp,
	2,
	(tword)&_txs,
	(tword)':',
	1 + (tword)&_tp,
	1,
// __first:
	(tword)&parse,
	_1,
#define __getfref  (tword)&labels[11]
	__getfref,
	__line,
	1 + (tword)&trans,
	1 + _4,
#undef _1
#define _1         (tword)&start[47]
	1,
#undef _2
#define _2         (tword)&start[48]
	2,
#undef _3
#define _3         (tword)&start[49]
	1 + (tword)&_txs,
	(tword)';',
#undef _5
#define _5         (tword)&start[51]
	(tword)"??? ",
#undef _4
#define _4         (tword)&start[52]
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
#define __none     (tword)&labels[12]
	__none,
	(tword)&any,
	_1,
	(tword)&string,
	_2,
	(tword)&scopy,
	(tword)&_pxs,
	(tword)';',
	(tword)&alt,
#define __3        (tword)&labels[13]
	__3,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __2        (tword)&labels[14]
	__2,
// __3:
#define __null     (tword)&labels[15]
	__null,
// __2:
	1 + (tword)&trans,
	1 + _4,
#undef _1
#define _1         (tword)&start[79]
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tp,
	1,
	1 + _tn,
// __line:
#define __labels   (tword)&labels[16]
	__labels,
#define __charcl   (tword)&labels[17]
	__charcl,
	(tword)&alt,
#define __7        (tword)&labels[18]
	__7,
	(tword)&_pxs,
	(tword)';',
	(tword)&tgoto,
#define __4        (tword)&labels[19]
	__4,
// __7:
#define __statement (tword)&labels[20]
	__statement,
	(tword)&salt,
#define __5        (tword)&labels[21]
	__5,
#define __numbers  (tword)&labels[22]
	__numbers,
	(tword)&salt,
#define __6        (tword)&labels[23]
	__6,
#define __trule    (tword)&labels[24]
	__trule,
	(tword)&_pxs,
	(tword)';',
// __6:
// __5:
// __4:
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[104]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __numbers:
#define __number   (tword)&labels[25]
	__number,
	(tword)&_pxs,
	(tword)';',
	__numbers,
	(tword)&alt,
#define __done     (tword)&labels[26]
	__done,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[117]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __labels:
#define __label    (tword)&labels[27]
	__label,
	__labels,
	(tword)&alt,
	__done,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[128]
	(tword)&_tp,
	1,
	1 + (tword)&_txs,
	(tword)':',
// __label:
#define __name     (tword)&labels[28]
	__name,
	(tword)&_pxs,
	(tword)':',
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[137]
	(tword)".pn:1 .pxs;12",
#undef _3
#define _3         (tword)&start[138]
	(tword)".tn:1 .txs;12",
#undef _1
#define _1         (tword)&start[139]
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
#define _1         (tword)&start[147]
	(tword)"/*",
#undef _2
#define _2         (tword)&start[148]
	4,
// __comment:
	(tword)&_px,
	_1,
#define __co1      (tword)&start[151]
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
#define _1         (tword)&start[161]
	0,
#undef _2
#define _2         (tword)&start[162]
	(tword)&gpar,
	1,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
#undef _3
#define _3         (tword)&start[168]
	(tword)&gpar,
	1,
	1 + (tword)&generate,
#undef _4
#define _4         (tword)&start[171]
	(tword)&gpar,
	1,
	(tword)&_tp,
	2,
#define __nil      (tword)&labels[29]
	__nil,
	_tn,
	1 + (tword)&_tp,
	1,
#define __q1       (tword)&labels[30]
	__q1,
#undef _5
#define _5         (tword)&start[180]
	1 + (tword)&_tp,
	1,
#define __xbit     (tword)&labels[31]
	__xbit,
#undef _7
#define _7         (tword)&start[183]
	(tword)"1 succ",
#undef _6
#define _6         (tword)&start[184]
	(tword)&_tp,
	1,
	__nil,
	_tn,
	1 + (tword)&_tx,
	_7,
// __statement:
	(tword)&_l,
#define __csym     (tword)&labels[32]
	__csym,
	(tword)&_l,
	_1,
	(tword)&_st,
	(tword)&_p,
#define __oldtab   (tword)&labels[33]
	__oldtab,
#define __dtt      (tword)&labels[34]
	__dtt,
	__oldtab,
#define __pat      (tword)&labels[35]
	__pat,
#define __proc     (tword)&labels[36]
	__proc,
	(tword)&alt,
#define __11       (tword)&labels[37]
	__11,
#define __plst     (tword)&labels[38]
	__plst,
#define __tlst     (tword)&labels[39]
	__tlst,
	(tword)&_pxs,
	(tword)')',
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __10       (tword)&labels[40]
	__10,
// __11:
	(tword)&trans,
	1 + _3,
#define __noelem   (tword)&labels[41]
	__noelem,
// __10:
#define __stt1     (tword)&start[214]
	(tword)&bundle,
#define __frag     (tword)&labels[42]
	__frag,
	(tword)&alt,
#define __15       (tword)&labels[43]
	__15,
	(tword)&trans,
	1 + _4,
	(tword)&salt,
	__stt1,
	(tword)&tgoto,
#define __12       (tword)&labels[44]
	__12,
// __15:
	(tword)&_pxs,
	(tword)';',
#define __ifelem   (tword)&labels[45]
	__ifelem,
	(tword)&alt,
#define __14       (tword)&labels[46]
	__14,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __13       (tword)&labels[47]
	__13,
// __14:
	(tword)&trans,
	1 + _6,
// __13:
// __12:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[236]
	(tword)"proc(",
// __proc:
	(tword)&smark,
	(tword)&ignore,
	__none,
	1 + (tword)&_px,
	_1,
#undef _1
#define _1         (tword)&start[242]
	1 + (tword)&octal,
#define __npa      (tword)&labels[48]
	__npa,
#undef _3
#define _3         (tword)&start[244]
	(tword)"params;",
#undef _2
#define _2         (tword)&start[245]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __plst:
#define __list     (tword)&labels[49]
	__list,
#define __pident   (tword)&labels[50]
	__pident,
	(tword)&alt,
	__null,
#define __remote   (tword)&labels[51]
	__remote,
	_1,
	1 + (tword)&trans,
	1 + _2,
// __pident:
#define __ident    (tword)&labels[52]
	__ident,
#define __newtab   (tword)&labels[53]
	1 + __newtab,
	__pat,
	__npa,
#undef _1
#define _1         (tword)&start[262]
	0,
#undef _2
#define _2         (tword)&start[263]
	__name,
	(tword)&_l,
#define __i        (tword)&labels[54]
	__i,
	(tword)&_ia,
	1 + (tword)&_p,
#undef _3
#define _3         (tword)&start[268]
	1 + (tword)&octal,
	__i,
#undef _5
#define _5         (tword)&start[270]
	(tword)"push;",
#undef _4
#define _4         (tword)&start[271]
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
#define _1         (tword)&start[295]
	(tword)&gpar,
	1,
	1 + (tword)&_tp,
	1,
	__nil,
	__q1,
#undef _2
#define _2         (tword)&start[301]
	(tword)&gpar,
	1,
	1 + (tword)&_tp,
	1,
// __frag:
#define __prule    (tword)&labels[55]
	__prule,
	(tword)&alt,
#define __17       (tword)&labels[56]
	__17,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __16       (tword)&labels[57]
	__16,
// __17:
	__labels,
	__noelem,
	(tword)&trans,
	1 + _2,
// __16:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[317]
	(tword)"salt;",
#undef _1
#define _1         (tword)&start[318]
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
#define __q2       (tword)&labels[58]
	__q2,
	__q1,
	_tn,
	(tword)&_tp,
	2,
	1 + (tword)&_txs,
	(tword)':',
#undef _5
#define _5         (tword)&start[339]
	(tword)"alt;",
#undef _4
#define _4         (tword)&start[340]
	_tn,
	(tword)&_tx,
	_5,
	1 + (tword)&_tp,
	1,
#undef _6
#define _6         (tword)&start[345]
	(tword)"goto;",
#undef _3
#define _3         (tword)&start[346]
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
#define __sndt     (tword)&labels[59]
	__sndt,
	(tword)&_l,
#define __ndt      (tword)&labels[60]
	__ndt,
	(tword)&_st,
	(tword)&_p,
#define __disj     (tword)&labels[61]
	__disj,
	(tword)&_pxs,
	(tword)'|',
	(tword)&alt,
#define __23       (tword)&labels[62]
	__23,
	(tword)&_l,
	__ndt,
	(tword)&_l,
	__sndt,
	(tword)&_st,
	(tword)&_p,
	__fref,
#define __ifeasy   (tword)&labels[63]
	__ifeasy,
	(tword)&alt,
#define __21       (tword)&labels[64]
	__21,
	__prule,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __20       (tword)&labels[65]
	__20,
// __21:
	__prule,
	__fref,
	(tword)&trans,
	1 + _3,
// __20:
	__noelem,
	(tword)&tgoto,
#define __22       (tword)&labels[66]
	__22,
// __23:
// __22:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[405]
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
#define __pelem    (tword)&labels[67]
	__pelem,
#define __pdot     (tword)&labels[68]
	__pdot,
	__disj,
	(tword)&alt,
#define __25       (tword)&labels[69]
	__25,
	(tword)&trans,
	1 + _1,
	__ifelem,
	(tword)&alt,
	__done,
#define __ishard   (tword)&labels[70]
	__ishard,
	(tword)&tgoto,
#define __24       (tword)&labels[71]
	__24,
// __25:
// __24:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[430]
	(tword)&gpar,
	2,
	(tword)&_tp,
	1,
	__q1,
	1 + (tword)&_tq,
	2,
#undef _2
#define _2         (tword)&start[437]
	1,
#undef _3
#define _3         (tword)&start[438]
	(tword)&gpar,
	2,
	1 + (tword)&generate,
// __pelem:
#define __pprim    (tword)&labels[72]
	__pprim,
	(tword)&alt,
#define __31       (tword)&labels[73]
	__31,
	(tword)&trans,
	1 + _1,
#define __iseasy   (tword)&labels[74]
	__iseasy,
	(tword)&tgoto,
#define __26       (tword)&labels[75]
	__26,
// __31:
	(tword)&_pxs,
	(tword)'(',
	(tword)&push,
	_2,
	__sndt,
	__prule,
	(tword)&alt,
#define __30       (tword)&labels[76]
	__30,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __27       (tword)&labels[77]
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
#define _1         (tword)&start[467]
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
#define _2         (tword)&start[476]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	1 + (tword)&_tp,
	1,
#undef _4
#define _4         (tword)&start[482]
	(tword)"alt;",
#undef _3
#define _3         (tword)&start[483]
	1 + (tword)&_tx,
	_4,
#undef _5
#define _5         (tword)&start[485]
	(tword)"\\",
#undef _7
#define _7         (tword)&start[486]
	(tword)"salt;",
#undef _6
#define _6         (tword)&start[487]
	1 + (tword)&_tx,
	_7,
#undef _10
#define _10        (tword)&start[489]
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
#define __special  (tword)&labels[78]
	__special,
	(tword)&salt,
#define __32       (tword)&labels[79]
	__32,
#define __rname    (tword)&labels[80]
	__rname,
	(tword)&_pxs,
	(tword)':',
	(tword)&alt,
#define __37       (tword)&labels[81]
	__37,
	(tword)&fail,
	(tword)&tgoto,
#define __33       (tword)&labels[82]
	__33,
// __37:
#define __spdot    (tword)&labels[83]
	__spdot,
	(tword)&salt,
#define __34       (tword)&labels[84]
	__34,
// __34:
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __36       (tword)&labels[85]
	__36,
	(tword)&ignore,
	__blanks,
	__list,
#define __parg     (tword)&labels[86]
	__parg,
	(tword)&_pxs,
	(tword)')',
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __35       (tword)&labels[87]
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
#define __41       (tword)&labels[88]
	__41,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __40       (tword)&labels[89]
	__40,
// __41:
	(tword)&_px,
	_5,
	(tword)&alt,
#define __43       (tword)&labels[90]
	__43,
	(tword)&trans,
	1 + _6,
// __40:
	__rname,
	(tword)&trans,
	1 + _10,
	(tword)&tgoto,
#define __42       (tword)&labels[91]
	__42,
// __43:
// __42:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[553]
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
#define __alias    (tword)&labels[92]
	__alias,
	(tword)&_l,
	__dtt,
	(tword)&_t,
	(tword)&salt,
#define __44       (tword)&labels[93]
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
#define _1         (tword)&start[580]
	1 + (tword)&any,
#define __letter   (tword)&labels[94]
	__letter,
// __spdot:
	(tword)&_pxs,
	(tword)'.',
	(tword)&ignore,
	__none,
#define __not      (tword)&labels[95]
	__not,
	_1,
// __alias:
	1 + __newtab,
	__dtt,
	__ndt,
// __parg:
	__rname,
	(tword)&salt,
#define __45       (tword)&labels[96]
	__45,
	__remote,
#define __specparg (tword)&labels[97]
	__specparg,
// __45:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[597]
	(tword)"\\n\\0",
#undef _1
#define _1         (tword)&start[598]
	1 + (tword)&_tx,
	_2,
#undef _4
#define _4         (tword)&start[600]
	(tword)"1 succ",
#undef _3
#define _3         (tword)&start[601]
	1 + (tword)&_tx,
	_4,
#undef _5
#define _5         (tword)&start[603]
	3,
#undef _6
#define _6         (tword)&start[604]
	0,
#undef _7
#define _7         (tword)&start[605]
	1 + (tword)&_tp,
	1,
	__nil,
	__xbit,
#undef _11
#define _11        (tword)&start[609]
	(tword)"1 succ",
#undef _10
#define _10        (tword)&start[610]
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
#define __46       (tword)&labels[98]
	__46,
	__charcl,
	(tword)&salt,
#define __47       (tword)&labels[99]
	__47,
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __57       (tword)&labels[100]
	__57,
#define __longlit  (tword)&labels[101]
	__longlit,
	(tword)&tgoto,
#define __50       (tword)&labels[102]
	__50,
// __57:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __56       (tword)&labels[103]
	__56,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __51       (tword)&labels[104]
	__51,
// __56:
	(tword)&_pxs,
	(tword)'(',
	(tword)&_pxs,
	(tword)')',
	(tword)&alt,
#define __55       (tword)&labels[105]
	__55,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __52       (tword)&labels[106]
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
#define __54       (tword)&labels[107]
	__54,
	(tword)&trans,
	1 + _7,
	(tword)&tgoto,
#define __53       (tword)&labels[108]
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
#define _1         (tword)&start[674]
	1,
// __iseasy:
	(tword)&_l,
#define __easy     (tword)&labels[109]
	__easy,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[681]
	0,
// __ishard:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[688]
	2,
// __noelem:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[695]
	2,
// __ifelem:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_1,
	(tword)&_ne,
	1 + (tword)&_t,
#undef _2
#define _2         (tword)&start[702]
	1,
// __ifeasy:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_2,
	(tword)&_eq,
	1 + (tword)&_t,
#undef _2
#define _2         (tword)&start[709]
	(tword)"trans;1 ",
#undef _1
#define _1         (tword)&start[710]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
#undef _4
#define _4         (tword)&start[718]
	(tword)".px",
#undef _3
#define _3         (tword)&start[719]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	(tword)&_tx,
	_4,
	1 + (tword)&_tp,
	1,
#undef _6
#define _6         (tword)&start[727]
	(tword)".pn",
#undef _5
#define _5         (tword)&start[728]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	1 + (tword)&_tx,
	_6,
#undef _10
#define _10        (tword)&start[734]
	(tword)".t",
#undef _7
#define _7         (tword)&start[735]
	1 + (tword)&_tx,
	_10,
#undef _12
#define _12        (tword)&start[737]
	(tword)".p",
#undef _11
#define _11        (tword)&start[738]
	1 + (tword)&_tx,
	_12,
#undef _13
#define _13        (tword)&start[740]
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
#define __70       (tword)&labels[110]
	__70,
	__rname,
	(tword)&salt,
#define __60       (tword)&labels[111]
	__60,
	__remote,
	__trule,
// __60:
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __61       (tword)&labels[112]
	__61,
// __70:
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __67       (tword)&labels[113]
	__67,
#define __literal  (tword)&labels[114]
	__literal,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __62       (tword)&labels[115]
	__62,
// __67:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __66       (tword)&labels[116]
	__66,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __63       (tword)&labels[117]
	__63,
// __66:
	(tword)&_pxs,
	(tword)'[',
#define __expr     (tword)&labels[118]
	__expr,
	(tword)&_pxs,
	(tword)'?',
	(tword)&alt,
#define __65       (tword)&labels[119]
	__65,
	(tword)&trans,
	1 + _7,
	(tword)&tgoto,
#define __64       (tword)&labels[120]
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
#define _2         (tword)&start[797]
	(tword)"[-",
#undef _3
#define _3         (tword)&start[798]
	(tword)"\\<1]",
#undef _1
#define _1         (tword)&start[799]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	1 + (tword)&_tx,
	_3,
// __rname:
	__name,
	(tword)&alt,
#define __72       (tword)&labels[121]
	__72,
#define __tabval   (tword)&labels[122]
	__tabval,
	__pat,
	__npa,
	(tword)&alt,
	__done,
	(tword)&tgoto,
#define __71       (tword)&labels[123]
	__71,
// __72:
	(tword)&_pxs,
	(tword)'$',
	__number,
// __71:
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[820]
	(tword)"gpar;",
#undef _1
#define _1         (tword)&start[821]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __trule:
	__oldtab,
#define __ptt      (tword)&labels[124]
	__ptt,
#define __tbody    (tword)&labels[125]
	__tbody,
	(tword)&salt,
#define __73       (tword)&labels[126]
	__73,
	(tword)&_pxs,
	(tword)'(',
	__number,
	(tword)&salt,
#define __74       (tword)&labels[127]
	__74,
#define __tra      (tword)&labels[128]
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
#define __tident   (tword)&labels[129]
	__tident,
	1 + (tword)&octal,
#define __npt      (tword)&labels[130]
	__npt,
// __tident:
	__ident,
	1 + __newtab,
	__ptt,
	__npt,
#undef _2
#define _2         (tword)&start[853]
	(tword)"1 generate",
#undef _1
#define _1         (tword)&start[854]
	1 + (tword)&_tx,
	_2,
// __tbody:
	(tword)&_pxs,
	(tword)'{',
	(tword)&_pxs,
	(tword)'}',
	(tword)&alt,
#define __76       (tword)&labels[131]
	__76,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __75       (tword)&labels[132]
	__75,
// __76:
#define __trb      (tword)&labels[133]
	__trb,
// __75:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[868]
	__xbit,
	1 + (tword)&_tp,
	1,
#undef _2
#define _2         (tword)&start[871]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __trb:
#define __telem    (tword)&labels[134]
	__telem,
	(tword)&_pxs,
	(tword)'}',
	(tword)&alt,
#define __100      (tword)&labels[135]
	__100,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __77       (tword)&labels[136]
	__77,
// __100:
	__trb,
	(tword)&trans,
	1 + _2,
// __77:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[889]
	(tword)".tx",
#undef _1
#define _1         (tword)&start[890]
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
#undef _4
#define _4         (tword)&start[894]
	(tword)".tn",
#undef _3
#define _3         (tword)&start[895]
	1 + (tword)&_tx,
	_4,
#undef _6
#define _6         (tword)&start[897]
	(tword)".tq;",
#undef _5
#define _5         (tword)&start[898]
	(tword)&_tx,
	_6,
	1 + (tword)&_tp,
	1,
// __telem:
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __110      (tword)&labels[137]
	__110,
	__literal,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __101      (tword)&labels[138]
	__101,
// __110:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __107      (tword)&labels[139]
	__107,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __102      (tword)&labels[140]
	__102,
// __107:
	(tword)&_pxs,
	(tword)'$',
	(tword)&alt,
#define __106      (tword)&labels[141]
	__106,
	__number,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __103      (tword)&labels[142]
	__103,
// __106:
	__number,
	(tword)&alt,
#define __105      (tword)&labels[143]
	__105,
#define __tdot     (tword)&labels[144]
	__tdot,
	(tword)&trans,
#define __tpt      (tword)&labels[145]
	1 + __tpt,
	(tword)&tgoto,
#define __104      (tword)&labels[146]
	__104,
// __105:
	__name,
#define __te1      (tword)&labels[147]
	__te1,
	(tword)&salt,
	__done,
#define __te2      (tword)&labels[148]
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
#define _2         (tword)&start[950]
	(tword)".tq;",
#undef _1
#define _1         (tword)&start[951]
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
#define _1         (tword)&start[960]
	1 + (tword)&_txs,
	(tword)'0',
#undef _2
#define _2         (tword)&start[962]
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
#define __112      (tword)&labels[149]
	__112,
	__number,
	(tword)&tgoto,
#define __111      (tword)&labels[150]
	__111,
// __112:
	(tword)&trans,
	1 + _1,
// __111:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __114      (tword)&labels[151]
	__114,
	__list,
#define __targ     (tword)&labels[152]
	__targ,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __113      (tword)&labels[153]
	__113,
// __114:
	__null,
// __113:
	1 + (tword)&trans,
	1 + _2,
// __targ:
	__name,
	(tword)&salt,
#define __115      (tword)&labels[154]
	__115,
	__remote,
	__tbody,
// __115:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[996]
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
#define _1         (tword)&start[1005]
	(tword)&_txs,
	(tword)';',
	1 + (tword)&_tp,
	1,
// __literal:
#define __shortlit (tword)&labels[155]
	__shortlit,
	(tword)&salt,
#define __116      (tword)&labels[156]
	__116,
	__remote,
	__longlit,
	(tword)&trans,
	1 + _1,
// __116:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[1017]
	(tword)">",
#undef _3
#define _3         (tword)&start[1018]
	(tword)"s;'",
#undef _2
#define _2         (tword)&start[1019]
	(tword)&_tx,
	_3,
	1 + (tword)&_tp,
	1,
// __shortlit:
	(tword)&ignore,
	__none,
	(tword)&smark,
	(tword)&any,
#define __litch    (tword)&labels[157]
	__litch,
	(tword)&_px,
	_1,
	(tword)&scopy,
	1 + (tword)&trans,
	1 + _2,
#undef _1
#define _1         (tword)&start[1033]
	(tword)">",
#undef _3
#define _3         (tword)&start[1034]
	(tword)"\\",
#undef _4
#define _4         (tword)&start[1035]
	(tword)">",
#undef _2
#define _2         (tword)&start[1036]
	(tword)&_tx,
	_3,
	1 + (tword)&_tx,
	_4,
#undef _5
#define _5         (tword)&start[1040]
	(tword)">",
#undef _7
#define _7         (tword)&start[1041]
	(tword)"\\0",
#undef _10
#define _10        (tword)&start[1042]
	(tword)">;.even",
#undef _6
#define _6         (tword)&start[1043]
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
#define __120      (tword)&labels[158]
	__120,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __117      (tword)&labels[159]
	__117,
// __120:
	__null,
// __117:
#define __litb     (tword)&labels[160]
	__litb,
	(tword)&_px,
	_5,
	1 + (tword)&trans,
	1 + _6,
#undef _1
#define _1         (tword)&start[1069]
	(tword)"\\",
#undef _3
#define _3         (tword)&start[1070]
	(tword)"\\\\",
#undef _2
#define _2         (tword)&start[1071]
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
#define __assignment (tword)&labels[161]
	__assignment,
	(tword)&salt,
#define __121      (tword)&labels[162]
	__121,
#define __rv       (tword)&labels[163]
	__rv,
// __121:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[1093]
	(tword)&_tp,
	3,
	_tn,
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
// __assignment:
#define __lv       (tword)&labels[164]
	__lv,
#define __assign   (tword)&labels[165]
	__assign,
	__expr,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[1106]
	(tword)&_tp,
	3,
	_tn,
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
#undef _2
#define _2         (tword)&start[1114]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __rv:
#define __prime    (tword)&labels[166]
	__prime,
#define __rv1      (tword)&start[1120]
	(tword)&bundle,
#define __infix    (tword)&labels[167]
	__infix,
	(tword)&alt,
#define __125      (tword)&labels[168]
	__125,
	__prime,
	(tword)&trans,
	1 + _1,
	(tword)&salt,
	__rv1,
	(tword)&tgoto,
#define __122      (tword)&labels[169]
	__122,
// __125:
#define __rva      (tword)&labels[170]
	__rva,
	(tword)&alt,
#define __124      (tword)&labels[171]
	__124,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __123      (tword)&labels[172]
	__123,
// __124:
// __123:
// __122:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[1139]
	(tword)".t;alt;",
#undef _3
#define _3         (tword)&start[1140]
	(tword)"salt;",
#undef _1
#define _1         (tword)&start[1141]
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
#define _1         (tword)&start[1175]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
#undef _2
#define _2         (tword)&start[1180]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
#undef _3
#define _3         (tword)&start[1185]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
#undef _5
#define _5         (tword)&start[1190]
	(tword)".l;",
#undef _4
#define _4         (tword)&start[1191]
	(tword)&_tx,
	_5,
	1 + (tword)&_tp,
	1,
// __prime:
	__lv,
	(tword)&alt,
#define __135      (tword)&labels[173]
	__135,
#define __suffix   (tword)&labels[174]
	__suffix,
	(tword)&alt,
	__done,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __126      (tword)&labels[175]
	__126,
// __135:
#define __prefix   (tword)&labels[176]
	__prefix,
	(tword)&alt,
#define __134      (tword)&labels[177]
	__134,
	__lv,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __127      (tword)&labels[178]
	__127,
// __134:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __133      (tword)&labels[179]
	__133,
	__expr,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __130      (tword)&labels[180]
	__130,
// __133:
#define __unary    (tword)&labels[181]
	__unary,
	(tword)&alt,
#define __132      (tword)&labels[182]
	__132,
	__prime,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __131      (tword)&labels[183]
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
#define _2         (tword)&start[1235]
	(tword)".l;",
#undef _1
#define _1         (tword)&start[1236]
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
#undef _4
#define _4         (tword)&start[1240]
	(tword)".rv",
#undef _3
#define _3         (tword)&start[1241]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tx,
	_4,
#undef _6
#define _6         (tword)&start[1246]
	(tword)".f",
#undef _5
#define _5         (tword)&start[1247]
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
#define __141      (tword)&labels[184]
	__141,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __136      (tword)&labels[185]
	__136,
// __141:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __140      (tword)&labels[186]
	__140,
	__lv,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __137      (tword)&labels[187]
	__137,
// __140:
	(tword)&_pxs,
	(tword)'*',
	__prime,
	(tword)&trans,
	1 + _3,
// __137:
// __136:
#define __lv1      (tword)&start[1276]
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
#define _2         (tword)&start[1288]
	(tword)".u",
#undef _1
#define _1         (tword)&start[1289]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tx,
	_2,
#undef _4
#define _4         (tword)&start[1294]
	(tword)".st",
#undef _3
#define _3         (tword)&start[1295]
	1 + (tword)&_tx,
	_4,
// __assign:
	(tword)&_pxs,
	(tword)'=',
	(tword)&ignore,
	__none,
	__infix,
	(tword)&alt,
#define __143      (tword)&labels[188]
	__143,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __142      (tword)&labels[189]
	__142,
// __143:
	(tword)&trans,
	1 + _3,
// __142:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[1311]
	1 + (tword)&_pxs,
	(tword)'+',
#undef _1
#define _1         (tword)&start[1313]
	(tword)&_pxs,
	(tword)'+',
	1 + __not,
	_2,
#undef _4
#define _4         (tword)&start[1317]
	(tword)".a",
#undef _3
#define _3         (tword)&start[1318]
	1 + (tword)&_tx,
	_4,
#undef _6
#define _6         (tword)&start[1320]
	(tword)".s",
#undef _5
#define _5         (tword)&start[1321]
	1 + (tword)&_tx,
	_6,
#undef _10
#define _10        (tword)&start[1323]
	(tword)".m",
#undef _7
#define _7         (tword)&start[1324]
	1 + (tword)&_tx,
	_10,
#undef _12
#define _12        (tword)&start[1326]
	(tword)".q",
#undef _11
#define _11        (tword)&start[1327]
	1 + (tword)&_tx,
	_12,
#undef _14
#define _14        (tword)&start[1329]
	(tword)".r",
#undef _13
#define _13        (tword)&start[1330]
	1 + (tword)&_tx,
	_14,
#undef _16
#define _16        (tword)&start[1332]
	(tword)".o",
#undef _15
#define _15        (tword)&start[1333]
	1 + (tword)&_tx,
	_16,
#undef _20
#define _20        (tword)&start[1335]
	(tword)".x",
#undef _17
#define _17        (tword)&start[1336]
	1 + (tword)&_tx,
	_20,
#undef _22
#define _22        (tword)&start[1338]
	(tword)".n",
#undef _21
#define _21        (tword)&start[1339]
	1 + (tword)&_tx,
	_22,
#undef _23
#define _23        (tword)&start[1341]
	(tword)"==",
#undef _25
#define _25        (tword)&start[1342]
	(tword)".eq",
#undef _24
#define _24        (tword)&start[1343]
	1 + (tword)&_tx,
	_25,
#undef _26
#define _26        (tword)&start[1345]
	(tword)"!=",
#undef _30
#define _30        (tword)&start[1346]
	(tword)".ne",
#undef _27
#define _27        (tword)&start[1347]
	1 + (tword)&_tx,
	_30,
#undef _31
#define _31        (tword)&start[1349]
	(tword)"<=",
#undef _33
#define _33        (tword)&start[1350]
	(tword)".le",
#undef _32
#define _32        (tword)&start[1351]
	1 + (tword)&_tx,
	_33,
#undef _34
#define _34        (tword)&start[1353]
	(tword)">=",
#undef _36
#define _36        (tword)&start[1354]
	(tword)".ge",
#undef _35
#define _35        (tword)&start[1355]
	1 + (tword)&_tx,
	_36,
#undef _37
#define _37        (tword)&start[1357]
	(tword)"<<",
#undef _41
#define _41        (tword)&start[1358]
	(tword)".sl",
#undef _40
#define _40        (tword)&start[1359]
	1 + (tword)&_tx,
	_41,
#undef _43
#define _43        (tword)&start[1361]
	(tword)".lt",
#undef _42
#define _42        (tword)&start[1362]
	1 + (tword)&_tx,
	_43,
#undef _44
#define _44        (tword)&start[1364]
	(tword)">",
#undef _45
#define _45        (tword)&start[1365]
	(tword)">",
#undef _47
#define _47        (tword)&start[1366]
	(tword)".sr",
#undef _46
#define _46        (tword)&start[1367]
	1 + (tword)&_tx,
	_47,
#undef _51
#define _51        (tword)&start[1369]
	(tword)".gt",
#undef _50
#define _50        (tword)&start[1370]
	1 + (tword)&_tx,
	_51,
// __infix:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'+',
	(tword)&alt,
#define __201      (tword)&labels[190]
	__201,
	__not,
	_1,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __144      (tword)&labels[191]
	__144,
// __201:
	(tword)&_pxs,
	(tword)'-',
	(tword)&alt,
#define __200      (tword)&labels[192]
	__200,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __145      (tword)&labels[193]
	__145,
// __200:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __177      (tword)&labels[194]
	__177,
	(tword)&trans,
	1 + _7,
	(tword)&tgoto,
#define __146      (tword)&labels[195]
	__146,
// __177:
	(tword)&_pxs,
	(tword)'/',
	(tword)&alt,
#define __176      (tword)&labels[196]
	__176,
	(tword)&trans,
	1 + _11,
	(tword)&tgoto,
#define __147      (tword)&labels[197]
	__147,
// __176:
	(tword)&_pxs,
	(tword)'%',
	(tword)&alt,
#define __175      (tword)&labels[198]
	__175,
	(tword)&trans,
	1 + _13,
	(tword)&tgoto,
#define __150      (tword)&labels[199]
	__150,
// __175:
	(tword)&_pxs,
	(tword)'|',
	(tword)&alt,
#define __174      (tword)&labels[200]
	__174,
	(tword)&trans,
	1 + _15,
	(tword)&tgoto,
#define __151      (tword)&labels[201]
	__151,
// __174:
	(tword)&_pxs,
	(tword)'^',
	(tword)&alt,
#define __173      (tword)&labels[202]
	__173,
	(tword)&trans,
	1 + _17,
	(tword)&tgoto,
#define __152      (tword)&labels[203]
	__152,
// __173:
	(tword)&_pxs,
	(tword)'&',
	(tword)&alt,
#define __172      (tword)&labels[204]
	__172,
	(tword)&trans,
	1 + _21,
	(tword)&tgoto,
#define __153      (tword)&labels[205]
	__153,
// __172:
	(tword)&_px,
	_23,
	(tword)&alt,
#define __171      (tword)&labels[206]
	__171,
	(tword)&trans,
	1 + _24,
	(tword)&tgoto,
#define __154      (tword)&labels[207]
	__154,
// __171:
	(tword)&_px,
	_26,
	(tword)&alt,
#define __170      (tword)&labels[208]
	__170,
	(tword)&trans,
	1 + _27,
	(tword)&tgoto,
#define __155      (tword)&labels[209]
	__155,
// __170:
	(tword)&_px,
	_31,
	(tword)&alt,
#define __167      (tword)&labels[210]
	__167,
	(tword)&trans,
	1 + _32,
	(tword)&tgoto,
#define __156      (tword)&labels[211]
	__156,
// __167:
	(tword)&_px,
	_34,
	(tword)&alt,
#define __166      (tword)&labels[212]
	__166,
	(tword)&trans,
	1 + _35,
	(tword)&tgoto,
#define __157      (tword)&labels[213]
	__157,
// __166:
	(tword)&_px,
	_37,
	(tword)&alt,
#define __165      (tword)&labels[214]
	__165,
	(tword)&trans,
	1 + _40,
	(tword)&tgoto,
#define __160      (tword)&labels[215]
	__160,
// __165:
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __164      (tword)&labels[216]
	__164,
	(tword)&trans,
	1 + _42,
	(tword)&tgoto,
#define __161      (tword)&labels[217]
	__161,
// __164:
	(tword)&_px,
	_44,
	(tword)&_px,
	_45,
	(tword)&alt,
#define __163      (tword)&labels[218]
	__163,
	(tword)&trans,
	1 + _46,
	(tword)&tgoto,
#define __162      (tword)&labels[219]
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
#define _2         (tword)&start[1502]
	(tword)".lv",
#undef _1
#define _1         (tword)&start[1503]
	1 + (tword)&_tx,
	_2,
#undef _3
#define _3         (tword)&start[1505]
	(tword)"++",
#undef _5
#define _5         (tword)&start[1506]
	(tword)".ib",
#undef _4
#define _4         (tword)&start[1507]
	1 + (tword)&_tx,
	_5,
#undef _6
#define _6         (tword)&start[1509]
	(tword)"--",
#undef _10
#define _10        (tword)&start[1510]
	(tword)".db",
#undef _7
#define _7         (tword)&start[1511]
	1 + (tword)&_tx,
	_10,
// __prefix:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'&',
	(tword)&alt,
#define __205      (tword)&labels[220]
	__205,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __202      (tword)&labels[221]
	__202,
// __205:
	(tword)&_px,
	_3,
	(tword)&alt,
#define __204      (tword)&labels[222]
	__204,
	(tword)&trans,
	1 + _4,
	(tword)&tgoto,
#define __203      (tword)&labels[223]
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
#define _1         (tword)&start[1537]
	(tword)"++",
#undef _3
#define _3         (tword)&start[1538]
	(tword)".ia",
#undef _2
#define _2         (tword)&start[1539]
	1 + (tword)&_tx,
	_3,
#undef _4
#define _4         (tword)&start[1541]
	(tword)"--",
#undef _6
#define _6         (tword)&start[1542]
	(tword)".da",
#undef _5
#define _5         (tword)&start[1543]
	1 + (tword)&_tx,
	_6,
// __suffix:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&_px,
	_1,
	(tword)&alt,
#define __207      (tword)&labels[224]
	__207,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __206      (tword)&labels[225]
	__206,
// __207:
	(tword)&_px,
	_4,
	(tword)&trans,
	1 + _5,
// __206:
	1 + (tword)&succ,
#undef _2
#define _2         (tword)&start[1561]
	(tword)".nt",
#undef _1
#define _1         (tword)&start[1562]
	1 + (tword)&_tx,
	_2,
#undef _4
#define _4         (tword)&start[1564]
	(tword)".ng",
#undef _3
#define _3         (tword)&start[1565]
	1 + (tword)&_tx,
	_4,
#undef _6
#define _6         (tword)&start[1567]
	(tword)".cm",
#undef _5
#define _5         (tword)&start[1568]
	1 + (tword)&_tx,
	_6,
// __unary:
	(tword)&_pxs,
	(tword)'!',
	(tword)&alt,
#define __213      (tword)&labels[226]
	__213,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __210      (tword)&labels[227]
	__210,
// __213:
	(tword)&_pxs,
	(tword)'-',
	(tword)&alt,
#define __212      (tword)&labels[228]
	__212,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __211      (tword)&labels[229]
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
#define __215      (tword)&labels[230]
	__215,
#define __ccla     (tword)&labels[231]
	__ccla,
#define __cclb     (tword)&labels[232]
	__cclb,
	(tword)&tgoto,
#define __214      (tword)&labels[233]
	__214,
// __215:
	__ccla,
// __214:
	1 + (tword)&octal,
#define __classmask (tword)&labels[234]
	__classmask,
#undef _1
#define _1         (tword)&start[1602]
	(tword)"<<",
#undef _2
#define _2         (tword)&start[1603]
	1,
#undef _4
#define _4         (tword)&start[1604]
	(tword)"<<",
// __ccla:
	(tword)&_px,
	_1,
	(tword)&_l,
	__classmask,
	(tword)&_l,
	_2,
	(tword)&_l,
#define __nclass   (tword)&labels[235]
	__nclass,
	(tword)&_ia,
	(tword)&_sl,
	(tword)&_st,
	(tword)&_p,
	(tword)&_l,
	__classmask,
	(tword)&_t,
	(tword)&alt,
#define __cherr    (tword)&labels[236]
	__cherr,
#define __ccl1     (tword)&start[1622]
#define __cclc     (tword)&labels[237]
	__cclc,
	(tword)&_px,
	_4,
	1 + (tword)&salt,
	__ccl1,
#undef _1
#define _1         (tword)&start[1627]
	(tword)">",
// __cclc:
	(tword)&ignore,
	__none,
#define __ccl3     (tword)&start[1630]
	(tword)&_px,
	_1,
	(tword)&salt,
#define __ccl4     (tword)&labels[238]
	__ccl4,
#define __ccle     (tword)&labels[239]
	__ccle,
	1 + (tword)&salt,
	__ccl3,
#undef _1
#define _1         (tword)&start[1637]
	(tword)">",
#undef _3
#define _3         (tword)&start[1638]
	(tword)">",
#undef _2
#define _2         (tword)&start[1639]
	1 + (tword)&_px,
	_3,
// __ccl4:
	(tword)&_px,
	_1,
	(tword)&salt,
#define __216      (tword)&labels[240]
	__216,
#define __cclx     (tword)&labels[241]
	__cclx,
	(tword)&fail,
// __216:
	__not,
	_2,
	(tword)&salt,
#define __217      (tword)&labels[242]
	__217,
	__ccle,
// __217:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[1653]
	2,
// __ccle:
	(tword)&tchar,
#define __n        (tword)&labels[243]
	__n,
	(tword)&_l,
	_1,
	(tword)&_l,
	__n,
	(tword)&_m,
	(tword)&_l,
#define __classes  (tword)&labels[244]
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
#define __zeron    (tword)&labels[245]
	__zeron,
#define __ccl5     (tword)&start[1672]
	(tword)&_l,
	__classes,
	(tword)&_lv,
	(tword)&_l,
	__n,
	(tword)&_a,
	(tword)&_rv,
	(tword)&_l,
	__classmask,
	(tword)&_x,
	(tword)&_u,
	(tword)&_p,
#define __testn    (tword)&labels[246]
	__testn,
	1 + (tword)&salt,
	__ccl5,
// __cclx:
	(tword)&_l,
	__nclass,
	(tword)&_da,
	(tword)&_p,
	__zeron,
#define __ccl6     (tword)&start[1692]
	(tword)&_l,
	__classes,
	(tword)&_lv,
	(tword)&_l,
	__n,
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
#define _3         (tword)&start[1708]
	(tword)"too many char classes",
#undef _2
#define _2         (tword)&start[1709]
	1 + (tword)&_tx,
	_3,
#undef _1
#define _1         (tword)&start[1711]
	1 + (tword)&trans,
	1 + _2,
// __cherr:
	1 + (tword)&diag,
	_1,
#undef _1
#define _1         (tword)&start[1715]
	0,
// __zeron:
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef _1
#define _1         (tword)&start[1722]
	2,
#undef _2
#define _2         (tword)&start[1723]
	0400,
// __testn:
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_a,
	(tword)&_u,
	(tword)&_l,
	_2,
	(tword)&_lt,
	1 + (tword)&_t,
#undef _1
#define _1         (tword)&start[1734]
	0,
#undef _4
#define _4         (tword)&start[1735]
	(tword)".globl classtab",
#undef _5
#define _5         (tword)&start[1736]
	(tword)"classtab:",
#undef _3
#define _3         (tword)&start[1737]
	_tn,
	(tword)&_tx,
	_4,
	_tn,
	(tword)&_tx,
	_5,
	1 + _tn,
#undef _2
#define _2         (tword)&start[1744]
	1 + (tword)&trans,
	1 + _3,
#undef _7
#define _7         (tword)&start[1746]
	(tword)&_tp,
	1,
	1 + _tn,
#undef _6
#define _6         (tword)&start[1749]
	(tword)&octal,
#define __w        (tword)&labels[247]
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
#define __ptc1     (tword)&start[1762]
	(tword)&_l,
	__w,
	(tword)&_l,
	__classes,
	(tword)&_lv,
	(tword)&_l,
	__n,
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
#define __cl1      (tword)&start[1781]
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
#define __cl2      (tword)&start[1797]
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
#define __cl3      (tword)&start[1813]
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
#define __cl4      (tword)&start[1829]
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
#define __cl5      (tword)&start[1845]
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
#define __cl6      (tword)&start[1861]
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
#define __cl7      (tword)&start[1877]
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
#define __cl8      (tword)&start[1893]
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
#define _1         (tword)&start[1910]
	(tword)&_txs,
	(tword)'.',
	1 + (tword)&_tp,
	1,
#define __create   (tword)&start[1914]
	(tword)&_l,
	__csym,
	(tword)&_ia,
	(tword)&_p,
#define __getcsym  (tword)&start[1918]
	(tword)&octal,
	__csym,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[1922]
	(tword)"..",
#undef _1
#define _1         (tword)&start[1923]
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
// __fref:
	(tword)&_l,
#define __fsym     (tword)&labels[248]
	__fsym,
	(tword)&_ia,
	(tword)&_p,
// __getfref:
	(tword)&octal,
	__fsym,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[1935]
	1,
// __not:
	(tword)&params,
	_1,
	(tword)((tuword)-1<<1),
	(tword)&alt,
	__done,
	1 + (tword)&fail,
#undef _1
#define _1         (tword)&start[1942]
	1,
#undef _2
#define _2         (tword)&start[1943]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __list:
	(tword)&params,
	_1,
	(tword)((tuword)-1<<1),
#define __list1    (tword)&start[1951]
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
#define _1         (tword)&start[1961]
	1,
// __remote:
	(tword)&params,
	_1,
	__create,
	1 + (tword)&parse,
#define __rem1     (tword)&labels[249]
	__rem1,
	(tword)((tuword)-1<<1),
#undef _1
#define _1         (tword)&start[1968]
	1,
#undef _3
#define _3         (tword)&start[1969]
	(tword)"=.",
#undef _2
#define _2         (tword)&start[1970]
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
#define __digit    (tword)&labels[250]
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
#define __alpha    (tword)&labels[251]
	__alpha,
#undef _1
#define _1         (tword)&start[2001]
	1,
#undef _3
#define _3         (tword)&start[2002]
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
#define _1         (tword)&start[2018]
	2,
#undef _3
#define _3         (tword)&start[2019]
	0,
// __newtab:
	(tword)&params,
	_1,
	(tword)&_l,
	(tword)((tuword)-2<<1),
	(tword)&_t,
	(tword)&salt,
#define __220      (tword)&labels[252]
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
#define _1         (tword)&start[2048]
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
#define _1         (tword)&start[2073]
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
#define __classtab (tword)&start[2100]
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
#define _pn        (tword)&start[2228]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[2081],    // __blanks
	(tword)&start[149],     // __comment
	(tword)&start[41],      // __first
	(tword)&start[12],      // __pr2
	(tword)&start[60],      // __error
	(tword)&start[85],      // __line
	(tword)&start[1753],    // __putcharcl
	(tword)&start[145],     // __last
	(tword)&start[2230],    // _tn
	(tword)&start[1927],    // __fref
	(tword)&start[1931],    // __getfref
	(tword)&start[2086],    // __none
	(tword)&start[76],      // __3
	(tword)&start[77],      // __2
	(tword)&start[2071],    // __null
	(tword)&start[122],     // __labels
	(tword)&start[1591],    // __charcl
	(tword)&start[93],      // __7
	(tword)&start[102],     // __4
	(tword)&start[190],     // __statement
	(tword)&start[102],     // __5
	(tword)&start[109],     // __numbers
	(tword)&start[102],     // __6
	(tword)&start[828],     // __trule
	(tword)&start[1984],    // __number
	(tword)&start[1909],    // __done
	(tword)&start[132],     // __label
	(tword)&start[1992],    // __name
	(tword)&start[2080],    // __nil
	(tword)&start[2076],    // __q1
	(tword)&start[2074],    // __xbit
	(tword)&start[2087],    // __csym
	(tword)&start[2003],    // __oldtab
	(tword)&start[2092],    // __dtt
	(tword)&start[2095],    // __pat
	(tword)&start[237],     // __proc
	(tword)&start[211],     // __11
	(tword)&start[250],     // __plst
	(tword)&start[279],     // __tlst
	(tword)&start[214],     // __10
	(tword)&start[689],     // __noelem
	(tword)&start[305],     // __frag
	(tword)&start[224],     // __15
	(tword)&start[235],     // __12
	(tword)&start[696],     // __ifelem
	(tword)&start[233],     // __14
	(tword)&start[235],     // __13
	(tword)&start[2096],    // __npa
	(tword)&start[1948],    // __list
	(tword)&start[258],     // __pident
	(tword)&start[1962],    // __remote
	(tword)&start[1994],    // __ident
	(tword)&start[2020],    // __newtab
	(tword)&start[2099],    // __i
	(tword)&start[371],     // __prule
	(tword)&start[312],     // __17
	(tword)&start[316],     // __16
	(tword)&start[2078],    // __q2
	(tword)&start[2094],    // __sndt
	(tword)&start[2093],    // __ndt
	(tword)&start[416],     // __disj
	(tword)&start[404],     // __23
	(tword)&start[703],     // __ifeasy
	(tword)&start[397],     // __21
	(tword)&start[401],     // __20
	(tword)&start[404],     // __22
	(tword)&start[441],     // __pelem
	(tword)&start[554],     // __pdot
	(tword)&start[429],     // __25
	(tword)&start[682],     // __ishard
	(tword)&start[429],     // __24
	(tword)&start[501],     // __pprim
	(tword)&start[449],     // __31
	(tword)&start[675],     // __iseasy
	(tword)&start[466],     // __26
	(tword)&start[461],     // __30
	(tword)&start[466],     // __27
	(tword)&start[749],     // __special
	(tword)&start[533],     // __32
	(tword)&start[805],     // __rname
	(tword)&start[512],     // __37
	(tword)&start[533],     // __33
	(tword)&start[582],     // __spdot
	(tword)&start[515],     // __34
	(tword)&start[531],     // __36
	(tword)&start[591],     // __parg
	(tword)&start[533],     // __35
	(tword)&start[541],     // __41
	(tword)&start[547],     // __40
	(tword)&start[552],     // __43
	(tword)&start[552],     // __42
	(tword)&start[588],     // __alias
	(tword)&start[576],     // __44
	(tword)&start[2083],    // __letter
	(tword)&start[1936],    // __not
	(tword)&start[596],     // __45
	(tword)&start[617],     // __specparg
	(tword)&start[673],     // __46
	(tword)&start[673],     // __47
	(tword)&start[630],     // __57
	(tword)&start[1053],    // __longlit
	(tword)&start[673],     // __50
	(tword)&start[638],     // __56
	(tword)&start[673],     // __51
	(tword)&start[648],     // __55
	(tword)&start[673],     // __52
	(tword)&start[671],     // __54
	(tword)&start[673],     // __53
	(tword)&start[2089],    // __easy
	(tword)&start[762],     // __70
	(tword)&start[758],     // __60
	(tword)&start[796],     // __61
	(tword)&start[771],     // __67
	(tword)&start[1009],    // __literal
	(tword)&start[796],     // __62
	(tword)&start[779],     // __66
	(tword)&start[796],     // __63
	(tword)&start[1088],    // __expr
	(tword)&start[790],     // __65
	(tword)&start[792],     // __64
	(tword)&start[815],     // __72
	(tword)&start[2049],    // __tabval
	(tword)&start[818],     // __71
	(tword)&start[2097],    // __ptt
	(tword)&start[856],     // __tbody
	(tword)&start[844],     // __73
	(tword)&start[839],     // __74
	(tword)&start[845],     // __tra
	(tword)&start[849],     // __tident
	(tword)&start[2098],    // __npt
	(tword)&start[866],     // __76
	(tword)&start[867],     // __75
	(tword)&start[876],     // __trb
	(tword)&start[902],     // __telem
	(tword)&start[885],     // __100
	(tword)&start[888],     // __77
	(tword)&start[911],     // __110
	(tword)&start[943],     // __101
	(tword)&start[919],     // __107
	(tword)&start[943],     // __102
	(tword)&start[928],     // __106
	(tword)&start[943],     // __103
	(tword)&start[936],     // __105
	(tword)&start[968],     // __tdot
	(tword)&start[997],     // __tpt
	(tword)&start[943],     // __104
	(tword)&start[944],     // __te1
	(tword)&start[955],     // __te2
	(tword)&start[975],     // __112
	(tword)&start[977],     // __111
	(tword)&start[987],     // __114
	(tword)&start[990],     // __targ
	(tword)&start[988],     // __113
	(tword)&start[995],     // __115
	(tword)&start[1023],    // __shortlit
	(tword)&start[1016],    // __116
	(tword)&start[2085],    // __litch
	(tword)&start[1063],    // __120
	(tword)&start[1064],    // __117
	(tword)&start[1077],    // __litb
	(tword)&start[1101],    // __assignment
	(tword)&start[1092],    // __121
	(tword)&start[1119],    // __rv
	(tword)&start[1255],    // __lv
	(tword)&start[1297],    // __assign
	(tword)&start[1195],    // __prime
	(tword)&start[1372],    // __infix
	(tword)&start[1131],    // __125
	(tword)&start[1138],    // __122
	(tword)&start[1165],    // __rva
	(tword)&start[1138],    // __124
	(tword)&start[1138],    // __123
	(tword)&start[1205],    // __135
	(tword)&start[1545],    // __suffix
	(tword)&start[1234],    // __126
	(tword)&start[1513],    // __prefix
	(tword)&start[1213],    // __134
	(tword)&start[1234],    // __127
	(tword)&start[1222],    // __133
	(tword)&start[1234],    // __130
	(tword)&start[1570],    // __unary
	(tword)&start[1230],    // __132
	(tword)&start[1234],    // __131
	(tword)&start[1262],    // __141
	(tword)&start[1276],    // __136
	(tword)&start[1271],    // __140
	(tword)&start[1276],    // __137
	(tword)&start[1308],    // __143
	(tword)&start[1310],    // __142
	(tword)&start[1385],    // __201
	(tword)&start[1501],    // __144
	(tword)&start[1393],    // __200
	(tword)&start[1501],    // __145
	(tword)&start[1401],    // __177
	(tword)&start[1501],    // __146
	(tword)&start[1409],    // __176
	(tword)&start[1501],    // __147
	(tword)&start[1417],    // __175
	(tword)&start[1501],    // __150
	(tword)&start[1425],    // __174
	(tword)&start[1501],    // __151
	(tword)&start[1433],    // __173
	(tword)&start[1501],    // __152
	(tword)&start[1441],    // __172
	(tword)&start[1501],    // __153
	(tword)&start[1449],    // __171
	(tword)&start[1501],    // __154
	(tword)&start[1457],    // __170
	(tword)&start[1501],    // __155
	(tword)&start[1465],    // __167
	(tword)&start[1501],    // __156
	(tword)&start[1473],    // __166
	(tword)&start[1501],    // __157
	(tword)&start[1481],    // __165
	(tword)&start[1501],    // __160
	(tword)&start[1489],    // __164
	(tword)&start[1501],    // __161
	(tword)&start[1499],    // __163
	(tword)&start[1501],    // __162
	(tword)&start[1524],    // __205
	(tword)&start[1536],    // __202
	(tword)&start[1532],    // __204
	(tword)&start[1536],    // __203
	(tword)&start[1556],    // __207
	(tword)&start[1560],    // __206
	(tword)&start[1578],    // __213
	(tword)&start[1590],    // __210
	(tword)&start[1586],    // __212
	(tword)&start[1590],    // __211
	(tword)&start[1599],    // __215
	(tword)&start[1605],    // __ccla
	(tword)&start[1671],    // __cclb
	(tword)&start[1600],    // __214
	(tword)&start[1779],    // __classmask
	(tword)&start[1780],    // __nclass
	(tword)&start[1713],    // __cherr
	(tword)&start[1628],    // __cclc
	(tword)&start[1641],    // __ccl4
	(tword)&start[1654],    // __ccle
	(tword)&start[1647],    // __216
	(tword)&start[1687],    // __cclx
	(tword)&start[1652],    // __217
	(tword)&start[2091],    // __n
	(tword)&start[1781],    // __classes
	(tword)&start[1716],    // __zeron
	(tword)&start[1724],    // __testn
	(tword)&start[2090],    // __w
	(tword)&start[2088],    // __fsym
	(tword)&start[1978],    // __rem1
	(tword)&start[2082],    // __digit
	(tword)&start[2084],    // __alpha
	(tword)&start[2035],    // __220
};

// Used builtins:
//   _a
//   _cm
//   _da
//   _eq
//   _f
//   _ia
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
