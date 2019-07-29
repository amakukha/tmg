// Reimplementation of the Unix compiler-compiler TMG in C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

//#define SRC_LANGUAGE "TMGL"
//#define DST_LANGUAGE "C driving table"
#define SRC_LANGUAGE "dummy"

const tword labels[];

// Driving table for a sample program: hello world

tword start[] = {
#define __1         (tword)&labels[0]
#define __program   (tword)&labels[1]
    1 + __1,
//__1:
//__program:
    1 + (tword)&parse,
#define __hello     (tword)&labels[2]
    __hello,
#undef _2
#define _2          (tword)&start[3]
    (tword)"Hello, World!",
#undef _1
#define _1          (tword)&start[4]
    (tword)&_tx, _2,
#define __tn        (tword)&labels[3]
    1 + __tn,
//__hello:
    1 + (tword)&trans, 1 + _1,
//__pn:
    1 + (tword)&_pxs, (tword)'\n',
//__tn:
    1 + (tword)&_txs, (tword)'\n',
};

// Global label addresses inside the driving table

const tword labels[] = {
    (tword)&start[1],       // __1
    (tword)&start[1],       // __program
    (tword)&start[7],       // __hello
    (tword)&start[11],      // __tn
};
