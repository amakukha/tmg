// Port of the Unix compiler-compiler TMG to C99.
// Based on the original PDP-11 assembly code by M. D. McIlroy.
// (c) 2020, Andriy Makukha, 2-clause BSD License.

#include <limits.h>
#include <stdint.h>
#include "libs.h"

// Defined in tmga.c
extern bool verbose;
extern tword* classtab;

extern void alt();
extern void diag();
extern void iget();
extern void errcom(const char* msg);
extern void fail();
extern void flush();
extern void generate();
extern void obuild();
extern void parse();
extern void pbundle();
extern void putch();
extern void salt();
extern void succ();
extern void tgoto();
extern void _tp();

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
char  cstrb[CSTRT];     // base of quick access fragment. (Quick access part of the current string.)
tword cstrr;            // read pointer. (Index of cstrb.)
tword cstrw = 0;        // current string write pointer. (Index of cstrb.)
sblock_t* symp = NULL;  // pointer to dynamically allocated (part of the) current string

// Structure from tmgb/find.s
//typedef struct table_record {
//    tword index;
//    tword tablep;
//    tword temp;
//    tword which;
//} table_record_t;
//#define framel sizeof(table_record_t)       // just for reference, not to be used

// Function declarations
void _a();
void _cm();
void _da();
void _db();
void _eq();
void _f();
void _false();
void _ge();
void _gt();
void _ia();
void _ib();
void _l();
void _le();
void _lt();
void _lv();
void _m();
void _n();
void _ne();
void _ng();
void _nt();
void _o();
void _p();
void _px();
void _pxcommon();
void _pxs();
void _q();
void _r();
void _rv();
void _s();
void _sl();
void _sr();
void _st();
void _t();
void _true();
void _tq();
void _tx();
void _txs();
void _u();
void _x();

void accept();
void _accept();
void any();
void append();
void bundle();
void _bundle();
void ctest();
void decimal();
void _decimal();
void discard();
void emit();
void enter();
void find();
void _find();
void getcstr();
void getnam();
void _getnam();
void gotab();
void gpar();
void ignore();
void jget();
void kput();
void octal();
void _octal();
void params();
void push();
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
void table();
void tchar();       // Original name char, collision with C type
void trace();
void trans();
void tstack();      // Original name stack, collision with stack array
void unstack();
void update();

// Function definitions

// infix +
void _a() {
    sprv();
    stack[sp+2] += stack[sp];
    DEBUG("    infix + = %ld", stack[sp+2]);
    return _p();    // Tail call
}

