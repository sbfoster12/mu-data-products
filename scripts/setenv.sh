#!/bin/bash

# Get absolute path to the root of the repo (assuming this script is in scripts/)
export DATA_PRODUCT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

export ROOT_INCLUDE_PATH=$ROOT_INCLUDE_PATH:$DATA_PRODUCT_PATH/install/include:$(pkg-config --cflags nlohmann_json 2>/dev/null | sed 's/-I//g')
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$DATA_PRODUCT_PATH/install/lib
export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:$DATA_PRODUCT_PATH/install/lib

echo "Environment configured from $DATA_PRODUCT_PATH"
