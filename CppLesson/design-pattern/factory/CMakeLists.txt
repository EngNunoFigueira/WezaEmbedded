cmake_minimum_required(VERSION 3.14)

message("This is the project path: "${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

PROJECT (partternfactory)

add_subdirectory(src)

add_executable(main main.cpp)

target_link_libraries(main src)
