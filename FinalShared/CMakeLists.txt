cmake_minimum_required(VERSION 3.23)
project(FinalShared)

set(CMAKE_CXX_STANDARD 14)

add_library(${PROJECT_NAME} SHARED dynamicLibrary.cpp)
