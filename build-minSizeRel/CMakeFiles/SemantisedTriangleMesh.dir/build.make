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
include CMakeFiles/SemantisedTriangleMesh.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SemantisedTriangleMesh.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SemantisedTriangleMesh.dir/flags.make

CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.o: ../src/Vertex.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Vertex.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Vertex.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Vertex.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.o: ../src/Point.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Point.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Point.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Point.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.o: ../src/Edge.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Edge.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Edge.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Edge.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.o: ../src/Triangle.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Triangle.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Triangle.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/Triangle.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.o: ../src/TriangleMesh.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/TriangleMesh.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/TriangleMesh.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/TriangleMesh.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.o: ../src/semanticsfilemanager.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/semanticsfilemanager.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/semanticsfilemanager.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/semanticsfilemanager.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.o: ../src/annotation.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/annotation.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/annotation.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/annotation.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.o: ../src/pointannotation.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/pointannotation.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/pointannotation.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/pointannotation.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.o: ../src/lineannotation.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/lineannotation.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/lineannotation.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/lineannotation.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.o: ../src/surfaceannotation.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/surfaceannotation.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/surfaceannotation.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/surfaceannotation.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.o: ../src/attribute.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/attribute.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/attribute.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/attribute.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.o: ../src/geometricattribute.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/geometricattribute.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/geometricattribute.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/geometricattribute.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.o: ../src/euclideanmeasure.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/euclideanmeasure.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/euclideanmeasure.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/euclideanmeasure.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.o: ../src/geodesicmeasure.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/geodesicmeasure.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/geodesicmeasure.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/geodesicmeasure.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.o: ../src/boundingmeasure.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/boundingmeasure.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/boundingmeasure.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/boundingmeasure.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.o: ../src/semanticattribute.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/semanticattribute.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/semanticattribute.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/semanticattribute.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.o: ../src/relationship.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/relationship.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/relationship.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/relationship.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.s

CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/flags.make
CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.o: ../src/KDTree.cpp
CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.o: CMakeFiles/SemantisedTriangleMesh.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.o -MF CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.o.d -o CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.o -c /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/KDTree.cpp

CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/KDTree.cpp > CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.i

CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/src/KDTree.cpp -o CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.s

# Object files for target SemantisedTriangleMesh
SemantisedTriangleMesh_OBJECTS = \
"CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.o" \
"CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.o"

# External object files for target SemantisedTriangleMesh
SemantisedTriangleMesh_EXTERNAL_OBJECTS =

libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/Vertex.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/Point.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/Edge.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/Triangle.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/TriangleMesh.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/semanticsfilemanager.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/annotation.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/pointannotation.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/lineannotation.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/surfaceannotation.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/attribute.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/geometricattribute.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/euclideanmeasure.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/geodesicmeasure.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/boundingmeasure.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/semanticattribute.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/relationship.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/src/KDTree.cpp.o
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/build.make
libSemantisedTriangleMesh.a: CMakeFiles/SemantisedTriangleMesh.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Linking CXX static library libSemantisedTriangleMesh.a"
	$(CMAKE_COMMAND) -P CMakeFiles/SemantisedTriangleMesh.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SemantisedTriangleMesh.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SemantisedTriangleMesh.dir/build: libSemantisedTriangleMesh.a
.PHONY : CMakeFiles/SemantisedTriangleMesh.dir/build

CMakeFiles/SemantisedTriangleMesh.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SemantisedTriangleMesh.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SemantisedTriangleMesh.dir/clean

CMakeFiles/SemantisedTriangleMesh.dir/depend:
	cd /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andreas/Documenti/Progetti/SemantisedTriangleMesh /home/andreas/Documenti/Progetti/SemantisedTriangleMesh /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel /home/andreas/Documenti/Progetti/SemantisedTriangleMesh/build-minSizeRel/CMakeFiles/SemantisedTriangleMesh.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SemantisedTriangleMesh.dir/depend
