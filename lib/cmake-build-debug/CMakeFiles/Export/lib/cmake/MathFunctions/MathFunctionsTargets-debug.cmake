#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "MathFunctions::lib" for configuration "Debug"
set_property(TARGET MathFunctions::lib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(MathFunctions::lib PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/lib.lib"
  )

list(APPEND _IMPORT_CHECK_TARGETS MathFunctions::lib )
list(APPEND _IMPORT_CHECK_FILES_FOR_MathFunctions::lib "${_IMPORT_PREFIX}/lib/lib.lib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
