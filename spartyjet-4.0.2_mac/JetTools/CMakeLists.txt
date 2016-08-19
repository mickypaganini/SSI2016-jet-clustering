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
file (GLOB JetTools_SOURCES *.cc)
file (GLOB JetTools_HEADERS *.hh)

set (JetTools_SOURCES ${JetTools_SOURCES} PARENT_SCOPE)


# include headers and Makefile so they show up in Xcode/VS project
add_library(JetTools ${JetTools_SOURCES} JetToolsDict.cpp ${JetTools_HEADERS} Makefile JetToolsLinkDef.hpp)
target_link_libraries(JetTools ${SJ_LDFLAGS})

# Dictionary generation (ugh)
add_custom_command(OUTPUT JetToolsDict.cpp
   COMMAND ${ROOTCINT} -f JetToolsDict.cpp -c -p -I${PROJECT_SOURCE_DIR} -I${ROOTSYS}/include -I${fastjet_INCLUDE_DIR} ${JetTools_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/JetToolsLinkDef.hpp
   DEPENDS JetToolsLinkDef.hpp ${JetTools_HEADERS}
   COMMENT "Generating dictionary for JetTools"
   VERBATIM
)
