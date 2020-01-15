Port of Unix TMG to C99. Work in progress.

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

To the best of our knowledge, unlike other Unix tools, it was never implemented
in a high-level language. This is an attempt to translate TMG from PDP-11
assembly to portable C.

Quotes about TMG
--
TMG was an early inspiration for Donald Knuth and his TAOCP. According to him:
> I was impressed by the metacompiler of Val Schorre and by the more powerful (though
> less elegant) "transmogrifier" of Bob McClure. I told Peter [Wegner] about my draft manuscript for
> Chapter 12 of The Art of Computer Programming, which included an example system of a similar kind,
> called TROL ("Translation-Oriented Language").

Stephen C. Johnson, creator of YACC, about his experience of working with TMG:
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

References
--

 - McIlroy, M. D. [*A Manual for the Tmg Compiler-writing
Language*](https://amakukha.github.io/tmg/TMG_Manual_McIlroy_1972.html) (1972)
 - McClure, R. M. *TMG — A syntax-directed compiler*, Proc. ACM 20th Natl. Conf. (1965) 262-274
 - Thompson, K., Ritchie, D. M. [*UNIX Programmer's Manual. Sixth Edition*](https://ia800600.us.archive.org/19/items/v6-manual/v6-manual.pdf) (May, 1975)
 - Ritchie, D. M. [*UNIX Assembler Reference Manual*](http://www.tom-yam.or.jp/2238/ref/as.pdf) (circa 1974)
 - [*PAL-11R Assembler Programmer's Manual*](http://www.bitsavers.org/pdf/dec/pdp11/dos-batch/DEC-11-ASDB-D_PAL-11R_Assembler_Programmers_Manual_May71.pdf). Digital Equipment Corporation. (May, 1971)
 - [*PDP11 Processor Handbook: pdp11/04/34a/44/60/70*](http://www.bitsavers.org/pdf/dec/pdp11/handbooks/PDP11_Handbook1979.pdf). Digital Equipment Corporation. (1979)
 - [PDP-11 architecture](https://en.wikipedia.org/wiki/PDP-11_architecture) Wikipedia article

