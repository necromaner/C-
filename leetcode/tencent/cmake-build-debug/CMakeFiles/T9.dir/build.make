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
include CMakeFiles/T9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/T9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/T9.dir/flags.make

CMakeFiles/T9.dir/T1/T9.cpp.o: CMakeFiles/T9.dir/flags.make
CMakeFiles/T9.dir/T1/T9.cpp.o: ../T1/T9.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/T9.dir/T1/T9.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/T9.dir/T1/T9.cpp.o -c /Users/necromaner/program/C-/leetcode/tencent/T1/T9.cpp

CMakeFiles/T9.dir/T1/T9.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/T9.dir/T1/T9.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/necromaner/program/C-/leetcode/tencent/T1/T9.cpp > CMakeFiles/T9.dir/T1/T9.cpp.i

CMakeFiles/T9.dir/T1/T9.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/T9.dir/T1/T9.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/necromaner/program/C-/leetcode/tencent/T1/T9.cpp -o CMakeFiles/T9.dir/T1/T9.cpp.s

CMakeFiles/T9.dir/T1/T9.cpp.o.requires:

.PHONY : CMakeFiles/T9.dir/T1/T9.cpp.o.requires

CMakeFiles/T9.dir/T1/T9.cpp.o.provides: CMakeFiles/T9.dir/T1/T9.cpp.o.requires
	$(MAKE) -f CMakeFiles/T9.dir/build.make CMakeFiles/T9.dir/T1/T9.cpp.o.provides.build
.PHONY : CMakeFiles/T9.dir/T1/T9.cpp.o.provides

CMakeFiles/T9.dir/T1/T9.cpp.o.provides.build: CMakeFiles/T9.dir/T1/T9.cpp.o


CMakeFiles/T9.dir/Output.cpp.o: CMakeFiles/T9.dir/flags.make
CMakeFiles/T9.dir/Output.cpp.o: ../Output.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/T9.dir/Output.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/T9.dir/Output.cpp.o -c /Users/necromaner/program/C-/leetcode/tencent/Output.cpp

CMakeFiles/T9.dir/Output.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/T9.dir/Output.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/necromaner/program/C-/leetcode/tencent/Output.cpp > CMakeFiles/T9.dir/Output.cpp.i

CMakeFiles/T9.dir/Output.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/T9.dir/Output.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/necromaner/program/C-/leetcode/tencent/Output.cpp -o CMakeFiles/T9.dir/Output.cpp.s

CMakeFiles/T9.dir/Output.cpp.o.requires:

.PHONY : CMakeFiles/T9.dir/Output.cpp.o.requires

CMakeFiles/T9.dir/Output.cpp.o.provides: CMakeFiles/T9.dir/Output.cpp.o.requires
	$(MAKE) -f CMakeFiles/T9.dir/build.make CMakeFiles/T9.dir/Output.cpp.o.provides.build
.PHONY : CMakeFiles/T9.dir/Output.cpp.o.provides

CMakeFiles/T9.dir/Output.cpp.o.provides.build: CMakeFiles/T9.dir/Output.cpp.o


# Object files for target T9
T9_OBJECTS = \
"CMakeFiles/T9.dir/T1/T9.cpp.o" \
"CMakeFiles/T9.dir/Output.cpp.o"

# External object files for target T9
T9_EXTERNAL_OBJECTS =

T9: CMakeFiles/T9.dir/T1/T9.cpp.o
T9: CMakeFiles/T9.dir/Output.cpp.o
T9: CMakeFiles/T9.dir/build.make
T9: CMakeFiles/T9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable T9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/T9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/T9.dir/build: T9

.PHONY : CMakeFiles/T9.dir/build

CMakeFiles/T9.dir/requires: CMakeFiles/T9.dir/T1/T9.cpp.o.requires
CMakeFiles/T9.dir/requires: CMakeFiles/T9.dir/Output.cpp.o.requires

.PHONY : CMakeFiles/T9.dir/requires

CMakeFiles/T9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/T9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/T9.dir/clean

CMakeFiles/T9.dir/depend:
	cd /Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/necromaner/program/C-/leetcode/tencent /Users/necromaner/program/C-/leetcode/tencent /Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug /Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug /Users/necromaner/program/C-/leetcode/tencent/cmake-build-debug/CMakeFiles/T9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/T9.dir/depend

