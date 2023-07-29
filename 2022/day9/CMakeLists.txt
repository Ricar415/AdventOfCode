
# CMakeLists files in this project can
# refer to the root source9 directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (SOURCE9)

set(SOURCE_FILES9 source9.cpp)
add_executable (source9 ${SOURCE_FILES9})

