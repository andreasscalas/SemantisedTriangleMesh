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
include DataStructures/CMakeFiles/testGraph.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include DataStructures/CMakeFiles/testGraph.dir/compiler_depend.make

# Include the progress variables for this target.
include DataStructures/CMakeFiles/testGraph.dir/progress.make

# Include the compile flags for this target's objects.
include DataStructures/CMakeFiles/testGraph.dir/flags.make

DataStructures/CMakeFiles/testGraph.dir/src/testGraph.cpp.o: DataStructures/CMakeFiles/testGraph.dir/flags.make
DataStructures/CMakeFiles/testGraph.dir/src/testGraph.cpp.o: ../DataStructures/src/testGraph.cpp
DataStructures/CMakeFiles/testGraph.dir/src/testGraph.cpp.o: DataStructures/CMakeFiles/testGraph.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object DataStructures/CMakeFiles/testGraph.dir/src/testGraph.cpp.o"
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT DataStructures/CMakeFiles/testGraph.dir/src/testGraph.cpp.o -MF CMakeFiles/testGraph.dir/src/testGraph.cpp.o.d -o CMakeFiles/testGraph.dir/src/testGraph.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/DataStructures/src/testGraph.cpp

DataStructures/CMakeFiles/testGraph.dir/src/testGraph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/testGraph.dir/src/testGraph.cpp.i"
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/DataStructures/src/testGraph.cpp > CMakeFiles/testGraph.dir/src/testGraph.cpp.i

DataStructures/CMakeFiles/testGraph.dir/src/testGraph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/testGraph.dir/src/testGraph.cpp.s"
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/DataStructures/src/testGraph.cpp -o CMakeFiles/testGraph.dir/src/testGraph.cpp.s

# Object files for target testGraph
testGraph_OBJECTS = \
"CMakeFiles/testGraph.dir/src/testGraph.cpp.o"

# External object files for target testGraph
testGraph_EXTERNAL_OBJECTS =

DataStructures/testGraph: DataStructures/CMakeFiles/testGraph.dir/src/testGraph.cpp.o
DataStructures/testGraph: DataStructures/CMakeFiles/testGraph.dir/build.make
DataStructures/testGraph: DataStructures/CMakeFiles/testGraph.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable testGraph"
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/testGraph.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
DataStructures/CMakeFiles/testGraph.dir/build: DataStructures/testGraph
.PHONY : DataStructures/CMakeFiles/testGraph.dir/build

DataStructures/CMakeFiles/testGraph.dir/clean:
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures && $(CMAKE_COMMAND) -P CMakeFiles/testGraph.dir/cmake_clean.cmake
.PHONY : DataStructures/CMakeFiles/testGraph.dir/clean

DataStructures/CMakeFiles/testGraph.dir/depend:
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andreas/Documenti/Progetti/SemantisedTriangleMesh /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/DataStructures /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/DataStructures/CMakeFiles/testGraph.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : DataStructures/CMakeFiles/testGraph.dir/depend
