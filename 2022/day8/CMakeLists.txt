
# CMakeLists files in this project can
# refer to the root source8 directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (SOURCE8)

set(SOURCE_FILES8 source8.cpp)
add_executable (source8 ${SOURCE_FILES8})

