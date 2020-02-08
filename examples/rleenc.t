/* Unix TMG program for run-length encoding */
/* RosettaCode task: http://rosettacode.org/wiki/Run-length_encoding */
/* Sample input:  AAAAAAAAAABBC */
/* Sample output: 10A2B1C */
/* Author: Andrii Makukha */

loop:   ordcop [lch?]\loop;
ordcop: ord/copy;
ord:    char(ch)/last [ch!=lch?]\new [cnt++] fail;
new:    ( [lch?] parse(out) | () ) [lch=ch] [cnt=1] fail;
out:    decimal(cnt) scopy = { 2 1 };
last:   parse(out) [lch=0];
copy:   smark any(!<<>>);

ch:     0;
lch:    0;
cnt:    0;
