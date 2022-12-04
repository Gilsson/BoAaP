cmake_minimum_required(VERSION 3.23)
project(LabNumber7)

set(CMAKE_CXX_STANDARD 14)

add_executable(1Task 1Task.cpp)
add_executable(2Task 2Task.cpp)
add_executable(3Task 3Task.cpp 3Task.h)
add_executable(4Task 4Task.cpp 4Task.h)
add_executable(5Task 5Task.cpp 5Task.h)
add_executable(6Task 6Task.cpp 6Task.h)
add_executable(7Task 7Task.cpp 7Task.h)
add_executable(8Task 8Task.cpp 8Task.h)
add_executable(9Task 9Task.cpp)
add_executable(main main.cpp)


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
add_executable(Test test.cpp)
target_link_libraries(Test gtest_main gtest)
