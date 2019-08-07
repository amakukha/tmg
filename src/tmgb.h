// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

#include <limits.h>
#include <stdint.h>
#include "libs.h"

// Defined in tmga.c
extern bool verbose;
extern uint8_t* classtab;

extern void  alt();
extern tword iget();
extern void  errcom(const char* msg);
extern void  fail();
extern void  generate();
extern void  obuild();
extern void  parse();
extern void  putch();
extern void  succ();
extern void  tgoto();
extern void  _tp();

char putbuff[256];      // Used in putdec

// Variables from tmgb
#define INPT 128        // Input buffer size; NOTE: Must be power of two
char  inpb[INPT];       // Input buffer
tword inpr = 0;         // Input file offset
tword jgetc = 0;        // Statistic: jget calls
tword litc = 0;         // 
tword readc = 0;        // Input read statistic
tword trswitch = 0;     // Trace switch

// Function declarations
void _a();
void _da();
void _db();
void _eq();
void _false();
void _ge();
void _ia();
void _ib();
void _l();
void _n();
void _ne();
void _o();
void _p();
void _px();
void _pxcommon();
void _pxs();
void _s();
void _st();
void _t();
void _true();
void _tx();
void _txs();
void _u();
void _x();

void decimal();
void _decimal();
void jget();
void kput();
void octal();
void _octal();
void putcall();
void putdec();
void puthex();
void putoct();
void sprv();
void trans();
void trace();
void update();

// Function definitions

// infix +
void _a() {
    sprv();
    stack[sp+2] += stack[sp];
    return _p();    // Tail call
}

// potsfix --
void _da() {
    stack[sp]--;
    update();
    stack[sp]++;
    return succ();  // Tail call
}

// prefix --
void _db() {
    stack[sp]--;
    DEBUG("    _db: new value: %lx", stack[sp]);
    return _u();    // Tail call
}

void _eq() {
    sprv();
    if (stack[sp+2] == stack[sp])
        return _true();     // Tail call
    else
        return _false();    // Tail call
}

// from tmgb/reln.s, original name false
void _false() {
    stack[sp+2] = 0;
    return _p();    // Tail call
}

void _ge() {
    sprv();
    if (stack[sp+2] >= stack[sp])
        return _true();     // Tail call
    else
        return _false();    // Tail call
}

// postfix ++
void _ia() {
    stack[sp]++;
    update();
    stack[sp]--;
    return succ();  // Tail call
}

// prefix ++
void _ib() {
    stack[sp]++;
    return _u();    // Tail call
}

// load named value
// rvalue into (sp), lvalue into 2(sp)
void _l() {
    iget();
    PUSH(r0);
    PUSH(*(tptr)r0);
    DEBUG("    loaded: %lx",*(tptr)r0);
    return succ();  // Tail call
}

// infix &
void _n() {
    sprv();
    stack[sp+2] &= stack[sp];
    return _p();    // Tail call
}

void _ne() {
    sprv();
    if (stack[sp+2] != stack[sp])
        return _true();     // Tail call
    else
        return _false();    // Tail call
}

// infix |
void _o() {
    sprv();
    stack[sp+2] |= stack[sp];
    return _p();    // Tail call
}

// pop stack
void _p() {
    DEBUG("    _p()");
    sprv();
    //cmp   (sp)+,(sp)+
    POP();  POP();
    return succ();  // Tail call
}

void _px() {
    iget();
    return _pxcommon(); // Tail call
}

void _pxs() {
    r0 = (tword)i++;
    return _pxcommon(); // Tail call
}

// TODO: what does it do?
// .pn:1 .pxs;012   - expects a newline?
void _pxcommon() {
    litc++;
    PUSH(((parse_frame_t*)f)->n);
    PUSH(((parse_frame_t*)f)->j);
    PUSH(r0);
    while ((char)stack[sp]) {
        jget();
        if (r0!=(char)stack[sp]) {
            POP();
            ((parse_frame_t*)f)->j = POP();
            ((parse_frame_t*)f)->n = POP();     // Restore input cursor on failure
            return fail();  // Tail call
        }
        ((parse_frame_t*)f)->n = 0;             // Do not ignore any characters
        stack[sp]++;                            // TODO: what is the meaning?
        ((parse_frame_t*)f)->j++;               // Advance input cursor
    }
    //cmp   (sp)+,(sp)+
    POP();  POP();
    ((parse_frame_t*)f)->n = POP();             // Restore ignored character class
    return succ();  // Tail call
}

// infix -
void _s() {
    sprv();
    stack[sp+2] -= stack[sp];
    return _p();    // Tail call
}

// infix =
void _st() {
    sprv();
    POP_PREV();
    POP_PREV();
}

// test stack
void _t() {
    sprv();
    if (POP()) {
        POP();
        return succ();  // Tail call
    } else {
        POP();
        return fail();  // Tail call
    }
}

// from tmgb/reln.s, original name true
void _true() {
    stack[sp+2] = 1;
    return _p();    // Tail call
}

