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
CMAKE_SOURCE_DIR = /home/arivera/can_test_prius

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arivera/can_test_prius/build

# Include any dependencies generated for this target.
include src/CMakeFiles/CAN.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/CAN.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/CAN.dir/flags.make

src/CMakeFiles/CAN.dir/can/can.cc.o: src/CMakeFiles/CAN.dir/flags.make
src/CMakeFiles/CAN.dir/can/can.cc.o: ../src/can/can.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arivera/can_test_prius/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/CAN.dir/can/can.cc.o"
	cd /home/arivera/can_test_prius/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CAN.dir/can/can.cc.o -c /home/arivera/can_test_prius/src/can/can.cc

src/CMakeFiles/CAN.dir/can/can.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CAN.dir/can/can.cc.i"
	cd /home/arivera/can_test_prius/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arivera/can_test_prius/src/can/can.cc > CMakeFiles/CAN.dir/can/can.cc.i

src/CMakeFiles/CAN.dir/can/can.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CAN.dir/can/can.cc.s"
	cd /home/arivera/can_test_prius/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arivera/can_test_prius/src/can/can.cc -o CMakeFiles/CAN.dir/can/can.cc.s

# Object files for target CAN
CAN_OBJECTS = \
"CMakeFiles/CAN.dir/can/can.cc.o"

# External object files for target CAN
CAN_EXTERNAL_OBJECTS =

src/libCAN.a: src/CMakeFiles/CAN.dir/can/can.cc.o
src/libCAN.a: src/CMakeFiles/CAN.dir/build.make
src/libCAN.a: src/CMakeFiles/CAN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arivera/can_test_prius/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libCAN.a"
	cd /home/arivera/can_test_prius/build/src && $(CMAKE_COMMAND) -P CMakeFiles/CAN.dir/cmake_clean_target.cmake
	cd /home/arivera/can_test_prius/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CAN.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/CAN.dir/build: src/libCAN.a

.PHONY : src/CMakeFiles/CAN.dir/build

src/CMakeFiles/CAN.dir/clean:
	cd /home/arivera/can_test_prius/build/src && $(CMAKE_COMMAND) -P CMakeFiles/CAN.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/CAN.dir/clean

src/CMakeFiles/CAN.dir/depend:
	cd /home/arivera/can_test_prius/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arivera/can_test_prius /home/arivera/can_test_prius/src /home/arivera/can_test_prius/build /home/arivera/can_test_prius/build/src /home/arivera/can_test_prius/build/src/CMakeFiles/CAN.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/CAN.dir/depend

