// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2020, Andriy Makukha, 2-clause BSD License.

#define SRC_LANGUAGE "octal number"
#define DST_LANGUAGE "decimal number"

const tword labels[];

// Driving table for a sample program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	1 + (tword)&parse,
#define __oct2dec  (tword)&labels[1]
	__oct2dec,
#undef _1
#define _1         (tword)&start[3]
	(tword)&_tp,
	1,
#define _tn        (tword)&labels[2]
	1 + _tn,
// __oct2dec:
#define __integer  (tword)&labels[3]
	__integer,
#define __n        (tword)&labels[4]
	__n,
	(tword)&decimal,
	__n,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[12]
	1,
#undef _2
#define _2         (tword)&start[13]
	1,
#undef _3
#define _3         (tword)&start[14]
	0,
#undef _4
#define _4         (tword)&start[15]
	010,
// __integer:
	(tword)&params,
	_1,
	(tword)&push,
	_2,
#define __i        (tword)&labels[5]
	__i,
	(tword)&_l,
	(tword)((tuword)-1<<1),
	(tword)&_l,
	_3,
	(tword)&_st,
	(tword)&_p,
#define __inta     (tword)&labels[6]
	__inta,
#define __int1     (tword)&start[28]
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
#define _1         (tword)&start[43]
	070,
#undef _3
#define _3         (tword)&start[44]
	060,
#undef _4
#define _4         (tword)&start[45]
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
// __n:
	0,
// __i:
	0,
#define __classtab (tword)&start[66]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[194]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[6],       // __oct2dec
	(tword)&start[196],     // _tn
	(tword)&start[16],      // __integer
	(tword)&start[64],      // __n
	(tword)&start[65],      // __i
	(tword)&start[46],      // __inta
};

// Used builtins:
//   _a
//   _ge
//   _l
//   _lt
//   _m
//   _p
//   _pxs
//   _s
//   _st
//   _t
//   _tp
//   _txs
//   _u
//   decimal
//   params
//   parse
//   push
//   salt
//   tchar
//   trans
