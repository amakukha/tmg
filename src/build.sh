#!/bin/bash

# Compiling without optimization will not convert tail calls into loops, but
# can thus prevent looping infinitely (due to stack overflows)
cc tmga.c -o tmga

# Tail calls are converted into loops already at -O1 when using LLVM.
# It also produces the shortest output.
#cc -O1 tmga.c -o tmga

# TODO: test higher optimization levels' relative performance.
#cc -O3 -march=native -mtune=native tmga.c -o tmga
