// Port of the Unix compiler-compiler TMG to C99.
// This file contains functions from the library libs.a, which allowed to
// swap up to 16KB of memory into a file using 3KB of RAM. (Supposedly, this
// was very useful in the PDP-7 days.)
// Based on the original PDP-11 assembly code from the Unix V6 sources.
// Douglas McIlroy, Ken Thompson and Dennis Ritchie are among the possible
// original authors. Translation to C by Andriy Makukha.
//
// Comments starting with a lowercase letter were either copied from the 
// original assembly code or directly stem from it.

// TODO: this library should be reworked to either:
//  - do all operations completely in memory
//  - write files only when the size if getting too big
// TODO:
//  - write a unit test for this (starting with log2)
//  - check whether stack[sp+2] have correct offsets (especially when r3 was present)

// NOTE: some of the functions here received state (like bufchar) and will
//       use stack as a result. If stackoverflow ever happens, might need to
//       convert back to using explicit stack[] array.

#include "tmgc.h"

#define ASMEM   "alloc.d"               // filename
#define DATASZ  (1<<14)                 // 16384
#define HSZ     1024
#define HEADSZ  HSZ
#define NUMB    4
#define NUMB2   NUMB*sizeof(tword)      // assuming 2 was word size
#define NBUF    NUMB
#define NBUF2   NUMB2
#define BUFSIZE 512
#define FRSIZE  16
#define DATADR  (HEADSZ+DATASZ)         // end of data offset (in bytes)

// Defined in tmga.c
extern bool verbose;
extern void errcom(const char* msg);

// Globals (from alloc3.s)

tword flag;
tword stats[9];
tword useful;
FILE* afi;
FILE* afout;

// File header structure (sizes in words, total size 1024 bytes):
//     |--hblk(1)--|--frlist(16)--|----strbuf(495)----|
// strbuf contains 4-word headers of type sblock_t.
// File structure:
//     |--hblk(1)--|--frlist(16)--|----strbuf(495)----|------data(8096)------|
// data is loaded from files as needed.

struct shead {
    tword _hblk;                    // must remain here - pointer to free header
    tword _frlist[FRSIZE];          //
    char  _strbuf[HSZ];             // TODO: sizeof(shead) is not HSZ! FIXIT
} _shd;

#define hblk    _shd._hblk
#define frlist  _shd._frlist
#define frend   (frlist + FRSIZE)
#define strbuf  _shd._strbuf
#define headers strbuf              // Synonym
#define strend  (strbuf + HSZ)

tword nchar;

tword b1s[NUMB];                    // Beginning of buffer in the file
tword b1e[NUMB];                    // End of buffer in the file (past last character)
tword w1[NUMB];
tword u1[NUMB];                     // Usage count of a buffer?; used to keep most used buffers in memory
char b1[NUMB*BUFSIZE];              // Buffers data

// Structs (from alloc3.s)

// each block has a four-word header:
//      W - write ptr (also used as link ptr in frlist)
//      R - read ptr
//      A - pointer to head of data
//      L - ptr to (end+1) of data. (End of allocated range.)
// Note:
//      W, R - are offsets relative to the start of each string
//      A, L - are offsets relative to the start of file
typedef struct sblock {
    tword w; 
    tword r;
    tword a;
    tword l;
} sblock_t;

// Function declarations

void allocate();
void alterchar();
void alterword();
void bufchar();
void clean(tword bn, char* buf);
void collect();
void copy();
void fixct();
void getb();
void getbuf();
int ilog2(tuword x);
void initl();
void plausible();
void preposterous();
void release();
void reset();
void seekchar();
void swap();
void wc();
void whead();

// Function definitions

