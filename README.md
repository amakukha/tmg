Port of Unix TMG to C99.

About TMG
--
TMG is an early compiler-compiler, or, according to McIlroy:
> TMG is a string processing language especially intended for writing 
> translators for computer languages. It deals with string scanning, building
> of tables and output generation, and provides some integer arithmetic.

Initially created by Robert McClure (1965) to work on supercomputers and
mainframes of the time, TMG was cross-compiled for PDP-7 microcomputer by
Douglas McIlroy to work under Unix operating system. Soon after that the
language was further developed by McIlroy for Unix on PDP-11, creating a
unique and powerful dialect of McClure's TMG. This version of TMG was
included into Unix from Version 2 to Version 6, after which it was phased
out in favor of Stephen Johnson's YACC.

This is a translation of TMG from PDP-11 assembly to portable C. To the best of
our knowledge, it is the first implementation of TMG in a high-level language,
done more than 50 years after the tool first appeared.

Quotes about TMG
--
TMG was an early inspiration for Donald Knuth and his TAOCP. According to him:
> I was impressed by the metacompiler of Val Schorre and by the more powerful (though
> less elegant) "transmogrifier" of Bob McClure. I told Peter [Wegner] about my draft manuscript for
> Chapter 12 of The Art of Computer Programming, which included an example system of a similar kind,
> called TROL ("Translation-Oriented Language").

Stephen C. Johnson, creator of YACC, about his experience of working with Unix TMG:
> There was a compiler/compiler in use at the Labs, imported I think by Doug
> McIlroy, called TMG.  It was a backtracking recursive descent compiler
> that could compile almost anything but was unbearably slow and, if it
> encountered a syntax error would backtrack back to the first character of
> the input file and say, in effect, "something's wrong in here somewhere".

Doug McIlroy, creator of the Unix dialect of TMG:
> And in some ways, TMG was nicer than YACC. Not specification of grammar, but it actually
> helps you do the translation. YACC only helps you do the parsing, it's up to you to do the
> translation after that.

Tom Duff, Bell Labs employee:
> It made syntax-directed translation really easy, but with an abstruse
> syntax and semantics that any esoteric language enthusiast could appreciate.

Wishlist
--
This is a working implementation of TMG in C. Self-compilation achieved (albeit
in two phases). 

However, there is still room for improvement:

 - make the `makefile`
 - prepare a release for Windows
 - figure out how to use LR-parsing builtins, contributed by Johnson and Aho,
   but not documented in the Manual
 - achieve self-compilation in a single phase (very hard).

The language itself is extremely spartan and could be improved by addition of
more builtins (like reverse operation for `char`) and more language features
(like better arrays, more flexible tables and strings). However, this might go
against McIlroy's own liking, who is a well-known proponent of mathematical
elegance and conciseness in programming, as well as smaller-sized systems.

License
--
All code except the original TMG implementation is published under the BSD
2-Clause License.

References
--

 - McIlroy, M. D. [*A Manual for the Tmg Compiler-writing
Language*](https://amakukha.github.io/tmg/TMG_Manual_McIlroy_1972.html) (1972)
 - McClure, R. M. *TMG — A syntax-directed compiler*, Proc. ACM 20th Natl. Conf. (1965) 262-274
 - Thompson, K., Ritchie, D. M. [*UNIX Programmer's Manual. Sixth Edition*](https://ia800600.us.archive.org/19/items/v6-manual/v6-manual.pdf) (May, 1975)
 - Ritchie, D. M. [*UNIX Assembler Reference Manual*](http://www.tom-yam.or.jp/2238/ref/as.pdf) (circa 1974)
 - [*PAL-11R Assembler Programmer's Manual*](http://www.bitsavers.org/pdf/dec/pdp11/dos-batch/DEC-11-ASDB-D_PAL-11R_Assembler_Programmers_Manual_May71.pdf). Digital Equipment Corporation. (May, 1971)
 - [PDP-11 architecture](https://en.wikipedia.org/wiki/PDP-11_architecture) Wikipedia article
