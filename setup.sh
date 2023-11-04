#!/bin/bash

set -e

source_path=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
build_dir=build

# If build dir exists, bail on setup.
if test -d "$source_path/$build_dir" ; then 
    echo "$build_dir already exists."
    exit 0
fi

# Make build directory for build artifacts.
mkdir -m 0755 "$source_path/$build_dir" 
pushd "$source_path/$build_dir"
# Initilize pico SDK.
time cmake -DPICO_BOARD=pico_w ..
popd