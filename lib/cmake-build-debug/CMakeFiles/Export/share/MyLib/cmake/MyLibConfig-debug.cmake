#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "mylib" for configuration "Debug"
set_property(TARGET mylib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(mylib PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/mylib.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/mylib.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS mylib )
list(APPEND _IMPORT_CHECK_FILES_FOR_mylib "${_IMPORT_PREFIX}/lib/mylib.lib" "${_IMPORT_PREFIX}/bin/mylib.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
