# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.2.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/A3_2_VisitorTemplates.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/A3_2_VisitorTemplates.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/A3_2_VisitorTemplates.dir/flags.make

CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj: CMakeFiles/A3_2_VisitorTemplates.dir/flags.make
CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\A3_2_VisitorTemplates.dir\main.cpp.obj -c C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates\main.cpp

CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates\main.cpp > CMakeFiles\A3_2_VisitorTemplates.dir\main.cpp.i

CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates\main.cpp -o CMakeFiles\A3_2_VisitorTemplates.dir\main.cpp.s

CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj.requires

CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj.provides: CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\A3_2_VisitorTemplates.dir\build.make CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj.provides

CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj.provides.build: CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj


# Object files for target A3_2_VisitorTemplates
A3_2_VisitorTemplates_OBJECTS = \
"CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj"

# External object files for target A3_2_VisitorTemplates
A3_2_VisitorTemplates_EXTERNAL_OBJECTS =

A3_2_VisitorTemplates.exe: CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj
A3_2_VisitorTemplates.exe: CMakeFiles/A3_2_VisitorTemplates.dir/build.make
A3_2_VisitorTemplates.exe: CMakeFiles/A3_2_VisitorTemplates.dir/linklibs.rsp
A3_2_VisitorTemplates.exe: CMakeFiles/A3_2_VisitorTemplates.dir/objects1.rsp
A3_2_VisitorTemplates.exe: CMakeFiles/A3_2_VisitorTemplates.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable A3_2_VisitorTemplates.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\A3_2_VisitorTemplates.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/A3_2_VisitorTemplates.dir/build: A3_2_VisitorTemplates.exe

.PHONY : CMakeFiles/A3_2_VisitorTemplates.dir/build

CMakeFiles/A3_2_VisitorTemplates.dir/requires: CMakeFiles/A3_2_VisitorTemplates.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/A3_2_VisitorTemplates.dir/requires

CMakeFiles/A3_2_VisitorTemplates.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\A3_2_VisitorTemplates.dir\cmake_clean.cmake
.PHONY : CMakeFiles/A3_2_VisitorTemplates.dir/clean

CMakeFiles/A3_2_VisitorTemplates.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates\cmake-build-debug C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates\cmake-build-debug C:\Users\Tera\Desktop\SCHOOL\A00820377_AyMSS18\Actividades\A3.2.VisitorTemplates\cmake-build-debug\CMakeFiles\A3_2_VisitorTemplates.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/A3_2_VisitorTemplates.dir/depend

