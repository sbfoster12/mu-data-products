cmake_minimum_required(VERSION 3.13)

project(mu-data-products VERSION 0.0.0 LANGUAGES CXX)

# for debug
# set(CMAKE_BUILD_TYPE RelWithDebInfo)

# Dependencies
find_package(ROOT REQUIRED)
include(${ROOT_USE_FILE})
include("${ROOT_DIR}/RootMacros.cmake")

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_OSX_ARCHITECTURES "arm64")

# Create installation directories
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/install")
endif()

# Set the path for where to look for the libraries of the installed target
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# Add all the subdirectories
add_subdirectory(src)

# # Enable debugging symbols
# target_compile_options(unpacker PRIVATE -g -v)

# target_compile_options(unpacker PRIVATE -Wall -Wextra -Wno-undef)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -v")