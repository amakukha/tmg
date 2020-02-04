#define SRC_LANGUAGE "anbncn"
#define DST_LANGUAGE "good/bad"

const tword labels[];

// Driving table for the program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	1 + (tword)&parse,
#define __detect   (tword)&labels[1]
	__detect,
#undef _2
#define _2         (tword)&start[3]
	(tword)"Good",
#undef _1
#define _1         (tword)&start[4]
	(tword)&_tx,
	_2,
#define _tn        (tword)&labels[2]
	1 + _tn,
#undef _4
#define _4         (tword)&start[7]
	(tword)"Bad",
#undef _3
#define _3         (tword)&start[8]
	(tword)&_tx,
	_4,
	1 + _tn,
// __detect:
#define __anbncn   (tword)&labels[3]
	__anbncn,
	(tword)&alt,
#define __3        (tword)&labels[4]
	__3,
	(tword)&trans,
	1 + _1,
	(tword)&tgoto,
#define __2        (tword)&labels[5]
	__2,
// __3:
	(tword)&trans,
	1 + _3,
// __2:
	1 + (tword)&succ,
#undef _1
#define _1         (tword)&start[21]
	1 + (tword)&_pxs,
	(tword)'b',
// __anbncn:
	(tword)&_pxs,
	(tword)'a',
#define __recurs   (tword)&labels[6]
	__recurs,
	_1,
	1 + (tword)&_pxs,
	(tword)'c',
#undef _1
#define _1         (tword)&start[29]
	1,
#undef _2
#define _2         (tword)&start[30]
	(tword)&_pxs,
	(tword)'b',
	1 + (tword)((tuword)-1<<1),
// __recurs:
	(tword)&params,
	_1,
	(tword)&_pxs,
	(tword)'a',
	(tword)&alt,
#define __5        (tword)&labels[7]
	__5,
	__recurs,
	_2,
	(tword)&_pxs,
	(tword)'c',
	(tword)&tgoto,
#define __4        (tword)&labels[8]
	__4,
// __5:
	(tword)((tuword)-1<<1),
// __4:
	1 + (tword)&succ,
#define __classtab (tword)&start[47]
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
#define _pn        (tword)&start[175]
	1 + (tword)&_pxs,
	(tword)'\n',
// _tn:
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[11],      // __detect
	(tword)&start[177],     // _tn
	(tword)&start[23],      // __anbncn
	(tword)&start[18],      // __3
	(tword)&start[20],      // __2
	(tword)&start[33],      // __recurs
	(tword)&start[45],      // __5
	(tword)&start[46],      // __4
};

// Used builtins:
//   _pxs
//   _tx
//   _txs
//   alt
//   params
//   parse
//   succ
//   tgoto
//   trans
