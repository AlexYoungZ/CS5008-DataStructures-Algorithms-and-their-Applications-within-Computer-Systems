# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab08_mergesort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab08_mergesort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab08_mergesort.dir/flags.make

CMakeFiles/lab08_mergesort.dir/mergesort.c.o: CMakeFiles/lab08_mergesort.dir/flags.make
CMakeFiles/lab08_mergesort.dir/mergesort.c.o: ../mergesort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab08_mergesort.dir/mergesort.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab08_mergesort.dir/mergesort.c.o -c /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/mergesort.c

CMakeFiles/lab08_mergesort.dir/mergesort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab08_mergesort.dir/mergesort.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/mergesort.c > CMakeFiles/lab08_mergesort.dir/mergesort.c.i

CMakeFiles/lab08_mergesort.dir/mergesort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab08_mergesort.dir/mergesort.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/mergesort.c -o CMakeFiles/lab08_mergesort.dir/mergesort.c.s

# Object files for target lab08_mergesort
lab08_mergesort_OBJECTS = \
"CMakeFiles/lab08_mergesort.dir/mergesort.c.o"

# External object files for target lab08_mergesort
lab08_mergesort_EXTERNAL_OBJECTS =

lab08_mergesort: CMakeFiles/lab08_mergesort.dir/mergesort.c.o
lab08_mergesort: CMakeFiles/lab08_mergesort.dir/build.make
lab08_mergesort: CMakeFiles/lab08_mergesort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab08_mergesort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab08_mergesort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab08_mergesort.dir/build: lab08_mergesort

.PHONY : CMakeFiles/lab08_mergesort.dir/build

CMakeFiles/lab08_mergesort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab08_mergesort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab08_mergesort.dir/clean

CMakeFiles/lab08_mergesort.dir/depend:
	cd /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/cmake-build-debug /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/cmake-build-debug /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab08-mergesort/cmake-build-debug/CMakeFiles/lab08_mergesort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab08_mergesort.dir/depend
