cmake_minimum_required(VERSION 3.23)
project(2TaskNew)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

#list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake") # CMAKE_CURRENT_LIST_DIR is the directory holding the CMakeLists.txt we are currently using
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



#include(FindPkgConfig)
#find_package(shared_lib REQUIRED)
add_executable(${PROJECT_NAME} 2Task.cpp)
#target_link_libraries(${PROJECT_NAME} "F:\\Projects\\BoAaP\\LabNumber5\\Debug\\shared_lib.dll")
#add_executable(2Task 2Task.cpp)

