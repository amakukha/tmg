#!/bin/bash

# TMG build script.
# Builds executables to translate TMGL into a TMG driving table in C.
# Corresponds to the original script `run`.

OPT=-O1
ALIGNED=1

compile () {
    cc -std=c99 -falign-functions=16 $OPT tmga.c -o $1
    if [ $? -ne 0 ]
    then
        cc -std=c99 $OPT tmga.c -o $1;
        ALIGNED=0
    fi
}

echo "Building TMGL translators..."
mkdir -p build/
if [ -e build/tmga.c ]; then rm build/*; fi
cp *.h *.c build/
cd build/
mv tmgl1.h tmgl.h
compile "../tmgl1"
mv tmgl2.h tmgl.h
compile "../tmgl2"
cd ..
if [ $ALIGNED -ne 1 ]; then
    echo "WARNING: could not align the functions"
fi
echo " - DONE"
echo "Now you can run ./tmg.sh to compile TMGL programs."

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
