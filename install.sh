#!/bin/bash

set -o nounset && set -o errexit

# Enter the src directory (if not there already)
[ ! -f build.sh ] && [ -d src ] && cd src

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
    [[ ! $YESNO =~ ^[Yy]$ ]] && echo "ERROR: $cmnd already exists" && exit 1
fi
cp tmg.sh "$cmnd"
echo "TMG installed into \$HOME/bin"

# Add $HOME/bin to $PATH
absent () {
    # Returns 0 (true) if string $2 is not found in file "$HOME/$1"
    [[ ! -f "$HOME/$1" ]] && return 0
    if grep -q "$2" "$HOME/$1"; then return 1; fi
    return 0
}

amend () {
    # Add string $2 to file "$HOME/$1" after user's confirmation
    read -p "Do you want to add \$HOME/bin into \$PATH in ~/$1? [yN] " -s -r -n 1 YESNO
    echo "$YESNO"
    [[ ! $YESNO =~ ^[Yy]$ ]] && return 1
    echo "$2" >> "$HOME/$1"
    echo "Please, run the following command to use TMG:"
    echo "    source ~/$1"
    return 0
}

if [[ $PATH != *"$HOME/bin:"* ]] && [[ $PATH != *"$HOME/bin/:"* ]]; then
    # $HOME/bin is not found in $PATH
    exp='export PATH="$HOME/bin:$PATH"'
    if absent ".bash_profile" "$exp" && absent ".bashrc" "$exp" && absent ".profile" "$exp"; then
        # $HOME/bin seems to be not added to $PATH in the common shell startup files
        err=0
        if [[ "$OSTYPE" == "darwin"* ]]; then
            amend ".bash_profile" "$exp" || amend ".bashrc" "$exp" || amend ".profile" "$exp" || err=1
        else
            amend ".bashrc" "$exp" || amend ".bash_profile" "$exp" || amend ".profile" "$exp" || err=1
        fi
        [ $err -ne 0 ] && echo "Add \$HOME/bin into \$PATH"
    fi
fi
