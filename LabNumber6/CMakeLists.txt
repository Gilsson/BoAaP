cmake_minimum_required(VERSION 3.23)
project(LabNumber6)

set(CMAKE_CXX_STANDARD 14)

add_executable(1Task 1Task.cpp)
add_executable(2Task 2Task.cpp)
add_executable(3Task 3Task.cpp)
add_executable(4Task 4Task.cpp)
add_executable(5Task 5Task.cpp 5Task.h)
add_executable(6Task 6Task.cpp)
add_executable(7Task 7Task.cpp)
add_executable(8Task 8Task.cpp)
add_subdirectory(tests)

