// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2019, Andriy Makukha, 2-clause BSD License.

#include <limits.h>
#include <stdint.h>
#include "libs.h"

// Defined in tmga.c
extern bool verbose;
extern tword* classtab;

extern void  alt();
extern tword iget();
extern void  errcom(const char* msg);
extern void  fail();
extern void  generate();
extern void  obuild();
extern void  parse();
extern void  pbundle();
extern void  putch();
extern void  salt();
extern void  succ();
extern void  tgoto();
extern void  _tp();

char putbuff[256];      // Used in putdec (size can be reduced)

// Variables from tmgb
#define INPT 128        // Input buffer size; NOTE: Must be power of two
tword ctestc = 0;       // Statistic: ctest calls
char  inpb[INPT];       // Input buffer
tword inpr = 1;         // Input file offset
tword jgetc = 0;        // Statistic: jget calls
tword litc = 0;         // 
tword readc = 0;        // Input read statistic
tword trswitch = 0;     // Trace switch

// Variables from tmgb/cstr.s:
//      current string manipulations
//      keep a initial fragment handy for quick access
//      go to allocator for the rest
#define CSTRT 16        // top of quick access current string
char  cstrb[CSTRT];     // base of quick access fragment
tword cstrr;            // read pointer. (Index of cstrb.)
tword cstrw = 0;        // current string write pointer. (Index of cstrb.)
sblock_t* symp = NULL;  // pointer to dynamically allocated current string

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

void any();
void bundle();
void _bundle();
void ctest();
void decimal();
void _decimal();
void getcstr();
void ignore();
void jget();
void kput();
void octal();
void _octal();
void putcall();
void putcstr();
void putdec();
void puthex();
void putoct();
void reduce();
void rewcstr();
void scopy();
void _scopy();
void size();
void smark();
void sprv();
void string();
void trans();
void trace();
void update();

// Function definitions

// infix +
void _a() {
    sprv();
    stack[sp+2] += stack[sp];
    DEBUG("    infix + = %ld", stack[sp+2]);
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
    DEBUG("    infix & = %ld", stack[sp+2]);
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
    DEBUG("    infix | = %ld", stack[sp+2]);
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
    // Unlike in the original, r0 contains address of address of C-string
    // (rather than address of the string directly)
    r0 = *(tptr)r0;
    return _pxcommon(); // Tail call
}

void _pxs() {
    r0 = (tword)i++;
    DEBUG("    _pxs(): address of word-length C-string: %lx", r0);
    return _pxcommon(); // Tail call
}

