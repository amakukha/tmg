#define SRC_LANGUAGE "decimal, base"
#define DST_LANGUAGE "representation in base"

const tword labels[];

// Driving table for the program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	1 + (tword)&parse,
#define __int2base (tword)&labels[1]
	__int2base,
#undef _2
#define _2         (tword)&start[3]
	(tword)" in base ",
#undef _3
#define _3         (tword)&start[4]
	(tword)" is ",
#undef _1
#define _1         (tword)&start[5]
	(tword)&_tp,
	3,
	(tword)&_tx,
	_2,
	(tword)&_tp,
	2,
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
#define _tn        (tword)&labels[2]
	1 + _tn,
// __int2base:
#define __readint  (tword)&labels[3]
	__readint,
#define __n        (tword)&labels[4]
	__n,
	__readint,
#define __b        (tword)&labels[5]
	__b,
	(tword)&decimal,
	__n,
	(tword)&decimal,
	__b,
#define __tobase   (tword)&labels[6]
	__tobase,
	__n,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[28]
	1,
#undef _2
#define _2         (tword)&start[29]
	1,
#undef _3
#define _3         (tword)&start[30]
	0,
#undef _4
#define _4         (tword)&start[31]
	(tword)'\n',
// __readint:
	(tword)&params,
	_1,
	(tword)&push,
	_2,
#define __i        (tword)&labels[7]
	__i,
	(tword)&string,
#define __space    (tword)&labels[8]
	__space,
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	_3,
	(tword)&_st,
	(tword)&_p,
#define __inta     (tword)&labels[9]
	__inta,
#define __int1     (tword)&start[46]
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	_4,
	(tword)&_m,
	(tword)&_l,
	__i,
	(tword)&_a,
	(tword)&_st,
	(tword)&_p,
	__inta,
	1 + (tword)&salt,
	__int1,
#undef _1
#define _1         (tword)&start[61]
	072,
#undef _3
#define _3         (tword)&start[62]
	060,
#undef _4
#define _4         (tword)&start[63]
	0,
// __inta:
	(tword)&tchar,
	__i,
	(tword)&_l,
	__i,
	(tword)&_l,
	_1,
	(tword)&_lt,
	(tword)&_t,
	(tword)&_l,
	__i,
	(tword)&_l,
	_3,
	(tword)&_s,
	(tword)&_u,
	(tword)&_l,
	_4,
	(tword)&_ge,
	1 + (tword)&_t,
#undef _1
#define _1         (tword)&start[82]
	1,
#undef _2
#define _2         (tword)&start[83]
	2,
#undef _4
#define _4         (tword)&start[84]
	0,
#undef _6
#define _6         (tword)&start[85]
	1 + (tword)&_txs,
	(tword)'0',
#undef _10
#define _10        (tword)&start[87]
	1,
#undef _12
#define _12        (tword)&start[88]
	1 + (tword)&_txs,
	(tword)'1',
#undef _14
#define _14        (tword)&start[90]
	2,
#undef _16
#define _16        (tword)&start[91]
	1 + (tword)&_txs,
	(tword)'2',
#undef _20
#define _20        (tword)&start[93]
	3,
#undef _22
#define _22        (tword)&start[94]
	1 + (tword)&_txs,
	(tword)'3',
#undef _24
#define _24        (tword)&start[96]
	4,
#undef _26
#define _26        (tword)&start[97]
	1 + (tword)&_txs,
	(tword)'4',
#undef _30
#define _30        (tword)&start[99]
	5,
#undef _32
#define _32        (tword)&start[100]
	1 + (tword)&_txs,
	(tword)'5',
#undef _34
#define _34        (tword)&start[102]
	6,
#undef _36
#define _36        (tword)&start[103]
	1 + (tword)&_txs,
	(tword)'6',
#undef _40
#define _40        (tword)&start[105]
	7,
#undef _42
#define _42        (tword)&start[106]
	1 + (tword)&_txs,
	(tword)'7',
#undef _44
#define _44        (tword)&start[108]
	(tword)&_tp,
	1,
	1 + (tword)&_tp,
	2,
// __tobase:
	(tword)&params,
	_1,
	(tword)&push,
	_2,
#define __m        (tword)&labels[10]
	__m,
	__i,
	(tword)&_l,
	__i,
	(tword)&_l,
	__m,
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_st,
	(tword)&_l,
	__b,
	(tword)&_r,
	(tword)&_st,
	(tword)&_p,
	(tword)&_l,
	__i,
	(tword)&_l,
	_4,
	(tword)&_eq,
	(tword)&_t,
	(tword)&alt,
