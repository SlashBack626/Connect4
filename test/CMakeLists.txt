cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

include_directories(../lib)
add_executable(4WinTest test.cpp)

target_link_libraries(
        4WinTest
        PUBLIC
        gtest_main
        GameLib
)