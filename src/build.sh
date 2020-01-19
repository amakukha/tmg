#!/bin/bash

# Compiling without optimization will not convert tail calls into loops, but
# can thus prevent looping infinitely (due to stack overflows)
cc -std=c99 tmga.c -o tmga

# Tail calls are converted into loops already at -O1 when using LLVM.
# It also produces the shortest output.
#cc -std=c99 -O1 tmga.c -o tmga

# TODO: test higher optimization levels' relative performance.
#cc -std=c99 -O3 -march=native -mtune=native tmga.c -o tmga
