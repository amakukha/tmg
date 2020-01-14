const tword labels[];

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	1 + (tword)&parse,
#define __mult     (tword)&labels[1]
	__mult,
#undef _1
#define _1         (tword)&start[3]
	023,
#undef _2
#define _2         (tword)&start[4]
	0777,
#undef _3
#define _3         (tword)&start[5]
	07654,
#undef _4
#define _4         (tword)&start[6]
	011,
#undef _5
#define _5         (tword)&start[7]
	(tword)&_tp,
	4,
#define _tn        (tword)&labels[2]
	_tn,
	(tword)&_tp,
	3,
	_tn,
	(tword)&_tp,
	2,
	_tn,
	(tword)&_tp,
	1,
	1 + _tn,
// __mult:
	(tword)&tchar,
#define __i        (tword)&labels[3]
	__i,
	(tword)&alt,
#define __empty    (tword)&labels[4]
	__empty,
	(tword)&_l,
#define __j        (tword)&labels[5]
	__j,
	(tword)&_l,
	__i,
	(tword)&_l,
	_1,
	(tword)&_m,
	(tword)&_st,
	(tword)&_p,
	(tword)&_l,
#define __k        (tword)&labels[6]
	__k,
	(tword)&_l,
	__i,
	(tword)&_l,
	_2,
	(tword)&_m,
	(tword)&_st,
	(tword)&_p,
	(tword)&_l,
#define __l        (tword)&labels[7]
	__l,
	(tword)&_l,
	_3,
	(tword)&_l,
	__i,
	(tword)&_m,
	(tword)&_st,
	(tword)&_p,
	(tword)&_l,
	__i,
	(tword)&_l,
	_4,
	(tword)&_m,
	(tword)&_u,
	(tword)&_p,
	(tword)&decimal,
	__i,
	(tword)&decimal,
	__j,
	(tword)&decimal,
	__k,
	(tword)&decimal,
	__l,
	1 + (tword)&trans,
	1 + _5,
// __empty:
	1 + (tword)&succ,
// __i:
	0,
// __j:
	0,
// __k:
	0,
// __l:
	0,
#define __classtab (tword)&start[72]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[200]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[19],      // __mult
	(tword)&start[202],     // _tn
	(tword)&start[68],      // __i
	(tword)&start[67],      // __empty
	(tword)&start[69],      // __j
	(tword)&start[70],      // __k
	(tword)&start[71],      // __l
};

// Used builtins:
//   _l
//   _m
//   _p
//   _pxs
//   _st
//   _tp
//   _txs
//   _u
//   alt
//   decimal
//   parse
//   succ
//   tchar
//   trans
