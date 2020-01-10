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

References
--

 - McIlroy, M. D. [*A Manual for the Tmg Compiler-writing
Language*](https://amakukha.github.io/tmg/TMG_Manual_McIlroy_1972.html) (1972)
 - McClure, R. M. *TMG — A syntax-directed compiler*, Proc. ACM 20th Natl. Conf. (1965) 262-274
 - Thompson, K., Ritchie, D. M. [*UNIX Programmer's Manual. Sixth Edition*](https://ia800600.us.archive.org/19/items/v6-manual/v6-manual.pdf) (May, 1975)
 - Ritchie, D. M. [*UNIX Assembler Reference Manual*](http://www.tom-yam.or.jp/2238/ref/as.pdf) (circa 1974)
 - [*PAL-11R Assembler Programmer's Manual*](http://www.bitsavers.org/pdf/dec/pdp11/dos-batch/DEC-11-ASDB-D_PAL-11R_Assembler_Programmers_Manual_May71.pdf). Digital Equipment Corporation. (May, 1971)
 - [PDP-11 architecture](https://en.wikipedia.org/wiki/PDP-11_architecture) Wikipedia article

