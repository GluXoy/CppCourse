# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\cpp\cmake\bin\cmake.exe

# The command to remove a file.
RM = C:\cpp\cmake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\cpp\cppcourse\sfml.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\cpp\cppcourse\sfml.1

# Include any dependencies generated for this target.
include 12/CMakeFiles/12.dir/depend.make

# Include the progress variables for this target.
include 12/CMakeFiles/12.dir/progress.make

# Include the compile flags for this target's objects.
include 12/CMakeFiles/12.dir/flags.make

12/CMakeFiles/12.dir/main.cpp.obj: 12/CMakeFiles/12.dir/flags.make
12/CMakeFiles/12.dir/main.cpp.obj: 12/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\cpp\cppcourse\sfml.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 12/CMakeFiles/12.dir/main.cpp.obj"
	cd /d C:\cpp\cppcourse\sfml.1\12 && C:\cpp\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\12.dir\main.cpp.obj -c C:\cpp\cppcourse\sfml.1\12\main.cpp

12/CMakeFiles/12.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/12.dir/main.cpp.i"
	cd /d C:\cpp\cppcourse\sfml.1\12 && C:\cpp\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\cpp\cppcourse\sfml.1\12\main.cpp > CMakeFiles\12.dir\main.cpp.i

12/CMakeFiles/12.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/12.dir/main.cpp.s"
	cd /d C:\cpp\cppcourse\sfml.1\12 && C:\cpp\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\cpp\cppcourse\sfml.1\12\main.cpp -o CMakeFiles\12.dir\main.cpp.s

12/CMakeFiles/12.dir/main.cpp.obj.requires:

.PHONY : 12/CMakeFiles/12.dir/main.cpp.obj.requires

12/CMakeFiles/12.dir/main.cpp.obj.provides: 12/CMakeFiles/12.dir/main.cpp.obj.requires
	$(MAKE) -f 12\CMakeFiles\12.dir\build.make 12/CMakeFiles/12.dir/main.cpp.obj.provides.build
.PHONY : 12/CMakeFiles/12.dir/main.cpp.obj.provides

12/CMakeFiles/12.dir/main.cpp.obj.provides.build: 12/CMakeFiles/12.dir/main.cpp.obj


# Object files for target 12
12_OBJECTS = \
"CMakeFiles/12.dir/main.cpp.obj"

# External object files for target 12
12_EXTERNAL_OBJECTS =

12/12.exe: 12/CMakeFiles/12.dir/main.cpp.obj
12/12.exe: 12/CMakeFiles/12.dir/build.make
12/12.exe: C:/cpp/MinGW/lib/libsfml-window-s.a
12/12.exe: C:/cpp/MinGW/lib/libsfml-graphics-s.a
12/12.exe: C:/cpp/MinGW/lib/libsfml-system-s.a
12/12.exe: C:/cpp/MinGW/lib/libfreetype.a
12/12.exe: C:/cpp/MinGW/lib/libjpeg.a
12/12.exe: 12/CMakeFiles/12.dir/linklibs.rsp
12/12.exe: 12/CMakeFiles/12.dir/objects1.rsp
12/12.exe: 12/CMakeFiles/12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\cpp\cppcourse\sfml.1\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 12.exe"
	cd /d C:\cpp\cppcourse\sfml.1\12 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\12.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
12/CMakeFiles/12.dir/build: 12/12.exe

.PHONY : 12/CMakeFiles/12.dir/build

12/CMakeFiles/12.dir/requires: 12/CMakeFiles/12.dir/main.cpp.obj.requires

.PHONY : 12/CMakeFiles/12.dir/requires

12/CMakeFiles/12.dir/clean:
	cd /d C:\cpp\cppcourse\sfml.1\12 && $(CMAKE_COMMAND) -P CMakeFiles\12.dir\cmake_clean.cmake
.PHONY : 12/CMakeFiles/12.dir/clean

12/CMakeFiles/12.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\cpp\cppcourse\sfml.1 C:\cpp\cppcourse\sfml.1\12 C:\cpp\cppcourse\sfml.1 C:\cpp\cppcourse\sfml.1\12 C:\cpp\cppcourse\sfml.1\12\CMakeFiles\12.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : 12/CMakeFiles/12.dir/depend

