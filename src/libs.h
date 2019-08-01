// Port of the Unix compiler-compiler TMG to C99.
// This file contains functions from the library libs.a.
// Based on the original PDP-11 assembly code from the Unix V6 sources.
// Douglas McIlroy, Ken Thompson and Dennis Ritchie are among the possible
// original authors. Translation to C by Andriy Makukha.
//
// Comments starting with a lowercase letter were either copied from the 
// original assembly code or directly stem from it.

// TODO: this library should be reworked to either:
//  - do all operations completely in memory
//  - write files only when the size if getting too big
//  - write a unit test for this (starting with log2)
//  - check whether stack[sp+2] have correct offsets (especially when r3 was present)

#include "tmgc.h"

#define DATASZ  (1<<14)                 // 16384
#define HSZ     1024
#define HEADSZ  HSZ
#define NUMB    4
#define NUMB2   NUMB*sizeof(tword)      // assuming 2 was word size
#define NBUF    NUMB
#define NBUF2   NUMB2
#define BUFSIZE 512
#define FRSIZE  17

// Defined in tmga.c

extern void errcom(const char* msg);

// Globals (from alloc3.s)

tword flag;
tword stats[9];
tword useful;
FILE* afi;
FILE* afout;
tword datadr;
tptr  hblk;                         // must remain here - pointer to free header
                                    // NOTE: originally hblk immediately precedes both frlist and strbuf
tword frlist[FRSIZE];               //
#define frend   (frlist + FRSIZE)
char  strbuf[HSZ];                  // NOTE: originally strbuf overlaps with frlist
#define headers strbuf              // Synonym
#define strend  (strbuf + HSZ)
tword nchar;

tword b1s[NUMB];
tword b1e[NUMB];
tword w1[NUMB];
tword u1[NUMB];
char b1[NUMB*BUFSIZE];              // Buffers data

// Structs (from alloc3.s)

// each block has a four-word header:
//      W - write ptr (also used as link ptr in frlist)
//      R - read ptr
//      A - pointer to head of data
//      L - ptr to (end+1) of data. (End of allocated range.)
typedef struct sblock {
    tword w; 
    tword r;
    tword a;
    tword l;
} sblock_t;

// Function declarations

void allocate();
void alterword();
void clean();
void copy();
int ilog2(tuword x);
void preposterous();
void release();
void reset();
void seekchar();
void swap();
void wc();
void whead();

// Function definitions

// Description:
//	allocate a new block
// Parameters:
//	requested size in bytes in r0
//	(convert to words, adjust for header, round up
//	to a power of two)
// Return:
//	pointer to header of allocated block returned in r1
//	r0 is preserved
void allocate() {
    // TODO
}

void alterword() {
    // TODO
}

// Description:
//      routine to wc a buffer.
//      (Subroutine of wc())
// Parameters:
//      bn  - buffer index
//      buf - beginning of buffer
inline void clean(tword bn, char* buf) {
    fseek(afout, b1s[bn], SEEK_SET);
    fwrite(buf, 1, BUFSIZE, afout);
    w1[bn] = 0;
}

// Description:
//      routine to copy the contents of one string to another.
// Parameters:
//      r0 - source (r0 is preserved)
//      r1 - dest
// Return:
//      r1 points to the new string and should be saved.
void copy() {
    PUSH(r0);
    PUSH(r2);
    tword r3;
    wc();

    sblock_t* _r0 = (sblock_t*)r0;      // Convenience cast
    sblock_t* _r1 = (sblock_t*)r1;
    r2 = _r0->w - _r0->a;               // W-A: number of bytes to be copied from source
    r3 = _r1->l - _r1->a;               // L-A: number of bytes allocated in in dest
    if (r2 > r3) {
        release();                      // Free block pointed by r1
        r0 = r2;                        // New size
        allocate();
        r0 = stack[sp+1];               // restore r0 (source)
        _r0 = (sblock_t*)r0;
    }

    // rewind w pointer
    _r1 = (sblock_t*)r1;
    _r1->w = _r1->a;
    tword roff = _r0->a;                // Read offset
    do {
        // set input pointer
        fseek(afi, roff, SEEK_SET);     // TODO: it's unnecessary to have seeks in loop
        if (r2 > 512) { 
            r3 = 512;                   // # output this time
            roff += r3;
        } else
            r3 = r2;
        r2 -= r3;                       // # left to output
        int ret = fread(b1, 1, r3, afi);
        if (ret < r3) goto bad;
        fseek(afout, _r1->w, SEEK_SET);
        _r1->w += r3;
        ret = fwrite(b1, 1, r3, afout);
        if (ret < r3) goto bad;
    } while (r2 > 0);

    // fix up read ptr of new string
    _r1->r = _r0->r - _r0->a + _r1->a;

    // restore and return
    r2 = POP();
    r0 = POP();
    return;
bad:
    errcom("error on copy");
}

