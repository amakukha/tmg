#ifndef __TMGB__
#define __TMGB__

#include <limits.h>
#include <stdint.h>
#include "tmgc.h"

extern tword iget();
extern void  succ();

tword trswitch = 0;

void trans();
void trace();

void trans() {
    *g++ = iget();
    succ();
}

void trace() {
    // TODO
    printf("trace\n");
}

#endif // __TMGB__
