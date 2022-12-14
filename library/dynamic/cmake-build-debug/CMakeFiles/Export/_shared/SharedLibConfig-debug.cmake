#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "shared_lib" for configuration "Debug"
set_property(TARGET shared_lib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(shared_lib PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/shared_lib.lib"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/shared_lib.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS shared_lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_shared_lib "${_IMPORT_PREFIX}/lib/shared_lib.lib" "${_IMPORT_PREFIX}/bin/shared_lib.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
