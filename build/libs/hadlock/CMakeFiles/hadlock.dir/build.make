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
include libs/hadlock/CMakeFiles/hadlock.dir/depend.make

# Include the progress variables for this target.
include libs/hadlock/CMakeFiles/hadlock.dir/progress.make

# Include the compile flags for this target's objects.
include libs/hadlock/CMakeFiles/hadlock.dir/flags.make

libs/hadlock/CMakeFiles/hadlock.dir/src/hadlock.cpp.o: libs/hadlock/CMakeFiles/hadlock.dir/flags.make
libs/hadlock/CMakeFiles/hadlock.dir/src/hadlock.cpp.o: /home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework\ 2/src/libs/hadlock/src/hadlock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/hadlock/CMakeFiles/hadlock.dir/src/hadlock.cpp.o"
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/hadlock" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/hadlock.dir/src/hadlock.cpp.o -c "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src/libs/hadlock/src/hadlock.cpp"

libs/hadlock/CMakeFiles/hadlock.dir/src/hadlock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/hadlock.dir/src/hadlock.cpp.i"
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/hadlock" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src/libs/hadlock/src/hadlock.cpp" > CMakeFiles/hadlock.dir/src/hadlock.cpp.i

libs/hadlock/CMakeFiles/hadlock.dir/src/hadlock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/hadlock.dir/src/hadlock.cpp.s"
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/hadlock" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src/libs/hadlock/src/hadlock.cpp" -o CMakeFiles/hadlock.dir/src/hadlock.cpp.s

# Object files for target hadlock
hadlock_OBJECTS = \
"CMakeFiles/hadlock.dir/src/hadlock.cpp.o"

# External object files for target hadlock
hadlock_EXTERNAL_OBJECTS =

libs/hadlock/libhadlock.a: libs/hadlock/CMakeFiles/hadlock.dir/src/hadlock.cpp.o
libs/hadlock/libhadlock.a: libs/hadlock/CMakeFiles/hadlock.dir/build.make
libs/hadlock/libhadlock.a: libs/hadlock/CMakeFiles/hadlock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libhadlock.a"
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/hadlock" && $(CMAKE_COMMAND) -P CMakeFiles/hadlock.dir/cmake_clean_target.cmake
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/hadlock" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/hadlock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/hadlock/CMakeFiles/hadlock.dir/build: libs/hadlock/libhadlock.a

.PHONY : libs/hadlock/CMakeFiles/hadlock.dir/build

libs/hadlock/CMakeFiles/hadlock.dir/clean:
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/hadlock" && $(CMAKE_COMMAND) -P CMakeFiles/hadlock.dir/cmake_clean.cmake
.PHONY : libs/hadlock/CMakeFiles/hadlock.dir/clean

libs/hadlock/CMakeFiles/hadlock.dir/depend:
	cd "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/src/libs/hadlock" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/hadlock" "/home/michael/Documents/drive_sync/Classwork/Spring2019/design_automation/homework/Homework 2/build/libs/hadlock/CMakeFiles/hadlock.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : libs/hadlock/CMakeFiles/hadlock.dir/depend

