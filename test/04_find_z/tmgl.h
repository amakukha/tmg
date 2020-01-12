// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

#define SRC_LANGUAGE "findZ"
//#define DST_LANGUAGE "Zfound"

const tword labels[];

// Driving table for a sample program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	1 + (tword)&parse,
#define __z        (tword)&labels[1]
	__z,
#undef _2
#define _2         (tword)&start[3]
	(tword)"Z found",
#undef _1
#define _1         (tword)&start[4]
	(tword)&_tx,
	_2,
#define _tn        (tword)&labels[2]
	1 + _tn,
// __z:
	(tword)&_pxs,
	(tword)'Z',
	(tword)&alt,
#define __nz       (tword)&labels[3]
	__nz,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[13]
	(tword)"Z not found",
#undef _1
#define _1         (tword)&start[14]
	(tword)&_tx,
	_2,
	1 + _tn,
// __nz:
	1 + (tword)&trans,
	1 + _1,
#define __classtab (tword)&start[19]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[147]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[7],       // __z
	(tword)&start[149],     // _tn
	(tword)&start[17],      // __nz
};

// Used builtins:
//   _pxs
//   _tx
//   _txs
//   alt
//   parse
//   trans
