#----------------------------------------------------------------------
# Copyright (c) 2010-12, Pierre-Antoine Delsart, Kurtis Geerlings, Joey Huston,
#                 Brian Martin, and Christopher Vermilion
#
#----------------------------------------------------------------------
# This file is part of SpartyJet.
#
#  SpartyJet is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 3 of the License, or
#  (at your option) any later version.
#
#  SpartyJet is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with SpartyJet; if not, write to the Free Software
#  Foundation, Inc.:
#      59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
#----------------------------------------------------------------------

# set minimum required cmake version
cmake_minimum_required (VERSION 2.8)

# make sure we are not going to build in the main source directory
if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
   message (FATAL_ERROR "You should call cmake from inside the build directory as 'cmake ..'")
endif ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")

#-------------------------------------------------------------------------------
# global settings
#-------------------------------------------------------------------------------

# set project name and version
project (SpartyJet)
set (SpartyJet_VERSION_MAJOR 4)
set (SpartyJet_VERSION_MINOR 0)


set (BUILD_SHARED_LIBS TRUE)

# set the path where to put the generated libraries and executables
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/examples_C)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
# don't use configuration-specific subdirectories in Xcode
if (CMAKE_GENERATOR STREQUAL "Xcode")
   set (CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG ${PROJECT_SOURCE_DIR}/lib)
   set (CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE ${PROJECT_SOURCE_DIR}/lib)
endif (CMAKE_GENERATOR STREQUAL "Xcode")


# set data dir for code that needs to find it
# TODO: Should this go somewhere else?  Install dir??
set (SpartyJet_DATADIR \"${PROJECT_SOURCE_DIR}/data\")

# check for ansi compliance and turn on extra warnings
# add_definitions(-ansi -pedantic -Wall -Wextra -Wold-style-cast -Wconversion)
#add_definitions(-ansi -pedantic -Wall)

# force 32bit architecture
# add_definitions(-m32)
# set (CMAKE_EXE_LINKER_FLAGS -m32)

# System-specific flags
# Always use PIC objects
message (STATUS "Configuring for ${CMAKE_SYSTEM_NAME}")
if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
   set (CMAKE_CXX_FLAGS -fpic)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
   set (CMAKE_CXX_FLAGS -fPIC)
   set (SJ_LDFLAGS "-undefined dynamic_lookup")
   set (CMAKE_SHARED_LIBRARY_SUFFIX ".so") # ROOT demands .so, not .dylib
else (CMAKE_SYSTEM_NAME STREQUAL "Linux")
   message (STATUS "Building on this system (${CMAKE_SYSTEM_NAME}) is not tested!  Beware!")
endif (CMAKE_SYSTEM_NAME STREQUAL "Linux")


# ROOT linking and includes -- TODO: Put in a FindROOT.cmake
execute_process (COMMAND which root-config
   OUTPUT_VARIABLE root_CONFIG
)
if (root_CONFIG)
   execute_process (COMMAND root-config --prefix
      OUTPUT_VARIABLE ROOTSYS
   )
   if (ROOTSYS)
      string (STRIP ${ROOTSYS} ROOTSYS)
      execute_process (COMMAND root-config --incdir
         OUTPUT_VARIABLE ROOTINC
      )
      include_directories(${ROOTINC})
      execute_process(COMMAND root-config --libs
         OUTPUT_VARIABLE ROOTLIBS
      )
      execute_process(COMMAND root-config --glibs
         OUTPUT_VARIABLE ROOTGLIBS
      )
      execute_process(COMMAND root-config --ldflags
         OUTPUT_VARIABLE ROOTLDFLAGS
      )
      string (STRIP ${ROOTLIBS} ROOTLIBS)
      string (STRIP ${ROOTGLIBS} ROOTGLIBS)
      string (STRIP ${ROOTLDFLAGS} ROOTLDFLAGS)

      # extra ROOT libs, necessary on some systems?
      set (ROOTLIBS ${ROOTLIBS} -lTMVA -lMinuit -lMLP -lXMLIO -lTreePlayer)
      find_file (ROOTCINT rootcint PATHS ENV PATH NO_DEFAULT_PATH)
      if (ROOTCINT STREQUAL "ROOTCINT-NOTFOUND")
         message (FATAL_ERROR "rootcint not found.  Make sure ROOT is installed and \$(ROOTSYS)/bin is in your path!")
      else (ROOTCINT STREQUAL "ROOTCINT-NOTFOUND")
         message (STATUS "Found rootcint at ${ROOTCINT}")
      endif (ROOTCINT STREQUAL "ROOTCINT-NOTFOUND")
   else (ROOTSYS)
      message (FATAL_ERROR "ROOT not found.  Make sure ROOT is installed and \$(ROOTSYS)/bin is in your path!")
   endif (ROOTSYS)
endif (root_CONFIG)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/UserPlugins/FastPrune-0.4.2/include)

#-------------------------------------------------------------------------------
# Add each subdirectory
#-------------------------------------------------------------------------------

add_subdirectory(External)
include_directories(${fastjet_INCLUDE_DIRS})

foreach (dir JetCore IO FastJetTools JetTools EventShape SpartyDisplay ExternalTools UserPlugins)
   add_subdirectory(${dir})
endforeach(dir)

# Monolithic shared library; not sure if this is useful so commenting out for
# now
#add_library (SpartyCore ${JetCore_SOURCES} ${PROJECT_SOURCE_DIR}/JetCore/JetCoreDict.cpp 
#                        ${IO_SOURCES} ${PROJECT_SOURCE_DIR}/IO/IODict.cpp
#                        ${JetTools_SOURCES} ${PROJECT_SOURCE_DIR}/JetTools/JetToolsDict.cpp
#                        ${FastJetTools_SOURCES} ${PROJECT_SOURCE_DIR}/FastJetTools/FastJetToolsDict.cpp)
#target_link_libraries (SpartyCore ${SJ_LDFLAGS} ${ROOTLIBS} ${fastjet_LIBRARIES} ${EXTERNAL_LIBRARIES})
#
#add_dependencies (SpartyCore JetCore IO FastJetTools JetTools)

add_dependencies (IO External) # IO depends on stdhep

# executables
add_subdirectory(examples_C)

#-------------------------------------------------------------------------------
# Add custom targets for Python stuff for IDE visibility
#-------------------------------------------------------------------------------

file (GLOB py_SRCS examples_py/*.py bin/sparty bin/convertToROOT)
add_custom_target (PYScripts SOURCES ${py_SRCS})

file (GLOB_RECURSE py_CORE python/*.py)
add_custom_target (PYCore SOURCES ${py_CORE})


#-------------------------------------------------------------------------------
# configure config.h to pass CMake settings to the source code
#-------------------------------------------------------------------------------

configure_file (
  ${PROJECT_SOURCE_DIR}/SJconfig.h.in
  ${PROJECT_SOURCE_DIR}/SJconfig.h
)
