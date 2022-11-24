cmake_minimum_required(VERSION 3.23)
project(LabNumber5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#add_executable(2Task_lib 2Task.cpp)
#target_link_libraries(2Task_lib ${CMAKE_SOURCE_DIR}/cmake-build-debug/myDynamicLib.dll)

include_directories(1Task)
include_directories(2Task)
add_subdirectory(1Task)
add_subdirectory(2Task)
add_subdirectory(2TaskNew)
#add_executable(Main main.h)
add_executable(3Task 3Task/3Task.cpp 3Task/3Task.h)
add_executable(4Task 4Task/4Task.cpp 4Task/4Task.h)
add_executable(5Task 5Task/5Task.cpp 5Task/5Task.h)
add_executable(6Task 6Task/6Task.cpp)
add_executable(7Task 7Task/7Task.cpp)
add_executable(8Task 8Task/8Task.cpp)
#add_executable(main main2.cpp main.h)

add_subdirectory(Tests)
#include(FetchContent)
#FetchContent_Declare(
#        googletest
#        # Specify the commit you depend on and update it regularly.
#        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
#)
# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
#FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
#add_executable(Test Tests/tests.cpp)
#target_link_libraries(Test gtest_main)
#add_test(NAME example_test COMMAND example)
#add_test(NAME simple_test COMMAND Task2)
#add_test(NAME modern_test COMMAND Task2)
#add_test(NAME difficult_test COMMAND Task2)
