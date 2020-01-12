// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

#define SRC_LANGUAGE "echo"

const tword labels[];

// Driving table for a sample program (see examples/echo.t)

tword start[] = {
#define __1        (tword)&labels[0]
	1 + __1,
// __1:
#define __prog     (tword)&start[1]
	1 + (tword)&parse,
#define __echo     (tword)&labels[1]
	__echo,
#undef _1
#define _1         (tword)&start[3]
	1 + (tword)&_tp,
	2,
// __echo:
	(tword)&smark,
	(tword)&ignore,
#define __none     (tword)&labels[2]
	__none,
	(tword)&any,
#define __ascii    (tword)&labels[3]
	__ascii,
	(tword)&string,
	__ascii,
	(tword)&scopy,
#define __done     (tword)&labels[4]
	__done,
	1 + (tword)&trans,
	1 + _1,
#undef _1
#define _1         (tword)&start[16]
	1 + (tword)&generate,
// __done:
	1 + (tword)&trans,
	1 + _1,
// __none:
	1,
// __ascii:
	2,
#define __classtab (tword)&start[21]
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
	2,
	2,
	2,
	2,
	2,
	2,
	2,
#define _pn        (tword)&start[149]
	1 + (tword)&_pxs,
	(tword)'\n',
#define _tn        (tword)&start[151]
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],       // __1
	(tword)&start[5],       // __echo
	(tword)&start[19],      // __none
	(tword)&start[20],      // __ascii
	(tword)&start[17],      // __done
};

// Used builtins:
//   _pxs
//   _tp
//   _txs
//   any
//   generate
//   ignore
//   parse
//   scopy
//   smark
//   string
//   trans
