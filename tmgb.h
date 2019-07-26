#include <limits.h>
#include <stdint.h>
#include "tmgc.h"

extern tword iget();
extern void  succ();

tword trswitch = 0;

// Function declarations
void _px();
void _pxs();
void _tx();
void _txs();
void parse();
void trans();
void trace();

// Function definitions
void _px() {}
void _pxs() {}
void _tx() {}
void _txs() {}
void parse() {}

void trans() {
    *g++ = iget();
    succ();
}

void trace() {
    // TODO
    printf("trace\n");
}
