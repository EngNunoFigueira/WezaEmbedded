cmake_minimum_required(VERSION 3.14)

message("This is the project path: "${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_FLAG "-stdlib=libc++")
set(CMAKE_CXX_STANDARD 20)
SET(CMAKE_CXX_STANDARD_REQUIRED true)

add_executable(main main.cpp)

target_link_libraries(main pthread)
