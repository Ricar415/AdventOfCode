# CMakeLists files in this project can
# refer to the root source directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (SOURCE2)

set(SOURCE_FILES_2 source_day2.cpp)
add_executable (source2 ${SOURCE_FILES_2})
