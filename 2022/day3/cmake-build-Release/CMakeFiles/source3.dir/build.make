# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ricar/Documents/AdventOfCode/2022/day3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ricar/Documents/AdventOfCode/2022/day3/cmake-build-Release

# Include any dependencies generated for this target.
include CMakeFiles/source3.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/source3.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/source3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/source3.dir/flags.make

CMakeFiles/source3.dir/source3.cpp.o: CMakeFiles/source3.dir/flags.make
CMakeFiles/source3.dir/source3.cpp.o: ../source3.cpp
CMakeFiles/source3.dir/source3.cpp.o: CMakeFiles/source3.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ricar/Documents/AdventOfCode/2022/day3/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/source3.dir/source3.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/source3.dir/source3.cpp.o -MF CMakeFiles/source3.dir/source3.cpp.o.d -o CMakeFiles/source3.dir/source3.cpp.o -c /home/ricar/Documents/AdventOfCode/2022/day3/source3.cpp

CMakeFiles/source3.dir/source3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/source3.dir/source3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ricar/Documents/AdventOfCode/2022/day3/source3.cpp > CMakeFiles/source3.dir/source3.cpp.i

CMakeFiles/source3.dir/source3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/source3.dir/source3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ricar/Documents/AdventOfCode/2022/day3/source3.cpp -o CMakeFiles/source3.dir/source3.cpp.s

# Object files for target source3
source3_OBJECTS = \
"CMakeFiles/source3.dir/source3.cpp.o"

# External object files for target source3
source3_EXTERNAL_OBJECTS =

source3: CMakeFiles/source3.dir/source3.cpp.o
source3: CMakeFiles/source3.dir/build.make
source3: CMakeFiles/source3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ricar/Documents/AdventOfCode/2022/day3/cmake-build-Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable source3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/source3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/source3.dir/build: source3
.PHONY : CMakeFiles/source3.dir/build

CMakeFiles/source3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/source3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/source3.dir/clean

CMakeFiles/source3.dir/depend:
	cd /home/ricar/Documents/AdventOfCode/2022/day3/cmake-build-Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ricar/Documents/AdventOfCode/2022/day3 /home/ricar/Documents/AdventOfCode/2022/day3 /home/ricar/Documents/AdventOfCode/2022/day3/cmake-build-Release /home/ricar/Documents/AdventOfCode/2022/day3/cmake-build-Release /home/ricar/Documents/AdventOfCode/2022/day3/cmake-build-Release/CMakeFiles/source3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/source3.dir/depend

