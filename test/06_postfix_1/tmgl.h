// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

#define SRC_LANGUAGE "parenthesized infix"
//#define DST_LANGUAGE "Polish postfix"

const tword labels[];

// Driving table for a sample program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	(tword)&_l,
#define __alpha    (tword)&labels[1]
	__alpha,
	(tword)&_l,
#define __letter   (tword)&labels[2]
	__letter,
	(tword)&_l,
#define __digit    (tword)&labels[3]
	__digit,
	(tword)&_o,
	(tword)&_st,
	(tword)&_p,
	1 + (tword)&parse,
#define __expr     (tword)&labels[4]
	__expr,
#undef _1
#define _1         (tword)&start[12]
	(tword)&_tp,
	3,
	(tword)&_tp,
	1,
	1 + (tword)&_tp,
	2,
// __expr:
	(tword)&_pxs,
	(tword)'(',
	(tword)&alt,
#define __exp1     (tword)&labels[5]
	__exp1,
	__expr,
#define __operator (tword)&labels[6]
	__operator,
	__expr,
	(tword)&_pxs,
	(tword)')',
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[29]
	(tword)"LOAD ",
#undef _1
#define _1         (tword)&start[30]
	(tword)&_tx,
	_2,
	(tword)&_tp,
	1,
	1 + (tword)&_txs,
	(tword)' ',
// __exp1:
#define __ident    (tword)&labels[7]
	__ident,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[39]
	(tword)"ADD ",
#undef _1
#define _1         (tword)&start[40]
	1 + (tword)&_tx,
	_2,
// __operator:
#define __op0      (tword)&start[42]
	(tword)&_pxs,
	(tword)'+',
	(tword)&alt,
#define __op1      (tword)&labels[8]
	__op1,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[48]
	(tword)"SUB ",
#undef _1
#define _1         (tword)&start[49]
	1 + (tword)&_tx,
	_2,
// __op1:
	(tword)&_pxs,
	(tword)'-',
	(tword)&alt,
#define __op2      (tword)&labels[9]
	__op2,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[57]
	(tword)"MPY ",
#undef _1
#define _1         (tword)&start[58]
	1 + (tword)&_tx,
	_2,
// __op2:
	(tword)&_pxs,
	(tword)'*',
	(tword)&alt,
#define __op3      (tword)&labels[10]
	__op3,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[66]
	(tword)"DIV ",
#undef _1
#define _1         (tword)&start[67]
	1 + (tword)&_tx,
	_2,
// __op3:
	(tword)&_pxs,
	(tword)'/',
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[73]
	1 + (tword)&_tp,
	1,
// __ident:
	(tword)&smark,
	(tword)&any,
	__letter,
	(tword)&string,
	__alpha,
	(tword)&scopy,
	1 + (tword)&trans,
	1 + _1,
// __letter:
	1,
// __digit:
	2,
// __alpha:
	0,
#define __classtab (tword)&start[86]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	2,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	0,
	0,
	0,
	0,
	0,
	0,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[214]
	1 + (tword)&_pxs,
	(tword)'\n',
#define _tn        (tword)&start[216]
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[85],      // __alpha
	(tword)&start[83],      // __letter
	(tword)&start[84],      // __digit
	(tword)&start[18],      // __expr
	(tword)&start[36],      // __exp1
	(tword)&start[42],      // __operator
	(tword)&start[75],      // __ident
	(tword)&start[51],      // __op1
	(tword)&start[60],      // __op2
	(tword)&start[69],      // __op3
};

// Used builtins:
//   _l
//   _o
//   _p
//   _pxs
//   _st
//   _tp
//   _tx
//   _txs
//   alt
//   any
//   parse
//   scopy
//   smark
//   string
//   trans
