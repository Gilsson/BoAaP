cmake_minimum_required(VERSION 3.23)
project(Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project GameOfLife.cpp FieldOfLife.h SlotMachine.h FieldOfLife.cpp)
