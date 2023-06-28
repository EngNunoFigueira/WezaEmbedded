cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)

PROJECT (project_ex01)

include_directories( include )

message("project dir folder "${PROJECT_SOURCE_DIR})

add_executable(main src/main.cpp src/Foo.cpp)

