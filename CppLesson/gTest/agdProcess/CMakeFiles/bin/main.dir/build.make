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
CMAKE_SOURCE_DIR = /media/nundelTech/CppLesson/gTest/agdProcess

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/nundelTech/CppLesson/gTest/agdProcess

# Include any dependencies generated for this target.
include CMakeFiles/bin/main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bin/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bin/main.dir/flags.make

CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.o: CMakeFiles/bin/main.dir/flags.make
CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.o: src/agdmedica_process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/nundelTech/CppLesson/gTest/agdProcess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.o -c /media/nundelTech/CppLesson/gTest/agdProcess/src/agdmedica_process.cpp

CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/nundelTech/CppLesson/gTest/agdProcess/src/agdmedica_process.cpp > CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.i

CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/nundelTech/CppLesson/gTest/agdProcess/src/agdmedica_process.cpp -o CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.s

CMakeFiles/bin/main.dir/src/Foo.cpp.o: CMakeFiles/bin/main.dir/flags.make
CMakeFiles/bin/main.dir/src/Foo.cpp.o: src/Foo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/nundelTech/CppLesson/gTest/agdProcess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bin/main.dir/src/Foo.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/bin/main.dir/src/Foo.cpp.o -c /media/nundelTech/CppLesson/gTest/agdProcess/src/Foo.cpp

CMakeFiles/bin/main.dir/src/Foo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bin/main.dir/src/Foo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /media/nundelTech/CppLesson/gTest/agdProcess/src/Foo.cpp > CMakeFiles/bin/main.dir/src/Foo.cpp.i

CMakeFiles/bin/main.dir/src/Foo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bin/main.dir/src/Foo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /media/nundelTech/CppLesson/gTest/agdProcess/src/Foo.cpp -o CMakeFiles/bin/main.dir/src/Foo.cpp.s

# Object files for target bin/main
bin/main_OBJECTS = \
"CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.o" \
"CMakeFiles/bin/main.dir/src/Foo.cpp.o"

# External object files for target bin/main
bin/main_EXTERNAL_OBJECTS =

bin/main: CMakeFiles/bin/main.dir/src/agdmedica_process.cpp.o
bin/main: CMakeFiles/bin/main.dir/src/Foo.cpp.o
bin/main: CMakeFiles/bin/main.dir/build.make
bin/main: CMakeFiles/bin/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/nundelTech/CppLesson/gTest/agdProcess/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bin/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bin/main.dir/build: bin/main

.PHONY : CMakeFiles/bin/main.dir/build

CMakeFiles/bin/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bin/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bin/main.dir/clean

CMakeFiles/bin/main.dir/depend:
	cd /media/nundelTech/CppLesson/gTest/agdProcess && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/nundelTech/CppLesson/gTest/agdProcess /media/nundelTech/CppLesson/gTest/agdProcess /media/nundelTech/CppLesson/gTest/agdProcess /media/nundelTech/CppLesson/gTest/agdProcess /media/nundelTech/CppLesson/gTest/agdProcess/CMakeFiles/bin/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bin/main.dir/depend
