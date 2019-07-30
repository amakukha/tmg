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
tword afi;
FILE* afout;
tword datadr;
tptr  hblk;                         // must remain here - pointer to free header
tword frlist[FRSIZE];               // NOTE: originally hblk immediately precedes frlist
#define frend   (frlist + FRSIZE)
char  strbuf[HSZ];                  // NOTE: originally hblk immediately precedes strbuf, strbuf overlaps with frlist
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
//	W - write ptr (also used as link ptr in frlist)
//	R - read ptr
//	A - pointer to head of data
//	L - ptr to (end+1) of data
typedef struct sblock {
    tptr w; 
    tptr r;
    tptr a;
    tptr l;
} sblock_t;

// Function declarations

void allocate();
void alterword();
void clean();
void copy();
void release();
void reset();
void seekchar();
void swap();
void wc();
void whead();

// Function definitions

void allocate() {
    // TODO
}

void alterword() {
    // TODO
}

// Description:
//	routine to wc a buffer
// Parameters:
//      bn  - buffer index
//      buf - beginning of buffer
void clean(tword bn, char* buf) {
    fseek(afout, b1s[bn], SEEK_SET);
    fwrite(buf, 1, BUFSIZE, afout);
    w1[bn] = 0;
}

// Description:
//	routine to copy the contents of one string
//	to another.
// Parameters:
//	r0 - source
//	r1 - dest
// Return:
//	on return, r1 points to the new string and should
//	be saved.  r0 is preserved.
void copy() {
    PUSH(r0);
    PUSH(r2);
    //PUSH(r3);
    wc();
l1:
    reset();
    // <-- CONT
//1:	jsr	pc,reset
//	mov	w(r0),r2
//	sub	a(r0),r2	/W-A
//	mov	l(r1),r3
//	sub	a(r1),r3	/L-A
//	cmp	r2,r3
//	ble	1f
//	jsr	pc,release
//	mov	r2,r0
//	jsr	pc,allocate
//	mov	4(sp),r0
///
//1:	mov	a(r1),w(r1)	/rewind w pointer
//	mov	a(r0),-(sp)
///
//4:	mov	(sp),0f
//	mov	afi,r0
//	sys	seek;0:.. ;0	/set input pointer
//	cmp	r2,$512.
//	ble	2f
//	mov	$512.,r3	/# output this time
//	mov	r3,0f
//	mov	r3,3f
//	add	r3,(sp)
//	sub	r3,r2	/# left to output
//	br	1f
///
//2:	mov	r2,0f
//	mov	r2,3f
//	mov	r2,r3
//	clr	r2
///
//1:	mov	afi,r0
//	sys	read;b1;0:..
//	bes	bad
//	cmp	r0,r3
//	bne	bad
//	mov	afout,r0
//	mov	(r1),0f
//	add	r3,(r1)
//	sys	seek;0:.. ;0
//	sys	write;b1;3:..
//	bes	bad
//	tst	r2
//	bgt	4b
//	tst	(sp)+
//	mov	4(sp),r0	/restore r0
////
////	fix up read ptr of new string
////
//1:	mov	r(r0),r2
//	sub	a(r0),r2
//	add	a(r1),r2
//	mov	r2,r(r1)
////
////	restore and return
////
//	mov	(sp)+,r3
//	mov	(sp)+,r2
//	mov	(sp)+,r0
//	rts	pc
///
//bad:
//        errcom("error on copy");
}

void release() {
    // TODO
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

// Parameters:
//      r0 - position
//      r1 - ...
void seekchar() {
    PUSH(r1);
    PUSH(r0);
l1:
    r0 = stack[sp];
    r0 += (tuword)((sblock_t*)r1)->a;
    if ((tptr)r0 > ((sblock_t*)r1)->l) goto l3;
    ((sblock_t*)r1)->r = (tptr)r0;
    if ((tptr)r0 < ((sblock_t*)r1)->w) goto f1;
    ((sblock_t*)r1)->w = (tptr)r0;
    goto f1;
l3:
    r0 = stack[sp];
    allocate();
    r0 = stack[sp+1];
    copy();
    swap();
    release();
    r1 = stack[sp+1];
    goto l1;
f1:
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
    fseek(afout, 0L, SEEK_SET);
    fwrite(hblk, 1, HSZ, afout);
}
