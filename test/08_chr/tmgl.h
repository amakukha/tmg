// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2020, Andriy Makukha, 2-clause BSD License.

#define SRC_LANGUAGE "char"
#define DST_LANGUAGE "ASCII value"

const tword labels[];

// Driving table for a sample program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	1 + (tword)&parse,
#define __chr      (tword)&labels[1]
	__chr,
#undef _2
#define _2         (tword)&start[3]
	(tword)"ASCII value of the first character: ",
#undef _1
#define _1         (tword)&start[4]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
#define _tn        (tword)&labels[2]
	1 + _tn,
// __chr:
	(tword)&tchar,
#define __i        (tword)&labels[3]
	__i,
	(tword)&alt,
#define __empty    (tword)&labels[4]
	__empty,
	(tword)&decimal,
	__i,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[17]
	(tword)"Empty input",
#undef _1
#define _1         (tword)&start[18]
	(tword)&_tx,
	_2,
	1 + _tn,
// __empty:
	1 + (tword)&trans,
	1 + _1,
// __i:
	0,
#define __classtab (tword)&start[24]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[152]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[9],       // __chr
	(tword)&start[154],     // _tn
	(tword)&start[23],      // __i
	(tword)&start[21],      // __empty
};

// Used builtins:
//   _pxs
//   _tp
//   _tx
//   _txs
//   alt
//   decimal
//   parse
//   tchar
//   trans
