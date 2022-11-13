cmake_minimum_required(VERSION 3.23)
project(shared VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

include(GenerateExportHeader)


set(SOURCE_FILES src/dynamicLibrary.cpp)

add_library(${PROJECT_NAME}_lib SHARED ${SOURCE_FILES})

set_target_properties(${PROJECT_NAME}_lib PROPERTIES VERSION ${PROJECT_VERSION})
set_target_properties(${PROJECT_NAME}_lib PROPERTIES PUBLIC_HEADER include/dynamicLibrary.h)
target_include_directories(${PROJECT_NAME}_lib PRIVATE include)
target_include_directories(${PROJECT_NAME}_lib PRIVATE src)
include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}_lib
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
configure_file(shared_lib.pc.in shared_lib.pc @ONLY)
generate_export_header(${PROJECT_NAME}_lib)
install(FILES ${CMAKE_BINARY_DIR}shared_lib.pc DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
#add_library(${PROJECT_NAME}_lib SHARED source/dynamicLibrary.cpp source/dynamicLibrary.h) # initialized below


#target_include_directories(${PROJECT_NAME}_lib PUBLIC ${PROJECT_SOURCE_DIR}/source ${PROJECT_BINARY_DIR})

#string(COMPARE EQUAL "${CMAKE_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}"
#        is_top_level)


#include(cmake/utils.cmake)
#include(GNUInstallDirs)

# MYLIB_SHARED_LIBS determines static/shared build when defined
#option(MYLIB_BUILD_TESTS "Build mylib tests" OFF)
#option(MYLIB_BUILD_EXAMPLES "Build mylib examples" OFF)
#option(MYLIB_INSTALL "Generate target for installing mylib" ${is_top_level})
#set_if_undefined(MYLIB_INSTALL_CMAKEDIR
#        "${CMAKE_INSTALL_LIBDIR}/cmake/mylib-${PROJECT_VERSION}" CACHE STRING
  #      "Install path for mylib package-related CMake files")

#if(DEFINED MYLIB_SHARED_LIBS)
#    set(BUILD_SHARED_LIBS ${MYLIB_SHARED_LIBS})
#endif()
