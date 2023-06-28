cmake_minimum_required(VERSION 3.14)

message("Compile the Google Test")

set(CMAKE_CXX_STANDARD 17)

PROJECT (Testproject_ex02)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        de6fe184a9ac1a06895cdd1c9b437f0a0bdf14ad # v2.13.4
)

# After the following call, the CMake targets defined by googletest and
# Catch2 will be available to the rest of the build
FetchContent_MakeAvailable(googletest Catch2)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME}
    mylibraries
    gtest_main
    gmock_main
)
target_include_directories(${PROJECT_NAME} PRIVATE "${GMOCK_INCLUDE_DIRS}" "${GTEST_INCLUDE_DIRS}")
add_test(NAME main COMMAND ${PROJECT_NAME})
