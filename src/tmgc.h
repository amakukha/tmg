// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2020, Andriy Makukha, 2-clause BSD License.
//
// Structure of this implementation closely follows the structure of the
// original code. Comments starting with a lowercase letter were either
// copied from the original assembly code or directly stem from it.

#include <stdio.h>
#include <stdbool.h>

// This implementation provides a verbose mode for the compiler (-v option).
// When compiled with the DEBUG_MODE macro set, the verbose mode will print
// detailed run-time debugging information.
#define DEBUG_MODE 1

// Original tracing capability; must be set together with trswitch in tmgb.h
#define TRACING 0

// Compile this with more memory than the original code?
#define MORE_MEMORY

// Flush the output every time obuild is called. Useful in debugging mode.
#define NOBUFFER DEBUG_MODE

// Just like B, Unix TMG operated with words, which could contain either a
// pointer or an integer value. This implementation also uses words of same
// size as pointers, but introduces distinction between the two.

#if UINTPTR_MAX == UINT_MAX 
#define tword       int
#else
#if UINTPTR_MAX == ULONG_MAX
#define tword       long
#else
#error "Unknown architecture; define your own tword (of same size as tword*)"
#endif
#endif

#define tptr        tword*
#define tuword      unsigned tword

// Global variables from PDP-11 registers

tword r0;       // Register R0
tword r1;       // Register R1
tword r2;       // Register R2

tptr  f;        // stack frame pointer during parse and translation
tptr  g;        // stack frame end during parse
tptr  i;        // interpreted instruction counter during parse and translation

bool carry;     // Corresponds to PDP-11 c-bit

// Carry bit (c-bit) is sometimes used as a failure indicator.
// Original code has these mnemonic synonyms defined:
// sef := sec; clf := clc; bfs := bcs; bfc := bcc
#define failure carry

// PDP-11 stack
tword stack[1024];                      // Stack for (sp), a.k.a. stack pointer register
tword sp = sizeof(stack)/sizeof(*stack);

// tmg tables and global definitions

// These constants are multiplied by four to account for larger words (64-bit vs 32)
// Constants could also be increased to provide bigger buffers and k table

#ifdef MORE_MEMORY
#define OUTT (1<<12)                    // output buffer size; 4096 bytes
#define STKT (1<<23)                    // stack size for (f), not for (sp); 8 MB
#define KTAT ((1<<21)*sizeof(tword))    // k table size; 2M words, or ~16 MB
#else
#define OUTT 64                         // output buffer size
#define STKT (1<<16)                    // stack size for (f), not for (sp)
#define KTAT (1200*sizeof(tword))       // k table size
#endif // MORE_MEMORY

FILE* input;                    // input
FILE* cfile;                    // current output
FILE* lfile;                    // last current output
FILE* dfile;                    // diagnostic file
FILE* ofile;                    // output file

tword outw = 0;                 // output write pointer, number of chars in buffer
uint8_t outb[OUTT];             // output buffer
uint8_t ktab[KTAT];             // contains translation rules that have been bundled
uint8_t stkb[STKT];             // stack, (f) points into this
uint8_t* stke = stkb + STKT;    // stack end

// parse stack frame layout
typedef struct parse_frame {
    struct parse_frame* prev;   // previous frame pointer
                                // return address in (sp)
    tword x;                    // exit bit, nonzero at end of rule
    tptr si;                    // save location for instruction counter
    tword j;                    // input cursor, counts characters
    tword k;                    // ktable high water mark, last use location relative to base (in bytes)
    tword n;                    // address of ignored character class
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

// Convenience macros
#define ARRAY_END(x)        (x + sizeof(x)/sizeof(*x))
#define BIT_CLEAR(mask,x)   ((~(tuword)(mask)) & ((tuword)(x)))
#define BIT0_CLEAR(x)       BIT_CLEAR(1, x)
#define NEG(x)              ((~(tuword)(x)) + 1)
#define PUSH(x)             (stack[--sp] = (tword)(x))
#define POP()               (stack[sp++])
#define POP_PREV()          do { stack[sp+1]=stack[sp]; sp++; } while(0)        // mov (sp)+,(sp)
#define SWAP_BYTES(x)       (((x & 0xFF)<<8) | ((x & 0xFF00)>>8))               // swab r0
#define HIGHEST_BIT         ((tuword)1<<(8*sizeof(tword)-1))
#define TF(addr, field)     ((translation_frame_t*)(addr))->field
#define PF(addr, field)     ((parse_frame_t*)(addr))->field

// Debugging output enabled?
#if DEBUG_MODE
tuword _depth = 0;
const char* _space = ">>>>..................................................................";
#define DEPTH               ((const char*)(_space + strlen(_space) - ((2*_depth < strlen(_space)) ? 2*_depth : strlen(_space)) ))
#define DEBUG(msg, ...)     do { if (verbose) fprintf(dfile, msg "\n", ##__VA_ARGS__); } while(0)
#define DEBUG_DEEPER        _depth++
#define DEBUG_SHALLOWER     _depth--
#else
#define DEBUG(msg, ...)
#define DEBUG_DEEPER
#define DEBUG_SHALLOWER
#endif
