


# CMakeLists files in this project can
# refer to the root source7 directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (SOURCE7)

set(SOURCE_FILES7 source7.cpp)
add_executable (source7 ${SOURCE_FILES7})

