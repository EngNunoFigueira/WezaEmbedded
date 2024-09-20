cmake_minimum_required(VERSION 3.16)

message("This is the project source file directory")

message("This is the source: " ${CMAKE_CURRENT_SOURCE_DIR})

PROJECT (partternfactory)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")

add_library(src SHARED ${CMAKE_CURRENT_SOURCE_DIR}/Restaurant.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Menu.cpp
${CMAKE_CURRENT_SOURCE_DIR}/Waitress.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Kitchen.cpp ${CMAKE_CURRENT_SOURCE_DIR}/IBurger.hpp ${CMAKE_CURRENT_SOURCE_DIR}/Beef.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Veggie.cpp ${CMAKE_CURRENT_SOURCE_DIR}/Chicken.cpp)

target_include_directories( src PUBLIC ${CMAKE_CURRENT_LIST_DIR} )
