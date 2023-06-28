cmake_minimum_required(VERSION 3.16)

message("This is the project libraries directory")

PROJECT (project_ex02)

add_library( mylibraries SHARED ${CMAKE_CURRENT_SOURCE_DIR}/Foo.h ${CMAKE_CURRENT_SOURCE_DIR}/Foo.cpp ${CMAKE_CURRENT_SOURCE_DIR}/BankService.hpp ${CMAKE_CURRENT_SOURCE_DIR}/BankService.cpp)

target_include_directories( mylibraries PUBLIC ${CMAKE_CURRENT_LIST_DIR} )
