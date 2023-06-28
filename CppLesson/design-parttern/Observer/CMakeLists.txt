cmake_minimum_required(VERSION 3.16)

# type of programming language C++ Version 17
set(CMAKE_CXX_STANDARD 17)

# Set output folders
message("The bin path: "${CMAKE_BINARY_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Project name
PROJECT (Observer_design_pattern)

message("This is the include directory: " ${PROJECT_SOURCE_DIR}/includes)

include_directories(${PROJECT_SOURCE_DIR}/includes)

# Adds the Sources subfolder of the Yoctopuce C++ library.
add_subdirectory (${PROJECT_SOURCE_DIR}/src)


