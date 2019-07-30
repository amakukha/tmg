#!/bin/bash

# Tail calls are converted into loops already at -O1 when using LLVM
cc -O1 tmga.c -o tmga
