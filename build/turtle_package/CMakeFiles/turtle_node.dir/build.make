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
CMAKE_SOURCE_DIR = /home/andrewubuntu/software-start-here/src/turtle_package

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrewubuntu/software-start-here/build/turtle_package

# Include any dependencies generated for this target.
include CMakeFiles/turtle_node.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/turtle_node.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/turtle_node.dir/flags.make

CMakeFiles/turtle_node.dir/src/turtle_node.cpp.o: CMakeFiles/turtle_node.dir/flags.make
CMakeFiles/turtle_node.dir/src/turtle_node.cpp.o: /home/andrewubuntu/software-start-here/src/turtle_package/src/turtle_node.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrewubuntu/software-start-here/build/turtle_package/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/turtle_node.dir/src/turtle_node.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/turtle_node.dir/src/turtle_node.cpp.o -c /home/andrewubuntu/software-start-here/src/turtle_package/src/turtle_node.cpp

CMakeFiles/turtle_node.dir/src/turtle_node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/turtle_node.dir/src/turtle_node.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrewubuntu/software-start-here/src/turtle_package/src/turtle_node.cpp > CMakeFiles/turtle_node.dir/src/turtle_node.cpp.i

CMakeFiles/turtle_node.dir/src/turtle_node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/turtle_node.dir/src/turtle_node.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrewubuntu/software-start-here/src/turtle_package/src/turtle_node.cpp -o CMakeFiles/turtle_node.dir/src/turtle_node.cpp.s

# Object files for target turtle_node
turtle_node_OBJECTS = \
"CMakeFiles/turtle_node.dir/src/turtle_node.cpp.o"

# External object files for target turtle_node
turtle_node_EXTERNAL_OBJECTS =

turtle_node: CMakeFiles/turtle_node.dir/src/turtle_node.cpp.o
turtle_node: CMakeFiles/turtle_node.dir/build.make
turtle_node: CMakeFiles/turtle_node.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrewubuntu/software-start-here/build/turtle_package/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable turtle_node"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/turtle_node.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/turtle_node.dir/build: turtle_node

.PHONY : CMakeFiles/turtle_node.dir/build

CMakeFiles/turtle_node.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/turtle_node.dir/cmake_clean.cmake
.PHONY : CMakeFiles/turtle_node.dir/clean

CMakeFiles/turtle_node.dir/depend:
	cd /home/andrewubuntu/software-start-here/build/turtle_package && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrewubuntu/software-start-here/src/turtle_package /home/andrewubuntu/software-start-here/src/turtle_package /home/andrewubuntu/software-start-here/build/turtle_package /home/andrewubuntu/software-start-here/build/turtle_package /home/andrewubuntu/software-start-here/build/turtle_package/CMakeFiles/turtle_node.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/turtle_node.dir/depend

