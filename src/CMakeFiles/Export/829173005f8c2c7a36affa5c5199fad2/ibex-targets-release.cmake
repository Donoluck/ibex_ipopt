#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "Ibex::ultim" for configuration "Release"
set_property(TARGET Ibex::ultim APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Ibex::ultim PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ibex/3rd/libultim.a"
  )

list(APPEND _cmake_import_check_targets Ibex::ultim )
list(APPEND _cmake_import_check_files_for_Ibex::ultim "${_IMPORT_PREFIX}/lib/ibex/3rd/libultim.a" )

# Import target "Ibex::gdtoa" for configuration "Release"
set_property(TARGET Ibex::gdtoa APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Ibex::gdtoa PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ibex/3rd/libgdtoa.a"
  )

list(APPEND _cmake_import_check_targets Ibex::gdtoa )
list(APPEND _cmake_import_check_files_for_Ibex::gdtoa "${_IMPORT_PREFIX}/lib/ibex/3rd/libgdtoa.a" )

# Import target "Ibex::gaol" for configuration "Release"
set_property(TARGET Ibex::gaol APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Ibex::gaol PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "C;CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ibex/3rd/libgaol.a"
  )

list(APPEND _cmake_import_check_targets Ibex::gaol )
list(APPEND _cmake_import_check_files_for_Ibex::gaol "${_IMPORT_PREFIX}/lib/ibex/3rd/libgaol.a" )

# Import target "Ibex::soplex" for configuration "Release"
set_property(TARGET Ibex::soplex APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Ibex::soplex PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/ibex/3rd/libsoplex.a"
  )

list(APPEND _cmake_import_check_targets Ibex::soplex )
list(APPEND _cmake_import_check_files_for_Ibex::soplex "${_IMPORT_PREFIX}/lib/ibex/3rd/libsoplex.a" )

# Import target "Ibex::ibex" for configuration "Release"
set_property(TARGET Ibex::ibex APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(Ibex::ibex PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_RELEASE "CXX"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/lib/libibex.a"
  )

list(APPEND _cmake_import_check_targets Ibex::ibex )
list(APPEND _cmake_import_check_files_for_Ibex::ibex "${_IMPORT_PREFIX}/lib/libibex.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
