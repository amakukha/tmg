#!/bin/bash

# TMG build script.
# Builds executables to translate TMGL into a TMG driving table in C.
# Corresponds to the original script `run`.

OPT=-O1

mkdir -p build/
if [ -e build/tmga.c ]; then rm build/*; fi
cp *.h *.c build/
cd build/
mv tmgl1.h tmgl.h
cc -std=c99 $OPT tmga.c -o "../tmgl1"
mv tmgl2.h tmgl.h
cc -std=c99 $OPT tmga.c -o "../tmgl2"
cd ..
echo "Build done" 

# NOTES ON OPTIMIZATION:
#
# Compiling without optimization will not convert tail calls into loops, but
# can thus prevent looping infinitely (due to stack overflows)
# 
# -O1
# Tail calls are converted into loops already at -O1 when using LLVM.
# It also produces the shortest output.
# 
# -O3
# TODO: test higher optimization levels' relative performance.