// .pn:1 .pxs;012   - expects a newline? TODO: what does it do exactly?
// Parameters:
//      r0 - address of C-string
void _pxcommon() {
    litc++;
    PUSH(((parse_frame_t*)f)->n);
    PUSH(((parse_frame_t*)f)->j);
    PUSH(r0);
    while (*(char*)stack[sp]) {
        jget();
        if (r0!=*(char*)stack[sp]) {
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
    DEBUG("    infix - = %ld", stack[sp+2]);
    return _p();    // Tail call
}

// infix =
void _st() {
    DEBUG("    infix =");
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
    r0 = (tword)i;
    i++;
    DEBUG("    _txs(): address of word-length C-string: %lx", r0);
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
    DEBUG("    infix ^ = %ld", stack[sp+2]);
    return _p();    // Tail call
}

void any() {
    DEBUG("    any()");
    PUSH(((parse_frame_t*)f)->j);
    iget();
    ctest();
    if (carry) {
        POP();
        return succ();  // Tail call
    } else {
        ((parse_frame_t*)f)->j = POP();
        return fail();  // Tail call
    }
}

void bundle() {
    r0 = (tword)f + sizeof(parse_frame_t);
    return _bundle();   // Tail call
}

void _bundle() {
    pbundle();
    //tst r0        // Sets n- and z-bits, clears v- (overflow) and c-bits
    failure = false;
    if (r0)
        *g++ = r0;
    return succ();  // Tail call
}

// Description:
//      Gets one character from the input and tests against current character class
// Parameters:
//      r0 - pointer to character class
// Return:
//      Carry bit set if the charater belongs to the character class
void ctest() {
    DEBUG("    ctest(): character class = %ld", *(tptr)r0);
    ctestc++;
    PUSH(r0);
    jget();
    DEBUG("    ctest(): classtab[r0] = %ld", classtab[r0]);
    //r0 <<= 1;
    if (*(tptr)POP() & classtab[r0]) {
        carry = false;
        //r0 >>= 1;
        putcstr();
        ((parse_frame_t*)f)->j++;
        carry = true;
    } else {
        carry = false;
    }
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
//     TODO: how it works? What it does?
void getcstr() {
    r1 = cstrr;
    if (r1 >= cstrw) {
        r0 = 0;         // end of string
        return;
    }
    cstrr++;
    if (r1 < CSTRT) {
        r0 = cstrb[r1];
        return;
    }
    if (r1 == CSTRT) {      // WHY???
        r1 = (tword)symp;
        rewinds();
    }
    r1 = (tword)symp;
    getschar();
}

void ignore() {
    iget();
    ((parse_frame_t*)f)->n = *(tptr)r0;
    return succ();  // Tail call
}

// Description:
//      Get next character from input which is not in ignored class.
// Return:
//      r0 - character
void jget() {
    jgetc++;
    do {
        r1 = ((parse_frame_t*)f)->j;    // input cursor
        r0 = BIT_CLEAR(INPT-1, r1);     // Clear lower 7 bits of r1 (INPT is 128); input file offset
        r1 = BIT_CLEAR(r0, r1);         // Leave lower 7 bits of r1
        if (r0 != inpr) {               // Input buffer needs to be updated?
            // Read next portion of buffer from the input file
            DEBUG("    jget: reading next portion, %ld != %ld", r0, inpr);
            readc++;
            inpr = r0;                  // Remember current input file offset
            fseek(input, inpr, SEEK_SET);
            r0 = fread(inpb, 1, INPT, input);
            DEBUG("    jget: offset = %ld, bytes read %ld", inpr, r0);
            for (; r0<INPT; r0++)
                inpb[r0] = 0;           // Rest of buffer is zeroed, loop will exit on '\0'
        }
        do {
            r0 = inpb[r1];
            DEBUG("    jget: char=\"%c\" (%d)", (char)r0>=32 && (char)r0<127 ? (char)r0 : '?', (uint8_t)r0);
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

// Description:
//      Puts word r0 into table ktab
// Parameters:
//      r0 - Contents to be put into ktable
// Side effect:
//      r1 - Contains ktab offset in bytes where r0 was put
void kput() {
    ((parse_frame_t*)f)->k -= sizeof(tword);
    r1 = -((parse_frame_t*)f)->k;
    if (r1 >= KTAT)
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
    DEBUG("    putcall: r0=%lx", r0);
    kput();
    *g++ = ((parse_frame_t*)f)->k;
}

// TODO: how it works? What it does?
// Description:
//      Put character into current string.
// Parameters:
//      r0 - char
void putcstr() {
    r1 = cstrw++;
    if (r1 < CSTRT) {           // is it quick access?
        cstrb[r1] = (char)r0;   // yes, stash the char
        return;
    }
    if (r1 == CSTRT) {          // WHY???
        PUSH(r0);               // first char to allocator
        r1 = (tword)symp;
        if (!r1) {
            r0 = 64;
            allocate();
            symp = (sblock_t*)r1;
        }
        creates();              // Rewind write pointer of string pointed by r1
        r0 = POP();
    }
    r1 = (tword)symp;
    putschar();
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

void reduce() {
    iget();
    r1 = *(tptr)r0;
    r0 = (tword)g;
    //r1 <<= 1;         // Accounting for word size
    r0 -= r1*sizeof(tword);
    return _bundle();   // Tail call
}

// Description:
//      rewind current string
void rewcstr() {
    cstrr = 0;      // Resets read pointer of the current string
}

// Description:
//      TMG builtin. Copies a string into ktab.
void scopy() {
    DEBUG("    scopy()");
    r0 = 1 + (tword)&_scopy;
    putcall();
    rewcstr();
    r2 = -(tword)((parse_frame_t*)f)->k + sizeof(tword);
    do {
        getcstr();
        if (!r0) break;
        ktab[r2++] = (uint8_t)r0;
        if (r2 >= KTAT)
            errcom("translation overflow");
    } while(1);
    ktab[r2] = 0;
    r2 = BIT0_CLEAR(r2);
    r2 = -r2;
    ((parse_frame_t*)f)->k = r2;
    return succ();  // Tail call
}

// Description:
//      Part of scopy() used via putcall.
void _scopy() {
    DEBUG("    _scopy(): \"%s\"", (char*)i);
    r0 = (tword)i;              // Pointer to C-string to be sent to output
    obuild();
    return generate();  // Tail call
}

void size() {
    iget();
    *(tptr)r0 = cstrw;
    return succ();  // Tail call
}

void smark() {
    DEBUG("    smark()");
    jget();
    cstrw = 0;
    return succ();  // Tail call
}

// from: arith.s
// make sp hold a simple rvalue (forget it might be a table value)
void sprv() {
    DEBUG("    sprv()");
    if (stack[sp+1]==-1) {
        DEBUG("    - 2x POP_PREV()");
        POP_PREV();
        POP_PREV();
    }
}

// Description:
//      Advances input pointer (j) as long as it matches the character class
//      NOTE: It will always succeed. Even if zero characters match.
void string() {
    DEBUG("    string()");
    PUSH(0);        // Temporary
    iget();         // Retrieve pointer to character class into r0
    do {
        stack[sp] = ((parse_frame_t*)f)->j;     // Update Temporary
        PUSH(r0);
        ctest();
        r0 = POP();
    } while (carry);
    ((parse_frame_t*)f)->j = POP();             // Retrieve Temporary
    return succ();  // Tail call
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
