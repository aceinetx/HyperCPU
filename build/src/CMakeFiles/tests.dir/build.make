# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/hyperwin/d/Projects/HyperCPU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hyperwin/d/Projects/HyperCPU/build

# Include any dependencies generated for this target.
include src/CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/tests.dir/flags.make

src/CMakeFiles/tests.dir/cpu.cpp.o: src/CMakeFiles/tests.dir/flags.make
src/CMakeFiles/tests.dir/cpu.cpp.o: /home/hyperwin/d/Projects/HyperCPU/src/cpu.cpp
src/CMakeFiles/tests.dir/cpu.cpp.o: src/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/tests.dir/cpu.cpp.o"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/tests.dir/cpu.cpp.o -MF CMakeFiles/tests.dir/cpu.cpp.o.d -o CMakeFiles/tests.dir/cpu.cpp.o -c /home/hyperwin/d/Projects/HyperCPU/src/cpu.cpp

src/CMakeFiles/tests.dir/cpu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/cpu.cpp.i"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyperwin/d/Projects/HyperCPU/src/cpu.cpp > CMakeFiles/tests.dir/cpu.cpp.i

src/CMakeFiles/tests.dir/cpu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/cpu.cpp.s"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyperwin/d/Projects/HyperCPU/src/cpu.cpp -o CMakeFiles/tests.dir/cpu.cpp.s

src/CMakeFiles/tests.dir/opcode_handler.cpp.o: src/CMakeFiles/tests.dir/flags.make
src/CMakeFiles/tests.dir/opcode_handler.cpp.o: /home/hyperwin/d/Projects/HyperCPU/src/opcode_handler.cpp
src/CMakeFiles/tests.dir/opcode_handler.cpp.o: src/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/tests.dir/opcode_handler.cpp.o"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/tests.dir/opcode_handler.cpp.o -MF CMakeFiles/tests.dir/opcode_handler.cpp.o.d -o CMakeFiles/tests.dir/opcode_handler.cpp.o -c /home/hyperwin/d/Projects/HyperCPU/src/opcode_handler.cpp

src/CMakeFiles/tests.dir/opcode_handler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/opcode_handler.cpp.i"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyperwin/d/Projects/HyperCPU/src/opcode_handler.cpp > CMakeFiles/tests.dir/opcode_handler.cpp.i

src/CMakeFiles/tests.dir/opcode_handler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/opcode_handler.cpp.s"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyperwin/d/Projects/HyperCPU/src/opcode_handler.cpp -o CMakeFiles/tests.dir/opcode_handler.cpp.s

src/CMakeFiles/tests.dir/__/test/tests.cpp.o: src/CMakeFiles/tests.dir/flags.make
src/CMakeFiles/tests.dir/__/test/tests.cpp.o: /home/hyperwin/d/Projects/HyperCPU/test/tests.cpp
src/CMakeFiles/tests.dir/__/test/tests.cpp.o: src/CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/tests.dir/__/test/tests.cpp.o"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/tests.dir/__/test/tests.cpp.o -MF CMakeFiles/tests.dir/__/test/tests.cpp.o.d -o CMakeFiles/tests.dir/__/test/tests.cpp.o -c /home/hyperwin/d/Projects/HyperCPU/test/tests.cpp

src/CMakeFiles/tests.dir/__/test/tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tests.dir/__/test/tests.cpp.i"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hyperwin/d/Projects/HyperCPU/test/tests.cpp > CMakeFiles/tests.dir/__/test/tests.cpp.i

src/CMakeFiles/tests.dir/__/test/tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tests.dir/__/test/tests.cpp.s"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hyperwin/d/Projects/HyperCPU/test/tests.cpp -o CMakeFiles/tests.dir/__/test/tests.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/cpu.cpp.o" \
"CMakeFiles/tests.dir/opcode_handler.cpp.o" \
"CMakeFiles/tests.dir/__/test/tests.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: src/CMakeFiles/tests.dir/cpu.cpp.o
tests: src/CMakeFiles/tests.dir/opcode_handler.cpp.o
tests: src/CMakeFiles/tests.dir/__/test/tests.cpp.o
tests: src/CMakeFiles/tests.dir/build.make
tests: src/CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/hyperwin/d/Projects/HyperCPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../tests"
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && ../tests

# Rule to build all files generated by this target.
src/CMakeFiles/tests.dir/build: tests
.PHONY : src/CMakeFiles/tests.dir/build

src/CMakeFiles/tests.dir/clean:
	cd /home/hyperwin/d/Projects/HyperCPU/build/src && $(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/tests.dir/clean

src/CMakeFiles/tests.dir/depend:
	cd /home/hyperwin/d/Projects/HyperCPU/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hyperwin/d/Projects/HyperCPU /home/hyperwin/d/Projects/HyperCPU/src /home/hyperwin/d/Projects/HyperCPU/build /home/hyperwin/d/Projects/HyperCPU/build/src /home/hyperwin/d/Projects/HyperCPU/build/src/CMakeFiles/tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/tests.dir/depend

