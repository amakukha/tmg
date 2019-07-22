// Reimplementation of the Unix compiler-compiler TMG in C.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.
//
// Structure of this implementation closely follows the structure of the
// original code. Comments starting with a lowercase letter were either
// copied from the original assembly code or directly stem from it.

// tmg
// main program and parsing rule interpreter

#define TRACING 1

#include <stdio.h>
#include <unistd.h>
#include "tmgb.h"

tptr  f;        // stack frame pointer during parse and translation
tptr  g;        // stack frame end during parse
tword i;        // interpreted instruction counter during parse and translation

// TODO:
// sef=sec^sec; clf=clc^clc; bfs=bcs^bcs; bfc=bcc^bcc	/fail indicator

FILE* input;    // input
FILE* cfile;    // current output
FILE* lfile;    // last current output
FILE* dfile;    // diagnostic file
FILE* ofile;    // output file

tword iget() {
    return 0;
}

void succ() {
    return;
}

int main(int argc, char* argv[]) {
    input = NULL;
    cfile = stdout;
    lfile = stdout;
    dfile = stderr;
    ofile = stdout;

    fprintf(dfile, "TMG compiler-compiler (%lu-bit)\n", 8*sizeof(tword));
    return 0;
}
