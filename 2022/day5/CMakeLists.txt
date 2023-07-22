
# CMakeLists files in this project can
# refer to the root source5 directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (SOURCE4)

set(SOURCE_FILES5 source5.cpp)
add_executable (source5 ${SOURCE_FILES5})

