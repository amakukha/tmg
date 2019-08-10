Port of Unix TMG to C99. Work in progress.

About TMG
--
> Tmg is a string processing language especially intended for writing 
> translators for computer languages. It deals with string scanning, building
> of tables and output generation, and provides some integer arithmetic.

Initially created by Robert McClure (1965) to work on supercomputers and
mainframes of the time, TMG was cross-compiled for PDP-7 microcomputer by
Douglas McIlroy to work under Unix operating system. Soon after that the
language was further developed my McIlroy for Unix on PDP-11, creating a
unique and powerful dialect of McClure's TMG. This version of TMG was
included into early versions of Unix, from Version 2 to Version 6, after
which it was phased out in favor of YACC.

This is an attempt to translate TMG from PDP-11 assembly to portable C.

References
--

 - M. D. McIlroy. [*A Manual for the Tmg Compiler-writing
Language*](https://amakukha.github.io/tmg/TMG_Manual_McIlroy_1972.html) (1972)
 - R. M. McClure. *TMG — A syntax-directed compiler*, Proc. ACM 20th Natl. Conf. (1965) 262-274
