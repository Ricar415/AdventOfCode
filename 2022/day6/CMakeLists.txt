

# CMakeLists files in this project can
# refer to the root source6 directory of the project as ${HELLO_SOURCE_DIR} and
# to the root binary directory of the project as ${HELLO_BINARY_DIR}.
cmake_minimum_required (VERSION 2.8.11)
project (SOURCE6)

set(SOURCE_FILES6 source6.cpp)
add_executable (source6 ${SOURCE_FILES6})