// unary ~
void _cm() {
    stack[sp] = ~stack[sp];
    return succ();  // Tail call
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

// Description:
//      Get word value from a table.
//      This is called when table indexing syntax is used: t[i]
void _f() {
    DEBUG("    _f:");
    r0 = stack[sp];     // Position for seekchar
    stack[sp+3] = r0;
    r1 = stack[sp+2];   // Pointer to the string (sblock_t)
    seekchar();
    getword();
    DEBUG("    _f: val=%ld", r0);
    stack[sp] = r0;
    stack[sp+1] = -1;
    return succ();  // Tail call
}

// From tmgb/reln.s, original name false
void _false() {
    stack[sp+2] = 0;
    return _p();    // Tail call
}

// Greater or equal
void _ge() {
    sprv();
    if (stack[sp+2] >= stack[sp])
        return _true();     // Tail call
    else
        return _false();    // Tail call
}

// Greater than
void _gt() {
    sprv();
    if (stack[sp+2] > stack[sp])
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
    DEBUG("    _l:");
    iget();
    PUSH(r0);
    PUSH(*(tptr)r0);
    DEBUG("    _l: loaded rvalue=0x%lX, lvalue=0x%lX", r0, *(tptr)r0);
    return succ();  // Tail call
}

// Less or equal
void _le() {
    sprv();
    if (stack[sp+2] <= stack[sp])
        return _true();     // Tail call
    else
        return _false();    // Tail call
}

// Less than
void _lt() {
    sprv();
    if (stack[sp+2] < stack[sp])
        return _true();     // Tail call
    else
        return _false();    // Tail call
}

// Description:
//      unary &, prefixed to an lvalue
//      return lvalue
void _lv() {
    stack[sp] = stack[sp+1];            // Lvalue becomes rvalue. New rvalue is the address.
    return succ();  // Tail call
}

// Multiplication
// NOTE: MPY / MUL instruction seems to have worked differently from the
//       one described in the "PDP11 Processor Handbook"
void _m() {
    DEBUG("    _m");
    sprv();
    // Short version
    stack[sp+2] *= stack[sp];
    // Long version (with r0,r1 side effects)
    //r0 = stack[sp];
    //r1 = r0*stack[sp+2];
    //stack[sp+2] = r1;
    DEBUG("    infix * = %ld", stack[sp+2]);
    return _p();    // Tail call
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

// unary -
void _ng() {
    stack[sp] = -stack[sp];
    return succ();  // Tail call
}

// unary !
void _nt() {
    //stack[sp] = !stack[sp];
    stack[sp] = stack[sp] ? 0 : 1;
    return succ();
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

void _q() {
    sprv();
    stack[sp+2] /= stack[sp];
    return _p();
}

void _r() {
    sprv();
    stack[sp+2] %= stack[sp];
    return _p();
}

// Description:
//      unary *, prefixed to an rvalue:
//      indirection, take rvalue to be lvalue
//      (NOTE: lvalue - something that can be assigned; to the left of assignment.)
void _rv() {
    stack[sp+1] = stack[sp];            // Rvalue becomes lvalue (address stored in rvalue "materializes").
    stack[sp] = *(tptr)stack[sp+1];     // Rvalue changes to be the contents of that address.
    return succ();
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

// Shift left <<
void _sl() {
    // TODO: do we need to set c-bit?
    stack[sp+2] <<= stack[sp];
    return _p();    // Tail call
}

// Shift right >>
void _sr() {
    // TODO: do we need to set c-bit?
    stack[sp+2] >>= stack[sp];
    return _p();    // Tail call
}

// infix =
void _st() {
    DEBUG("    _st: infix =");
    sprv();
    POP_PREV();
    POP_PREV();
    return _u();    // Tail call
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

// From tmgb/reln.s, original name true
void _true() {
    stack[sp+2] = 1;
    return _p();    // Tail call
}

// TODO: what is it? what it does?
void _tq() {
    DEBUG("    _tq()");
    r0 = *i++;
    ((translation_frame_t*)f)->si = i;
    r1 = (tword)((translation_frame_t*)f)->ep;
    translation_frame_t* _f_fs = (translation_frame_t*)((tword)f + fs);      // For convenience
    _f_fs->ep = ((translation_frame_t*)r1)->ep;
    _f_fs->ek = ((translation_frame_t*)r1)->ek;
    r1 = (tword)((translation_frame_t*)r1)->si;
    r0 *= sizeof(tword);    //r0 <<= 1;   // Accounting for word size
    r1 -= r0;
    i = (tptr)(*(tptr)r1);
    f = (tptr)((tword)f + fs);      // Alternatively: f = _f_fs;
    ((parse_frame_t*)f)->x = 0;     // Clear exit bit
    generate();
    return generate();  // Tail call
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

// Description:
//      builtin for shift-reduce parsing.
//      clean out all states from stack
// Tmg Manual:
//      "unstack remaining labels stacked during this rule and bundle"
//      delivers a translation
void accept() {
    DEBUG("    accept()");
    r1 = (tword)f + sizeof(parse_frame_t);
    return _accept();   // Tail call
}

// Description:
//      Part of accept. Called from unstack()
void _accept() {
    DEBUG("    _accept()");
    r0 = r1;
    PUSH(r1);
    do {
        if (r1 >= (tword)g)
            break; 
        bool r = (*(tptr)r1) & (HIGHEST_BIT | 1);       // Statefull
        r1 = (tword)((tptr)r1 + 1);     // (r1)+
        if (!r)
            continue;
        *(tptr)r0 = *((tptr)r1 - 1);    // mov -2(r1),(r0)
        r0 = (tword)((tptr)r0 + 1);     // (r0)+
    } while (1);
    g = (tptr)r0;
    r0 = POP();
    pbundle();
    if (!r0)
        *g++ = r0;
    return succ();  // Tail call
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

// Description:
//      Builtin append(l).
//      Append string literal to the current string. 
void append() {
    iget();
    // Unlike in the original, r0 contains address of address of C-string
    // (rather than address of the string directly)
    r0 = *(tptr)r0;     // Pointer to C-string address -> C-string address
    PUSH(r0);
    do {
        r0 = *(uint8_t*)stack[sp];
        if (!r0) break;
        putcstr();
        stack[sp]++;
    } while(1);
    POP();
    return succ();  // Tail call
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

void tchar() {
    jget();
    if (!r0) {
        // tst (i)+     // Sets n- and z-bits, clears v- (overflow) and c-bits
        i++;
        failure = false;
        return fail();  // Tail call
    }
    PUSH(r0);
    iget();
    *(tptr)r0 = POP();
    ((parse_frame_t*)f)->j++;
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
    //r0 <<= 1;     // Conversion to word offset
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

// Description:
//      Part of decimal() used via putcall.
void _decimal() {
    r0 = *i;
    putdec();
    return generate();    // Tail call
}

// Description:
//      Builtin: discard(t)
//      discard table t
void discard() {
    iget();         // Retrieve the parameter
    r1 = *(tptr)r0;
    release();
    succ();
}

// Description:
//      "execute and forget last translation delivered to this rule"
void emit() {
    DEBUG("    emit(): NOT IMPLEMENTED");
    // TODO: emit routin refers to an unknown routine `dogen`
}

// Description:
//      Builtin enter(t,i).
//      look up the current string in table t;
//      enter if not there; assign its index to variable i;
//      fail if current string is empty 
void enter() {
    DEBUG("    enter()");
    PUSH(0);        // which(sp)
    return _find(); // Tail call
}

// Description:
//      Builtin find(t,i).
//      look up the current string in table t;
//      assign its index to variable i;
//      fail if not there (or the current string is empty)
void find() {
    DEBUG("    find()");
    PUSH(1);        // which(sp) // Instead of pc
    return _find(); // Tail call
}

// TODO: not entirely clear how it works
void _find() {
    DEBUG("    _find(): find=%ld", stack[sp]);
    rewcstr();
    getcstr();
    if (!r0) {
        // The current string is empty -> find/enter fails
        POP();
        return fail();  // Tail call
    }
    DEBUG("    _find(): chr=%c", (char)r0);
    PUSH(0);            // temp(sp)
    iget();             // Get first parameter: the table pointer
    PUSH(*(tptr)r0);    // tablep(sp)
    PUSH(0);            // index(sp)
right:
    //add     $rptr,index(sp)
    //br      1f
    stack[sp] += 4;
    goto next;
left:
    //add     $lptr,index(sp)
    stack[sp] += 2;
next:                   // get index of next entry
    r1 = stack[sp+1];   // tablep (Which is an sblock_t*.) 
    r0 = stack[sp];     // index + 3 +/- 1
    seekchar();
    getword();
    //tst r0    // Sets n- and z-bits, clears v- (overflow) and c-bits
    if (!r0)            // No table entry found for the current string
        goto nomore;
    stack[sp] = r0;
    r0 += 6;            // add $sptr,r0     (Location of the table entry string is in r0 now.)
    //r0 = (tword)((symbol_t*)r0)->sptr;
    seekchar();
    rewcstr();
    do {                // comparison loop. (Compare the current string with the table entry string.)
        r1 = stack[sp+1];   // tablep
        getschar();     // Character from the table entry
        PUSH(r0);
        getcstr();      // Character from the current string
        tword pop = POP();
        if (r0 > pop)   // Current string is greater -> go to the right.
            goto right;
        if (r0 < pop)   // Current string is lower -> go to the left.
            goto left;
        //tst r0
        if (!r0)        // Reached the end of the current string
            goto found;
    } while (1);

nomore:         // not in table
    if (stack[sp+3]) {     // which(sp); (If non-zero, then it was a find() call.)
        // exit from find
        //tst (i)+
        i++;
        sp += 4;        // Instead of 4x POP()
        return fail();
    }

    // Enter the current string into the table
    r1 = stack[sp+1];   // tablep
    length();
    stack[sp+2] = r0;   // temp <- Length
    r0 = 0;
    putword();          // scratch word. (User-accessible table data.)
    putword();          // left pointer
    putword();          // right pointer
    r0 = stack[sp];     // index
    seekchar();         // Move the read pointer of the string to this newly added table entry
    r0 = stack[sp+2];   // temp == Length
    stack[sp] = r0;     // index
    alterword();
    rewcstr();
    do {                // copy loop
        getcstr();
        r1 = stack[sp+1];   // tablep
        putschar();
    } while (r0);

found:
    // Table entry for the current string was found or added
    iget();             // Get second parameter: index variable
    *(tptr)r0 = stack[sp];     // Save index into the supplied variable
    sp += 4;            // Instead of 4x POP()
    return succ();  // Tail call
}

// Description:
//      Get next character from the current string 
// Return:
//      r0 - Character from the current string 
void getcstr() {
    r1 = cstrr;
    if (r1 >= cstrw) {
        r0 = 0;             // end of string
        return;
    }
    cstrr++;
    if (r1 < CSTRT) {       // Within the quick access fragment?
        r0 = cstrb[r1];     // Yes. 
        return;
    }
    if (r1 == CSTRT) {      // Reached the end of the quick access fragment -> prepare sblock
        r1 = (tword)symp;
        rewinds();
    }
    r1 = (tword)symp;
    getschar();             // Read character from the sblock
}

// Description:
//      Builting getnam(t, i).
//      deliver the string of entry i in table t
void getnam() {
    r0 = 1 + (tword)&_getnam;
    putcall();
    iget();             // Get first parameter `t` - table
    r0 = *(tptr)r0;
    kput();
    iget();             // Get second parameter `i` - entry index
    r0 = *(tptr)r0;
    kput();
    return succ();  // Tail call
}

// Description:
//      Part of getnam() used via putcall.
//      (This function is only called after successful descent.)
void _getnam() {
    if (cfile != lfile) {   // Flush if output destination changed
        flush();
        lfile = cfile;
    }
    r1 = *i++;          // Table "string"
    PUSH(r1);
    r0 = *i++ + 6;      // sptr == three words    TODO: change to actual word size
    seekchar();         // Register r0 contains the character position (i + 6)
    do {
        r1 = stack[sp]; // Restore the table "string"
        r2 = outw;
        do {
            getschar();
            if (!r0)
                goto done;
            outb[r2] = (uint8_t)r0;
        } while ((outw = ++r2) < OUTT);
        flush();
    } while(1);

done:
    POP();
    return generate();  // Tail call
}

// Description:
//      builtin for shift-reduce parsing.
//      gotab(s1,t1,s2,t2,...sn,tn,0,t)
//      checks top of stack for states s1,s2,... and goes to t1, t2 accordingly
//      if top of stack is not in table, goes to t
// Tmg Manual:
//      "list has form s1,l1,s2,l2,...,0,ln; if top stacked label is s1 go to
//      l1, if s2 go to l2, ... else go to ln"
void gotab() {
    DEBUG("    gotab()");
    r0 = (tword)g;
    // find top state
    do {
        r0 = (tword)((tptr)r0 - 1);     // -(r0)
    } while((*(tptr)r0) & (HIGHEST_BIT | 1));
    PUSH(*(tptr)r0);
    do {
        iget();     // Get next parameter
        if (!*(tptr)r0 || r0==stack[sp]) break;
        iget();
    } while (1);
    POP();
    return tgoto(); // Tail call 
}

void gpar() {
    r0 = *i++;
    r1 = (tword)((translation_frame_t*)f)->ep;
    //r0 <<= 1;         // Accounting for word size
    ((translation_frame_t*)r1)->si += r0;
    return generate();  // Tail call
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

// Description:
//      Part of octal() used via putcall.
void _octal() {
    r0 = *i;
    putoct();
    return generate();  // Tail call
}

// Description:
//     Builtin: params(n)
void params() {
    DEBUG("    params: r0=%ld", r0);
    iget();
    r0 = *(tptr)r0;
    //r0 <<= 1;     // Accounting for word size
    r1 = (tword)((parse_frame_t*)f)->env;
    ((parse_frame_t*)r1)->si += r0;
    return succ();  // Tail call
}

// Description:
//     Builtin: push(n, list)
void push() {
    DEBUG("    push");
    iget();
    r2 = *(tptr)r0;         // First parameter - n
    DEBUG("    push: n=%ld", r2);
    r1 = r2;
    // Push each parameter from the `list`
    do {
        PUSH(r1);
        iget();
        r1 = POP();
        PUSH(r0);           // Remember address
        PUSH(*(tptr)r0);    // Remember value
    } while (--r2 > 0);
    PUSH(r1);
    succ();
    DEBUG("    push after succ");
    // preserve c bit from here on
    r2 = POP();             // Original n
    do {
        tword value   = POP();
        tword address = POP(); 
        *(tptr)address = value;
    } while (--r2 > 0);
    // pass sret or fret back to invoking rule
    return;
}

// Description:
//      Puts function pointer r0 into table ktab.
//      See also: kput()
// Parameters:
//      r0 - Function pointer to be put into ktable.
void putcall() {
    DEBUG("    putcall: r0=%lx", r0);
    kput();
    *g++ = ((parse_frame_t*)f)->k;
}

// Description:
//      Put character into current string.
// Parameters:
//      r0 - char
void putcstr() {
    r1 = cstrw++;
    if (r1 < CSTRT) {           // is it quick access?
        cstrb[r1] = (char)r0;   // yes, stash the char (In the quick access fragment)
        return;
    }
    if (r1 == CSTRT) {          // Quick access fragment got full -> prepare sblock
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

// Description:
//      Derived from putoct (hex is much more convenient for modern machines)
//      (Not part of the original code.)
void puthex() {
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
//      TMG builtin. Copies the current string into ktab.
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
    r2 = BIT0_CLEAR(r2);    // TODO: this is like .even directive; maybe needs change for 32- and 64-bit architectures?
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

// From: arith.s
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

// Description:
//      Builtin table(t).
//      make a new table; assign its designator to t
void table() {
    r0 = 8;         // Requested initial size for the table string
    allocate();
    PUSH(r1);       // Save pointer to header of allocated block 
    r0 = 0;
    putword();      // Field `custom`
    putword();      // Field `lptr`
    putword();      // Field `rptr`
    putschar();     // Field `sptr`
    iget();
    *(tptr)r0 = POP();      // Return pointer to the table string (sblock_t*)
    return succ();  // Tail call
}

void trans() {
    DEBUG("    trans()");
    iget();
    *g++ = r0;
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

// Description:
//      builtin for shift-reduce parsing.
//      stack label of present rule (state)
//      should come first in a rule
// Tmg Manual:
//      "place label of this element on stack"
void tstack() {
    DEBUG("    tstack()");
    // mov     i,(g)
    // sub     $2,(g)+      // Word size
    *(tptr)g++ = (tword)i - sizeof(tword);
    return succ();  // Tail call
}

// Description:
//      builtin for shift-reduce parsing.
//      unstack(n) deletes last n stacked states
//      states are distinguishable from translations in not having
//      an exit bit ($1) nor being bundles ($100000 = 0x8000)
// Tmg Manual:
//      "remove last n labels stacked during this rule and bundle all
//      translations delivered since the label so uncovered was stacked"
//      delivers a translation
void unstack() {
    DEBUG("    unstack()");
    iget();             // Get parameter
    r0 = *(tptr)r0;     // n
    r1 = (tword)g;
    do {
        r0 = (tword)((tptr)r0 - 1);     // -(r0)
        if ((*(tptr)r1) & (HIGHEST_BIT | 1))        // TODO: do bundles have highest bit set???
            continue;
    } while (--r0>=0);  // TODO: why >= ?
    r1 = (tword)((tptr)r1 + 1);     // tst (r1)+
    return _accept();   // Tail call
}

// From: arith.s
// update a stored value, used by all assignments
// NOTE: all stack offsets are smaller by 1, because calls don't use `stack`
void update() {
    DEBUG("    update()");
    if (stack[sp+1] != -1) {
        DEBUG("    update: *0x%lX <- %ld", stack[sp+1], stack[sp]);
        *(tptr)stack[sp+1] = stack[sp];
        DEBUG("    updated");
        return;
    }
    DEBUG("    update: -1");
    // TODO: what's the meaning of this?
    r1 = stack[sp+2];
    r0 = stack[sp+3];
    seekchar();
    r0 = stack[sp];
    alterword();
    return sprv();  // Tail call
}
