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
file (GLOB SpartyDisplay_SOURCES *.cc)
file (GLOB SpartyDisplay_HEADERS *.hh)


# include headers and Makefile so they show up in Xcode/VS project
add_library (SpartyDisplay ${SpartyDisplay_SOURCES} SpartyDisplayDict.cpp ${SpartyDisplay_HEADERS} Makefile SpartyDisplayLinkDef.hpp)
target_link_libraries (SpartyDisplay ${SJ_LDFLAGS})

# Dictionary generation (ugh)
add_custom_command (OUTPUT SpartyDisplayDict.cpp
   COMMAND ${ROOTCINT} -f SpartyDisplayDict.cpp -c -p -I${PROJECT_SOURCE_DIR} -I${fastjet_INCLUDE_DIR} ${SpartyDisplay_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/SpartyDisplayLinkDef.hpp
   DEPENDS SpartyDisplayLinkDef.hpp ${SpartyDisplay_HEADERS}
   COMMENT "Generating dictionary for SpartyDisplay"
   VERBATIM
)
