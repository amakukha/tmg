#!/bin/bash

# Compiling without optimization can prevent looping infinitely.
cc tmga.c -o tmga

# Tail calls are converted into loops already at -O1 when using LLVM.
# It also produces the shortest output.
#cc -O1 tmga.c -o tmga

# TODO: test higher optimization levels' relative performance.
#cc -O3 -march=native -mtune=native tmga.c -o tmga
