#!/bin/bash 

## Builds programs using different driving tables and tests those programs
## agains sets of inputs with known outputs.
##
## Usage:
##     ./run_tests.sh
##         - to run all tests
##     ./run_tests.sh 05
##         - to run a specific test

OPT=-O1
BUILD_DIR="build"
TMP="out.tmp"

compile () {
    cc -std=c99 -falign-functions=16 $OPT tmga.c -o $1
    if [ $? -ne 0 ]
    then
        cc -std=c99 $OPT tmga.c -o $1;
        echo "WARNING: functions could not be aligned"
    fi
}

mkdir -p "$BUILD_DIR"
if [[ -f "$BUILD_DIR/tmga" ]]; then rm "$BUILD_DIR/tmga"; fi 
cp ../src/*.h ../src/*.c ../src/build.sh "$BUILD_DIR/"
rm "$BUILD_DIR/tmgl.h";

mask=[0123456789]
if [[ $# -ne 0 ]]; then
    mask="$1"
else
    echo "Test                             Result"
    echo "======                           ======"
fi
for dir in $mask*; do
    if [[ ! -d $dir ]]; then continue; fi
    len=${#dir}
    pad=$( echo "                                " | cut -c $len- )
    echo -n "$dir$pad"

    fail=0

    # Create or find tmgl.h
    if [[ -f $dir/tmgl.h ]]; then
        cp "$dir/tmgl.h" "$BUILD_DIR/"
    else
        # Find a TMG file
        tmg=""
        for fn in "$dir"/*.t; do
            tmg="$fn"
            break
        done
        if [[ -f $tmg ]]; then
            # Generating the driving table in C

            # - Variant 1: by means of TMG
            ../src/tmgl1 "$tmg" > "$TMP"
            ../src/tmgl2 "$TMP" "$BUILD_DIR/tmgl.h"

            # - Variant 2: generate driving table for PDP-11 and then translate with a script
            #../src/tmga "$tmg" > "$dir/tmgl.s"
            #../tools/translate.py "$dir/tmgl.s" > "$BUILD_DIR/tmgl.h"
        else
            echo "not found: neither tmgl.h nor TMG file"
        fi
    fi

    # Build executable
    if [[ -f $BUILD_DIR/tmgl.h ]]; then
        cd "$BUILD_DIR"
        compile tmga
        cd ..
    fi

    # Test executable
    cnt=0
    if [[ $fail != 1 ]]; then
        for fn in "$dir"/input*; do 
            if test ! -f "$fn"; then
                echo "No inputs"
                fail=1
                break
            fi
            out="${fn#*/}"
            out="$dir/output${out:5}"
            if [[ -f $out ]]; then
                "$BUILD_DIR"/tmga "$fn" > "$TMP"
                if cmp -s "$TMP" "$out"; then
                    cnt=$((cnt+1))
                else
                    echo "FAIL" out "$out"
                    fail=1
                    break
                fi
            else
                echo "$out not found"
                fail=1
            fi
        done
    fi

    # Print result
    if [[ $fail = 1 ]] || [[ $cnt = 0 ]]; then
        echo -n "$dir" "$pad"
        printf "[\033[31m%s\033[m]\n" "FAIL"
    else
        printf "[\033[32m%s\033[m]\n" "PASS"
    fi
done 

# Clean up
if [[ $# == 0 ]]; then
    rm "$TMP"
    rm -r "$BUILD_DIR"
fi
