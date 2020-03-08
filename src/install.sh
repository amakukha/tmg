#!/bin/bash

set -o nounset && set -o errexit

# Make sure TMG is built
[ ! -x tmgl1 ] && ./build.sh
[ ! -x tmgl2 ] && ./build.sh

# Copy TMG executables to $HOME/bin  
mkdir -p "$HOME/bin/"
cp tmgl1 tmgl2 "$HOME/bin/"

# Copy TMG sources to $HOME
src_dir="$HOME/.local/share/tmg/src/"
mkdir -p "$src_dir"
cp *.h *.c "$src_dir"

# Install the command
cmnd="$HOME/bin/tmg"
if [ -f "$cmnd" ]; then
    read -p "Do you want to overwrite $cmnd? [yN] " -s -r -n 1 YESNO
    echo "$YESNO"
    [[ ! $YESNO =~ ^[Yy]$ ]] && echo "ERROR: $cmnd exists" && exit 1
fi
cp tmg.sh "$cmnd"