// Description:
//      routine to find integer part of log2(x)
//      (Generalized to tword.)
int ilog2(tuword x) {
    int cnt = 0;
    for (tuword r = 1; r; r <<= 1, cnt++)
        if (r > x) break;
    return --cnt>=0 ? cnt : 0;      // Don't return negative result for r0==0
}

// Description:
//      routine to discover whether r1 points to
//      a plausible header - to avoid ruination.
//      r1 is preserved 
// Return:
//      r0 gets a suitable index for frlist
void preposterous() {
    if ((tptr)r1 < (tptr)strbuf) goto botch;
    if ((tptr)r1 >= (tptr)strend) goto botch;
    sblock_t* _r1 = (sblock_t*)r1;
    if (_r1->a < HEADSZ) goto botch;    // A
    if (_r1->l > datadr) goto botch;    // L
    r0 = _r1->l - _r1->a;
    PUSH(r0);
    r0 = ilog2(r0);
    r0 <<= 1;       // what's the point here? Doesn't make sense. Did they mean +1? TODO
    if ((1<<r0) != stack[sp]) goto botch;
    stack[sp] = r0;
    r0 = frlist[r0];
    while (r0 != 0) {
        r0 += (tword)hblk;          // TODO: what is the meaning of this??? DANGEROUS
        if (r0 == r1) goto botch;
        r0 = *(tptr)r0;
    }
    r0 = POP();
    return;
botch:
    errcom("error in allocator.");
}

// Description:
//      here to release a block
// Parameters:
//      pointer to block in r1
void release() {
    // discover that this is a plausible pointer
    // and get a suitable index for frlist into r0.
    PUSH(r0);
    preposterous();                     

    // find free list index and link block to that entry
    stats[1]++; 
    sblock_t* _r1 = (sblock_t*)r1;      // Convenience casting
    _r1->w = frlist[r0];
    _r1->r = 0;
    r1 = (tuword)r1 - (tuword)hblk;     // TODO: what's the meaning of this??? DANGEROUS
    frlist[r0] = r1;
    r1 = 0;                 // self-defense
    // whead()
    r0 = POP();
}

void reset() {
    for (tword r3=0; r3<NBUF; r3++) {
        w1[r3] = -1;
        b1s[r3] = 0;
        b1e[r3] = 0;
        u1[r3] = 0;
    }
    flag = 0;
}

// Description:
//      routine to move the read pointer of a string to the
//      relative position indicated by r0.  the string is
//      extended if necessary - there is no error return.
// Parameters:
//      r0 - position
//      r1 - ... (The string.)
void seekchar() {
    PUSH(r1);
    PUSH(r0);
    do {
        r0 = stack[sp];         // Restore r0 (position)
        r0 += (tuword)((sblock_t*)r1)->a;
        if (r0 > ((sblock_t*)r1)->l) {
            r0 = stack[sp];     // Requested allocation size for string r1
            allocate();
            r0 = stack[sp+1];
            copy();             // Copy the string to newly allocated block currently in r1
            swap();             // r0 <- new block, r1 <- old block
            release();          // Free old block pointed by r1
            r1 = stack[sp+1];   // Restore r1 (string)
        } else {
            ((sblock_t*)r1)->r = r0;
            if (r0 >= ((sblock_t*)r1)->w)
                ((sblock_t*)r1)->w = r0;
            break;
        }
    } while(1);
    r0 = POP();
    r1 = POP();
}

// Description:
//      Swap data in two block headers.
// Parameters:
//      r0, r1 - pointers to sblock_t
void swap() {
    sblock_t tmp = *(sblock_t*)r1;
    *(sblock_t*)r1 = *(sblock_t*)r0;
    *(sblock_t*)r0 = tmp;
}

// Description:
//      Saves buffers data along with the headers block to the output file
//      (write current?)
void wc() {
    for (tword r3=0; r3<NBUF; r3++) {    
        if (w1[r3]<=0) continue;
        clean(r3, (char*)(BUFSIZE*r3 + (tuword)b1));
    }
    whead();
}

// Description:
//      write header block to the output file
void whead() {
    fseek(afout, 0, SEEK_SET);
    fwrite(hblk, 1, HSZ, afout);
}
