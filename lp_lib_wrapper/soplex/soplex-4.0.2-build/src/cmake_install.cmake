# Install script for directory: /home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ibex/3rd" TYPE FILE FILES "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex.h")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/ibex/3rd/soplex" TYPE FILE FILES
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/array.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/basevectors.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/classarray.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/clufactor.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/clufactor_rational.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/cring.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/dataarray.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/datahashtable.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/datakey.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/dataset.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/didxset.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/dsvectorbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/dsvector.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/dvectorbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/dvector.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/exceptions.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/gzstream.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/idlist.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/idxset.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/islist.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/lpcolbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/lpcol.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/lpcolsetbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/lpcolset.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/lprowbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/lprow.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/lprowsetbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/lprowset.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/mpsinput.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/nameset.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/notimer.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/random.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/rational.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/ratrecon.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/slinsolver.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/slinsolver_rational.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/slufactor.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/slufactor_rational.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/solbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/sol.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/sorter.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxalloc.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxautopr.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxbasis.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxboundflippingrt.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxdantzigpr.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxdefaultrt.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxdefines.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxdevexpr.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxequilisc.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxfastrt.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxfileio.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxgeometsc.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxgithash.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxharrisrt.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxhybridpr.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxid.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxleastsqsc.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxlpbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxlp.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxmainsm.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxout.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxparmultpr.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxpricer.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxratiotester.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxscaler.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxsimplifier.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxsolver.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxstarter.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxsteepexpr.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxsteeppr.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxsumst.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxvectorst.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxweightpr.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/spxweightst.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/ssvectorbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/ssvector.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/stablesum.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/statistics.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/svectorbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/svector.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/svsetbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/svset.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/timerfactory.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/timer.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/unitvectorbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/unitvector.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/updatevector.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/usertimer.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/validation.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/vectorbase.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/vector.h"
    "/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2/src/soplex/wallclocktimer.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "devtools" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/ibex/3rd" TYPE STATIC_LIBRARY FILES "/home/research/optimizeripopt/lib/libsoplex.a")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "devtools" OR NOT CMAKE_INSTALL_COMPONENT)
  include("/home/research/optimizeripopt/lp_lib_wrapper/soplex/soplex-4.0.2-build/src/CMakeFiles/soplex.dir/install-cxx-module-bmi-Release.cmake" OPTIONAL)
endif()

