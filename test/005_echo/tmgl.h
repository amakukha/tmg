// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2020, Andriy Makukha, 2-clause BSD License.

#define SRC_LANGUAGE "echo"

const tword labels[];

// Driving table for the program

tword start[] = {
#define __1	(tword)&labels[0]
	1 + __1,
// __1:
#define __prog	(tword)&start[1]
	1 + (tword)&parse,
#define __echo	(tword)&labels[1]
	__echo,
// __echo:
	(tword)&smark,
	(tword)&ignore,
#define __none	(tword)&labels[2]
	__none,
	(tword)&any,
#define __ascii	(tword)&labels[3]
	__ascii,
	(tword)&string,
	__ascii,
	(tword)&scopy,
#define __done	(tword)&labels[4]
	1 + __done,
// __done:
	1 + (tword)&succ,
// __none:
	1,
// __ascii:
	2,
#define __classtab	(tword)&start[15]
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
#define _pn	(tword)&start[143]
	1 + (tword)&_pxs,
	(tword)'\n',
#define _tn	(tword)&start[145]
	1 + (tword)&_txs,
	(tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
	(tword)&start[1],	// __1
	(tword)&start[3],	// __echo
	(tword)&start[13],	// __none
	(tword)&start[14],	// __ascii
	(tword)&start[12],	// __done
};

// Used builtins:
//   _pxs
//   _txs
//   any
//   ignore
//   parse
//   scopy
//   smark
//   string
//   succ
