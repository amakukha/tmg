// Reimplementation of the Unix compiler-compiler TMG in C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

// Driving table for the TMGL.

#include "tmgc.h"
#include "tmgb.h"

tword start[] = {
    1,
#undef  __2
#define __2         (tword)&start[1]
    2,
    3,
    (tword)&trans,
#undef  __2
#define __2         (tword)&start[4]
    (tword)&succ,
    (tword)&iget,   __2,
    (tword)&succ,   (tword)"Hello, world\n"
};
