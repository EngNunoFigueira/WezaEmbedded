cmake_minimum_required(VERSION 3.16)

# Project name
PROJECT (Observer_design_pattern)

# type of programming language C++ Version 17
set(CMAKE_CXX_STANDARD 17)

#list of cpp files
set(MY_LIB_SOURCES
    Observer.cpp
    DbContext.cpp
    ObserverPattern.cpp)
add_library(src_files ${MY_LIB_SOURCES})

# create binary file
add_executable(observer main.cpp)

# this the oiption to build a libray to link with the main
target_link_libraries(observer src_files)

