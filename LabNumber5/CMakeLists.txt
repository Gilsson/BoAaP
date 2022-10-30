cmake_minimum_required(VERSION 3.23)
project(LabNumber5)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES 1Task.cpp)

add_library(myLib STATIC library.cpp library.h)
add_executable(1Task 1Task.cpp)
add_executable(1Task_lib 1Task.cpp)

target_link_libraries(1Task_lib myLib)

add_executable(Tests testexample.cpp)
add_executable(2Task 2Task.cpp)
add_executable(3Task 3Task.cpp)
add_executable(4Task 4Task.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(Test testexample.cpp)
target_link_libraries(Test gtest_main)
add_test(NAME example_test COMMAND example)
add_test(NAME simple_test COMMAND Task2)
add_test(NAME modern_test COMMAND Task2_0)
add_test(NAME difficult_test COMMAND Task2_0)
