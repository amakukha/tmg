// Reimplementation of the Unix compiler-compiler TMG in C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

const tword labels[];

// Driving table for a sample program

tword start[] = {
    1,
#define __1         (tword)&labels[0]
#define __program   (tword)&labels[1]
    __1,
//__1:
//__program:
    1, (tword)&parse,
#define __hello     (tword)&labels[2]
    __hello,
#undef _2
#define _2          (tword)&start[5]
    (tword)"Hello, World!",
#undef _1
#define _1          (tword)&start[6]
    (tword)&_tx, _2,
#define __tn        (tword)&labels[3]
    1, __tn,
//__hello:
    1, (tword)&trans, 1, _1,
//__pn:
    1, (tword)&_pxs, 012,
//__tn:
    1, (tword)&_txs, 012,
};

// Global label addresses inside the driving table

const tword labels[] = {
    (tword)&start[2],       // __1
    (tword)&start[2],       // __program
    (tword)&start[10],      // __hello
    (tword)&start[17],      // __tn
};