#define __17       (tword)&labels[11]
	__17,
	(tword)&trans,
	1 + _6,
	(tword)&tgoto,
#define __2        (tword)&labels[12]
	__2,
// __17:
	(tword)&_l,
	__i,
	(tword)&_l,
	_10,
	(tword)&_eq,
	(tword)&_t,
	(tword)&alt,
#define __16       (tword)&labels[13]
	__16,
	(tword)&trans,
	1 + _12,
	(tword)&tgoto,
#define __3        (tword)&labels[14]
	__3,
// __16:
	(tword)&_l,
	__i,
	(tword)&_l,
	_14,
	(tword)&_eq,
	(tword)&_t,
	(tword)&alt,
#define __15       (tword)&labels[15]
	__15,
	(tword)&trans,
	1 + _16,
	(tword)&tgoto,
#define __4        (tword)&labels[16]
	__4,
// __15:
	(tword)&_l,
	__i,
	(tword)&_l,
	_20,
	(tword)&_eq,
	(tword)&_t,
	(tword)&alt,
#define __14       (tword)&labels[17]
	__14,
	(tword)&trans,
	1 + _22,
	(tword)&tgoto,
#define __5        (tword)&labels[18]
	__5,
// __14:
	(tword)&_l,
	__i,
	(tword)&_l,
	_24,
	(tword)&_eq,
	(tword)&_t,
	(tword)&alt,
#define __13       (tword)&labels[19]
	__13,
	(tword)&trans,
	1 + _26,
	(tword)&tgoto,
#define __6        (tword)&labels[20]
	__6,
// __13:
	(tword)&_l,
	__i,
	(tword)&_l,
	_30,
	(tword)&_eq,
	(tword)&_t,
	(tword)&alt,
#define __12       (tword)&labels[21]
	__12,
	(tword)&trans,
	1 + _32,
	(tword)&tgoto,
#define __7        (tword)&labels[22]
	__7,
// __12:
	(tword)&_l,
	__i,
	(tword)&_l,
	_34,
	(tword)&_eq,
	(tword)&_t,
	(tword)&alt,
#define __11       (tword)&labels[23]
	__11,
	(tword)&trans,
	1 + _36,
	(tword)&tgoto,
#define __10       (tword)&labels[24]
	__10,
// __11:
	(tword)&_l,
	__i,
	(tword)&_l,
	_40,
	(tword)&_eq,
	(tword)&_t,
	(tword)&trans,
	1 + _42,
// __10:
// __7:
// __6:
// __5:
// __4:
// __3:
// __2:
	(tword)&_l,
	__m,
	(tword)&_l,
	__b,
	(tword)&_q,
	(tword)&_u,
	(tword)&_t,
	(tword)&alt,
#define __done     (tword)&labels[25]
	__done,
	__tobase,
	__m,
	1 + (tword)&trans,
	1 + _44,
// __done:
	1 + (tword)&succ,
// __n:
	0,
// __b:
	0,
// __i:
	0,
// __m:
	0,
// __space:
	1,
#define __classtab (tword)&start[241]
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
	1,
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
#define _pn        (tword)&start[369]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[16],      // __int2base
	(tword)&start[371],     // _tn
	(tword)&start[32],      // __readint
	(tword)&start[236],     // __n
	(tword)&start[237],     // __b
	(tword)&start[112],     // __tobase
	(tword)&start[238],     // __i
	(tword)&start[240],     // __space
	(tword)&start[64],      // __inta
	(tword)&start[239],     // __m
	(tword)&start[142],     // __17
	(tword)&start[222],     // __2
	(tword)&start[154],     // __16
	(tword)&start[222],     // __3
	(tword)&start[166],     // __15
	(tword)&start[222],     // __4
	(tword)&start[178],     // __14
	(tword)&start[222],     // __5
	(tword)&start[190],     // __13
	(tword)&start[222],     // __6
	(tword)&start[202],     // __12
	(tword)&start[222],     // __7
	(tword)&start[214],     // __11
	(tword)&start[222],     // __10
	(tword)&start[235],     // __done
};

// Used builtins:
//   _a
//   _eq
//   _ge
//   _l
//   _lt
//   _m
//   _p
//   _pxs
//   _q
//   _r
//   _s
//   _st
//   _t
//   _tp
//   _tx
//   _txs
//   _u
//   alt
//   decimal
//   params
//   parse
//   push
//   salt
//   string
//   succ
//   tchar
//   tgoto
//   trans
