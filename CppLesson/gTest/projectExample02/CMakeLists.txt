cmake_minimum_required(VERSION 3.14)

message("This is the project path: "${CMAKE_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

PROJECT (project_ex02)

add_subdirectory(mylibraries)
add_subdirectory(test)

add_executable(main ${CMAKE_SOURCE_DIR}/src/main.cpp)

target_link_libraries(main mylibraries)
