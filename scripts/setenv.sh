#!/bin/bash

# Get absolute path to the root of the repo (assuming this script is in scripts/)
export DATA_PRODUCTS_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

export DATA_PRODUCTS_CMAKE_PREFIX_PATH="$DATA_PRODUCTS_PATH/install"
export CMAKE_PREFIX_PATH="${DATA_PRODUCTS_CMAKE_PREFIX_PATH}${CMAKE_PREFIX_PATH:+:$CMAKE_PREFIX_PATH}"

export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$DATA_PRODUCTS_PATH/install/include
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DATA_PRODUCTS_PATH/install/lib
export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$DATA_PRODUCTS_PATH/install/lib

echo "Environment configured from $DATA_PRODUCTS_PATH"
