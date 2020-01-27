#!/bin/bash

# TMGL compilation script.
# For a given TMGL program it produces an executable. 
# Corresponds to the original script `tmg`.
# 
# While the original script relies on the UNIX assembler to produce the
# executable, this script calls the C compiler. It is a principal difference
# between this project and the original.
# 
# Another slight difference is that this implementation relies on two phases of
# translations by TMG (from TMGL to C arrays), while the original required only
# one phase (from TMGL to an assembly table).

inp="$1"
echo "TMGL file: $inp"
out="a.out"
if [ $# -gt 1 ]; then
    out="$2"
fi
echo "Dest file: $out"
./tmgl1  "$inp" > table.1.tmp
if [ $? -eq 0 ]; then
    ./tmgl2 table.1.tmp > table.tmp
    if [ $? -eq 0 ]; then
        rm table.1.tmp
        mkdir -p build/
        if [ -e build/tmga.c ]; then rm build/*; fi
        cp *.h *.c build/
        mv table.tmp build/tmgl.h               # overwrite
        cd build/
        cc -std=c99 -O1 tmga.c -o "../$out"
        cd ..
        echo "Compiling done" 
    else 
        echo "Compiling TMGL file FAILED at phase 2"
    fi
else 
    echo "Compiling TMGL file FAILED at phase 1"
fi
