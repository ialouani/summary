# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu20/summary_compilation_2A

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu20/summary_compilation_2A/build

# Include any dependencies generated for this target.
include CMakeFiles/all2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/all2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/all2.dir/flags.make

CMakeFiles/all2.dir/src/lexer.c.o: CMakeFiles/all2.dir/flags.make
CMakeFiles/all2.dir/src/lexer.c.o: ../src/lexer.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu20/summary_compilation_2A/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/all2.dir/src/lexer.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/all2.dir/src/lexer.c.o   -c /home/ubuntu20/summary_compilation_2A/src/lexer.c

CMakeFiles/all2.dir/src/lexer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/all2.dir/src/lexer.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ubuntu20/summary_compilation_2A/src/lexer.c > CMakeFiles/all2.dir/src/lexer.c.i

CMakeFiles/all2.dir/src/lexer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/all2.dir/src/lexer.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ubuntu20/summary_compilation_2A/src/lexer.c -o CMakeFiles/all2.dir/src/lexer.c.s

CMakeFiles/all2.dir/src/lexer.c.o.requires:
.PHONY : CMakeFiles/all2.dir/src/lexer.c.o.requires

CMakeFiles/all2.dir/src/lexer.c.o.provides: CMakeFiles/all2.dir/src/lexer.c.o.requires
	$(MAKE) -f CMakeFiles/all2.dir/build.make CMakeFiles/all2.dir/src/lexer.c.o.provides.build
.PHONY : CMakeFiles/all2.dir/src/lexer.c.o.provides

CMakeFiles/all2.dir/src/lexer.c.o.provides.build: CMakeFiles/all2.dir/src/lexer.c.o

CMakeFiles/all2.dir/tst/test1.c.o: CMakeFiles/all2.dir/flags.make
CMakeFiles/all2.dir/tst/test1.c.o: ../tst/test1.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ubuntu20/summary_compilation_2A/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/all2.dir/tst/test1.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/all2.dir/tst/test1.c.o   -c /home/ubuntu20/summary_compilation_2A/tst/test1.c

CMakeFiles/all2.dir/tst/test1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/all2.dir/tst/test1.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/ubuntu20/summary_compilation_2A/tst/test1.c > CMakeFiles/all2.dir/tst/test1.c.i

CMakeFiles/all2.dir/tst/test1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/all2.dir/tst/test1.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/ubuntu20/summary_compilation_2A/tst/test1.c -o CMakeFiles/all2.dir/tst/test1.c.s

CMakeFiles/all2.dir/tst/test1.c.o.requires:
.PHONY : CMakeFiles/all2.dir/tst/test1.c.o.requires

CMakeFiles/all2.dir/tst/test1.c.o.provides: CMakeFiles/all2.dir/tst/test1.c.o.requires
	$(MAKE) -f CMakeFiles/all2.dir/build.make CMakeFiles/all2.dir/tst/test1.c.o.provides.build
.PHONY : CMakeFiles/all2.dir/tst/test1.c.o.provides

CMakeFiles/all2.dir/tst/test1.c.o.provides.build: CMakeFiles/all2.dir/tst/test1.c.o

# Object files for target all2
all2_OBJECTS = \
"CMakeFiles/all2.dir/src/lexer.c.o" \
"CMakeFiles/all2.dir/tst/test1.c.o"

# External object files for target all2
all2_EXTERNAL_OBJECTS =

all2: CMakeFiles/all2.dir/src/lexer.c.o
all2: CMakeFiles/all2.dir/tst/test1.c.o
all2: CMakeFiles/all2.dir/build.make
all2: CMakeFiles/all2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable all2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/all2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/all2.dir/build: all2
.PHONY : CMakeFiles/all2.dir/build

CMakeFiles/all2.dir/requires: CMakeFiles/all2.dir/src/lexer.c.o.requires
CMakeFiles/all2.dir/requires: CMakeFiles/all2.dir/tst/test1.c.o.requires
.PHONY : CMakeFiles/all2.dir/requires

CMakeFiles/all2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/all2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/all2.dir/clean

CMakeFiles/all2.dir/depend:
	cd /home/ubuntu20/summary_compilation_2A/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu20/summary_compilation_2A /home/ubuntu20/summary_compilation_2A /home/ubuntu20/summary_compilation_2A/build /home/ubuntu20/summary_compilation_2A/build /home/ubuntu20/summary_compilation_2A/build/CMakeFiles/all2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/all2.dir/depend

