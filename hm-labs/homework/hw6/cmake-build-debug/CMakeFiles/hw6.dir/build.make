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
CMAKE_SOURCE_DIR = /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hw6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hw6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hw6.dir/flags.make

CMakeFiles/hw6.dir/main.c.o: CMakeFiles/hw6.dir/flags.make
CMakeFiles/hw6.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hw6.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hw6.dir/main.c.o -c /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/main.c

CMakeFiles/hw6.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw6.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/main.c > CMakeFiles/hw6.dir/main.c.i

CMakeFiles/hw6.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw6.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/main.c -o CMakeFiles/hw6.dir/main.c.s

CMakeFiles/hw6.dir/deadlock.c.o: CMakeFiles/hw6.dir/flags.make
CMakeFiles/hw6.dir/deadlock.c.o: ../deadlock.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/hw6.dir/deadlock.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hw6.dir/deadlock.c.o -c /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/deadlock.c

CMakeFiles/hw6.dir/deadlock.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw6.dir/deadlock.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/deadlock.c > CMakeFiles/hw6.dir/deadlock.c.i

CMakeFiles/hw6.dir/deadlock.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw6.dir/deadlock.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/deadlock.c -o CMakeFiles/hw6.dir/deadlock.c.s

CMakeFiles/hw6.dir/racecondition.c.o: CMakeFiles/hw6.dir/flags.make
CMakeFiles/hw6.dir/racecondition.c.o: ../racecondition.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/hw6.dir/racecondition.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hw6.dir/racecondition.c.o -c /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/racecondition.c

CMakeFiles/hw6.dir/racecondition.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw6.dir/racecondition.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/racecondition.c > CMakeFiles/hw6.dir/racecondition.c.i

CMakeFiles/hw6.dir/racecondition.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw6.dir/racecondition.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/racecondition.c -o CMakeFiles/hw6.dir/racecondition.c.s

CMakeFiles/hw6.dir/diningPhilosopher.c.o: CMakeFiles/hw6.dir/flags.make
CMakeFiles/hw6.dir/diningPhilosopher.c.o: ../diningPhilosopher.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/hw6.dir/diningPhilosopher.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/hw6.dir/diningPhilosopher.c.o -c /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/diningPhilosopher.c

CMakeFiles/hw6.dir/diningPhilosopher.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hw6.dir/diningPhilosopher.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/diningPhilosopher.c > CMakeFiles/hw6.dir/diningPhilosopher.c.i

CMakeFiles/hw6.dir/diningPhilosopher.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hw6.dir/diningPhilosopher.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/diningPhilosopher.c -o CMakeFiles/hw6.dir/diningPhilosopher.c.s

# Object files for target hw6
hw6_OBJECTS = \
"CMakeFiles/hw6.dir/main.c.o" \
"CMakeFiles/hw6.dir/deadlock.c.o" \
"CMakeFiles/hw6.dir/racecondition.c.o" \
"CMakeFiles/hw6.dir/diningPhilosopher.c.o"

# External object files for target hw6
hw6_EXTERNAL_OBJECTS =

hw6: CMakeFiles/hw6.dir/main.c.o
hw6: CMakeFiles/hw6.dir/deadlock.c.o
hw6: CMakeFiles/hw6.dir/racecondition.c.o
hw6: CMakeFiles/hw6.dir/diningPhilosopher.c.o
hw6: CMakeFiles/hw6.dir/build.make
hw6: CMakeFiles/hw6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable hw6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hw6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hw6.dir/build: hw6

.PHONY : CMakeFiles/hw6.dir/build

CMakeFiles/hw6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/hw6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/hw6.dir/clean

CMakeFiles/hw6.dir/depend:
	cd /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6 /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6 /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug /Users/siyangzhang/Documents/GitHub/CS5008_siyangzhang/homework/hw6/cmake-build-debug/CMakeFiles/hw6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hw6.dir/depend
