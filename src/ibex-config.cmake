# Get path of current directory
get_filename_component(_DIR "${CMAKE_CURRENT_LIST_FILE}" DIRECTORY)

# Load main config file
include(${_DIR}/ibex-targets.cmake)

# Set some variables that can be useful for plugins
set (IBEX_INTERVAL_LIB_NAME Gaol)
set (IBEX_INTERVAL_LIB_VERSION 4.2.0)
set (IBEX_LP_LIB_NAME SoPlex)
set (IBEX_LP_LIB_VERSION 4.0.2)

# Append to CMAKE_MODULE_PATH the directory containing some useful CMake scripts
# installed by Ibex. In particular, it contains the Find<package>.cmake files
# that are needed for dependencies of Ibex, if they were not install
# automatically.
list (APPEND CMAKE_MODULE_PATH "${_DIR}/cmake.utils")

# These files contain paths (like GAOL_DIR, FILIB_DIR, ..., if they exist) that
# are used as hints to where we found dependencies of Ibex. The paths can be
# overriden on CMake command-line with -D<NAME>_DIR=<path>.
file(GLOB _cfg_files "${_DIR}/ibex-path-hints-*.cmake")
foreach(_f ${_cfg_files})
  include(${_f})
endforeach()
unset (_cfg_files)
unset (_f)

# Set some var to respect QUIET et REQUIRED when looking for dependencies
if (${CMAKE_FIND_PACKAGE_NAME}_FIND_QUIETLY)
  set (_quiet_arg QUIET)
endif ()
if (${CMAKE_FIND_PACKAGE_NAME}_FIND_REQUIRED)
  set (_required_arg REQUIRED)
endif ()

#
get_target_property (_list_libs Ibex::ibex INTERFACE_LINK_LIBRARIES)
if (_list_libs)
  foreach (_lib ${_list_libs})
    if (NOT _lib MATCHES "^Ibex::")
      string (REGEX REPLACE "^.*::" "" _name ${_lib})
      string (TOUPPER "${_name}" _name_upper)
      find_package (${_name} ${_quiet_arg} ${_required_arg})
      if (NOT ${_name_upper}_FOUND)
        set(${CMAKE_FIND_PACKAGE_NAME}_NOT_FOUND_MESSAGE
                              "${CMAKE_FIND_PACKAGE_NAME} could not be found \
                              because dependency ${_name} could not be found.")
        set(${CMAKE_FIND_PACKAGE_NAME}_FOUND False)
      endif()
      unset (_name)
      unset (_name_upper)
    endif ()
  endforeach ()
  unset (_lib)
endif ()
unset (_list_libs)

unset (_quiet_arg)
unset (_required_arg)

# Include main utility script (useful for development of plugins)
include(ibex-dev-utils)

#
unset (_DIR)
