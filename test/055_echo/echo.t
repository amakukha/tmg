/* Unix TMG program which copies entire input to output */

prog:   parse(echo);
echo:   smark ignore(none) any(ascii) string(ascii) scopy done;
done:   ;
none:   <<>>;
ascii:  !<<>>;
