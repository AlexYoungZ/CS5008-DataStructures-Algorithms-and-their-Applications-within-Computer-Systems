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
CMAKE_SOURCE_DIR = /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/practicum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/practicum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practicum.dir/flags.make

CMakeFiles/practicum.dir/main.c.o: CMakeFiles/practicum.dir/flags.make
CMakeFiles/practicum.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/practicum.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/practicum.dir/main.c.o -c /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/main.c

CMakeFiles/practicum.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/practicum.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/main.c > CMakeFiles/practicum.dir/main.c.i

CMakeFiles/practicum.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/practicum.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/main.c -o CMakeFiles/practicum.dir/main.c.s

# Object files for target practicum
practicum_OBJECTS = \
"CMakeFiles/practicum.dir/main.c.o"

# External object files for target practicum
practicum_EXTERNAL_OBJECTS =

practicum: CMakeFiles/practicum.dir/main.c.o
practicum: CMakeFiles/practicum.dir/build.make
practicum: CMakeFiles/practicum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable practicum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/practicum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practicum.dir/build: practicum

.PHONY : CMakeFiles/practicum.dir/build

CMakeFiles/practicum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/practicum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/practicum.dir/clean

CMakeFiles/practicum.dir/depend:
	cd /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/cmake-build-debug /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/cmake-build-debug /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/practicum/cmake-build-debug/CMakeFiles/practicum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practicum.dir/depend
