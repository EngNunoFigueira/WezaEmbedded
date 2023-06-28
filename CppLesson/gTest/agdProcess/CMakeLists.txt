cmake_minimum_required(VERSION 2.6)

PROJECT (agdmedica_process)
SET(CMAKE_CXX_STANDARD 17)
#add_subdirectory(src)
# Locate GTest
#find_package(GTest REQUIRED)
#include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(bin/main src/agdmedica_process.cpp src/Foo.cpp)
#target_link_libraries(main gtest pthread)
