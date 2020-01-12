#!/bin/bash 

## Builds programs using different driving tables and tests those programs
## agains sets of inputs with known outputs.
##
## Usage:
##     ./run_tests.sh
##         - to run all tests
##     ./run_tests.sh 05
##         - to run a specific test

BUILD_DIR="build"
TMP="out.tmp"

mkdir -p build
cp ../src/*.h ../src/*.c ../src/build.sh build/
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

    # Build executable
    if [[ -f $dir/tmgl.h ]]; then
        cp "$dir/tmgl.h" "$BUILD_DIR/"
        cd "$BUILD_DIR"
        ./build.sh
        cd ..
    else
        echo "tmgl.h not found"
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
    rm "$TMP" "alloc.d"
    rm -r "$BUILD_DIR"
fi
