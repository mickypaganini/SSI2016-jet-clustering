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

add_executable (FJExample FJExample.cc)
target_link_libraries (FJExample External JetCore IO FastJetTools JetTools UserPlugins) # could add others, don't need them

add_executable (FJToolExample FJToolExample.cc)
target_link_libraries (FJToolExample External JetCore IO FastJetTools JetTools ExternalTools UserPlugins) # could add others, don't need them

add_executable (FourVecExample FourVecExample.cc)
target_link_libraries (FourVecExample External JetCore IO FastJetTools JetTools UserPlugins)
