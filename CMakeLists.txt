cmake_minimum_required(VERSION 3.16)
project(Connect4)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(googletest)
add_subdirectory(lib)
add_subdirectory(test)

include_directories(lib)

add_executable(Connect4 main.cpp)

target_link_libraries(
        Connect4
        PUBLIC
        GameLib
)