# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yzwang/PythonProject/TRTDemo/LeetCode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yzwang/PythonProject/TRTDemo/LeetCode/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/main.cpp.o: /home/yzwang/PythonProject/TRTDemo/LeetCode/main.cpp
CMakeFiles/main.dir/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yzwang/PythonProject/TRTDemo/LeetCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/main.cpp.o"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/main.cpp.o -MF CMakeFiles/main.dir/main.cpp.o.d -o CMakeFiles/main.dir/main.cpp.o -c /home/yzwang/PythonProject/TRTDemo/LeetCode/main.cpp

CMakeFiles/main.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/main.cpp.i"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yzwang/PythonProject/TRTDemo/LeetCode/main.cpp > CMakeFiles/main.dir/main.cpp.i

CMakeFiles/main.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/main.cpp.s"
	/usr/bin/g++-11 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yzwang/PythonProject/TRTDemo/LeetCode/main.cpp -o CMakeFiles/main.dir/main.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/main.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS = \
"/home/yzwang/PythonProject/TRTDemo/LeetCode/build/ArrayCode/CMakeFiles/arrayCode.dir/src/example.cpp.o" \
"/home/yzwang/PythonProject/TRTDemo/LeetCode/build/ListCode/CMakeFiles/listCode.dir/src/example.cpp.o" \
"/home/yzwang/PythonProject/TRTDemo/LeetCode/build/HashCode/CMakeFiles/hashCode.dir/src/example.cpp.o" \
"/home/yzwang/PythonProject/TRTDemo/LeetCode/build/SSCode/CMakeFiles/ssCode.dir/src/example.cpp.o" \
"/home/yzwang/PythonProject/TRTDemo/LeetCode/build/Deque/CMakeFiles/deque.dir/src/example.cpp.o"

bin/main: CMakeFiles/main.dir/main.cpp.o
bin/main: ArrayCode/CMakeFiles/arrayCode.dir/src/example.cpp.o
bin/main: ListCode/CMakeFiles/listCode.dir/src/example.cpp.o
bin/main: HashCode/CMakeFiles/hashCode.dir/src/example.cpp.o
bin/main: SSCode/CMakeFiles/ssCode.dir/src/example.cpp.o
bin/main: Deque/CMakeFiles/deque.dir/src/example.cpp.o
bin/main: CMakeFiles/main.dir/build.make
bin/main: /usr/lib/gcc/x86_64-linux-gnu/11/libgomp.so
bin/main: /usr/lib/x86_64-linux-gnu/libpthread.so
bin/main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yzwang/PythonProject/TRTDemo/LeetCode/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: bin/main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /home/yzwang/PythonProject/TRTDemo/LeetCode/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yzwang/PythonProject/TRTDemo/LeetCode /home/yzwang/PythonProject/TRTDemo/LeetCode /home/yzwang/PythonProject/TRTDemo/LeetCode/build /home/yzwang/PythonProject/TRTDemo/LeetCode/build /home/yzwang/PythonProject/TRTDemo/LeetCode/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend

