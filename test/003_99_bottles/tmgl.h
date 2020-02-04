// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

#define SRC_LANGUAGE "no input"
//#define DST_LANGUAGE "99bottles"

const tword labels[];

// Driving table for a sample program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
#undef _1
#define _1         (tword)&start[1]
	1,
// __1:
#define __loop     (tword)&start[2]
	(tword)&parse,
#define __line1    (tword)&labels[1]
	__line1,
	(tword)&_l,
#define __n        (tword)&labels[2]
	__n,
	(tword)&_db,
	(tword)&_p,
	(tword)&parse,
#define __line2    (tword)&labels[3]
	__line2,
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_ge,
	(tword)&_t,
	(tword)&alt,
#define __done     (tword)&labels[4]
	__done,
	1 + __loop,
#undef _2
#define _2         (tword)&start[19]
	(tword)" on the wall, ",
#undef _1
#define _1         (tword)&start[20]
	(tword)&_tp,
	1,
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	(tword)&_txs,
	(tword)'.',
#define _tn        (tword)&labels[5]
	1 + _tn,
// __line1:
#define __beer     (tword)&labels[6]
	__beer,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[32]
	(tword)"If one of those bottles should happen to fall, ",
#undef _3
#define _3         (tword)&start[33]
	(tword)" on the wall.",
#undef _1
#define _1         (tword)&start[34]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	(tword)&_tx,
	_3,
	1 + _tn,
// __line2:
	__beer,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[44]
	(tword)" bottle",
#undef _3
#define _3         (tword)&start[45]
	(tword)" of beer",
#undef _1
#define _1         (tword)&start[46]
	(tword)&_tp,
	2,
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	1 + (tword)&_tx,
	_3,
// __beer:
#define __left     (tword)&labels[7]
	__left,
#define __plural   (tword)&labels[8]
	__plural,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[58]
	1,
#undef _3
#define _3         (tword)&start[59]
	1 + (tword)&_tp,
	1,
#undef _5
#define _5         (tword)&start[61]
	(tword)"no more",
#undef _4
#define _4         (tword)&start[62]
	1 + (tword)&_tx,
	_5,
// __left:
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_ge,
	(tword)&_t,
	(tword)&alt,
#define __3        (tword)&labels[9]
	__3,
	(tword)&decimal,
	__n,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __2        (tword)&labels[10]
	__2,
// __3:
	(tword)&trans,
	1 + _4,
// __2:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[81]
	1,
#undef _3
#define _3         (tword)&start[82]
	1 + (tword)&_txs,
	(tword)'s',
#undef _4
#define _4         (tword)&start[84]
	1 + (tword)&generate,
// __plural:
	(tword)&_l,
	__n,
	(tword)&_l,
	_1,
	(tword)&_ne,
	(tword)&_t,
	(tword)&alt,
#define __5        (tword)&labels[11]
	__5,
	(tword)&trans,
	1 + _3,
	(tword)&tgoto,
#define __4        (tword)&labels[12]
	__4,
// __5:
	(tword)&trans,
	1 + _4,
// __4:
	1 + (tword)&succ,
// __done:
	1 + (tword)&succ,
// __n:
	99,
#define __classtab (tword)&start[102]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[230]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[2],       // __1
	(tword)&start[29],      // __line1
	(tword)&start[101],     // __n
	(tword)&start[41],      // __line2
	(tword)&start[100],     // __done
	(tword)&start[232],     // _tn
	(tword)&start[54],      // __beer
	(tword)&start[64],      // __left
	(tword)&start[85],      // __plural
	(tword)&start[78],      // __3
	(tword)&start[80],      // __2
	(tword)&start[97],      // __5
	(tword)&start[99],      // __4
};
