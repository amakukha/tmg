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
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tmgb.h"

tptr  f;        // stack frame pointer during parse and translation
tptr  g;        // stack frame end during parse
tword i;        // interpreted instruction counter during parse and translation

tword r0;
tword r1;

// TODO:
// sef=sec^sec; clf=clc^clc; bfs=bcs^bcs; bfc=bcc^bcc	/fail indicator

tword succc     = 0;
tword continc   = 0;
tword failc     = 0;
tword advc      = 0;

tword iget() {
    // TODO
    return 0;
}

void succ() {
    // TODO
    return;
}

void contin() {
    // TODO
}

void errcom(const char* error) {
    // TODO 
    fprintf(dfile, "%s", error);
    exit(1);
}

// advance stack frame to invoke a parsing rule
// copy  cursor, water mark, ignored class to new frame
// set intial frame length to default (g1)
// check end of stack
// r0,r1 are new i,environment
void adv() {
    advc++;
    parse_frame_t* _f = (parse_frame_t*)f;      // Cast for convenience
    parse_frame_t* _g = (parse_frame_t*)g;
    _g->prev = _f;
    _f->si = i;
    _g->j = _f->j;
    _g->k = _f->k;
    _g->n = _f->n;
    f = g;
    g += sizeof(parse_frame_t); // g1
    if ((uint8_t*)g >= stke)
        errcom("stack overflow");
    i = r0;
    _f->env = (tptr)r1;
    contin();
}

// copy output buffer onto last output file and clear buffer
void flush() {
    fwrite(outb, 1, outw, lfile);
    outw = 0;
}

int main(int argc, char* argv[]) {
    // These have to be initialized here because stdout/stderr are not compile-time constants
    input = NULL;
    cfile = stdout;
    lfile = stdout;
    dfile = stderr;
    ofile = stdout;

    // Help message
    if (argc <= 1 || !strcmp(argv[1], "-h")) {
        printf("TMG compiler-compiler (%lu-bit)\n", 8*sizeof(tword));
        printf("Usage:\t%s input output\n", argv[0]);
        printf("\tinput\t- program in TMGL\n");
        printf("\toutput\t- name of resulting binary (translator)\n");
        return 0;
    }

    // get arguments from shell
    // arg1 is input file
    // arg2 is output file (standard output if missing)
    input = fopen(argv[1], "r");
    if (!input) {
        fprintf(dfile, "could not open: %s\n", argv[1]);
        return 1;
    }
    if (argc >= 3) {
        ofile = fopen(argv[2], "w");
        if (!ofile) {
            fprintf(dfile, "could not open for writing: %s\n", argv[2]);
            return 1;
        }
    }

    // set up tables
    // initialize stack
    // go interpret beginning at "start"
    // finish up
    f = (tptr) stkb;
    parse_frame_t* p = (parse_frame_t*) f;
    p->j = 0;
    p->k = 0;
    p->n = 0;
    g = (tptr)((uint8_t*)f + stkt);
    adv();
    flush();
    //unlink("alloc.d");

    return 0;
}
