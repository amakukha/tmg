/* Port of the Unix compiler-compiler TMG to C99.
 * Based on the original PDP-11 assembly code by M. D. McIlroy.
 * (c) 2020, Andriy Makukha, 2-clause BSD License.
 * 
 * Phase 1 of translating TMGL into a TMG driving table in C. */

#define SRC_LANGUAGE "TMGL"
#define DST_LANGUAGE "phase 1"

const tword labels[];

// Driving table for the program

tword start[] = {
#define __1	(tword)&labels[0]
	1 + __1,
// __1:
#define __begin	(tword)&start[1]
	(tword)&ignore,
#define __blanks	(tword)&labels[1]
	__blanks,
	(tword)&_l,
#define __wordsz	(tword)&labels[2]
	__wordsz,
	(tword)&_l,
#define __classes	(tword)&labels[3]
	__classes,
	(tword)&_lv,
	(tword)&_l,
#define __nclass	(tword)&labels[4]
	__nclass,
	(tword)&_lv,
	(tword)&_s,
	(tword)&_st,
	(tword)&_p,
#define __pr1	(tword)&start[14]
#define __comment	(tword)&labels[5]
	__comment,
	(tword)&salt,
	__pr1,
	(tword)&parse,
#define __first	(tword)&labels[6]
	__first,
	(tword)&salt,
#define __pr2	(tword)&labels[7]
	__pr2,
	(tword)&diag,
#define __error	(tword)&labels[8]
	__error,
// __pr2:
	__comment,
	(tword)&salt,
	__pr2,
	(tword)&parse,
#define __line	(tword)&labels[9]
	__line,
	(tword)&salt,
	__pr2,
	(tword)&diag,
	__error,
	(tword)&salt,
	__pr2,
#define __putcharcl	(tword)&labels[10]
	__putcharcl,
	1 + (tword)&parse,
#define __last	(tword)&labels[11]
	__last,
#undef  _3
#define _3	(tword)&start[37]
	(tword)"1 + ",
#undef  _2
#define _2	(tword)&start[38]
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
#define _tn	(tword)&labels[12]
	1 + _tn,
#undef  _1
#define _1	(tword)&start[43]
#define __fref	(tword)&labels[13]
	__fref,
	1 + (tword)&trans,
	1 + _2,
#undef  _4
#define _4	(tword)&start[46]
	(tword)&_tp,
	2,
	(tword)&_txs,
	(tword)':',
	1 + (tword)&_tp,
	1,
// __first:
	(tword)&parse,
	_1,
#define __getfref	(tword)&labels[14]
	__getfref,
	__line,
	1 + (tword)&trans,
	1 + _4,
#undef  _1
#define _1	(tword)&start[58]
	1,
#undef  _2
#define _2	(tword)&start[59]
	2,
#undef  _3
#define _3	(tword)&start[60]
	1 + (tword)&_txs,
	(tword)';',
#undef  _5
#define _5	(tword)&start[62]
	(tword)"??? error: ",
#undef  _4
#define _4	(tword)&start[63]
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
#define __none	(tword)&labels[15]
	__none,
	(tword)&any,
	_1,
	(tword)&string,
	_2,
	(tword)&scopy,
	(tword)&_pxs,
	(tword)';',
	(tword)&alt,
#define __3	(tword)&labels[16]
	__3,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __2	(tword)&labels[17]
	__2,
// __3:
#define __null	(tword)&labels[18]
	__null,
// __2:
	1 + (tword)&trans,
	1 + _4,
#undef  _1
#define _1	(tword)&start[90]
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tp,
	1,
	1 + _tn,
// __line:
#define __labels	(tword)&labels[19]
	__labels,
#define __charcl	(tword)&labels[20]
	__charcl,
	(tword)&alt,
#define __7	(tword)&labels[21]
	__7,
	(tword)&_pxs,
	(tword)';',
	(tword)&tgoto,
#define __4	(tword)&labels[22]
	__4,
// __7:
#define __statement	(tword)&labels[23]
	__statement,
	(tword)&salt,
#define __5	(tword)&labels[24]
	__5,
#define __numbers	(tword)&labels[25]
	__numbers,
	(tword)&salt,
#define __6	(tword)&labels[26]
	__6,
#define __trule	(tword)&labels[27]
	__trule,
	(tword)&_pxs,
	(tword)';',
// __6:
// __5:
// __4:
	1 + (tword)&trans,
	1 + _1,
#undef  _1
#define _1	(tword)&start[115]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __numbers:
#define __number	(tword)&labels[28]
	__number,
	(tword)&_pxs,
	(tword)';',
	__numbers,
	(tword)&alt,
#define __done	(tword)&labels[29]
	__done,
	1 + (tword)&trans,
	1 + _1,
#undef  _1
#define _1	(tword)&start[128]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __labels:
#define __label	(tword)&labels[30]
	__label,
	__labels,
	(tword)&alt,
	__done,
	1 + (tword)&trans,
	1 + _1,
#undef  _1
#define _1	(tword)&start[139]
	(tword)&_tp,
	1,
	1 + (tword)&_txs,
	(tword)':',
// __label:
#define __name	(tword)&labels[31]
	__name,
	(tword)&_pxs,
	(tword)':',
	1 + (tword)&trans,
	1 + _1,
#undef  _2
#define _2	(tword)&start[148]
	(tword)"_pn:1 + _pxs;",
#undef  _3
#define _3	(tword)&start[149]
	(tword)"'\\n'",
#undef  _4
#define _4	(tword)&start[150]
	(tword)"_tn:1 + _txs;",
#undef  _5
#define _5	(tword)&start[151]
	(tword)"'\\n'",
#undef  _1
#define _1	(tword)&start[152]
	(tword)&_tx,
	_2,
	_tn,
	(tword)&_tx,
	_3,
	_tn,
	(tword)&_tx,
	_4,
	_tn,
	(tword)&_tx,
	_5,
	1 + _tn,
// __last:
	1 + (tword)&trans,
	1 + _1,
#undef  _1
#define _1	(tword)&start[166]
	(tword)"/*",
#undef  _2
#define _2	(tword)&start[167]
	4,
// __comment:
	(tword)&_px,
	_1,
#define __co1	(tword)&start[170]
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
#undef  _1
#define _1	(tword)&start[180]
	0,
#undef  _2
#define _2	(tword)&start[181]
	(tword)&gpar,
	1,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
#undef  _3
#define _3	(tword)&start[187]
	(tword)&gpar,
	1,
	1 + (tword)&generate,
#undef  _4
#define _4	(tword)&start[190]
	(tword)&gpar,
	1,
	(tword)&_tp,
	2,
#define __nil	(tword)&labels[32]
	__nil,
	_tn,
	1 + (tword)&_tp,
	1,
#define __q1	(tword)&labels[33]
	__q1,
#undef  _5
#define _5	(tword)&start[199]
	1 + (tword)&_tp,
	1,
#define __xbit	(tword)&labels[34]
	__xbit,
#undef  _7
#define _7	(tword)&start[202]
	(tword)"1 + succ;",
#undef  _6
#define _6	(tword)&start[203]
	(tword)&_tp,
	1,
	__nil,
	_tn,
	1 + (tword)&_tx,
	_7,
// __statement:
	(tword)&_l,
#define __csym	(tword)&labels[35]
	__csym,
	(tword)&_l,
	_1,
	(tword)&_st,
	(tword)&_p,
#define __oldtab	(tword)&labels[36]
	__oldtab,
#define __dtt	(tword)&labels[37]
	__dtt,
	__oldtab,
#define __pat	(tword)&labels[38]
	__pat,
#define __prc	(tword)&labels[39]
	__prc,
	(tword)&alt,
#define __11	(tword)&labels[40]
	__11,
#define __plst	(tword)&labels[41]
	__plst,
#define __tlst	(tword)&labels[42]
	__tlst,
	(tword)&_pxs,
	(tword)')',
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __10	(tword)&labels[43]
	__10,
// __11:
	(tword)&trans,
	1 + _3,
#define __noelem	(tword)&labels[44]
	__noelem,
// __10:
#define __stt1	(tword)&start[233]
	(tword)&bundle,
#define __frag	(tword)&labels[45]
	__frag,
	(tword)&alt,
#define __15	(tword)&labels[46]
	__15,
	(tword)&trans,
	1 + _4,
	(tword)&salt,
	__stt1,
	(tword)&tgoto,
#define __12	(tword)&labels[47]
	__12,
// __15:
	(tword)&_pxs,
	(tword)';',
#define __ifelem	(tword)&labels[48]
	__ifelem,
	(tword)&alt,
#define __14	(tword)&labels[49]
	__14,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __13	(tword)&labels[50]
	__13,
// __14:
	(tword)&trans,
	1 + _6,
// __13:
// __12:
	1 + (tword)&succ,
#undef  _1
#define _1	(tword)&start[255]
	(tword)"proc(",
// __prc:
	(tword)&smark,
	(tword)&ignore,
	__none,
	1 + (tword)&_px,
	_1,
#undef  _1
#define _1	(tword)&start[261]
	1 + (tword)&octal,
#define __npa	(tword)&labels[51]
	__npa,
#undef  _3
#define _3	(tword)&start[263]
	(tword)"params;",
#undef  _2
#define _2	(tword)&start[264]
	(tword)&_tx,
	_3,
	_tn,
	(tword)&_tp,
	1,
	1 + _tn,
// __plst:
#define __list	(tword)&labels[52]
	__list,
#define __pident	(tword)&labels[53]
	__pident,
	(tword)&alt,
	__null,
#define __remote	(tword)&labels[54]
	__remote,
	_1,
	1 + (tword)&trans,
	1 + _2,
// __pident:
#define __ident	(tword)&labels[55]
	__ident,
#define __newtab	(tword)&labels[56]
	1 + __newtab,
	__pat,
	__npa,
#undef  _1
#define _1	(tword)&start[282]
	0,
#undef  _2
#define _2	(tword)&start[283]
	__name,
	(tword)&_l,
#define __i	(tword)&labels[57]
	__i,
	(tword)&_ia,
	1 + (tword)&_p,
#undef  _3
#define _3	(tword)&start[288]
	1 + (tword)&octal,
	__i,
#undef  _5
#define _5	(tword)&start[290]
	(tword)"push;",
#undef  _4
#define _4	(tword)&start[291]
	(tword)&_tx,
	_5,
	_tn,
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
#undef  _1
#define _1	(tword)&start[316]
	(tword)&gpar,
	1,
	1 + (tword)&_tp,
	1,
	__nil,
	__q1,
#undef  _2
#define _2	(tword)&start[322]
	(tword)&gpar,
	1,
	1 + (tword)&_tp,
	1,
// __frag:
#define __prule	(tword)&labels[58]
	__prule,
	(tword)&alt,
#define __17	(tword)&labels[59]
	__17,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __16	(tword)&labels[60]
	__16,
// __17:
	__labels,
	__noelem,
	(tword)&trans,
	1 + _2,
// __16:
	1 + (tword)&succ,
#undef  _2
#define _2	(tword)&start[338]
	(tword)"salt;",
#undef  _1
#define _1	(tword)&start[339]
	(tword)&gpar,
	2,
	(tword)&_tp,
	3,
	__nil,
	__nil,
	_tn,
	(tword)&_tx,
	_2,
	_tn,
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tp,
	1,
#define __q2	(tword)&labels[61]
	__q2,
	__q1,
	_tn,
	(tword)&_tp,
	2,
	1 + (tword)&_txs,
	(tword)':',
#undef  _5
#define _5	(tword)&start[361]
	(tword)"alt;",
#undef  _4
#define _4	(tword)&start[362]
	_tn,
	(tword)&_tx,
	_5,
	_tn,
	1 + (tword)&_tp,
	1,
#undef  _6
#define _6	(tword)&start[368]
	(tword)"goto;",
#undef  _3
#define _3	(tword)&start[369]
	(tword)&gpar,
	2,
	(tword)&_tp,
	4,
	_4,
	__q1,
	_tn,
	(tword)&_tx,
	_6,
	_tn,
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
#define __sndt	(tword)&labels[62]
	__sndt,
	(tword)&_l,
#define __ndt	(tword)&labels[63]
	__ndt,
	(tword)&_st,
	(tword)&_p,
#define __disj	(tword)&labels[64]
	__disj,
	(tword)&_pxs,
	(tword)'|',
	(tword)&alt,
#define __23	(tword)&labels[65]
	__23,
	(tword)&_l,
	__ndt,
	(tword)&_l,
	__sndt,
	(tword)&_st,
	(tword)&_p,
	__fref,
#define __ifeasy	(tword)&labels[66]
	__ifeasy,
	(tword)&alt,
#define __21	(tword)&labels[67]
	__21,
	__prule,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __20	(tword)&labels[68]
	__20,
// __21:
	__prule,
	__fref,
	(tword)&trans,
	1 + _3,
// __20:
	__noelem,
	(tword)&tgoto,
#define __22	(tword)&labels[69]
	__22,
// __23:
// __22:
	1 + (tword)&succ,
#undef  _1
#define _1	(tword)&start[429]
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
#define __pelem	(tword)&labels[70]
	__pelem,
#define __pdot	(tword)&labels[71]
	__pdot,
	__disj,
	(tword)&alt,
#define __25	(tword)&labels[72]
	__25,
	(tword)&trans,
	1 + _1,
	__ifelem,
	(tword)&alt,
	__done,
#define __ishard	(tword)&labels[73]
	__ishard,
	(tword)&tgoto,
#define __24	(tword)&labels[74]
	__24,
// __25:
// __24:
	1 + (tword)&succ,
#undef  _1
#define _1	(tword)&start[454]
	(tword)&gpar,
	2,
	(tword)&_tp,
	1,
	__q1,
	1 + (tword)&_tq,
	2,
#undef  _2
#define _2	(tword)&start[461]
	1,
#undef  _3
#define _3	(tword)&start[462]
	(tword)&gpar,
	2,
	1 + (tword)&generate,
// __pelem:
#define __pprim	(tword)&labels[75]
	__pprim,
	(tword)&alt,
#define __31	(tword)&labels[76]
	__31,
	(tword)&trans,
	1 + _1,
#define __iseasy	(tword)&labels[77]
	__iseasy,
	(tword)&tgoto,
#define __26	(tword)&labels[78]
	__26,
// __31:
	(tword)&_pxs,
	(tword)'(',
	(tword)&push,
	_2,
	__sndt,
	__prule,
	(tword)&alt,
#define __30	(tword)&labels[79]
	__30,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __27	(tword)&labels[80]
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
#undef  _1
#define _1	(tword)&start[491]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
#undef  _2
#define _2	(tword)&start[500]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	1 + (tword)&_tp,
	1,
#undef  _4
#define _4	(tword)&start[506]
	(tword)"alt;",
#undef  _3
#define _3	(tword)&start[507]
	(tword)&_tx,
	_4,
	1 + _tn,
#undef  _5
#define _5	(tword)&start[510]
	(tword)"\\",
#undef  _7
#define _7	(tword)&start[511]
	(tword)"salt;",
#undef  _6
#define _6	(tword)&start[512]
	(tword)&_tx,
	_7,
	1 + _tn,
#undef  _10
#define _10	(tword)&start[515]
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
#define __special	(tword)&labels[81]
	__special,
	(tword)&salt,
#define __32	(tword)&labels[82]
	__32,
#define __rname	(tword)&labels[83]
	__rname,
	(tword)&_pxs,
	(tword)':',
	(tword)&alt,
#define __37	(tword)&labels[84]
	__37,
	(tword)&fail,
	(tword)&tgoto,
#define __33	(tword)&labels[85]
	__33,
// __37:
#define __spdot	(tword)&labels[86]
	__spdot,
	(tword)&salt,
#define __34	(tword)&labels[87]
	__34,
// __34:
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __36	(tword)&labels[88]
	__36,
	(tword)&ignore,
	__blanks,
	__list,
#define __parg	(tword)&labels[89]
	__parg,
	(tword)&_pxs,
	(tword)')',
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __35	(tword)&labels[90]
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
#define __41	(tword)&labels[91]
	__41,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __40	(tword)&labels[92]
	__40,
// __41:
	(tword)&_px,
	_5,
	(tword)&alt,
#define __43	(tword)&labels[93]
	__43,
	(tword)&trans,
	1 + _6,
// __40:
	__rname,
	(tword)&trans,
	1 + _10,
	(tword)&tgoto,
#define __42	(tword)&labels[94]
	__42,
// __43:
// __42:
	1 + (tword)&succ,
#undef  _2
#define _2	(tword)&start[579]
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
#define __alias	(tword)&labels[95]
	__alias,
	(tword)&_l,
	__dtt,
	(tword)&_t,
	(tword)&salt,
#define __44	(tword)&labels[96]
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
#undef  _1
#define _1	(tword)&start[606]
	1 + (tword)&any,
#define __letter	(tword)&labels[97]
	__letter,
// __spdot:
	(tword)&_pxs,
	(tword)'.',
	(tword)&ignore,
	__none,
#define __not	(tword)&labels[98]
	__not,
	_1,
// __alias:
	1 + __newtab,
	__dtt,
	__ndt,
// __parg:
	__rname,
	(tword)&salt,
#define __45	(tword)&labels[99]
	__45,
	__remote,
#define __specparg	(tword)&labels[100]
	__specparg,
// __45:
	1 + (tword)&succ,
#undef  _2
#define _2	(tword)&start[623]
	(tword)"\\n",
#undef  _1
#define _1	(tword)&start[624]
	1 + (tword)&_tx,
	_2,
#undef  _4
#define _4	(tword)&start[626]
	(tword)"1 + succ;",
#undef  _3
#define _3	(tword)&start[627]
	1 + (tword)&_tx,
	_4,
#undef  _5
#define _5	(tword)&start[629]
	3,
#undef  _6
#define _6	(tword)&start[630]
	0,
#undef  _7
#define _7	(tword)&start[631]
	1 + (tword)&_tp,
	1,
	__nil,
	__xbit,
#undef  _11
#define _11	(tword)&start[635]
	(tword)"1 + succ;",
#undef  _10
#define _10	(tword)&start[636]
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
#define __46	(tword)&labels[101]
	__46,
	__charcl,
	(tword)&salt,
#define __47	(tword)&labels[102]
	__47,
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __57	(tword)&labels[103]
	__57,
#define __longlit	(tword)&labels[104]
	__longlit,
	(tword)&tgoto,
#define __50	(tword)&labels[105]
	__50,
// __57:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __56	(tword)&labels[106]
	__56,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __51	(tword)&labels[107]
	__51,
// __56:
	(tword)&_pxs,
	(tword)'(',
	(tword)&_pxs,
	(tword)')',
	(tword)&alt,
#define __55	(tword)&labels[108]
	__55,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __52	(tword)&labels[109]
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
#define __54	(tword)&labels[110]
	__54,
	(tword)&trans,
	1 + _7,
	(tword)&tgoto,
#define __53	(tword)&labels[111]
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
#undef  _1
#define _1	(tword)&start[700]
	1,
// __iseasy:
	(tword)&_l,
#define __easy	(tword)&labels[112]
	__easy,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef  _1
#define _1	(tword)&start[707]
	0,
// __ishard:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef  _1
#define _1	(tword)&start[714]
	2,
// __noelem:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef  _1
#define _1	(tword)&start[721]
	2,
// __ifelem:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_1,
	(tword)&_ne,
	1 + (tword)&_t,
#undef  _2
#define _2	(tword)&start[728]
	1,
// __ifeasy:
	(tword)&_l,
	__easy,
	(tword)&_l,
	_2,
	(tword)&_eq,
	1 + (tword)&_t,
#undef  _2
#define _2	(tword)&start[735]
	(tword)"trans;",
#undef  _3
#define _3	(tword)&start[736]
	(tword)"1 + ",
#undef  _1
#define _1	(tword)&start[737]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	(tword)&_tx,
	_2,
	_tn,
	(tword)&_tx,
	_3,
	1 + (tword)&_tp,
	1,
#undef  _5
#define _5	(tword)&start[748]
	(tword)"_px",
#undef  _4
#define _4	(tword)&start[749]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	(tword)&_tx,
	_5,
	1 + (tword)&_tp,
	1,
#undef  _7
#define _7	(tword)&start[757]
	(tword)"_pn",
#undef  _6
#define _6	(tword)&start[758]
	(tword)&gpar,
	1,
	(tword)&_tq,
	1,
	1 + (tword)&_tx,
	_7,
#undef  _11
#define _11	(tword)&start[764]
	(tword)"_t",
#undef  _10
#define _10	(tword)&start[765]
	1 + (tword)&_tx,
	_11,
#undef  _13
#define _13	(tword)&start[767]
	(tword)"_p",
#undef  _12
#define _12	(tword)&start[768]
	1 + (tword)&_tx,
	_13,
#undef  _14
#define _14	(tword)&start[770]
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
#define __70	(tword)&labels[113]
	__70,
	__rname,
	(tword)&salt,
#define __60	(tword)&labels[114]
	__60,
	__remote,
	__trule,
// __60:
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __61	(tword)&labels[115]
	__61,
// __70:
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __67	(tword)&labels[116]
	__67,
#define __literal	(tword)&labels[117]
	__literal,
	(tword)&trans,
	1 + _4,
	(tword)&tgoto,
#define __62	(tword)&labels[118]
	__62,
// __67:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __66	(tword)&labels[119]
	__66,
	(tword)&trans,
	1 + _6,
	(tword)&tgoto,
#define __63	(tword)&labels[120]
	__63,
// __66:
	(tword)&_pxs,
	(tword)'[',
#define __expr	(tword)&labels[121]
	__expr,
	(tword)&_pxs,
	(tword)'?',
	(tword)&alt,
#define __65	(tword)&labels[122]
	__65,
	(tword)&trans,
	1 + _10,
	(tword)&tgoto,
#define __64	(tword)&labels[123]
	__64,
// __65:
	(tword)&trans,
	1 + _12,
// __64:
	(tword)&_pxs,
	(tword)']',
	(tword)&trans,
	1 + _14,
// __63:
// __62:
// __61:
	1 + (tword)&succ,
#undef  _2
#define _2	(tword)&start[827]
	(tword)"[-",
#undef  _3
#define _3	(tword)&start[828]
	(tword)"\\<1]",
#undef  _1
#define _1	(tword)&start[829]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	1 + (tword)&_tx,
	_3,
// __rname:
	__name,
	(tword)&alt,
#define __72	(tword)&labels[124]
	__72,
#define __tabval	(tword)&labels[125]
	__tabval,
	__pat,
	__npa,
	(tword)&alt,
	__done,
	(tword)&tgoto,
#define __71	(tword)&labels[126]
	__71,
// __72:
	(tword)&_pxs,
	(tword)'$',
	__number,
// __71:
	1 + (tword)&trans,
	1 + _1,
#undef  _2
#define _2	(tword)&start[850]
	(tword)"gpar;",
#undef  _1
#define _1	(tword)&start[851]
	(tword)&_tx,
	_2,
	_tn,
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __trule:
	__oldtab,
#define __ptt	(tword)&labels[127]
	__ptt,
#define __tbody	(tword)&labels[128]
	__tbody,
	(tword)&salt,
#define __73	(tword)&labels[129]
	__73,
	(tword)&_pxs,
	(tword)'(',
	__number,
	(tword)&salt,
#define __74	(tword)&labels[130]
	__74,
#define __tra	(tword)&labels[131]
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
#define __tident	(tword)&labels[132]
	__tident,
	1 + (tword)&octal,
#define __npt	(tword)&labels[133]
	__npt,
// __tident:
	__ident,
	1 + __newtab,
	__ptt,
	__npt,
#undef  _2
#define _2	(tword)&start[884]
	(tword)"1 + generate",
#undef  _1
#define _1	(tword)&start[885]
	1 + (tword)&_tx,
	_2,
// __tbody:
	(tword)&_pxs,
	(tword)'{',
	(tword)&_pxs,
	(tword)'}',
	(tword)&alt,
#define __76	(tword)&labels[134]
	__76,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __75	(tword)&labels[135]
	__75,
// __76:
#define __trb	(tword)&labels[136]
	__trb,
// __75:
	1 + (tword)&succ,
#undef  _1
#define _1	(tword)&start[899]
	__xbit,
	1 + (tword)&_tp,
	1,
#undef  _2
#define _2	(tword)&start[902]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __trb:
#define __telem	(tword)&labels[137]
	__telem,
	(tword)&_pxs,
	(tword)'}',
	(tword)&alt,
#define __100	(tword)&labels[138]
	__100,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __77	(tword)&labels[139]
	__77,
// __100:
	__trb,
	(tword)&trans,
	1 + _2,
// __77:
	1 + (tword)&succ,
#undef  _2
#define _2	(tword)&start[920]
	(tword)"_tx",
#undef  _1
#define _1	(tword)&start[921]
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
#undef  _4
#define _4	(tword)&start[925]
	(tword)"_tn",
#undef  _3
#define _3	(tword)&start[926]
	1 + (tword)&_tx,
	_4,
#undef  _6
#define _6	(tword)&start[928]
	(tword)"_tq;",
#undef  _5
#define _5	(tword)&start[929]
	(tword)&_tx,
	_6,
	_tn,
	1 + (tword)&_tp,
	1,
// __telem:
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __110	(tword)&labels[140]
	__110,
	__literal,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __101	(tword)&labels[141]
	__101,
// __110:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __107	(tword)&labels[142]
	__107,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __102	(tword)&labels[143]
	__102,
// __107:
	(tword)&_pxs,
	(tword)'$',
	(tword)&alt,
#define __106	(tword)&labels[144]
	__106,
	__number,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __103	(tword)&labels[145]
	__103,
// __106:
	__number,
	(tword)&alt,
#define __105	(tword)&labels[146]
	__105,
#define __tdot	(tword)&labels[147]
	__tdot,
	(tword)&trans,
#define __tpt	(tword)&labels[148]
	1 + __tpt,
	(tword)&tgoto,
#define __104	(tword)&labels[149]
	__104,
// __105:
	__name,
#define __te1	(tword)&labels[150]
	__te1,
	(tword)&salt,
	__done,
#define __te2	(tword)&labels[151]
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
#undef  _2
#define _2	(tword)&start[982]
	(tword)"_tq;",
#undef  _1
#define _1	(tword)&start[983]
	(tword)&_tx,
	_2,
	_tn,
	1 + (tword)&_tp,
	1,
// __te2:
	__tabval,
	__ptt,
	__npt,
	1 + (tword)&trans,
	1 + _1,
#undef  _1
#define _1	(tword)&start[993]
	1 + (tword)&_txs,
	(tword)'0',
#undef  _2
#define _2	(tword)&start[995]
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
#define __112	(tword)&labels[152]
	__112,
	__number,
	(tword)&tgoto,
#define __111	(tword)&labels[153]
	__111,
// __112:
	(tword)&trans,
	1 + _1,
// __111:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __114	(tword)&labels[154]
	__114,
	__list,
#define __targ	(tword)&labels[155]
	__targ,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __113	(tword)&labels[156]
	__113,
// __114:
	__null,
// __113:
	1 + (tword)&trans,
	1 + _2,
// __targ:
	__name,
	(tword)&salt,
#define __115	(tword)&labels[157]
	__115,
	__remote,
	__tbody,
// __115:
	1 + (tword)&succ,
#undef  _1
#define _1	(tword)&start[1029]
	(tword)"_tp;.byte ",
// __tpt:
	(tword)&_tx,
	_1,
	(tword)&_tp,
	2,
	(tword)&_txs,
	(tword)',',
	1 + (tword)&_tp,
	1,
#undef  _1
#define _1	(tword)&start[1038]
	(tword)&_txs,
	(tword)';',
	1 + (tword)&_tp,
	1,
// __literal:
#define __shortlit	(tword)&labels[158]
	__shortlit,
	(tword)&salt,
#define __116	(tword)&labels[159]
	__116,
	__remote,
	__longlit,
	(tword)&trans,
	1 + _1,
// __116:
	1 + (tword)&succ,
#undef  _1
#define _1	(tword)&start[1050]
	(tword)">",
#undef  _3
#define _3	(tword)&start[1051]
	(tword)"s;",
#undef  _4
#define _4	(tword)&start[1052]
	(tword)"';",
#undef  _2
#define _2	(tword)&start[1053]
	(tword)&_tx,
	_3,
	_tn,
	(tword)&_txs,
	(tword)'\'',
	(tword)&_tp,
	1,
	1 + (tword)&_tx,
	_4,
// __shortlit:
	(tword)&ignore,
	__none,
	(tword)&smark,
	(tword)&any,
#define __litch	(tword)&labels[160]
	__litch,
	(tword)&_px,
	_1,
	(tword)&scopy,
	1 + (tword)&trans,
	1 + _2,
#undef  _1
#define _1	(tword)&start[1072]
	(tword)">",
#undef  _3
#define _3	(tword)&start[1073]
	(tword)"\\",
#undef  _4
#define _4	(tword)&start[1074]
	(tword)">",
#undef  _2
#define _2	(tword)&start[1075]
	(tword)&_tx,
	_3,
	1 + (tword)&_tx,
	_4,
#undef  _5
#define _5	(tword)&start[1079]
	(tword)">",
#undef  _7
#define _7	(tword)&start[1080]
	(tword)">;",
#undef  _6
#define _6	(tword)&start[1081]
	(tword)&_txs,
	(tword)'<',
	(tword)&_tp,
	2,
	(tword)&_tp,
	1,
	1 + (tword)&_tx,
	_7,
// __longlit:
	(tword)&ignore,
	__none,
	(tword)&_px,
	_1,
	(tword)&alt,
#define __120	(tword)&labels[161]
	__120,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __117	(tword)&labels[162]
	__117,
// __120:
	__null,
// __117:
#define __litb	(tword)&labels[163]
	__litb,
	(tword)&_px,
	_5,
	1 + (tword)&trans,
	1 + _6,
#undef  _1
#define _1	(tword)&start[1105]
	(tword)"\\",
#undef  _3
#define _3	(tword)&start[1106]
	(tword)"\\\\",
#undef  _2
#define _2	(tword)&start[1107]
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
#define __assignment	(tword)&labels[164]
	__assignment,
	(tword)&salt,
#define __121	(tword)&labels[165]
	__121,
#define __rv	(tword)&labels[166]
	__rv,
// __121:
	1 + (tword)&succ,
#undef  _1
#define _1	(tword)&start[1129]
	(tword)&_tp,
	3,
	_tn,
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
// __assignment:
#define __lv	(tword)&labels[167]
	__lv,
#define __assign	(tword)&labels[168]
	__assign,
	__expr,
	1 + (tword)&trans,
	1 + _1,
#undef  _1
#define _1	(tword)&start[1142]
	(tword)&_tp,
	3,
	_tn,
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
#undef  _2
#define _2	(tword)&start[1150]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __rv:
#define __prime	(tword)&labels[169]
	__prime,
#define __rv1	(tword)&start[1156]
	(tword)&bundle,
#define __infix	(tword)&labels[170]
	__infix,
	(tword)&alt,
#define __125	(tword)&labels[171]
	__125,
	__prime,
	(tword)&trans,
	1 + _1,
	(tword)&salt,
	__rv1,
	(tword)&tgoto,
#define __122	(tword)&labels[172]
	__122,
// __125:
#define __rva	(tword)&labels[173]
	__rva,
	(tword)&alt,
#define __124	(tword)&labels[174]
	__124,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __123	(tword)&labels[175]
	__123,
// __124:
// __123:
// __122:
	1 + (tword)&succ,
#undef  _2
#define _2	(tword)&start[1175]
	(tword)"_t;",
#undef  _3
#define _3	(tword)&start[1176]
	(tword)"alt;",
#undef  _4
#define _4	(tword)&start[1177]
	(tword)"salt;",
#undef  _1
#define _1	(tword)&start[1178]
	(tword)&_tx,
	_2,
	_tn,
	(tword)&_tx,
	_3,
	_tn,
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tp,
	4,
	_tn,
	(tword)&_tx,
	_4,
	_tn,
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
#undef  _1
#define _1	(tword)&start[1217]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
#undef  _2
#define _2	(tword)&start[1222]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
#undef  _3
#define _3	(tword)&start[1227]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tp,
	2,
#undef  _5
#define _5	(tword)&start[1232]
	(tword)"_l;",
#undef  _4
#define _4	(tword)&start[1233]
	(tword)&_tx,
	_5,
	_tn,
	1 + (tword)&_tp,
	1,
// __prime:
	__lv,
	(tword)&alt,
#define __135	(tword)&labels[176]
	__135,
#define __suffix	(tword)&labels[177]
	__suffix,
	(tword)&alt,
	__done,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __126	(tword)&labels[178]
	__126,
// __135:
#define __prefix	(tword)&labels[179]
	__prefix,
	(tword)&alt,
#define __134	(tword)&labels[180]
	__134,
	__lv,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __127	(tword)&labels[181]
	__127,
// __134:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __133	(tword)&labels[182]
	__133,
	__expr,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __130	(tword)&labels[183]
	__130,
// __133:
#define __unary	(tword)&labels[184]
	__unary,
	(tword)&alt,
#define __132	(tword)&labels[185]
	__132,
	__prime,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __131	(tword)&labels[186]
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
#undef  _2
#define _2	(tword)&start[1278]
	(tword)"_l;",
#undef  _1
#define _1	(tword)&start[1279]
	(tword)&_tx,
	_2,
	_tn,
	1 + (tword)&_tp,
	1,
#undef  _4
#define _4	(tword)&start[1284]
	(tword)"_rv",
#undef  _3
#define _3	(tword)&start[1285]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tx,
	_4,
#undef  _6
#define _6	(tword)&start[1290]
	(tword)"_f",
#undef  _5
#define _5	(tword)&start[1291]
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
#define __141	(tword)&labels[187]
	__141,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __136	(tword)&labels[188]
	__136,
// __141:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __140	(tword)&labels[189]
	__140,
	__lv,
	(tword)&_pxs,
	(tword)')',
	(tword)&tgoto,
#define __137	(tword)&labels[190]
	__137,
// __140:
	(tword)&_pxs,
	(tword)'*',
	__prime,
	(tword)&trans,
	1 + _3,
// __137:
// __136:
#define __lv1	(tword)&start[1320]
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
#undef  _2
#define _2	(tword)&start[1332]
	(tword)"_u",
#undef  _1
#define _1	(tword)&start[1333]
	(tword)&_tp,
	1,
	_tn,
	1 + (tword)&_tx,
	_2,
#undef  _4
#define _4	(tword)&start[1338]
	(tword)"_st",
#undef  _3
#define _3	(tword)&start[1339]
	1 + (tword)&_tx,
	_4,
// __assign:
	(tword)&_pxs,
	(tword)'=',
	(tword)&ignore,
	__none,
	__infix,
	(tword)&alt,
#define __143	(tword)&labels[191]
	__143,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __142	(tword)&labels[192]
	__142,
// __143:
	(tword)&trans,
	1 + _3,
// __142:
	1 + (tword)&succ,
#undef  _2
#define _2	(tword)&start[1355]
	1 + (tword)&_pxs,
	(tword)'+',
#undef  _1
#define _1	(tword)&start[1357]
	(tword)&_pxs,
	(tword)'+',
	1 + __not,
	_2,
#undef  _4
#define _4	(tword)&start[1361]
	(tword)"_a",
#undef  _3
#define _3	(tword)&start[1362]
	1 + (tword)&_tx,
	_4,
#undef  _6
#define _6	(tword)&start[1364]
	(tword)"_s",
#undef  _5
#define _5	(tword)&start[1365]
	1 + (tword)&_tx,
	_6,
#undef  _10
#define _10	(tword)&start[1367]
	(tword)"_m",
#undef  _7
#define _7	(tword)&start[1368]
	1 + (tword)&_tx,
	_10,
#undef  _12
#define _12	(tword)&start[1370]
	(tword)"_q",
#undef  _11
#define _11	(tword)&start[1371]
	1 + (tword)&_tx,
	_12,
#undef  _14
#define _14	(tword)&start[1373]
	(tword)"_r",
#undef  _13
#define _13	(tword)&start[1374]
	1 + (tword)&_tx,
	_14,
#undef  _16
#define _16	(tword)&start[1376]
	(tword)"_o",
#undef  _15
#define _15	(tword)&start[1377]
	1 + (tword)&_tx,
	_16,
#undef  _20
#define _20	(tword)&start[1379]
	(tword)"_x",
#undef  _17
#define _17	(tword)&start[1380]
	1 + (tword)&_tx,
	_20,
#undef  _22
#define _22	(tword)&start[1382]
	(tword)"_n",
#undef  _21
#define _21	(tword)&start[1383]
	1 + (tword)&_tx,
	_22,
#undef  _23
#define _23	(tword)&start[1385]
	(tword)"==",
#undef  _25
#define _25	(tword)&start[1386]
	(tword)"_eq",
#undef  _24
#define _24	(tword)&start[1387]
	1 + (tword)&_tx,
	_25,
#undef  _26
#define _26	(tword)&start[1389]
	(tword)"!=",
#undef  _30
#define _30	(tword)&start[1390]
	(tword)"_ne",
#undef  _27
#define _27	(tword)&start[1391]
	1 + (tword)&_tx,
	_30,
#undef  _31
#define _31	(tword)&start[1393]
	(tword)"<=",
#undef  _33
#define _33	(tword)&start[1394]
	(tword)"_le",
#undef  _32
#define _32	(tword)&start[1395]
	1 + (tword)&_tx,
	_33,
#undef  _34
#define _34	(tword)&start[1397]
	(tword)">=",
#undef  _36
#define _36	(tword)&start[1398]
	(tword)"_ge",
#undef  _35
#define _35	(tword)&start[1399]
	1 + (tword)&_tx,
	_36,
#undef  _37
#define _37	(tword)&start[1401]
	(tword)"<<",
#undef  _41
#define _41	(tword)&start[1402]
	(tword)"_sl",
#undef  _40
#define _40	(tword)&start[1403]
	1 + (tword)&_tx,
	_41,
#undef  _43
#define _43	(tword)&start[1405]
	(tword)"_lt",
#undef  _42
#define _42	(tword)&start[1406]
	1 + (tword)&_tx,
	_43,
#undef  _44
#define _44	(tword)&start[1408]
	(tword)">",
#undef  _45
#define _45	(tword)&start[1409]
	(tword)">",
#undef  _47
#define _47	(tword)&start[1410]
	(tword)"_sr",
#undef  _46
#define _46	(tword)&start[1411]
	1 + (tword)&_tx,
	_47,
#undef  _51
#define _51	(tword)&start[1413]
	(tword)"_gt",
#undef  _50
#define _50	(tword)&start[1414]
	1 + (tword)&_tx,
	_51,
// __infix:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'+',
	(tword)&alt,
#define __201	(tword)&labels[193]
	__201,
	__not,
	_1,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __144	(tword)&labels[194]
	__144,
// __201:
	(tword)&_pxs,
	(tword)'-',
	(tword)&alt,
#define __200	(tword)&labels[195]
	__200,
	(tword)&trans,
	1 + _5,
	(tword)&tgoto,
#define __145	(tword)&labels[196]
	__145,
// __200:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __177	(tword)&labels[197]
	__177,
	(tword)&trans,
	1 + _7,
	(tword)&tgoto,
#define __146	(tword)&labels[198]
	__146,
// __177:
	(tword)&_pxs,
	(tword)'/',
	(tword)&alt,
#define __176	(tword)&labels[199]
	__176,
	(tword)&trans,
	1 + _11,
	(tword)&tgoto,
#define __147	(tword)&labels[200]
	__147,
// __176:
	(tword)&_pxs,
	(tword)'%',
	(tword)&alt,
#define __175	(tword)&labels[201]
	__175,
	(tword)&trans,
	1 + _13,
	(tword)&tgoto,
#define __150	(tword)&labels[202]
	__150,
// __175:
	(tword)&_pxs,
	(tword)'|',
	(tword)&alt,
#define __174	(tword)&labels[203]
	__174,
	(tword)&trans,
	1 + _15,
	(tword)&tgoto,
#define __151	(tword)&labels[204]
	__151,
// __174:
	(tword)&_pxs,
	(tword)'^',
	(tword)&alt,
#define __173	(tword)&labels[205]
	__173,
	(tword)&trans,
	1 + _17,
	(tword)&tgoto,
#define __152	(tword)&labels[206]
	__152,
// __173:
	(tword)&_pxs,
	(tword)'&',
	(tword)&alt,
#define __172	(tword)&labels[207]
	__172,
	(tword)&trans,
	1 + _21,
	(tword)&tgoto,
#define __153	(tword)&labels[208]
	__153,
// __172:
	(tword)&_px,
	_23,
	(tword)&alt,
#define __171	(tword)&labels[209]
	__171,
	(tword)&trans,
	1 + _24,
	(tword)&tgoto,
#define __154	(tword)&labels[210]
	__154,
// __171:
	(tword)&_px,
	_26,
	(tword)&alt,
#define __170	(tword)&labels[211]
	__170,
	(tword)&trans,
	1 + _27,
	(tword)&tgoto,
#define __155	(tword)&labels[212]
	__155,
// __170:
	(tword)&_px,
	_31,
	(tword)&alt,
#define __167	(tword)&labels[213]
	__167,
	(tword)&trans,
	1 + _32,
	(tword)&tgoto,
#define __156	(tword)&labels[214]
	__156,
// __167:
	(tword)&_px,
	_34,
	(tword)&alt,
#define __166	(tword)&labels[215]
	__166,
	(tword)&trans,
	1 + _35,
	(tword)&tgoto,
#define __157	(tword)&labels[216]
	__157,
// __166:
	(tword)&_px,
	_37,
	(tword)&alt,
#define __165	(tword)&labels[217]
	__165,
	(tword)&trans,
	1 + _40,
	(tword)&tgoto,
#define __160	(tword)&labels[218]
	__160,
// __165:
	(tword)&_pxs,
	(tword)'<',
	(tword)&alt,
#define __164	(tword)&labels[219]
	__164,
	(tword)&trans,
	1 + _42,
	(tword)&tgoto,
#define __161	(tword)&labels[220]
	__161,
// __164:
	(tword)&_px,
	_44,
	(tword)&_px,
	_45,
	(tword)&alt,
#define __163	(tword)&labels[221]
	__163,
	(tword)&trans,
	1 + _46,
	(tword)&tgoto,
#define __162	(tword)&labels[222]
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
#undef  _2
#define _2	(tword)&start[1546]
	(tword)"_lv",
#undef  _1
#define _1	(tword)&start[1547]
	1 + (tword)&_tx,
	_2,
#undef  _3
#define _3	(tword)&start[1549]
	(tword)"++",
#undef  _5
#define _5	(tword)&start[1550]
	(tword)"_ib",
#undef  _4
#define _4	(tword)&start[1551]
	1 + (tword)&_tx,
	_5,
#undef  _6
#define _6	(tword)&start[1553]
	(tword)"--",
#undef  _10
#define _10	(tword)&start[1554]
	(tword)"_db",
#undef  _7
#define _7	(tword)&start[1555]
	1 + (tword)&_tx,
	_10,
// __prefix:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&_pxs,
	(tword)'&',
	(tword)&alt,
#define __205	(tword)&labels[223]
	__205,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __202	(tword)&labels[224]
	__202,
// __205:
	(tword)&_px,
	_3,
	(tword)&alt,
#define __204	(tword)&labels[225]
	__204,
	(tword)&trans,
	1 + _4,
	(tword)&tgoto,
#define __203	(tword)&labels[226]
	__203,
// __204:
	(tword)&_px,
	_6,
	(tword)&trans,
	1 + _7,
// __203:
// __202:
	1 + (tword)&succ,
#undef  _1
#define _1	(tword)&start[1581]
	(tword)"++",
#undef  _3
#define _3	(tword)&start[1582]
	(tword)"_ia",
#undef  _2
#define _2	(tword)&start[1583]
	1 + (tword)&_tx,
	_3,
#undef  _4
#define _4	(tword)&start[1585]
	(tword)"--",
#undef  _6
#define _6	(tword)&start[1586]
	(tword)"_da",
#undef  _5
#define _5	(tword)&start[1587]
	1 + (tword)&_tx,
	_6,
// __suffix:
	(tword)&smark,
	(tword)&ignore,
	__none,
	(tword)&_px,
	_1,
	(tword)&alt,
#define __207	(tword)&labels[227]
	__207,
	(tword)&trans,
	1 + _2,
	(tword)&tgoto,
#define __206	(tword)&labels[228]
	__206,
// __207:
	(tword)&_px,
	_4,
	(tword)&trans,
	1 + _5,
// __206:
	1 + (tword)&succ,
#undef  _2
#define _2	(tword)&start[1605]
	(tword)"_nt",
#undef  _1
#define _1	(tword)&start[1606]
	1 + (tword)&_tx,
	_2,
#undef  _4
#define _4	(tword)&start[1608]
	(tword)"_ng",
#undef  _3
#define _3	(tword)&start[1609]
	1 + (tword)&_tx,
	_4,
#undef  _6
#define _6	(tword)&start[1611]
	(tword)"_cm",
#undef  _5
#define _5	(tword)&start[1612]
	1 + (tword)&_tx,
	_6,
// __unary:
	(tword)&_pxs,
	(tword)'!',
	(tword)&alt,
#define __213	(tword)&labels[229]
	__213,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __210	(tword)&labels[230]
	__210,
// __213:
	(tword)&_pxs,
	(tword)'-',
	(tword)&alt,
#define __212	(tword)&labels[231]
	__212,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __211	(tword)&labels[232]
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
#define __215	(tword)&labels[233]
	__215,
#define __ccla	(tword)&labels[234]
	__ccla,
#define __cclb	(tword)&labels[235]
	__cclb,
	(tword)&tgoto,
#define __214	(tword)&labels[236]
	__214,
// __215:
	__ccla,
// __214:
	1 + (tword)&octal,
#define __classmask	(tword)&labels[237]
	__classmask,
#undef  _1
#define _1	(tword)&start[1646]
	(tword)"<<",
#undef  _2
#define _2	(tword)&start[1647]
	1,
#undef  _4
#define _4	(tword)&start[1648]
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
#define __cherr	(tword)&labels[238]
	__cherr,
#define __ccl1	(tword)&start[1666]
#define __cclc	(tword)&labels[239]
	__cclc,
	(tword)&_px,
	_4,
	1 + (tword)&salt,
	__ccl1,
#undef  _1
#define _1	(tword)&start[1671]
	(tword)">",
// __cclc:
	(tword)&ignore,
	__none,
#define __ccl3	(tword)&start[1674]
	(tword)&_px,
	_1,
	(tword)&salt,
#define __ccl4	(tword)&labels[240]
	__ccl4,
#define __ccle	(tword)&labels[241]
	__ccle,
	1 + (tword)&salt,
	__ccl3,
#undef  _1
#define _1	(tword)&start[1681]
	(tword)">",
#undef  _3
#define _3	(tword)&start[1682]
	(tword)">",
#undef  _2
#define _2	(tword)&start[1683]
	1 + (tword)&_px,
	_3,
// __ccl4:
	(tword)&_px,
	_1,
	(tword)&salt,
#define __216	(tword)&labels[242]
	__216,
#define __cclx	(tword)&labels[243]
	__cclx,
	(tword)&fail,
// __216:
	__not,
	_2,
	(tword)&salt,
#define __217	(tword)&labels[244]
	__217,
	__ccle,
// __217:
	1 + (tword)&succ,
// __ccle:
	(tword)&tchar,
#define __n	(tword)&labels[245]
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
#define __zeron	(tword)&labels[246]
	__zeron,
#define __ccl5	(tword)&start[1715]
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
#define __testn	(tword)&labels[247]
	__testn,
	1 + (tword)&salt,
	__ccl5,
// __cclx:
	(tword)&_l,
	__nclass,
	(tword)&_da,
	(tword)&_p,
	__zeron,
#define __ccl6	(tword)&start[1738]
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
#undef  _3
#define _3	(tword)&start[1757]
	(tword)"too many char classes",
#undef  _2
#define _2	(tword)&start[1758]
	1 + (tword)&_tx,
	_3,
#undef  _1
#define _1	(tword)&start[1760]
	1 + (tword)&trans,
	1 + _2,
// __cherr:
	1 + (tword)&diag,
	_1,
#undef  _1
#define _1	(tword)&start[1764]
	0,
// __zeron:
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_st,
	1 + (tword)&_p,
#undef  _1
#define _1	(tword)&start[1771]
	0200,
// __testn:
	(tword)&_l,
	__n,
	(tword)&_ib,
	(tword)&_l,
	_1,
	(tword)&_lt,
	1 + (tword)&_t,
#undef  _1
#define _1	(tword)&start[1779]
	0,
#undef  _4
#define _4	(tword)&start[1780]
	(tword)"classtab:",
#undef  _3
#define _3	(tword)&start[1781]
	_tn,
	(tword)&_tx,
	_4,
	1 + _tn,
#undef  _2
#define _2	(tword)&start[1785]
	1 + (tword)&trans,
	1 + _3,
#undef  _6
#define _6	(tword)&start[1787]
	(tword)&_tp,
	1,
	1 + _tn,
#undef  _5
#define _5	(tword)&start[1790]
	(tword)&octal,
#define __w	(tword)&labels[248]
	__w,
	1 + (tword)&trans,
	1 + _6,
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
#define __ptc1	(tword)&start[1803]
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
	_5,
	(tword)&bundle,
	__testn,
	1 + (tword)&salt,
	__ptc1,
// __classmask:
	0,
// __nclass:
	0,
// __classes:
#define __cl1	(tword)&start[1825]
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
#define __cl2	(tword)&start[1841]
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
#define __cl3	(tword)&start[1857]
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
#define __cl4	(tword)&start[1873]
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
#define __cl5	(tword)&start[1889]
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
#define __cl6	(tword)&start[1905]
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
#define __cl7	(tword)&start[1921]
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
#define __cl8	(tword)&start[1937]
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
#undef  _1
#define _1	(tword)&start[1954]
	(tword)&_txs,
	(tword)'_',
	1 + (tword)&_tp,
	1,
#define __create	(tword)&start[1958]
	(tword)&_l,
	__csym,
	(tword)&_ia,
	(tword)&_p,
#define __getcsym	(tword)&start[1962]
	(tword)&octal,
	__csym,
	1 + (tword)&trans,
	1 + _1,
#undef  _2
#define _2	(tword)&start[1966]
	(tword)"__",
#undef  _1
#define _1	(tword)&start[1967]
	(tword)&_tx,
	_2,
	1 + (tword)&_tp,
	1,
// __fref:
	(tword)&_l,
#define __fsym	(tword)&labels[249]
	__fsym,
	(tword)&_ia,
	(tword)&_p,
// __getfref:
	(tword)&octal,
	__fsym,
	1 + (tword)&trans,
	1 + _1,
#undef  _1
#define _1	(tword)&start[1979]
	1,
// __not:
	(tword)&params,
	_1,
	(tword)((tuword)-1<<1),
	(tword)&alt,
	__done,
	1 + (tword)&fail,
#undef  _1
#define _1	(tword)&start[1986]
	1,
#undef  _2
#define _2	(tword)&start[1987]
	(tword)&_tp,
	2,
	_tn,
	1 + (tword)&_tp,
	1,
// __list:
	(tword)&params,
	_1,
	(tword)((tuword)-1<<1),
#define __list1	(tword)&start[1995]
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
#undef  _1
#define _1	(tword)&start[2005]
	1,
// __remote:
	(tword)&params,
	_1,
	__create,
	1 + (tword)&parse,
#define __rem1	(tword)&labels[250]
	__rem1,
	(tword)((tuword)-1<<1),
#undef  _1
#define _1	(tword)&start[2012]
	1,
#undef  _3
#define _3	(tword)&start[2013]
	(tword)"=.",
#undef  _2
#define _2	(tword)&start[2014]
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
#define __digit	(tword)&labels[251]
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
#define __alpha	(tword)&labels[252]
	__alpha,
#undef  _1
#define _1	(tword)&start[2045]
	1,
#undef  _3
#define _3	(tword)&start[2046]
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
#undef  _1
#define _1	(tword)&start[2062]
	2,
#undef  _3
#define _3	(tword)&start[2063]
	0,
// __newtab:
	(tword)&params,
	_1,
	(tword)&_l,
	(tword)((tuword)-2<<1),
	(tword)&_t,
	(tword)&salt,
#define __220	(tword)&labels[253]
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
#undef  _1
#define _1	(tword)&start[2092]
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
#undef  _1
#define _1	(tword)&start[2117]
	(tword)"1 + ",
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
#define __classtab	(tword)&start[2145]
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
#define _pn	(tword)&start[2273]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],	// __1
	(tword)&start[2125],	// __blanks
	(tword)&start[2144],	// __wordsz
	(tword)&start[1825],	// __classes
	(tword)&start[1824],	// __nclass
	(tword)&start[168],	// __comment
	(tword)&start[52],	// __first
	(tword)&start[23],	// __pr2
	(tword)&start[71],	// __error
	(tword)&start[96],	// __line
	(tword)&start[1794],	// __putcharcl
	(tword)&start[164],	// __last
	(tword)&start[2275],	// _tn
	(tword)&start[1971],	// __fref
	(tword)&start[1975],	// __getfref
	(tword)&start[2130],	// __none
	(tword)&start[87],	// __3
	(tword)&start[88],	// __2
	(tword)&start[2115],	// __null
	(tword)&start[133],	// __labels
	(tword)&start[1635],	// __charcl
	(tword)&start[104],	// __7
	(tword)&start[113],	// __4
	(tword)&start[209],	// __statement
	(tword)&start[113],	// __5
	(tword)&start[120],	// __numbers
	(tword)&start[113],	// __6
	(tword)&start[859],	// __trule
	(tword)&start[2028],	// __number
	(tword)&start[1953],	// __done
	(tword)&start[143],	// __label
	(tword)&start[2036],	// __name
	(tword)&start[2124],	// __nil
	(tword)&start[2120],	// __q1
	(tword)&start[2118],	// __xbit
	(tword)&start[2131],	// __csym
	(tword)&start[2047],	// __oldtab
	(tword)&start[2136],	// __dtt
	(tword)&start[2139],	// __pat
	(tword)&start[256],	// __prc
	(tword)&start[230],	// __11
	(tword)&start[270],	// __plst
	(tword)&start[300],	// __tlst
	(tword)&start[233],	// __10
	(tword)&start[715],	// __noelem
	(tword)&start[326],	// __frag
	(tword)&start[243],	// __15
	(tword)&start[254],	// __12
	(tword)&start[722],	// __ifelem
	(tword)&start[252],	// __14
	(tword)&start[254],	// __13
	(tword)&start[2140],	// __npa
	(tword)&start[1992],	// __list
	(tword)&start[278],	// __pident
	(tword)&start[2006],	// __remote
	(tword)&start[2038],	// __ident
	(tword)&start[2064],	// __newtab
	(tword)&start[2143],	// __i
	(tword)&start[395],	// __prule
	(tword)&start[333],	// __17
	(tword)&start[337],	// __16
	(tword)&start[2122],	// __q2
	(tword)&start[2138],	// __sndt
	(tword)&start[2137],	// __ndt
	(tword)&start[440],	// __disj
	(tword)&start[428],	// __23
	(tword)&start[729],	// __ifeasy
	(tword)&start[421],	// __21
	(tword)&start[425],	// __20
	(tword)&start[428],	// __22
	(tword)&start[465],	// __pelem
	(tword)&start[580],	// __pdot
	(tword)&start[453],	// __25
	(tword)&start[708],	// __ishard
	(tword)&start[453],	// __24
	(tword)&start[527],	// __pprim
	(tword)&start[473],	// __31
	(tword)&start[701],	// __iseasy
	(tword)&start[490],	// __26
	(tword)&start[485],	// __30
	(tword)&start[490],	// __27
	(tword)&start[779],	// __special
	(tword)&start[559],	// __32
	(tword)&start[835],	// __rname
	(tword)&start[538],	// __37
	(tword)&start[559],	// __33
	(tword)&start[608],	// __spdot
	(tword)&start[541],	// __34
	(tword)&start[557],	// __36
	(tword)&start[617],	// __parg
	(tword)&start[559],	// __35
	(tword)&start[567],	// __41
	(tword)&start[573],	// __40
	(tword)&start[578],	// __43
	(tword)&start[578],	// __42
	(tword)&start[614],	// __alias
	(tword)&start[602],	// __44
	(tword)&start[2127],	// __letter
	(tword)&start[1980],	// __not
	(tword)&start[622],	// __45
	(tword)&start[643],	// __specparg
	(tword)&start[699],	// __46
	(tword)&start[699],	// __47
	(tword)&start[656],	// __57
	(tword)&start[1089],	// __longlit
	(tword)&start[699],	// __50
	(tword)&start[664],	// __56
	(tword)&start[699],	// __51
	(tword)&start[674],	// __55
	(tword)&start[699],	// __52
	(tword)&start[697],	// __54
	(tword)&start[699],	// __53
	(tword)&start[2133],	// __easy
	(tword)&start[792],	// __70
	(tword)&start[788],	// __60
	(tword)&start[826],	// __61
	(tword)&start[801],	// __67
	(tword)&start[1042],	// __literal
	(tword)&start[826],	// __62
	(tword)&start[809],	// __66
	(tword)&start[826],	// __63
	(tword)&start[1124],	// __expr
	(tword)&start[820],	// __65
	(tword)&start[822],	// __64
	(tword)&start[845],	// __72
	(tword)&start[2093],	// __tabval
	(tword)&start[848],	// __71
	(tword)&start[2141],	// __ptt
	(tword)&start[887],	// __tbody
	(tword)&start[875],	// __73
	(tword)&start[870],	// __74
	(tword)&start[876],	// __tra
	(tword)&start[880],	// __tident
	(tword)&start[2142],	// __npt
	(tword)&start[897],	// __76
	(tword)&start[898],	// __75
	(tword)&start[907],	// __trb
	(tword)&start[934],	// __telem
	(tword)&start[916],	// __100
	(tword)&start[919],	// __77
	(tword)&start[943],	// __110
	(tword)&start[975],	// __101
	(tword)&start[951],	// __107
	(tword)&start[975],	// __102
	(tword)&start[960],	// __106
	(tword)&start[975],	// __103
	(tword)&start[968],	// __105
	(tword)&start[1001],	// __tdot
	(tword)&start[1030],	// __tpt
	(tword)&start[975],	// __104
	(tword)&start[976],	// __te1
	(tword)&start[988],	// __te2
	(tword)&start[1008],	// __112
	(tword)&start[1010],	// __111
	(tword)&start[1020],	// __114
	(tword)&start[1023],	// __targ
	(tword)&start[1021],	// __113
	(tword)&start[1028],	// __115
	(tword)&start[1062],	// __shortlit
	(tword)&start[1049],	// __116
	(tword)&start[2129],	// __litch
	(tword)&start[1099],	// __120
	(tword)&start[1100],	// __117
	(tword)&start[1113],	// __litb
	(tword)&start[1137],	// __assignment
	(tword)&start[1128],	// __121
	(tword)&start[1155],	// __rv
	(tword)&start[1299],	// __lv
	(tword)&start[1341],	// __assign
	(tword)&start[1238],	// __prime
	(tword)&start[1416],	// __infix
	(tword)&start[1167],	// __125
	(tword)&start[1174],	// __122
	(tword)&start[1207],	// __rva
	(tword)&start[1174],	// __124
	(tword)&start[1174],	// __123
	(tword)&start[1248],	// __135
	(tword)&start[1589],	// __suffix
	(tword)&start[1277],	// __126
	(tword)&start[1557],	// __prefix
	(tword)&start[1256],	// __134
	(tword)&start[1277],	// __127
	(tword)&start[1265],	// __133
	(tword)&start[1277],	// __130
	(tword)&start[1614],	// __unary
	(tword)&start[1273],	// __132
	(tword)&start[1277],	// __131
	(tword)&start[1306],	// __141
	(tword)&start[1320],	// __136
	(tword)&start[1315],	// __140
	(tword)&start[1320],	// __137
	(tword)&start[1352],	// __143
	(tword)&start[1354],	// __142
	(tword)&start[1429],	// __201
	(tword)&start[1545],	// __144
	(tword)&start[1437],	// __200
	(tword)&start[1545],	// __145
	(tword)&start[1445],	// __177
	(tword)&start[1545],	// __146
	(tword)&start[1453],	// __176
	(tword)&start[1545],	// __147
	(tword)&start[1461],	// __175
	(tword)&start[1545],	// __150
	(tword)&start[1469],	// __174
	(tword)&start[1545],	// __151
	(tword)&start[1477],	// __173
	(tword)&start[1545],	// __152
	(tword)&start[1485],	// __172
	(tword)&start[1545],	// __153
	(tword)&start[1493],	// __171
	(tword)&start[1545],	// __154
	(tword)&start[1501],	// __170
	(tword)&start[1545],	// __155
	(tword)&start[1509],	// __167
	(tword)&start[1545],	// __156
	(tword)&start[1517],	// __166
	(tword)&start[1545],	// __157
	(tword)&start[1525],	// __165
	(tword)&start[1545],	// __160
	(tword)&start[1533],	// __164
	(tword)&start[1545],	// __161
	(tword)&start[1543],	// __163
	(tword)&start[1545],	// __162
	(tword)&start[1568],	// __205
	(tword)&start[1580],	// __202
	(tword)&start[1576],	// __204
	(tword)&start[1580],	// __203
	(tword)&start[1600],	// __207
	(tword)&start[1604],	// __206
	(tword)&start[1622],	// __213
	(tword)&start[1634],	// __210
	(tword)&start[1630],	// __212
	(tword)&start[1634],	// __211
	(tword)&start[1643],	// __215
	(tword)&start[1649],	// __ccla
	(tword)&start[1714],	// __cclb
	(tword)&start[1644],	// __214
	(tword)&start[1823],	// __classmask
	(tword)&start[1762],	// __cherr
	(tword)&start[1672],	// __cclc
	(tword)&start[1685],	// __ccl4
	(tword)&start[1697],	// __ccle
	(tword)&start[1691],	// __216
	(tword)&start[1733],	// __cclx
	(tword)&start[1696],	// __217
	(tword)&start[2135],	// __n
	(tword)&start[1765],	// __zeron
	(tword)&start[1772],	// __testn
	(tword)&start[2134],	// __w
	(tword)&start[2132],	// __fsym
	(tword)&start[2022],	// __rem1
	(tword)&start[2126],	// __digit
	(tword)&start[2128],	// __alpha
	(tword)&start[2079],	// __220
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
