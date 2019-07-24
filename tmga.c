// Reimplementation of the Unix compiler-compiler TMG in C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.
//
// Structure of this implementation closely follows the structure of the
// original code. Comments starting with a lowercase letter were either
// copied from the original assembly code or directly stem from it.

// tmg
// main program and parsing rule interpreter

#define TRACING 1

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tmgb.h"
#include "table.h"

// TODO:
// sef=sec^sec; clf=clc^clc; bfs=bcs^bcs; bfc=bcc^bcc	/fail indicator

tword succc     = 0;
tword continc   = 0;
tword failc     = 0;
tword advc      = 0;

// get interpreted instruction for a parsing rule
// negative instruction is a pointer to a parameter in this
// stack frame, fetch that instead
// put environment pointer in r1

tword iget() {
    r1 = (tword)f;
    r0 = *i++;
    if (r0 < 0) {
        // TODO         <-- CONT
    }
    return r0;
}

void contin() {
    continc++;
#if TRACING
    if (trswitch) {
        // TODO
        trace();
    }
#endif

    // get interpreted instruction
    // save its exit bit (bit 0) on stack
    // distinguish type of instruction by ranges of value
    ((parse_frame_t*)f)->x = iget(); 
    // TODO
}

// all functions that succeed come here
// test the exit indicator, and leave the rule if on
void succ() {
    succc++;
    if (((parse_frame_t*)f)->x)
        goto sret;
    contin();

// do a success return
// bundle translations delivered to this rule,
// pop stack frame
// restore  interpreted instruction counter (i)
// update input cursor (j) for invoking rule
// update high water mark (k) in ktable
// if there was a translation delivered, add to stack frame
// clear the fail flag
sret:
    // TODO
    return;
}

void errcom(const char* error) {
    // TODO 
    fprintf(dfile, "%s\n", error);
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
    g = (tptr)((uint8_t*)g + sizeof(parse_frame_t)); // g1
    if ((uint8_t*)g >= stke)
        errcom("stack overflow");
    i = (tptr)r0;                       // Initially this contains &start[0]
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
    parse_frame_t* _f = (parse_frame_t*) f;
    _f->j = 0;
    _f->k = 0;
    _f->n = 0;
    g = (tptr)((uint8_t*)f + sizeof(parse_frame_t));
    r0 = (tword)start;
    adv();
    flush();
    //unlink("alloc.d");

    return 0;
}
