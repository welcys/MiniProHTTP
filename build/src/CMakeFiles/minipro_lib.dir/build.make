# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/welch/Desktop/top/MiniPro-HTTP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/welch/Desktop/top/MiniPro-HTTP/build

# Include any dependencies generated for this target.
include src/CMakeFiles/minipro_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/minipro_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/minipro_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/minipro_lib.dir/flags.make

src/CMakeFiles/minipro_lib.dir/codegen:
.PHONY : src/CMakeFiles/minipro_lib.dir/codegen

src/CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.o: src/CMakeFiles/minipro_lib.dir/flags.make
src/CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.o: /Users/welch/Desktop/top/MiniPro-HTTP/src/threadpool/threadpool.cpp
src/CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.o: src/CMakeFiles/minipro_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/welch/Desktop/top/MiniPro-HTTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.o"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.o -MF CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.o.d -o CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.o -c /Users/welch/Desktop/top/MiniPro-HTTP/src/threadpool/threadpool.cpp

src/CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.i"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/welch/Desktop/top/MiniPro-HTTP/src/threadpool/threadpool.cpp > CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.i

src/CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.s"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/welch/Desktop/top/MiniPro-HTTP/src/threadpool/threadpool.cpp -o CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.s

src/CMakeFiles/minipro_lib.dir/logger/Logger.cpp.o: src/CMakeFiles/minipro_lib.dir/flags.make
src/CMakeFiles/minipro_lib.dir/logger/Logger.cpp.o: /Users/welch/Desktop/top/MiniPro-HTTP/src/logger/Logger.cpp
src/CMakeFiles/minipro_lib.dir/logger/Logger.cpp.o: src/CMakeFiles/minipro_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/welch/Desktop/top/MiniPro-HTTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/minipro_lib.dir/logger/Logger.cpp.o"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minipro_lib.dir/logger/Logger.cpp.o -MF CMakeFiles/minipro_lib.dir/logger/Logger.cpp.o.d -o CMakeFiles/minipro_lib.dir/logger/Logger.cpp.o -c /Users/welch/Desktop/top/MiniPro-HTTP/src/logger/Logger.cpp

src/CMakeFiles/minipro_lib.dir/logger/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minipro_lib.dir/logger/Logger.cpp.i"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/welch/Desktop/top/MiniPro-HTTP/src/logger/Logger.cpp > CMakeFiles/minipro_lib.dir/logger/Logger.cpp.i

src/CMakeFiles/minipro_lib.dir/logger/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minipro_lib.dir/logger/Logger.cpp.s"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/welch/Desktop/top/MiniPro-HTTP/src/logger/Logger.cpp -o CMakeFiles/minipro_lib.dir/logger/Logger.cpp.s

src/CMakeFiles/minipro_lib.dir/config/Config.cpp.o: src/CMakeFiles/minipro_lib.dir/flags.make
src/CMakeFiles/minipro_lib.dir/config/Config.cpp.o: /Users/welch/Desktop/top/MiniPro-HTTP/src/config/Config.cpp
src/CMakeFiles/minipro_lib.dir/config/Config.cpp.o: src/CMakeFiles/minipro_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/welch/Desktop/top/MiniPro-HTTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/minipro_lib.dir/config/Config.cpp.o"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/minipro_lib.dir/config/Config.cpp.o -MF CMakeFiles/minipro_lib.dir/config/Config.cpp.o.d -o CMakeFiles/minipro_lib.dir/config/Config.cpp.o -c /Users/welch/Desktop/top/MiniPro-HTTP/src/config/Config.cpp

src/CMakeFiles/minipro_lib.dir/config/Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/minipro_lib.dir/config/Config.cpp.i"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/welch/Desktop/top/MiniPro-HTTP/src/config/Config.cpp > CMakeFiles/minipro_lib.dir/config/Config.cpp.i

src/CMakeFiles/minipro_lib.dir/config/Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/minipro_lib.dir/config/Config.cpp.s"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/welch/Desktop/top/MiniPro-HTTP/src/config/Config.cpp -o CMakeFiles/minipro_lib.dir/config/Config.cpp.s

# Object files for target minipro_lib
minipro_lib_OBJECTS = \
"CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.o" \
"CMakeFiles/minipro_lib.dir/logger/Logger.cpp.o" \
"CMakeFiles/minipro_lib.dir/config/Config.cpp.o"

# External object files for target minipro_lib
minipro_lib_EXTERNAL_OBJECTS =

src/libminipro_lib.a: src/CMakeFiles/minipro_lib.dir/threadpool/threadpool.cpp.o
src/libminipro_lib.a: src/CMakeFiles/minipro_lib.dir/logger/Logger.cpp.o
src/libminipro_lib.a: src/CMakeFiles/minipro_lib.dir/config/Config.cpp.o
src/libminipro_lib.a: src/CMakeFiles/minipro_lib.dir/build.make
src/libminipro_lib.a: src/CMakeFiles/minipro_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/welch/Desktop/top/MiniPro-HTTP/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libminipro_lib.a"
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && $(CMAKE_COMMAND) -P CMakeFiles/minipro_lib.dir/cmake_clean_target.cmake
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minipro_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/minipro_lib.dir/build: src/libminipro_lib.a
.PHONY : src/CMakeFiles/minipro_lib.dir/build

src/CMakeFiles/minipro_lib.dir/clean:
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build/src && $(CMAKE_COMMAND) -P CMakeFiles/minipro_lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/minipro_lib.dir/clean

src/CMakeFiles/minipro_lib.dir/depend:
	cd /Users/welch/Desktop/top/MiniPro-HTTP/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/welch/Desktop/top/MiniPro-HTTP /Users/welch/Desktop/top/MiniPro-HTTP/src /Users/welch/Desktop/top/MiniPro-HTTP/build /Users/welch/Desktop/top/MiniPro-HTTP/build/src /Users/welch/Desktop/top/MiniPro-HTTP/build/src/CMakeFiles/minipro_lib.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/minipro_lib.dir/depend

