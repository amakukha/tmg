/* Unix TMG program */
/* Test for ignoring UTF-8 BOM */
/* Works with C port of McIlroy's TMG for Unix */
/* Author: Andrii Makukha */

prog:   ignore(other) smark ignore(<<>>) any(letters) string(letters) parse(word);
word:   scopy = { 1 * };

letters:  <<ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz>>;
other:   !<<ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz>>;