// Description:
//      allocate a new block
// Parameters:
//      requested size in bytes in r0
//      (convert to words, adjust for header, round up
//      to a power of two)
// Return:
//      pointer to header of allocated block returned in r1
//      r0 is preserved
void allocate() {
    DEBUG("    allocate()");
    PUSH(r0);
    PUSH(r2);
    tword r3;
    if (stats[0]++==0)
        initl();
    r0 = r0>0 ? ilog2(r0-1)+1 : 0;
    PUSH(r0);

    // look on free list for block of required size
zzz:
    r0 = POP();
    if (frlist[r0]==0) goto xxx;

    // found it, allocate and return
    r1 = frlist[r0] + (tuword)&hblk;
    frlist[r0] = *(tptr)r1;     // Same as ((sblock_t*)r1)->w
    r0 = ((sblock_t*)r1)->a;
    ((sblock_t*)r1)->w = r0;
    ((sblock_t*)r1)->r = r0;
    POP();
    r2 = POP();
    r0 = POP();
    //whead() 
    return;

    // no block of required size
    // look for larger block
xxx:
    r0++;
    if (r0 >= FRSIZE) goto www;
    if (frlist[r0]) goto yyy;
    goto xxx;

    // there are no larger blocks;  must garbage collect
www:
    collect();
    if (r0) goto zzz;
    errcom("out of space.");

    // split larger block into two smaller pieces and
    // link together as smaller blocks in the free list.
yyy:
    r3 = hblk;      // get free header block
    if (!r3) goto www;
    r1 = frlist[r0] + (tuword)&hblk;    // Pointer to header of the free block
    frlist[r0] = ((sblock_t*)r1)->w;    // Removing the free block from the original size list
    ((sblock_t*)r1)->w = r3;
    r3 += (tuword)&hblk;                // Pointer to free header
    r2 = 1<<(r0-1);                     // Halved block size
    r2 += ((sblock_t*)r1)->a;           // Middle of the original free block
    hblk = ((sblock_t*)r3)->w;          // Removing the free header from the list of free headers
    ((sblock_t*)r3)->l = ((sblock_t*)r1)->l;
    ((sblock_t*)r1)->l = r2;
    ((sblock_t*)r3)->a = r2;
    ((sblock_t*)r3)->w = 0;             // These two block are the only ones of this size
    r2 = r1 - (tuword)&hblk;
    frlist[r0-1] = r2;
    goto zzz;
}

// TODO: check this routine
// Description:
//      routine to rewrite the character pointer to by
//      read pointer.  The read pointer is advanced.
//      the string is extended if necessary.
//      there is no error return.
// Parameters:
//      r0 - character
//      r1 - ...
void alterchar() {
    PUSH(r2);
    PUSH(r1);
    nchar = r0;
    plausible();
    stats[4]++;
    if (((sblock_t*)r1)->r >= ((sblock_t*)r1)->l) {
        r0 = 1 + ((sblock_t*)r1)->l - ((sblock_t*)r1)->a;       // W-A+1
        allocate();
        r0 = stack[sp];
        copy();
        swap();
        release();
        r1 = stack[sp];
    }
    r0 = ((sblock_t*)r1)->r;
    bufchar();
    if (failure)
        getbuf();
    *(tptr)r0 = nchar;
    r0 = nchar;                 // to preserve r0 for user
    ((sblock_t*)r1)->r++;
    w1[r2] = 1;
    if (((sblock_t*)r1)->r >= ((sblock_t*)r1)->w)
        ((sblock_t*)r1)->w = ((sblock_t*)r1)->r;
    if (++flag)
        u1[r2] = flag;
    else
        fixct();
    r1 = POP();
    r2 = POP();
    return;
}

// TODO: what does it do?
// Description:
//      routine to alter a word in the string
void alterword() {
    DEBUG("    alterword()");
    alterchar();
    r0 = SWAP_BYTES(r0);
    alterchar();
    r0 = SWAP_BYTES(r0);
}

// Description:
//      routine to get buffer addr of byte whose disc
//      addr is in r0. also returns addr of write
//      flag for buffer in r2.
// Parameters:
//      r0 - disc addr
// Return:
//      (r0) - r0 for read
//      (r2) - for write must inc w
//      c-bit - set if char not in either buffer
void bufchar() {
    PUSH(r1);
    for (tword r3 = 0; r3 < NBUF; r3++) {
        r2 = r3;
        //r2 <<= 1;     // accounting for word size
        if (r0 >= b1s[r2] && r0 < b1e[r2]) {
            // This byte is in the buffer!
            // Convert file offset into memory address in the buffer.
            r0 = r0 - b1s[r2] + r3*BUFSIZE + (tuword)b1;
            r1 = POP();
            failure = false;
            return;
        }
    }
    r1 = POP();
    failure = true;
}

// Description:
//      routine to wc a buffer.
// Parameters:
//      bn  - buffer index
//      buf - beginning of buffer
void clean(tword bn, char* buf) {
    fseek(afout, b1s[bn], SEEK_SET);
    fwrite(buf, 1, BUFSIZE, afout);
    w1[bn] = 0;
}

