# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_SOURCE_DIR = "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build"

# Include any dependencies generated for this target.
include libs/graph/CMakeFiles/graph.dir/depend.make

# Include the progress variables for this target.
include libs/graph/CMakeFiles/graph.dir/progress.make

# Include the compile flags for this target's objects.
include libs/graph/CMakeFiles/graph.dir/flags.make

libs/graph/CMakeFiles/graph.dir/src/graph.cpp.o: libs/graph/CMakeFiles/graph.dir/flags.make
libs/graph/CMakeFiles/graph.dir/src/graph.cpp.o: /home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework\ 2/src/libs/graph/src/graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/graph/CMakeFiles/graph.dir/src/graph.cpp.o"
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/graph" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graph.dir/src/graph.cpp.o -c "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src/libs/graph/src/graph.cpp"

libs/graph/CMakeFiles/graph.dir/src/graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graph.dir/src/graph.cpp.i"
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/graph" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src/libs/graph/src/graph.cpp" > CMakeFiles/graph.dir/src/graph.cpp.i

libs/graph/CMakeFiles/graph.dir/src/graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graph.dir/src/graph.cpp.s"
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/graph" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src/libs/graph/src/graph.cpp" -o CMakeFiles/graph.dir/src/graph.cpp.s

# Object files for target graph
graph_OBJECTS = \
"CMakeFiles/graph.dir/src/graph.cpp.o"

# External object files for target graph
graph_EXTERNAL_OBJECTS =

libs/graph/libgraph.so: libs/graph/CMakeFiles/graph.dir/src/graph.cpp.o
libs/graph/libgraph.so: libs/graph/CMakeFiles/graph.dir/build.make
libs/graph/libgraph.so: libs/graph/CMakeFiles/graph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libgraph.so"
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/graph" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/graph/CMakeFiles/graph.dir/build: libs/graph/libgraph.so

.PHONY : libs/graph/CMakeFiles/graph.dir/build

libs/graph/CMakeFiles/graph.dir/clean:
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/graph" && $(CMAKE_COMMAND) -P CMakeFiles/graph.dir/cmake_clean.cmake
.PHONY : libs/graph/CMakeFiles/graph.dir/clean

libs/graph/CMakeFiles/graph.dir/depend:
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src/libs/graph" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/graph" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/graph/CMakeFiles/graph.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : libs/graph/CMakeFiles/graph.dir/depend
