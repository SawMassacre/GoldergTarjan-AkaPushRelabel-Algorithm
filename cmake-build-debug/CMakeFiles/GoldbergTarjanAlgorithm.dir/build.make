# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/GoldbergTarjanAlgorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GoldbergTarjanAlgorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GoldbergTarjanAlgorithm.dir/flags.make

CMakeFiles/GoldbergTarjanAlgorithm.dir/main.cpp.obj: CMakeFiles/GoldbergTarjanAlgorithm.dir/flags.make
CMakeFiles/GoldbergTarjanAlgorithm.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/GoldbergTarjanAlgorithm.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\GoldbergTarjanAlgorithm.dir\main.cpp.obj -c "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm\main.cpp"

CMakeFiles/GoldbergTarjanAlgorithm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GoldbergTarjanAlgorithm.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm\main.cpp" > CMakeFiles\GoldbergTarjanAlgorithm.dir\main.cpp.i

CMakeFiles/GoldbergTarjanAlgorithm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GoldbergTarjanAlgorithm.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm\main.cpp" -o CMakeFiles\GoldbergTarjanAlgorithm.dir\main.cpp.s

# Object files for target GoldbergTarjanAlgorithm
GoldbergTarjanAlgorithm_OBJECTS = \
"CMakeFiles/GoldbergTarjanAlgorithm.dir/main.cpp.obj"

# External object files for target GoldbergTarjanAlgorithm
GoldbergTarjanAlgorithm_EXTERNAL_OBJECTS =

GoldbergTarjanAlgorithm.exe: CMakeFiles/GoldbergTarjanAlgorithm.dir/main.cpp.obj
GoldbergTarjanAlgorithm.exe: CMakeFiles/GoldbergTarjanAlgorithm.dir/build.make
GoldbergTarjanAlgorithm.exe: CMakeFiles/GoldbergTarjanAlgorithm.dir/linklibs.rsp
GoldbergTarjanAlgorithm.exe: CMakeFiles/GoldbergTarjanAlgorithm.dir/objects1.rsp
GoldbergTarjanAlgorithm.exe: CMakeFiles/GoldbergTarjanAlgorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable GoldbergTarjanAlgorithm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\GoldbergTarjanAlgorithm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GoldbergTarjanAlgorithm.dir/build: GoldbergTarjanAlgorithm.exe

.PHONY : CMakeFiles/GoldbergTarjanAlgorithm.dir/build

CMakeFiles/GoldbergTarjanAlgorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\GoldbergTarjanAlgorithm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/GoldbergTarjanAlgorithm.dir/clean

CMakeFiles/GoldbergTarjanAlgorithm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm" "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm" "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm\cmake-build-debug" "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm\cmake-build-debug" "C:\Program Files\Uni\SecondYearFirstTerm\Algorithms\GoldbergTarjanAlgorithm\cmake-build-debug\CMakeFiles\GoldbergTarjanAlgorithm.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/GoldbergTarjanAlgorithm.dir/depend

