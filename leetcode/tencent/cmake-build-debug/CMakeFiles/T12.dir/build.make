# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/necromaner/program/C-/leetcode/tencent

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/T12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/T12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/T12.dir/flags.make

CMakeFiles/T12.dir/T1/T12.cpp.o: CMakeFiles/T12.dir/flags.make
CMakeFiles/T12.dir/T1/T12.cpp.o: ../T1/T12.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/T12.dir/T1/T12.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/T12.dir/T1/T12.cpp.o -c /Users/necromaner/program/C-/leetcode/tencent/T1/T12.cpp

CMakeFiles/T12.dir/T1/T12.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/T12.dir/T1/T12.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/necromaner/program/C-/leetcode/tencent/T1/T12.cpp > CMakeFiles/T12.dir/T1/T12.cpp.i

CMakeFiles/T12.dir/T1/T12.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/T12.dir/T1/T12.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/necromaner/program/C-/leetcode/tencent/T1/T12.cpp -o CMakeFiles/T12.dir/T1/T12.cpp.s

CMakeFiles/T12.dir/T1/T12.cpp.o.requires:

.PHONY : CMakeFiles/T12.dir/T1/T12.cpp.o.requires

CMakeFiles/T12.dir/T1/T12.cpp.o.provides: CMakeFiles/T12.dir/T1/T12.cpp.o.requires
	$(MAKE) -f CMakeFiles/T12.dir/build.make CMakeFiles/T12.dir/T1/T12.cpp.o.provides.build
.PHONY : CMakeFiles/T12.dir/T1/T12.cpp.o.provides

CMakeFiles/T12.dir/T1/T12.cpp.o.provides.build: CMakeFiles/T12.dir/T1/T12.cpp.o


CMakeFiles/T12.dir/Output.cpp.o: CMakeFiles/T12.dir/flags.make
CMakeFiles/T12.dir/Output.cpp.o: ../Output.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/T12.dir/Output.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/T12.dir/Output.cpp.o -c /Users/necromaner/program/C-/leetcode/tencent/Output.cpp

CMakeFiles/T12.dir/Output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/T12.dir/Output.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/necromaner/program/C-/leetcode/tencent/Output.cpp > CMakeFiles/T12.dir/Output.cpp.i

CMakeFiles/T12.dir/Output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/T12.dir/Output.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/necromaner/program/C-/leetcode/tencent/Output.cpp -o CMakeFiles/T12.dir/Output.cpp.s

CMakeFiles/T12.dir/Output.cpp.o.requires:

.PHONY : CMakeFiles/T12.dir/Output.cpp.o.requires

CMakeFiles/T12.dir/Output.cpp.o.provides: CMakeFiles/T12.dir/Output.cpp.o.requires
	$(MAKE) -f CMakeFiles/T12.dir/build.make CMakeFiles/T12.dir/Output.cpp.o.provides.build
.PHONY : CMakeFiles/T12.dir/Output.cpp.o.provides

CMakeFiles/T12.dir/Output.cpp.o.provides.build: CMakeFiles/T12.dir/Output.cpp.o


# Object files for target T12
T12_OBJECTS = \
"CMakeFiles/T12.dir/T1/T12.cpp.o" \
"CMakeFiles/T12.dir/Output.cpp.o"

# External object files for target T12
T12_EXTERNAL_OBJECTS =

T12: CMakeFiles/T12.dir/T1/T12.cpp.o
T12: CMakeFiles/T12.dir/Output.cpp.o
T12: CMakeFiles/T12.dir/build.make
T12: CMakeFiles/T12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable T12"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/T12.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/T12.dir/build: T12

.PHONY : CMakeFiles/T12.dir/build

CMakeFiles/T12.dir/requires: CMakeFiles/T12.dir/T1/T12.cpp.o.requires
CMakeFiles/T12.dir/requires: CMakeFiles/T12.dir/Output.cpp.o.requires

.PHONY : CMakeFiles/T12.dir/requires

CMakeFiles/T12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/T12.dir/cmake_clean.cmake
.PHONY : CMakeFiles/T12.dir/clean

CMakeFiles/T12.dir/depend:
	cd /Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/necromaner/program/C-/leetcode/tencent /Users/necromaner/program/C-/leetcode/tencent /Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug /Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug /Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug/CMakeFiles/T12.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/T12.dir/depend

