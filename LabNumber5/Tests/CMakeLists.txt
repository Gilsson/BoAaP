cmake_minimum_required(VERSION 3.23)
project(tests)

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
add_executable(Test tests.cpp)
target_link_libraries(Test gtest_main gtest)
add_test(NAME example_test COMMAND example)
add_test(NAME simple_test COMMAND Task2)
add_test(NAME modern_test COMMAND Task2)
add_test(NAME difficult_test COMMAND Task2)
