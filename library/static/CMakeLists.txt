cmake_minimum_required(VERSION 3.23)
project(static)

set(CMAKE_CXX_STANDARD 14)

add_executable(main library.cpp)
set(SOURCE_FILES library.cpp)
add_library(static STATIC ${SOURCE_FILES})