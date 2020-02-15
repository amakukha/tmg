" Vim syntax file
" Language: Unix TMG
" Author:   Andrii Makukha
" Latest Revision: 19 January 2020

" Installation for Unix-like systems:
" 1) Copy this file into ~/.vim/syntax/
" 2) Add the following line into  ~/.vim/ftdetect/tmg.vim:
"    au BufRead,BufNewFile *.t set filetype=tmg 

if exists("b:current_syntax")
  finish
endif

" Comments
" TODO multiline comments
syn keyword tmgTodo contained TODO FIXME NOTE XXX
syn match tmgComment "/\*.*\*/" contains=tmgTodo

" Character class
" TODO multiline chatacter classes
syn match tmgCharClass '<<.\{-}>>' display

" Strings
syn match tmgString '<[^<][^>]*>' display
" TODO fix it to not include the next character
syn match tmgString '<<[^>]*>\([^>]\|$\)' display

" Parameters
syn match tmgParam  '[$][0123456789]\+' display

" Translation rule
syn match tmgName '\a\(\a\|\d\)*'
syn match tmgTransNumber '\d\+' contained display
syn match tmgNewLine '[*]' display
" TODO distinguish parsing rules () and translation rule parameters
syn region tmgTransRule start="{" end="}" fold transparent contains=tmgTransNumber,tmgNewLine,tmgString,tmgParam,tmgName

" Other
syn match tmgLabel '\a\(\a\|\d\)*[:]' display

syn keyword tmgBuiltin any append bundle char decimal diag emit discard enter
syn keyword tmgBuiltin fail find getnam goto ignore octal params parse proc
syn keyword tmgBuiltin push reduce scopy size smark string stop succ table
syn keyword tmgBuiltin accept gotab stack unstack

syn match tmgOctNumber '-\=[01234567]\+' display

" Hidden reserved words (see ``UNIX Programmer's Manual. Sixth Edition''); except goto
syn keyword tmgReserved gpar classtab trans alt salt

" Hidden keywords due to shortcommings of translation
syn keyword tmgReserved generate

"----------------------------------------------------------------------------/
" Setup syntax highlighting
"----------------------------------------------------------------------------/

let b:current_syntax = "unixtmg"

hi def link tmgTodo          Todo
hi def link tmgComment       Comment
hi def link tmgCharClass     Special
hi def link tmgString        Constant
hi def link tmgParam         Special
hi def link tmgTransNumber   Type
hi def link tmgNewLine       Special
hi def link tmgOctNumber     Constant
hi def link tmgBuiltin       Statement
hi def link tmgLabel         Identifier
hi def link tmgReserved      Error