void _tx() {
    DEBUG("    _tx()");
    r0 = *i++;
    DEBUG("    _tx: r0=%lx", (tword)r0);
    // Unlike in the original, r0 contains address of address of C-string
    // (rather than address of the string directly)
    r0 = *(tptr)r0;
    obuild();
    return generate();  // Tail call
}

void _txs() {
    DEBUG("    _txs()");
    r0 = (tword)i;
    i++;
    obuild();
    return generate();  // Tail call
}

// update
void _u() {
    update();
    return succ();  // Tail call
}

// infix ^ exclusive or
void _x() {
    sprv();
    stack[sp+2] ^= stack[sp];
    return _p();    // Tail call
}

void decimal() {
    DEBUG("    decimal()");
    r0 = 1 + (tword)&_decimal;
    putcall();
    iget();
    r0 = *(tptr)r0;
    kput();
    return succ();  // Tail call
}

void _decimal() {
    r0 = *i;
    putdec();
    return generate();    // Tail call
}

// Description:
//      Get next character from input which is not in ignored class.
// Return:
//      r0 - character
void jget() {
    jgetc++;
    do {
        r1 = ((parse_frame_t*)f)->j;    // input cursor
        r0 = BIT_CLEAR(INPT-1, r1);     // Clear lower 7 bits (INPT is 128); input file offset
        r1 = BIT_CLEAR(r0, r1);         // Leave lower 7 bits of r1
        if (r0 != inpr) {               // Input buffer needs to be updated?
            // Read next portion of buffer from the input file
            readc++;
            inpr = r0;                  // Remember current input file offset
            fseek(input, inpr, SEEK_SET);
            r0 = fread(inpb, 1, INPT, input);
            for (; r0<INPT; r0++)
                inpb[r0] = 0;           // Rest of buffer is zeroed, loop will exit on '\0'
        }
        do {
            r0 = inpb[r1];
            //r0 <<= 1;                 // Conversion to word offset
            if (!(classtab[r0] & ((parse_frame_t*)f)->n))   // n - address of ignored character class
                goto done;
            ((parse_frame_t*)f)->j++;
            r1++;
        } while (r1 < INPT);
    } while (1);
done:
    //r0 >>= 1;                         // Last character
    return;
}

void kput() {
    ((parse_frame_t*)f)->k -= sizeof(tword);
    r1 = -((parse_frame_t*)f)->k;
    if (r1 >= ktat)
        errcom("translation overflow");
    *((tptr)(ktab + r1)) = r0;
}

void octal() {
    DEBUG("    octal()");
    r0 = 1 + (tword)&_octal;
    putcall();
    iget();
    r0 = *(tptr)r0;
    kput();
    return succ();  // Tail call
}

void _octal() {
    r0 = *i;
    putoct();
    return generate();  // Tail call
}

void putcall() {
    kput();
    *g++ = ((parse_frame_t*)f)->k;
}

// Description:
//      Output decimal representation of a number into output file.
//      (This is a rewrite rather than a translation.)
// Parameters:
//      r0 - number
void putdec() {
    sprintf(putbuff, "%ld", r0);
    r0 = (tword)putbuff;
    return obuild();    // Tail call
}

void puthex() {
    // Derived from putoct (hex is much more convenient for modern machines)
    PUSH(r0);
    r0 = (tword)BIT_CLEAR(15, r0);
    stack[sp] = (tword)BIT_CLEAR(r0, stack[sp]);
    r0 >>= 4;
    if (r0) puthex();
    r0 = POP();
    if (r0 < 10) r0 += '0';
    else r0 += 'W';
    putch();
}

void putoct() {
    PUSH(r0);
    r0 = (tword)BIT_CLEAR(7, r0);
    stack[sp] = (tword)BIT_CLEAR(r0, stack[sp]);
    r0 >>= 3;
    if (r0) putoct();
    r0 = POP() + '0';
    putch();
}

// from: arith.s
// make sp hold a simple rvalue (forget it might be a table value)
void sprv() {
    DEBUG("    sprv()");
    if (stack[sp+1]==-1) {
        POP_PREV();
        POP_PREV();
    }
}

void trans() {
    DEBUG("    trans()");
    *g++ = iget();
    return succ();  // Tail call
}

void trace() {
    DEBUG("    trace(): %c%lx", (char)r0, (tuword)i);
    putch();
    r0 = 'x';
    putch();
    r0 = (tword)i;
    puthex();
    r0 = '\n';
    putch();
}

// from: arith.s
// update a stored value, used by all assignments
// NOTE: all stack offsets are smaller by 1, because calls don't use `stack`
void update() {
    DEBUG("    update()");
    if (stack[sp+1] != -1) {
        DEBUG("    0(): %lx", stack[sp+1]);
        *(tptr)stack[sp+1] = stack[sp];
        return;
    }
    DEBUG("    1()");
    // TODO: what's the meaning of this?
    r1 = stack[sp+2];
    r0 = stack[sp+3];
    seekchar();
    r0 = stack[sp];
    alterword();
    return sprv();  // Tail call
}
