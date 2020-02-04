// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2020, Andriy Makukha, 2-clause BSD License.

#define SRC_LANGUAGE "text"
#define DST_LANGUAGE "aliased text"

const tword labels[];

// Driving table for a sample program

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __program  (tword)&start[1]
	(tword)&table,
#define __t        (tword)&labels[1]
	__t,
	1 + (tword)&parse,
#define __text     (tword)&labels[2]
	__text,
#undef _1
#define _1         (tword)&start[5]
	1 + (tword)&_tp,
	1,
#undef _2
#define _2         (tword)&start[7]
	(tword)&_tp,
	3,
	(tword)&_tp,
	2,
	1 + (tword)&_tp,
	1,
// __text:
#define __space    (tword)&labels[3]
	__space,
	(tword)&trans,
	1 + _1,
#define __text1    (tword)&start[16]
#define __ident    (tword)&labels[4]
	__ident,
	(tword)&alt,
#define __done     (tword)&labels[5]
	__done,
	__space,
	(tword)&trans,
	1 + _2,
	(tword)&bundle,
	1 + (tword)&salt,
	__text1,
// __done:
	1 + (tword)&succ,
// __ident:
	(tword)&smark,
	(tword)&any,
#define __letter   (tword)&labels[6]
	__letter,
	(tword)&string,
#define __alpha    (tword)&labels[7]
	__alpha,
#define __install  (tword)&labels[8]
	1 + __install,
#undef _1
#define _1         (tword)&start[32]
	1 + (tword)&_tp,
	1,
// __space:
	(tword)&smark,
	(tword)&string,
#define __noletter (tword)&labels[9]
	__noletter,
	(tword)&scopy,
	1 + (tword)&trans,
	1 + _1,
#undef _2
#define _2         (tword)&start[40]
	(tword)&_txs,
	(tword)'x',
	1 + (tword)&_tp,
	1,
// __install:
	(tword)&enter,
	__t,
#define __i        (tword)&labels[10]
	__i,
	(tword)&_l,
#define __temp     (tword)&labels[11]
	__temp,
	(tword)&_l,
	__t,
	(tword)&_l,
	__i,
	(tword)&_f,
	(tword)&_st,
	(tword)&_t,
	(tword)&salt,
#define __2        (tword)&labels[12]
	__2,
	(tword)&_l,
	__temp,
	(tword)&_l,
	__t,
	(tword)&_l,
	__i,
	(tword)&_f,
	(tword)&_l,
#define __count    (tword)&labels[13]
	__count,
	(tword)&_ib,
	(tword)&_st,
	(tword)&_st,
	(tword)&_p,
// __2:
	(tword)&octal,
	__temp,
	1 + (tword)&trans,
	1 + _2,
// __count:
	0,
// __temp:
	0,
// __t:
	0,
// __i:
	0,
// __letter:
	1,
// __alpha:
	2,
// __noletter:
	4,
#define __classtab (tword)&start[82]
	0,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	6,
	6,
	6,
	6,
	6,
	6,
	6,
	6,
	6,
	6,
	4,
	4,
	4,
	4,
	4,
	4,
	4,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	4,
	4,
	4,
	4,
	4,
	4,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	3,
	4,
	4,
	4,
	4,
	4,
#define _pn        (tword)&start[210]
	1 + (tword)&_pxs,
	(tword)'\n',
#define _tn        (tword)&start[212]
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[77],      // __t
	(tword)&start[13],      // __text
	(tword)&start[34],      // __space
	(tword)&start[26],      // __ident
	(tword)&start[25],      // __done
	(tword)&start[79],      // __letter
	(tword)&start[80],      // __alpha
	(tword)&start[44],      // __install
	(tword)&start[81],      // __noletter
	(tword)&start[78],      // __i
	(tword)&start[76],      // __temp
	(tword)&start[71],      // __2
	(tword)&start[75],      // __count
};

// Used builtins:
//   _f
//   _ib
//   _l
//   _p
//   _pxs
//   _st
//   _t
//   _tp
//   _txs
//   alt
//   any
//   bundle
//   enter
//   octal
//   parse
//   salt
//   scopy
//   smark
//   string
//   succ
//   table
//   trans
