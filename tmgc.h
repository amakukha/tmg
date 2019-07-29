// Reimplementation of the Unix compiler-compiler TMG in C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.
//
// Structure of this implementation closely follows the structure of the
// original code. Comments starting with a lowercase letter were either
// copied from the original assembly code or directly stem from it.

#include <stdio.h>
#include <stdbool.h>

// This implementation provides a verbose mode for the compiler (-v option).
// Additionally, when compiled with the DEBUG_MODE macro set, verbose mode
// will print detailed debugging information.
#define DEBUG_MODE 1

// Original tracing capability; must be set together with trswitch in tmgb.h
#define TRACING 1       

// Flush the output every time obuild is called. Useful in debugging mode.
#define NOBUFFER DEBUG_MODE

// Just like B, Unix TMG operated with words, which could contain either a
// pointer or an integer value. This implementation also uses words of same
// size as pointers, but introduces distinction between the two.

#if UINTPTR_MAX == UINT_MAX 
#define tword       int
#define tptr        int*
#define tuword      unsigned int
#else
#if UINTPTR_MAX == ULONG_MAX
#define tword       long
#define tptr        long*
#define tuword      unsigned long
#else
#error "Unknown architecture; define your own tword / tptr"
#endif
#endif

// Global variables from PDP-11 registers

tword r0;       // Register R0
tword r1;       // Register R1

tptr  f;        // stack frame pointer during parse and translation
tptr  g;        // stack frame end during parse
tptr  i;        // interpreted instruction counter during parse and translation

// Carry bit was used as a failure indicator.
// Original code has these mnemonic synonyms defined:
// sef := sec; clf := clc; bfs := bcs; bfc := bcc
bool failure;

// PDP-11 stack
tword stack[1000];
tword sp = sizeof(stack)/sizeof(*stack);

// tmg tables and global definitions

// These constants are multiplied by four to account for larger words (64-bit vs 32)
// Constants could also be increased to provide bigger buffers and k table

#define outt 64                         // output buffer top
#define stkt (800*sizeof(tword))	// stack top for (f), not for (sp)
#define ktat (1200*sizeof(tword))	// k table top

FILE* input;                    // input
FILE* cfile;                    // current output
FILE* lfile;                    // last current output
FILE* dfile;                    // diagnostic file
FILE* ofile;                    // output file

tword outw = 0;                 // output write pointer, number of chars in buffer
uint8_t outb[outt];             // output buffer
uint8_t ktab[ktat];             // contains translation rules that have been bundled
uint8_t stkb[stkt];             // stack, (f) points into this
uint8_t* stke = stkb + stkt;    // stack end

// parse stack frame layout
typedef struct parse_frame {
    struct parse_frame* prev;   // previous frame pointer
                                // return address in (sp)
    tword x;                    // exit bit, nonzero at end of rule
    tptr si;                    // save location for instruction counter
    tword j;                    // input cursor counts characters
    tword k;                    // ktable high water mark, last use location relative to base (in bytes)
    tptr n;                     // address of ignored character class
    tptr env;                   // frame pointer for static environment
} parse_frame_t;

#define g1   sizeof(parse_frame_t)      // Not really intended to be used

// symbol table entry layout
typedef struct symbol {
    tword custom;               // word 0 is for customer
    tptr lptr;                  // index of next entry on tree to left
    tptr rptr;                  // index of next entry to right
    char* sptr;                 // first character of string in this entry
                                // next char is in *(sptr+1), etc.
} symbol_t;
	 
// translation frame layout
// used as ek(f), ep(f), etc.
// return address in (sp)
typedef struct translation_frame { 
    tptr ek;                    // k environment, frame where bunlde address is in si
    // x and si have same meaning as in parse stack frame
    tword x;                    // exit bit, nonzero at end of rule
    tptr si;                    // save location for instruction counter
    tptr ep;                    // p environment, frame where si points to parameter list
    // ek.fs = ek+fs	/ k environment in next frame
    // ep.fs = ep+fs	/ p env in next frame
} translation_frame_t;

// TODO: why original fs (frame size) is 10 instead of 8?
#define fs  (sizeof(translation_frame_t)+sizeof(tword))     // frame size
