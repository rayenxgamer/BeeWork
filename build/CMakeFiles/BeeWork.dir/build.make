# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = /home/ray/CProjects/BeeWork

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ray/CProjects/BeeWork/build

# Include any dependencies generated for this target.
include CMakeFiles/BeeWork.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BeeWork.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BeeWork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BeeWork.dir/flags.make

CMakeFiles/BeeWork.dir/codegen:
.PHONY : CMakeFiles/BeeWork.dir/codegen

CMakeFiles/BeeWork.dir/examples/main.c.o: CMakeFiles/BeeWork.dir/flags.make
CMakeFiles/BeeWork.dir/examples/main.c.o: /home/ray/CProjects/BeeWork/examples/main.c
CMakeFiles/BeeWork.dir/examples/main.c.o: CMakeFiles/BeeWork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ray/CProjects/BeeWork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/BeeWork.dir/examples/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BeeWork.dir/examples/main.c.o -MF CMakeFiles/BeeWork.dir/examples/main.c.o.d -o CMakeFiles/BeeWork.dir/examples/main.c.o -c /home/ray/CProjects/BeeWork/examples/main.c

CMakeFiles/BeeWork.dir/examples/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BeeWork.dir/examples/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ray/CProjects/BeeWork/examples/main.c > CMakeFiles/BeeWork.dir/examples/main.c.i

CMakeFiles/BeeWork.dir/examples/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BeeWork.dir/examples/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ray/CProjects/BeeWork/examples/main.c -o CMakeFiles/BeeWork.dir/examples/main.c.s

CMakeFiles/BeeWork.dir/libs/glad/glad.c.o: CMakeFiles/BeeWork.dir/flags.make
CMakeFiles/BeeWork.dir/libs/glad/glad.c.o: /home/ray/CProjects/BeeWork/libs/glad/glad.c
CMakeFiles/BeeWork.dir/libs/glad/glad.c.o: CMakeFiles/BeeWork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ray/CProjects/BeeWork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/BeeWork.dir/libs/glad/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/BeeWork.dir/libs/glad/glad.c.o -MF CMakeFiles/BeeWork.dir/libs/glad/glad.c.o.d -o CMakeFiles/BeeWork.dir/libs/glad/glad.c.o -c /home/ray/CProjects/BeeWork/libs/glad/glad.c

CMakeFiles/BeeWork.dir/libs/glad/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/BeeWork.dir/libs/glad/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ray/CProjects/BeeWork/libs/glad/glad.c > CMakeFiles/BeeWork.dir/libs/glad/glad.c.i

CMakeFiles/BeeWork.dir/libs/glad/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/BeeWork.dir/libs/glad/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ray/CProjects/BeeWork/libs/glad/glad.c -o CMakeFiles/BeeWork.dir/libs/glad/glad.c.s

# Object files for target BeeWork
BeeWork_OBJECTS = \
"CMakeFiles/BeeWork.dir/examples/main.c.o" \
"CMakeFiles/BeeWork.dir/libs/glad/glad.c.o"

# External object files for target BeeWork
BeeWork_EXTERNAL_OBJECTS =

BeeWork: CMakeFiles/BeeWork.dir/examples/main.c.o
BeeWork: CMakeFiles/BeeWork.dir/libs/glad/glad.c.o
BeeWork: CMakeFiles/BeeWork.dir/build.make
BeeWork: CMakeFiles/BeeWork.dir/compiler_depend.ts
BeeWork: /usr/lib/libSDL2main.a
BeeWork: /usr/lib/libSDL2-2.0.so.0.3200.52
BeeWork: CMakeFiles/BeeWork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ray/CProjects/BeeWork/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable BeeWork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BeeWork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BeeWork.dir/build: BeeWork
.PHONY : CMakeFiles/BeeWork.dir/build

CMakeFiles/BeeWork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BeeWork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BeeWork.dir/clean

CMakeFiles/BeeWork.dir/depend:
	cd /home/ray/CProjects/BeeWork/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ray/CProjects/BeeWork /home/ray/CProjects/BeeWork /home/ray/CProjects/BeeWork/build /home/ray/CProjects/BeeWork/build /home/ray/CProjects/BeeWork/build/CMakeFiles/BeeWork.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/BeeWork.dir/depend

