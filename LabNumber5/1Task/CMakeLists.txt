cmake_minimum_required(VERSION 3.23)
project(1Task)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") # CMAKE_CURRENT_LIST_DIR is the directory holding the CMakeLists.txt we are currently using


include(FindPkgConfig)
find_package(static REQUIRED)
add_executable(${PROJECT_NAME} 1Task.cpp)
include_directories(${STATIC_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${STATIC_LIBRARY})
