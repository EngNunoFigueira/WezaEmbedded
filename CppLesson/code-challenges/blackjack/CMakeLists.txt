cmake_minimum_required(VERSION 3.10)

project(MyProject)

# Set the build type to Debug by default
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Set debug-specific flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_C_FLAGS_DEBUG "-g -O0")

# Add debug-specific definitions
add_compile_definitions($<$<CONFIG:Debug>:DEBUG>)

# Add your source files and targets
add_executable(MyExecutable main.cpp)