// TODO: check this one
// Description:
//      coalesce free storage by rejoining paired blocks
//      on the free list.
// Return:
//      r0 - zero if no paired blocks were found.
void collect() {
    PUSH(r1);
    PUSH(r2);
    tword r3, r4, exp;
    useful = 0;
    stats[2]++;
    r0 = 0;                     // start with smallest blocks
                                // r0 contains frlist index
loop1:  
    r1 = (tword)&frlist[r0];

    // try next list member at this level
loop2:
    r3 = *(tptr)r1;
    if (!r3) goto advance;      // list is empty
    r3 += (tuword)&hblk;
    if (((sblock_t*)r3)->w == 0) goto advance;  // only one list element

    // calculate address of buddy
    r4 = ((sblock_t*)r3)->a - HEADSZ;
    exp = 1<<r0;
    if (exp & r4)
        r4 = BIT_CLEAR(exp, r4);
    else
        r4 |= exp;
    r4 += HEADSZ;

    // and search for him
loop3:
    r4 = ((sblock_t*)r3)->a;
    if (!r4) goto coal;
    r2 = r3;
    r3 = ((sblock_t*)r3)->w;
    if (!r3) goto nocoal;
    r3 += (tuword)&hblk;
    goto loop3;

    // have found a pair; remove both blocks from list,
    // coalesce them, and put them on next higher list
coal:
    useful++;
    ((sblock_t*)r2)->w = ((sblock_t*)r3)->w;    // remove him from list
    r2 = *(tptr)r1 + (tuword)&hblk;
    r4 = r3;
    ((sblock_t*)r1)->w = ((sblock_t*)r2)->w;    // remove other one
    if (((sblock_t*)r2)->a <= ((sblock_t*)r4)->a) {
        tword tmp = r2;
        r2 = r4;
        r4 = tmp;
    }
    *(tptr)r2 = hblk;
    ((sblock_t*)r2)->r = 0;
    ((sblock_t*)r2)->a = HEADSZ;
    ((sblock_t*)r2)->l = HEADSZ;
    r2 -= (tuword)&hblk;
    hblk = r2;
    exp = 1<<r0;
    ((sblock_t*)r4)->l += exp;
    ((sblock_t*)r4)->r = 0;
    ((sblock_t*)r4)->w = frlist[r0+1];
    r4 -= (tuword)&hblk;
    frlist[r0+1] = r4;
    goto loop2;

    // no buddy found, try next block on this list
nocoal:
    r1 = *(tptr)r1 + (tuword)&hblk;
    goto loop2;

    // advance to next free list
advance:
    if (++r0 < FRSIZE) goto loop1;
    r0 = useful;

    // restore registers and return
    r2 = POP();
    r1 = POP();
    return;
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
        fseek(afi, roff, SEEK_SET);
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

// TODO: try to understand this
// Parameters:
//      r2 - number of buffer
void fixct() {
    PUSH(r1);
    tword r3;
    r1 = NBUF;
    flag = NBUF;
l2:
    u1[r2] = r1;
    if (--r1 < 0) {
        r1 = POP();
        return;
    }
    r2 = 0;
    r3 = 1;
l1:
    if (r3 >= NBUF) goto l2;
    if (u1[r3] >= u1[r2])
        r2 = r3;
    r3++;
    goto l1;
}

// Description:
//      routine to read from disc to a buffer
//      wcing the buffer if necessary
// Parameters:
//      r0 - disc addr (File offset of a byte)
//      r2 - buffer addr
// Return:
//      r0 - addr of byte in buffer (Memory address of the byte)
inline void getb() {
    PUSH(r1);
    PUSH(r0);
    r1 = (tuword)b1 + r2*BUFSIZE;      // Current buffer starting byte
    if (w1[r2] > 0)
        clean(r2, (char*)r1);
    r0 = BIT_CLEAR(0777, stack[sp]);    // get lowest multiple of 512.
    b1s[r2] = r0;                       // set start
    fseek(afi, r0, SEEK_SET);
    fread((char*)r1, 1, BUFSIZE, afi);
    b1e[r2] = b1s[r2] + BUFSIZE;        // set end
    w1[r2] = 0;                         // clear w
    r0 = POP() - b1s[r2] + r1;          // set r0=byte addr in buffer
    r1 = POP();
}

// Description:
//      routine to get a buffer
// Parameters:
//      r0 - disc addr
// Return:
//      (r0) - r0 (for read)
//      (r2) - must inc w for w
void getbuf() {
    // Determine what buffer is least used to replace it
    tword r4 = 1;
    r2 = 0;
    while (r4 < NBUF) {
        if (u1[r4]<u1[r2])
            r2 = r4;
        r4++;
    }
    r4 = r2;
    getb();
    stats[3+r4]++;
    return;
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
//      Initialization, used by allocate()
void initl() {
    DEBUG("    initl()");
    PUSH(r0);
    PUSH(r2);

    // Open the save file
    afout = fopen(ASMEM, "w+");
    if (afout == NULL)
        errcom("cannot open output file: " ASMEM);
    afi = afout;

    // Where are free headers are located?
    r2 = (tuword)headers;
    r0 = (tuword)headers - (tuword)&hblk;
    hblk = r0;      // Arrithmetic offset to first free header (== headers)

    // Initialize headers with pointers to next header (arithmetic offset in file)
    while ((tuword)r2 < (tuword)strend - sizeof(sblock_t)) {
        r0 += sizeof(sblock_t);
        ((sblock_t*)r2)->w = r0;    // Next header offset?
        r2 += sizeof(sblock_t);
    }
    ((sblock_t*)(r2-sizeof(sblock_t)))->w = 0;

    // Clear list of free blocks
    memset(frlist, 0, sizeof(frlist));

    // Create one big free block
    r2 = hblk + (tuword)&hblk;      // Points to the first header location
    hblk = *(tptr)r2;               // Next header location (free header)
    ((sblock_t*)r2)->w = 0;         // Write pointer in the string (arithmetic offset)
    ((sblock_t*)r2)->a = HEADSZ;    // Where does the block start in the file (arithmetic offset)
    ((sblock_t*)r2)->l = DATADR;    // Where does the block end in the file (arithmetic offset)
    r0 = ilog2(DATASZ);             // Index for frlist
    if (r0 >= FRSIZE)
        errcom("frlist error");
    r2 -= (tuword)&hblk;            // Back to the original hblk (== headers)
    frlist[r0] = r2;                // List this free block in the list of free blocks

    // install plausible pointers to make octal dumps look ok
    r1 = (tuword)&hblk;
l1:     
    r1 = *(tword*)r1;
    if (!r1) goto l2;
    r1 += (tuword)&hblk;
    ((sblock_t*)r1)->a = r1;    // doesn't make sense, because we were holding arithmetic offsets in a & l
    ((sblock_t*)r1)->l = r1;
    goto l1;
l2:
    whead();
    reset();
    r2 = POP();
    r0 = POP();
}

// Description:
//      shorter, faster version of preposterous()
void plausible() {
    if ((tuword)r1 < (tuword)strbuf) goto botch;
    if ((tuword)r1 >= (tuword)strend) goto botch;
    return;
botch:
    errcom("error in allocator.");
}

// Description:
//      routine to discover whether r1 points to
//      a plausible header - to avoid ruination.
//      r1 is preserved 
// Return:
//      r0 gets a suitable index for frlist
void preposterous() {
    // Check bounds
    if ((tptr)r1 < (tptr)strbuf) goto botch;
    if ((tptr)r1 >= (tptr)strend) goto botch;
    sblock_t* _r1 = (sblock_t*)r1;      // Conveniene casting
    if (_r1->a < HEADSZ) goto botch;
    if (_r1->l > DATADR) goto botch;
    
    // Check that allocated block size is a power of 2
    tword asz = _r1->l - _r1->a;        // Allocated size of the block
    tword ilog = ilog2(asz);
    //ilog <<= 1;                       // This was to convert r0 (ilog) to byte offset for frlist; not needed
    if ((1<<ilog) != asz) goto botch;

    // Avoid freeing a block that was already freed
    r0 = frlist[ilog];
    while (r0 != 0) {
        r0 += (tword)&hblk;
        if (r0 == r1) goto botch;       // Error: block pointed by r1 is listed as free.
        r0 = *(tptr)r0;                 // Same as *(tptr)((sblock_t*)r0)->w 
    }

    r0 = ilog;
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
    frlist[r0] = (tuword)r1 - (tuword)&hblk;    // Note: frlist contains offsets relative to hblk
    r1 = 0;                 // self-defense
    // whead()
    r0 = POP();
}

// Description:
//      Reset buffers.
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
    DEBUG("    seekchar()");
    PUSH(r1);
    PUSH(r0);
    do {
        r0 = stack[sp];         // Restore r0 (position)
        r0 += (tuword)((sblock_t*)r1)->a;
        if (r0 > ((sblock_t*)r1)->l) {
            // Step 1: extend string (if necessary)
            r0 = stack[sp];     // Requested allocation size for string r1
            allocate();
            r0 = stack[sp+1];
            copy();             // Copy the string to newly allocated block currently in r1
            swap();             // r0 <- new block, r1 <- old block
            release();          // Free old block pointed by r1
            r1 = stack[sp+1];   // Restore r1 (string)
        } else {
            // Step 2: actually move the read pointer
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
    fwrite(&hblk, 1, HSZ, afout);
}
