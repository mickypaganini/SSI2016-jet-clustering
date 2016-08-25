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

# TODO: Pythia8, Pythia6 options

# Create a variable containing a list of all source files
set (IO_SOURCES CalchepPartonTextInput.cc HepMCInput.cc HuskyInput.cc InputMaker_Ntuple.cc LheInput.cc MultiInput.cc StdTextInput.cc)

# optional sources
if (DO_STDHEP)
   set (IO_SOURCES ${IO_SOURCES} StdHepInput.cc)
endif (DO_STDHEP)


# Create header list for dictionary generation, absolute paths for sources as
# well
foreach (src ${IO_SOURCES})
   string (REPLACE ".cc" ".hh" hdr ${src})
   file (RELATIVE_PATH hdr ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/${hdr})
   set (IO_HEADERS ${IO_HEADERS} ${hdr})
   set (IO_SOURCES_ABS ${IO_SOURCES_ABS} ${CMAKE_CURRENT_SOURCE_DIR}/${src})
endforeach (src)

set (IO_SOURCES ${IO_SOURCES_ABS} PARENT_SCOPE)

# include headers and Makefile so they show up in Xcode/VS project
add_library (IO ${IO_SOURCES} IODict.cpp ${IO_HEADERS} FourVecInput.hh Makefile IOLinkDef.hpp)
target_link_libraries (IO ${SJ_LDFLAGS} ${EXTERNAL_LIBRARIES})


# Dictionary generation (ugh)
if (DO_STDHEP)
   set (CINTFLAGS -DDO_STDHEP)
endif (DO_STDHEP)
add_custom_command (OUTPUT IODict.cpp
   COMMAND ${ROOTCINT} -f IODict.cpp -c -p ${CINTFLAGS} -I${PROJECT_SOURCE_DIR} -I${ROOTSYS}/include -I${fastjet_INCLUDE_DIR} ${IO_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/IOLinkDef.hpp
   DEPENDS IOLinkDef.hpp ${IO_HEADERS}
   COMMENT "Generating dictionary for IO"
   VERBATIM
)
