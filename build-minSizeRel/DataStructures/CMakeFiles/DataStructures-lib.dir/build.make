# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/andreas/Documenti/Progetti/SemantisedTriangleMesh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel

# Include any dependencies generated for this target.
include DataStructures/CMakeFiles/DataStructures-lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include DataStructures/CMakeFiles/DataStructures-lib.dir/compiler_depend.make

# Include the progress variables for this target.
include DataStructures/CMakeFiles/DataStructures-lib.dir/progress.make

# Include the compile flags for this target's objects.
include DataStructures/CMakeFiles/DataStructures-lib.dir/flags.make

# Object files for target DataStructures-lib
DataStructures__lib_OBJECTS =

# External object files for target DataStructures-lib
DataStructures__lib_EXTERNAL_OBJECTS =

DataStructures/libDataStructures-lib.a: DataStructures/CMakeFiles/DataStructures-lib.dir/build.make
DataStructures/libDataStructures-lib.a: DataStructures/CMakeFiles/DataStructures-lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libDataStructures-lib.a"
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures && $(CMAKE_COMMAND) -P CMakeFiles/DataStructures-lib.dir/cmake_clean_target.cmake
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DataStructures-lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DataStructures/CMakeFiles/DataStructures-lib.dir/build: DataStructures/libDataStructures-lib.a
.PHONY : DataStructures/CMakeFiles/DataStructures-lib.dir/build

DataStructures/CMakeFiles/DataStructures-lib.dir/clean:
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures && $(CMAKE_COMMAND) -P CMakeFiles/DataStructures-lib.dir/cmake_clean.cmake
.PHONY : DataStructures/CMakeFiles/DataStructures-lib.dir/clean

DataStructures/CMakeFiles/DataStructures-lib.dir/depend:
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andreas/Documenti/Progetti/SemantisedTriangleMesh /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/DataStructures /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures/CMakeFiles/DataStructures-lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DataStructures/CMakeFiles/DataStructures-lib.dir/depend

