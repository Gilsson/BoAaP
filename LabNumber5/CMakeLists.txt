cmake_minimum_required(VERSION 3.23)
project(LabNumber5)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)

set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
include(GenerateExportHeader)

add_library(myLib STATIC library.cpp library.h)
add_library(myDynamicLib SHARED dynamicLibrary.cpp dynamicLibrary.h)
generate_export_header(myDynamicLib)
add_executable(1Task_lib 1Task.cpp library.cpp library.h)

target_link_libraries(1Task_lib myLib)

set_target_properties(myDynamicLib PROPERTIES SOVERSION 1)


add_executable(2Task_lib 2Task.cpp)
target_link_libraries(2Task_lib PRIVATE myDynamicLib)

add_executable(3Task 3Task.cpp)
add_executable(4Task 4Task.cpp)
add_executable(5Task 5Task.cpp)
add_executable(6Task 6Task.cpp)
add_executable(7Task 7Task.cpp)
add_executable(8Task 8Task.cpp)

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
add_test(NAME modern_test COMMAND Task2)
add_test(NAME difficult_test COMMAND Task2)
