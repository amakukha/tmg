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

set -o nounset

TRACING=
if [ "x$1" = x-t ]; then
    TRACING=-DTRACING
    shift
fi

# What is the input and output files?
inp_file="$1"
echo "TMGL file: $inp_file"
out_file="a.out"
[ $# -ge 2 ] && out_file="$2"
cur_dir=$( pwd )
dst_file="$cur_dir/$out_file"

error () {
    # Error helper
    echo "ERROR: $1" && exit 1
}

# Determine location of TMGL translators
tmgl1="./tmgl1"
[ ! -x "$tmgl1" ] && tmgl1="$HOME/bin/tmgl1"
[ ! -x "$tmgl1" ] && error "tmgl1 not found"
tmgl2="./tmgl2"
[ ! -x "$tmgl2" ] && tmgl2="$HOME/bin/tmgl2"
[ ! -x "$tmgl2" ] && error "tmgl2 not found"

# Determine TMG source and build locations
build_dir="/tmp/tmg_build"
tmg_src_dir="$HOME/.local/share/tmg/src"
if [ -f tmga.c ]; then
    build_dir="build"
    tmg_src_dir="."
fi
[ ! -f "$tmg_src_dir/tmga.c" ] && error "TMG source not found in $tmg_src_dir/"
echo "TMG source found at: $tmg_src_dir/"
echo "Build location: $build_dir/"

# Compilation routine
compile () {
    align="-falign-functions=16"
    opt="-O1"
    while true; do
        cc $TRACING -std=c99 "$align" "$opt" tmga.c -o $1
        if [ $? -eq 0 ]; then
            [ -z "$align" ] && echo "WARNING: functions could not be aligned"
            break
        else
            [ -z "$align" ] && break
            align=""
        fi
    done
}

# TMG translation: phase 1
"$tmgl1"  "$inp_file" > table.1.tmp
[ $? -ne 0 ] && error "compiling TMGL file FAILED at phase 1"

# TMG translation: phase 2
"$tmgl2" table.1.tmp > table.tmp
[ $? -ne 0 ] && error "compiling TMGL file FAILED at phase 2"

# Build executable with C compiler
rm table.1.tmp
mkdir -p "$build_dir"
[ -e "$build_dir/tmga.c" ] && rm "$build_dir"/*
cp $tmg_src_dir/*.c "$build_dir/"
cp $tmg_src_dir/*.h "$build_dir/"
mv table.tmp "$build_dir"/tmgl.h               # overwrite
cd "$build_dir"
echo "Dest file: $out_file"
compile "$dst_file"
#cd "$cur_dir"
echo "Compiling done" 
