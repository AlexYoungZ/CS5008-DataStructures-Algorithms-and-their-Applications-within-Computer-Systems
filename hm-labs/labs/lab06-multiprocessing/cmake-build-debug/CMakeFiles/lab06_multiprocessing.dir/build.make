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
CMAKE_SOURCE_DIR = /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/lab06_multiprocessing.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lab06_multiprocessing.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab06_multiprocessing.dir/flags.make

CMakeFiles/lab06_multiprocessing.dir/main.c.o: CMakeFiles/lab06_multiprocessing.dir/flags.make
CMakeFiles/lab06_multiprocessing.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lab06_multiprocessing.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/lab06_multiprocessing.dir/main.c.o -c /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/main.c

CMakeFiles/lab06_multiprocessing.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lab06_multiprocessing.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/main.c > CMakeFiles/lab06_multiprocessing.dir/main.c.i

CMakeFiles/lab06_multiprocessing.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lab06_multiprocessing.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/main.c -o CMakeFiles/lab06_multiprocessing.dir/main.c.s

# Object files for target lab06_multiprocessing
lab06_multiprocessing_OBJECTS = \
"CMakeFiles/lab06_multiprocessing.dir/main.c.o"

# External object files for target lab06_multiprocessing
lab06_multiprocessing_EXTERNAL_OBJECTS =

lab06_multiprocessing: CMakeFiles/lab06_multiprocessing.dir/main.c.o
lab06_multiprocessing: CMakeFiles/lab06_multiprocessing.dir/build.make
lab06_multiprocessing: CMakeFiles/lab06_multiprocessing.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable lab06_multiprocessing"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab06_multiprocessing.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab06_multiprocessing.dir/build: lab06_multiprocessing

.PHONY : CMakeFiles/lab06_multiprocessing.dir/build

CMakeFiles/lab06_multiprocessing.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab06_multiprocessing.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab06_multiprocessing.dir/clean

CMakeFiles/lab06_multiprocessing.dir/depend:
	cd /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/cmake-build-debug /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/cmake-build-debug /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/labs/lab06-multiprocessing/cmake-build-debug/CMakeFiles/lab06_multiprocessing.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lab06_multiprocessing.dir/depend
