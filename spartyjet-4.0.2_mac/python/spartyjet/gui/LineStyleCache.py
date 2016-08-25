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

import ROOT
from ROOT import TAttLine

Black = ROOT.kBlack
White = ROOT.kWhite
Red = ROOT.kRed+2
Blue = ROOT.kBlue+2
Green = ROOT.kGreen+2
Gray = ROOT.kGray+2
Brown = ROOT.kOrange+3
Orange = ROOT.kOrange+7
Yellow = ROOT.kYellow
Magenta = ROOT.kMagenta
Cyan = ROOT.kCyan

# Should set up several variations on this -- just a list of TATTLine's to use
#  TODO: Add "B+W" set where each line has a different style as well
SolidColors = [TAttLine(color, 1, 2) for color in reversed([Red, Blue, Green, Orange, Black, Yellow, Magenta, Cyan])]

class LineStyleCache(object):
    def __init__(self, styles = SolidColors):
        self.clear(styles)
    
    def clear(self, styles = SolidColors):
        self.styleList = styles[:]
        self.styleDict = {}

    def set(self, line, name=''):
        ''' Set the line style for object line.
        
        line must inherit from TAttLine and TNamed.  Objects with the same name are
        assigned the same style, until clear() is called.  If the object's name has
        not been seen before, the next style in self.styleList is used.
        '''
        if name is '':
            name = line.GetName()
        if name not in self.styleDict:
            self.styleDict[name] = self.styleList.pop()
            if len(self.styleList) is 0:
                # start over if out of styles
                self.styleList = SolidColors[:]
        self.styleDict[name].Copy(line)
