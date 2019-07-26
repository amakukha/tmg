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
#include "tmgl.h"

// This is an address range used to recognize predefined functions pointers
// TODO
tptr  func_min = 0;
tptr  func_max = (tptr)UINTPTR_MAX;

// Statictics counters
tword succc     = 0;
tword continc   = 0;
tword failc     = 0;
tword advc      = 0;

// Function declarations
void adv();
void succ();
void fail();
void contin();
void errcom(const char* error);

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
    r0 &= ~(tword)1;
    if (r0 >= (tword)start && r0 < (tword)start + sizeof(start)) {
        // tmg-coded rule, execute and test its success
        adv();
        if (failure)
            fail();
        else
            succ();
    } else if (r0 >= (tword)func_min && r0 <= (tword)func_max) {
        // machine coded function
        (*(void (*)(void))r0)();
    } else {
        errcom("bad address in parsing");
    }
}

void alt() {
    i++;
    return succ();      // Tail call
}

void salt() {
    i = (tptr)iget();
    return contin();    // Tail call
}

void tgoto() {
    return salt();      // Tail call
}

// all functions and rules that fail come here
// if exit bit is on do a fail return
// if following instruction is an alternate (recognized literally)
// do a goto, if a success alternate, do a nop
// otherwise do a fail return
void fail() {
    failc++;
    if (!(((parse_frame_t*)f)->x & 1)) {    // Exit bit not set
        ((parse_frame_t*)f)->x = iget(); 
        r0 &= ~(tword)1;
        if (r0 == (tword)&alt)      // TODO: why does it go to salt if equal to alt and v.v.?
            return salt();  // Tail call
        if (r0 == (tword)&salt)
            return alt();   // Tail call
    }

    // do a fail return
    // pop stack
    // do not update j or k
    // restore interpreted instruction counter
    g = f;
    f = (tptr)((parse_frame_t*)f)->prev;
    i = ((parse_frame_t*)f)->si;
    failure = true;
}

// all functions that succeed come here
// test the exit indicator, and leave the rule if on
void succ() {
    succc++;
    if (((parse_frame_t*)f)->x & 1) {       // Exit bit set
        // do a success return
        // bundle translations delivered to this rule,
        // pop stack frame
        // restore  interpreted instruction counter (i)
        // update input cursor (j) for invoking rule
        // update high water mark (k) in ktable
        // if there was a translation delivered, add to stack frame
        // clear the fail flag
        // TODO: sret       <-- CONTIN
        return;
    }
    return contin();    // Tail call
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
        printf("Usage:\t%s input.t output.h\n", argv[0]);
        printf("\tinput.t \t- program in TMGL\n");
        printf("\toutput.h\t- resulting driving table in C\n");
        
        // Testing
        for (int i=0; i<sizeof(start)/sizeof(*start); i++)
            printf("%08lx\n", (tword)start[i]);
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
