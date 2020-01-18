#define SRC_LANGUAGE "no input"
#define DST_LANGUAGE "test"

const tword labels[];

// Driving table for the program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	(tword)&parse,
#define __bits     (tword)&labels[1]
	__bits,
	1 + (tword)&parse,
#define __pointers (tword)&labels[2]
	__pointers,
#undef _2
#define _2         (tword)&start[5]
	(tword)"Word size: ",
#undef _1
#define _1         (tword)&start[6]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
#define _tn        (tword)&labels[3]
	1 + _tn,
// __bits:
	(tword)&_l,
#define __n        (tword)&labels[4]
	__n,
	(tword)&_l,
#define __b        (tword)&labels[5]
	__b,
	(tword)&_lv,
	(tword)&_l,
#define __a        (tword)&labels[6]
	__a,
	(tword)&_lv,
	(tword)&_s,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__n,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[26]
	(tword)"b=",
#undef _3
#define _3         (tword)&start[27]
	(tword)", a=",
#undef _1
#define _1         (tword)&start[28]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	2,
	(tword)&_tx,
	_3,
	(tword)&_tp,
	1,
	1 + _tn,
// __pointers:
	(tword)&_l,
#define __p        (tword)&labels[7]
	__p,
	(tword)&_l,
	__b,
	(tword)&_lv,
	(tword)&_st,
	(tword)&_p,
	(tword)&_l,
	__n,
	(tword)&_l,
	__p,
	(tword)&_rv,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__n,
	(tword)&_l,
	__p,
	(tword)&_l,
	__a,
	(tword)&_lv,
	(tword)&_st,
	(tword)&_p,
	(tword)&_l,
	__n,
	(tword)&_l,
	__p,
	(tword)&_rv,
	(tword)&_st,
	(tword)&_p,
	(tword)&decimal,
	__n,
	1 + (tword)&trans,
	1 + _1,
// __a:
	1,
// __b:
	2,
// __n:
	0,
// __p:
	0,
#define __classtab (tword)&start[75]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[203]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[11],      // __bits
	(tword)&start[37],      // __pointers
	(tword)&start[205],     // _tn
	(tword)&start[73],      // __n
	(tword)&start[72],      // __b
	(tword)&start[71],      // __a
	(tword)&start[74],      // __p
};

// Used builtins:
//   _l
//   _lv
//   _p
//   _pxs
//   _rv
//   _s
//   _st
//   _tp
//   _tx
//   _txs
//   decimal
//   parse
//   trans
