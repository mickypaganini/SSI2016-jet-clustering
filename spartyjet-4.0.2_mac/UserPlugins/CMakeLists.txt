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

# could get these more cleverly; not going to bother right now
set (PLUGINS ExamplePlugin)
file (GLOB_RECURSE UserPlugins_HEADERS *.hh)

#set (plugin_LIBS ${CMAKE_CURRENT_SOURCE_DIR}/[your-lib-dir]/lib/[your-lib].a
#)

# pass these to the outside world if needed
set (EXTERNAL_LIBRARIES ${plugin_LIBS} ${EXTERNAL_LIBRARIES} PARENT_SCOPE)

# custom targets to build plugins
foreach (plugin ${PLUGINS})
   set (PATH_STRING "PATH=/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:${ROOTSYS}/bin:${fastjet_PREFIX}/bin")
   set (SPARTYDIR "SPARTYJETDIR=${PROJECT_SOURCE_DIR}")
   add_custom_target (${plugin} make ${PATH_STRING} ${SPARTYDIR} # so make can find root-config, fastjet-config, SPARTYJETDIR in MakefileCommonOpt
      COMMAND echo "Building ${plugin}"
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${plugin}
   )
endforeach (plugin)

   

# include headers and Makefile so they show up in Xcode/VS project
add_library (UserPlugins UserPluginsDict.cpp ${UserPlugins_HEADERS} Makefile UserPluginsLinkDef.hpp)
target_link_libraries (UserPlugins ${SJ_LDFLAGS} ${plugin_LIBS})
add_dependencies (UserPlugins ${PLUGINS})

# Dictionary generation (ugh)
add_custom_command (OUTPUT UserPluginsDict.cpp
   COMMAND ${ROOTCINT} -f UserPluginsDict.cpp -c -p -I${PROJECT_SOURCE_DIR} -I${ROOTSYS}/include -I${fastjet_INCLUDE_DIR} ${UserPlugins_HEADERS} ${CMAKE_CURRENT_SOURCE_DIR}/UserPluginsLinkDef.hpp
   DEPENDS UserPluginsLinkDef.hpp ${UserPlugins_HEADERS}
   COMMENT "Generating dictionary for UserPlugins"
   VERBATIM
)
