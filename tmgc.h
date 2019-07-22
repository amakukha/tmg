// Reimplementation of the Unix compiler-compiler TMG in C.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.
//
// Structure of this implementation closely follows the structure of the
// original code. Comments starting with a lowercase letter were either
// copied from the original assembly code or directly stem from it.

// Just like B, Unix TMG operated with words, which could contain either a
// pointer or an integer value. This implementation uses words of same size
// as pointers for simplicity, but introduces distinction between the two.
#if UINTPTR_MAX == UINT_MAX 
#define tword   int
#define tptr    int*
#else
#if UINTPTR_MAX == ULONG_MAX
#define tword   long
#define tptr    long*
#else
#error "Unknown architecture; define your own tword / tptr"
#endif
#endif

// tmg tables and global definitions

#define outt 64         // output buffer top
#define stkt 800	// stack top for (f), not for (sp)
#define ktat 1200	// k table top

tword outw = 0;         // output write pointer, number of chars in buffer
uint8_t outb[outt];     // output buffer
uint8_t ktab[ktat];     // contains translation rules that have been bundled
uint8_t stkb[stkt];     // stack, (f) points into this
uint8_t* stke = stkb + stkt;     // stack end

// parse stack frame layout
struct parse_frame {
    tptr prev;          // previous frame pointer
                        // return address in (sp)
    tword x;            // exit bit, nonzero at end of rule                      
    tptr si;            // save location for instruction counter
    tword j;            // input cursor counts characters
    tptr k;             // ktable high water mark, last use location relative to base
    tptr n;             // address of ignored character class
    tptr env;           // frame pointer for static environment
    tword g1;           // frame length during parse
};

// symbol table entry layout
struct symbol {
    tword custom;       // word 0 is for customer
    tptr lptr;          // index of next entry on tree to left
    tptr rptr;          // index of next entry to right
    char* sptr;         // first character of string in this entry
                        // next char is in *(sptr+1), etc.
};
	 
// translation frame layout
// used as ek(f), ep(f), etc.
// return address in (sp)
struct translation_frame { 
    tptr ek;            // k environment, frame where bunlde address is in si
    // x and si have same meaning as in parse stack frame
    tword x;            // exit bit, nonzero at end of rule
    tptr si;            // save location for instruction counter
    tptr ep;            // p environment, frame where si points to parameter list
    // TODO: why frame size is 10, not 8?
    // fs = 10	/ frame size
    // ek.fs = ek+fs	/ k environment in next frame
    // ep.fs = ep+fs	/ p env in next frame
};

