#include <limits.h>
#include <stdint.h>
#include "tmgc.h"

extern tword iget();
extern void  succ();
extern void  parse();

tword trswitch = 0;

// Function declarations
void _px();
void _pxs();
void _tx();
void _txs();
void trans();
void trace();

// Function definitions
void _px() {}
void _pxs() {}
void _tx() {}
void _txs() {}

void trans() {
    *g++ = iget();
    succ();
}

void trace() {
    // TODO
    printf("trace\n");
}
