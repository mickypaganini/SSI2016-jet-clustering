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

# where to find cmake Modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake/Modules/)

#-------------------------------------------------------------------------------
# Configure FastJet
#-------------------------------------------------------------------------------

set (fastjet_LOCAL ${CMAKE_CURRENT_SOURCE_DIR}/fastjet-install)

# add local installation in external to search path
set (fastjet_USER_LIB_PATH ${fastjet_USER_LIB_PATH} ${fastjet_LOCAL}/lib)
set (fastjet_USER_INCLUDE_PATH ${fastjet_USER_INCLUDE_PATH} ${fastjet_LOCAL}/include)

find_package (fastjet)
if (FASTJET_FOUND)
   # add FastJet requirements to external requirements
   set (fastjet_LIBRARIES ${fastjet_LIBRARIES} PARENT_SCOPE)
   set (fastjet_PREFIX ${fastjet_PREFIX} PARENT_SCOPE)
   set (LIBRARIES ${LIBRARIES} ${fastjet_LIBRARIES})
   set (fastjet_INCLUDE_DIRS ${fastjet_INCLUDE_DIRS} PARENT_SCOPE)
   set (INCLUDE_DIRS ${INCLUDE_DIRS} ${fastjet_INCLUDE_DIRS})
else (FASTJET_FOUND)
   message (STATUS "No external FastJet found.  Run \"make fastjet\" to build and install the built-in version!")
endif (FASTJET_FOUND)

#------------ Commands to build FastJet as external project --------------------

set (URL http://fastjet.fr/repo/fastjet-3.0.0.tar.gz)
set (MD5 a8fc1cb61eb2f8f17f3fdf44f57c65df) 
# note the directory -- this is the default place CMake puts the FJ source (see ExternalProject docs)
set (CONFCMD ${CMAKE_CURRENT_BINARY_DIR}/fastjet-prefix/src/fastjet/configure --prefix=${fastjet_LOCAL} --enable-allcxxplugins --with-pic)

# this defines a target fastjet which does everything to build FastJet
include (ExternalProject)
ExternalProject_Add (fastjet
   URL ${URL}
   URL_MD5 ${MD5}
   CONFIGURE_COMMAND ${CONFCMD}
   BUILD_COMMAND make
   INSTALL_COMMAND make install
)
set_target_properties (fastjet PROPERTIES EXCLUDE_FROM_ALL TRUE)

include_directories(${fastjet_INCLUDE_DIRS})

#-------------------  FASTJET --------------------------------------------------


#-------------------------------------------------------------------------------
# Configure StdHEP
#-------------------------------------------------------------------------------

option (DO_STDHEP "Build the StdHEP library to read .hep files.  Requires Fortran." ON)

if (DO_STDHEP)
   enable_language (Fortran)
   set (stdhep_LOCAL ${CMAKE_CURRENT_SOURCE_DIR}/STDHEP)
   set (STDHEP_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/STDHEP/lib/libstdhepC.a ${CMAKE_CURRENT_SOURCE_DIR}/STDHEP/lib/libFmcfio.a)
   set (LIBRARIES ${LIBRARIES} ${STDHEP_LIBS})

   # command to build STDHEP if needed
   add_custom_command (OUTPUT ${STDHEP_LIBS}
      COMMAND make F77=${CMAKE_Fortran_COMPILER}
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/STDHEP
   )
endif (DO_STDHEP)


#-------------------  STDHEP ---------------------------------------------------


#-------------------------------------------------------------------------------
# Configure wtag
#-------------------------------------------------------------------------------

set (wtag_LOCAL ${CMAKE_CURRENT_SOURCE_DIR}/wtag-1.00)
set (wtag_SRC ${wtag_LOCAL}/src/wtag.cc)
include_directories(${wtag_LOCAL}/include)
add_custom_command (OUTPUT ${wtag_SRC}
   COMMAND tar xzf wtag-1.00.tar.gz
   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
   VERBATIM
)
#-------------------  wtag -----------------------------------------------------

# include headers and Makefile so they show up in Xcode/VS project
set (SRCS ExternalDict.cpp ${wtag_SRC} ${External_HEADERS} Makefile ExternalLinkDef.hpp FJWrapper.hh)
if (DO_STDHEP)
   set (SRCS ${SRCS} ${STDHEP_LIBS})
endif (DO_STDHEP)
add_library (External ${SRCS})
target_link_libraries(External ${SJ_LDFLAGS} ${ROOTLDFLAGS} ${ROOTLIBS} ${LIBRARIES})


# Dictionary generation (ugh)
file (GLOB fastjet_CORE_HEADERS RELATIVE ${fastjet_INCLUDE_DIR} ${fastjet_INCLUDE_DIR}/fastjet/*.hh)
file (GLOB fastjet_PLUGIN_HEADERS RELATIVE ${fastjet_INCLUDE_DIR} ${fastjet_INCLUDE_DIR}/fastjet/*Plugin.hh)
file (GLOB fastjet_TOOL_HEADERS RELATIVE ${fastjet_INCLUDE_DIR} ${fastjet_INCLUDE_DIR}/fastjet/tools/*.hh)

# remove deprecated core headers as well as PseudoJet.hh which we need to alter
list (REMOVE_ITEM fastjet_CORE_HEADERS fastjet/ActiveAreaSpec.hh)
list (REMOVE_ITEM fastjet_CORE_HEADERS fastjet/CircularRange.hh)
list (REMOVE_ITEM fastjet_CORE_HEADERS fastjet/ClusterSequenceWithArea.hh)
list (REMOVE_ITEM fastjet_CORE_HEADERS fastjet/RangeDefinition.hh)
list (REMOVE_ITEM fastjet_CORE_HEADERS fastjet/PseudoJet.hh)

set (fastjet_HEADERS ${fastjet_CORE_HEADERS} fastjet/internal/BasicRandom.hh ${fastjet_PLUGIN_HEADERS} ${fastjet_TOOL_HEADERS})
set (fastjet_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/FJWrapper.hh ${fastjet_HEADERS})

# sanitize PseudoJet.hh for CINT
add_custom_command (OUTPUT fastjet/PseudoJet.hh
   COMMAND mkdir -p fastjet
   COMMAND ${PROJECT_SOURCE_DIR}/utils/PseudoJet_sanitize.py ${fastjet_INCLUDE_DIR}/fastjet/PseudoJet.hh fastjet/PseudoJet.hh
   VERBATIM
)

add_custom_command (OUTPUT ExternalDict.cpp
   COMMAND ${ROOTCINT} -f ExternalDict.cpp -c -p ${CINTFLAGS} -I${ROOTSYS}/include -I${CMAKE_CURRENT_BINARY_DIR} -I${CMAKE_CURRENT_SOURCE_DIR} -I${PROJECT_SOURCE_DIR} -I${fastjet_INCLUDE_DIR} fastjet/PseudoJet.hh ${fastjet_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/ExternalLinkDef.hpp
   DEPENDS ExternalLinkDef.hpp fastjet/PseudoJet.hh ${CMAKE_CURRENT_SOURCE_DIR}/FJWrapper.hh
   COMMENT "Generating dictionary for External"
   VERBATIM
)

include_directories (BEFORE ${CMAKE_CURRENT_BINARY_DIR}) 

# export libraries, FastJet define
set (EXTERNAL_LIBRARIES ${LIBRARIES} PARENT_SCOPE)
