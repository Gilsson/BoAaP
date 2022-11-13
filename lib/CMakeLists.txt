cmake_minimum_required(VERSION 3.23)
project(mylib VERSION 1.0.1 DESCRIPTION "mylib description")


set(CMAKE_CXX_STANDARD 14)


include(GNUInstallDirs)


add_library(lib STATIC library.cpp)

target_include_directories(lib
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>"
        )

install(TARGETS lib
        EXPORT libTargets
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
        )



install(FILES library.h DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})


install(EXPORT libTargets
        FILE libTargets.cmake
        NAMESPACE lib::
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/staticlib
        )