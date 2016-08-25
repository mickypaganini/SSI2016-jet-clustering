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

# Create a variable containing a list of all source files
file (GLOB_RECURSE ExternalTools_SOURCES *.cc)
file (GLOB_RECURSE ExternalTools_HEADERS *.hh)

list (REMOVE_ITEM ExternalTools_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/HEPTopTagger.hh)
list (REMOVE_ITEM ExternalTools_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/Dipolarity.hh)

# include headers and Makefile so they show up in Xcode/VS project
add_library (ExternalTools ${ExternalTools_SOURCES} ExternalToolsDict.cpp ${ExternalTools_HEADERS} Makefile ExternalToolsLinkDef.hpp)
target_link_libraries (ExternalTools ${SJ_LDFLAGS})

# Dictionary generation (ugh)
add_custom_command (OUTPUT ExternalToolsDict.cpp
   COMMAND ${ROOTCINT} -f ExternalToolsDict.cpp -c -p -I${PROJECT_SOURCE_DIR}
-I${PROJECT_SOURCE_DIR}/UserPlugins/FastPrune-0.4.2/include -I${ROOTSYS}/include -I${fastjet_INCLUDE_DIR} ${ExternalTools_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/ExternalToolsLinkDef.hpp
   DEPENDS ExternalToolsLinkDef.hpp ${ExternalTools_HEADERS}
   COMMENT "Generating dictionary for ExternalTools"
   VERBATIM
)
