# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2

# Include any dependencies generated for this target.
include tests/CMakeFiles/events.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/events.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/events.dir/flags.make

tests/CMakeFiles/events.dir/events.c.o: tests/CMakeFiles/events.dir/flags.make
tests/CMakeFiles/events.dir/events.c.o: tests/events.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/CMakeFiles/events.dir/events.c.o"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/events.dir/events.c.o   -c /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests/events.c

tests/CMakeFiles/events.dir/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/events.c.i"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests/events.c > CMakeFiles/events.dir/events.c.i

tests/CMakeFiles/events.dir/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/events.c.s"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests/events.c -o CMakeFiles/events.dir/events.c.s

tests/CMakeFiles/events.dir/__/deps/getopt.c.o: tests/CMakeFiles/events.dir/flags.make
tests/CMakeFiles/events.dir/__/deps/getopt.c.o: deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/CMakeFiles/events.dir/__/deps/getopt.c.o"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/events.dir/__/deps/getopt.c.o   -c /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/deps/getopt.c

tests/CMakeFiles/events.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/getopt.c.i"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/deps/getopt.c > CMakeFiles/events.dir/__/deps/getopt.c.i

tests/CMakeFiles/events.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/getopt.c.s"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/deps/getopt.c -o CMakeFiles/events.dir/__/deps/getopt.c.s

tests/CMakeFiles/events.dir/__/deps/glad_gl.c.o: tests/CMakeFiles/events.dir/flags.make
tests/CMakeFiles/events.dir/__/deps/glad_gl.c.o: deps/glad_gl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/CMakeFiles/events.dir/__/deps/glad_gl.c.o"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/events.dir/__/deps/glad_gl.c.o   -c /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/deps/glad_gl.c

tests/CMakeFiles/events.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/glad_gl.c.i"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/deps/glad_gl.c > CMakeFiles/events.dir/__/deps/glad_gl.c.i

tests/CMakeFiles/events.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/glad_gl.c.s"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && /bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/deps/glad_gl.c -o CMakeFiles/events.dir/__/deps/glad_gl.c.s

# Object files for target events
events_OBJECTS = \
"CMakeFiles/events.dir/events.c.o" \
"CMakeFiles/events.dir/__/deps/getopt.c.o" \
"CMakeFiles/events.dir/__/deps/glad_gl.c.o"

# External object files for target events
events_EXTERNAL_OBJECTS =

tests/events: tests/CMakeFiles/events.dir/events.c.o
tests/events: tests/CMakeFiles/events.dir/__/deps/getopt.c.o
tests/events: tests/CMakeFiles/events.dir/__/deps/glad_gl.c.o
tests/events: tests/CMakeFiles/events.dir/build.make
tests/events: src/libglfw3.a
tests/events: /usr/lib/x86_64-linux-gnu/libm.so
tests/events: /usr/lib/x86_64-linux-gnu/librt.so
tests/events: /usr/lib/x86_64-linux-gnu/libm.so
tests/events: /usr/lib/x86_64-linux-gnu/libX11.so
tests/events: tests/CMakeFiles/events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable events"
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/events.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/events.dir/build: tests/events

.PHONY : tests/CMakeFiles/events.dir/build

tests/CMakeFiles/events.dir/clean:
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests && $(CMAKE_COMMAND) -P CMakeFiles/events.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/events.dir/clean

tests/CMakeFiles/events.dir/depend:
	cd /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2 /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2 /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests /home/jjaouen/projects/scop_42/Contents/Resources/GLFW-3.3.2/glfw-3.3.2/tests/CMakeFiles/events.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/events.dir/depend

