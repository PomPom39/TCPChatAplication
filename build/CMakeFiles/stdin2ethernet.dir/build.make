# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = "/home/mahesh/Desktop/git_projects/Chat Application"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/mahesh/Desktop/git_projects/Chat Application/build"

# Include any dependencies generated for this target.
include CMakeFiles/stdin2ethernet.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/stdin2ethernet.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/stdin2ethernet.dir/flags.make

CMakeFiles/stdin2ethernet.dir/src/netconf.c.o: CMakeFiles/stdin2ethernet.dir/flags.make
CMakeFiles/stdin2ethernet.dir/src/netconf.c.o: ../src/netconf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mahesh/Desktop/git_projects/Chat Application/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/stdin2ethernet.dir/src/netconf.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stdin2ethernet.dir/src/netconf.c.o   -c "/home/mahesh/Desktop/git_projects/Chat Application/src/netconf.c"

CMakeFiles/stdin2ethernet.dir/src/netconf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stdin2ethernet.dir/src/netconf.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mahesh/Desktop/git_projects/Chat Application/src/netconf.c" > CMakeFiles/stdin2ethernet.dir/src/netconf.c.i

CMakeFiles/stdin2ethernet.dir/src/netconf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stdin2ethernet.dir/src/netconf.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mahesh/Desktop/git_projects/Chat Application/src/netconf.c" -o CMakeFiles/stdin2ethernet.dir/src/netconf.c.s

CMakeFiles/stdin2ethernet.dir/src/netconf.c.o.requires:

.PHONY : CMakeFiles/stdin2ethernet.dir/src/netconf.c.o.requires

CMakeFiles/stdin2ethernet.dir/src/netconf.c.o.provides: CMakeFiles/stdin2ethernet.dir/src/netconf.c.o.requires
	$(MAKE) -f CMakeFiles/stdin2ethernet.dir/build.make CMakeFiles/stdin2ethernet.dir/src/netconf.c.o.provides.build
.PHONY : CMakeFiles/stdin2ethernet.dir/src/netconf.c.o.provides

CMakeFiles/stdin2ethernet.dir/src/netconf.c.o.provides.build: CMakeFiles/stdin2ethernet.dir/src/netconf.c.o


CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o: CMakeFiles/stdin2ethernet.dir/flags.make
CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o: ../src/stdin2ethernet.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mahesh/Desktop/git_projects/Chat Application/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o   -c "/home/mahesh/Desktop/git_projects/Chat Application/src/stdin2ethernet.c"

CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mahesh/Desktop/git_projects/Chat Application/src/stdin2ethernet.c" > CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.i

CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mahesh/Desktop/git_projects/Chat Application/src/stdin2ethernet.c" -o CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.s

CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o.requires:

.PHONY : CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o.requires

CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o.provides: CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o.requires
	$(MAKE) -f CMakeFiles/stdin2ethernet.dir/build.make CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o.provides.build
.PHONY : CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o.provides

CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o.provides.build: CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o


# Object files for target stdin2ethernet
stdin2ethernet_OBJECTS = \
"CMakeFiles/stdin2ethernet.dir/src/netconf.c.o" \
"CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o"

# External object files for target stdin2ethernet
stdin2ethernet_EXTERNAL_OBJECTS =

stdin2ethernet: CMakeFiles/stdin2ethernet.dir/src/netconf.c.o
stdin2ethernet: CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o
stdin2ethernet: CMakeFiles/stdin2ethernet.dir/build.make
stdin2ethernet: CMakeFiles/stdin2ethernet.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/mahesh/Desktop/git_projects/Chat Application/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable stdin2ethernet"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stdin2ethernet.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/stdin2ethernet.dir/build: stdin2ethernet

.PHONY : CMakeFiles/stdin2ethernet.dir/build

CMakeFiles/stdin2ethernet.dir/requires: CMakeFiles/stdin2ethernet.dir/src/netconf.c.o.requires
CMakeFiles/stdin2ethernet.dir/requires: CMakeFiles/stdin2ethernet.dir/src/stdin2ethernet.c.o.requires

.PHONY : CMakeFiles/stdin2ethernet.dir/requires

CMakeFiles/stdin2ethernet.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/stdin2ethernet.dir/cmake_clean.cmake
.PHONY : CMakeFiles/stdin2ethernet.dir/clean

CMakeFiles/stdin2ethernet.dir/depend:
	cd "/home/mahesh/Desktop/git_projects/Chat Application/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/mahesh/Desktop/git_projects/Chat Application" "/home/mahesh/Desktop/git_projects/Chat Application" "/home/mahesh/Desktop/git_projects/Chat Application/build" "/home/mahesh/Desktop/git_projects/Chat Application/build" "/home/mahesh/Desktop/git_projects/Chat Application/build/CMakeFiles/stdin2ethernet.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/stdin2ethernet.dir/depend
