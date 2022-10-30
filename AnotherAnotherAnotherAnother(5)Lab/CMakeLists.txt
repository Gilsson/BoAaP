cmake_minimum_required(VERSION 3.23)
project(AnotherAnotherAnotherAnother_5_Lab)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES 1Task.cpp testexample.cpp staticlib/library.cpp)

add_executable(AnotherAnotherAnotherAnother_5_Lab 1Task.cpp)
add_executable(AnotherAnotherAnotherAnother_5_Lab_0 testexample.cpp)
add_library(library ${SOURCE_FILES})

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
add_executable(example testexample.cpp)
target_link_libraries(example gtest_main)
add_test(NAME example_test COMMAND example)

target_link_libraries(AnotherAnotherAnotherAnother_5_Lab )