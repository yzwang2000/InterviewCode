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
CMAKE_SOURCE_DIR = /home/yzwang/PythonProject/InterviewCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yzwang/PythonProject/InterviewCode/build

# Include any dependencies generated for this target.
include ArrayCode/CMakeFiles/arrayCode.dir/depend.make

# Include the progress variables for this target.
include ArrayCode/CMakeFiles/arrayCode.dir/progress.make

# Include the compile flags for this target's objects.
include ArrayCode/CMakeFiles/arrayCode.dir/flags.make

ArrayCode/CMakeFiles/arrayCode.dir/src/example.cpp.o: ArrayCode/CMakeFiles/arrayCode.dir/flags.make
ArrayCode/CMakeFiles/arrayCode.dir/src/example.cpp.o: ../ArrayCode/src/example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yzwang/PythonProject/InterviewCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ArrayCode/CMakeFiles/arrayCode.dir/src/example.cpp.o"
	cd /home/yzwang/PythonProject/InterviewCode/build/ArrayCode && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arrayCode.dir/src/example.cpp.o -c /home/yzwang/PythonProject/InterviewCode/ArrayCode/src/example.cpp

ArrayCode/CMakeFiles/arrayCode.dir/src/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrayCode.dir/src/example.cpp.i"
	cd /home/yzwang/PythonProject/InterviewCode/build/ArrayCode && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yzwang/PythonProject/InterviewCode/ArrayCode/src/example.cpp > CMakeFiles/arrayCode.dir/src/example.cpp.i

ArrayCode/CMakeFiles/arrayCode.dir/src/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrayCode.dir/src/example.cpp.s"
	cd /home/yzwang/PythonProject/InterviewCode/build/ArrayCode && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yzwang/PythonProject/InterviewCode/ArrayCode/src/example.cpp -o CMakeFiles/arrayCode.dir/src/example.cpp.s

arrayCode: ArrayCode/CMakeFiles/arrayCode.dir/src/example.cpp.o
arrayCode: ArrayCode/CMakeFiles/arrayCode.dir/build.make

.PHONY : arrayCode

# Rule to build all files generated by this target.
ArrayCode/CMakeFiles/arrayCode.dir/build: arrayCode

.PHONY : ArrayCode/CMakeFiles/arrayCode.dir/build

ArrayCode/CMakeFiles/arrayCode.dir/clean:
	cd /home/yzwang/PythonProject/InterviewCode/build/ArrayCode && $(CMAKE_COMMAND) -P CMakeFiles/arrayCode.dir/cmake_clean.cmake
.PHONY : ArrayCode/CMakeFiles/arrayCode.dir/clean

ArrayCode/CMakeFiles/arrayCode.dir/depend:
	cd /home/yzwang/PythonProject/InterviewCode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yzwang/PythonProject/InterviewCode /home/yzwang/PythonProject/InterviewCode/ArrayCode /home/yzwang/PythonProject/InterviewCode/build /home/yzwang/PythonProject/InterviewCode/build/ArrayCode /home/yzwang/PythonProject/InterviewCode/build/ArrayCode/CMakeFiles/arrayCode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ArrayCode/CMakeFiles/arrayCode.dir/depend

