/* Unix TMG program which copies entire input to output */
/* This is intended only as a test for getnam builtin */

prog:   table(t) parse(echo);
echo:   smark ignore(none) any(ascii) string(ascii) install done;
install:enter(t,i) getnam(t,i);
done:   ;

t:      0;  /* table */
i:      0;  /* index */

none:   <<>>;
ascii:  !<<>>;
