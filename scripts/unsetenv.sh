#!/bin/bash

# Get absolute path to the root of the repo (assuming this script is in scripts/)
export DATA_PRODUCT_PATH="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

# Function to remove a path from an environment variable
remove_from_path() {
    local var_name=$1
    local path_to_remove=$2
    local current_value=$(eval echo \$$var_name)
    
    # Remove the path and clean up any double colons
    local new_value=$(echo "$current_value" | sed "s|:*$path_to_remove:*|:|g" | sed 's/^:|//;s/:$//')
    
    # Set the new value
    eval export $var_name="$new_value"
    
    # If the variable is now empty, unset it
    if [ -z "$(eval echo \$$var_name)" ]; then
        unset $var_name
    fi
}

# Remove paths that were added by setenv.sh
remove_from_path "ROOT_INCLUDE_PATH" "$DATA_PRODUCT_PATH/install/include"
remove_from_path "LD_LIBRARY_PATH" "$DATA_PRODUCT_PATH/install/lib"
remove_from_path "DYLD_LIBRARY_PATH" "$DATA_PRODUCT_PATH/install/lib"
remove_from_path "CMAKE_PREFIX_PATH" "$CMAKE_PREFIX_PATH/install"

# Remove nlohmann_json paths if they were added
NLOHMANN_PATHS=$(pkg-config --cflags nlohmann_json 2>/dev/null | sed 's/-I//g')
if [ ! -z "$NLOHMANN_PATHS" ]; then
    for path in $NLOHMANN_PATHS; do
        remove_from_path "ROOT_INCLUDE_PATH" "$path"
    done
fi

echo "Environment paths removed for $DATA_PRODUCT_PATH"

# Finally unset the UNPACKER_PATH variable itself
unset UNPACKER_PATH