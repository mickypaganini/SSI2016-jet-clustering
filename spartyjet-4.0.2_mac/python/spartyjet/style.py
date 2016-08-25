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

from ROOT import gROOT, TStyle

print "\nApplying SpartyJet style settings for ROOT...\n"


SpartyStyle = TStyle("SpartyJet","SpartyJet style")

# whitening
SpartyStyle.SetFrameBorderMode(0)
SpartyStyle.SetFrameFillColor(0)
SpartyStyle.SetCanvasBorderMode(0)
SpartyStyle.SetCanvasColor(0)
SpartyStyle.SetPadBorderMode(0)
SpartyStyle.SetPadColor(0)
SpartyStyle.SetStatColor(0)
SpartyStyle.SetGridColor(0)
# pad margins
SpartyStyle.SetPadTopMargin(0.05)
SpartyStyle.SetPadRightMargin(0.05)
SpartyStyle.SetPadBottomMargin(0.16)
SpartyStyle.SetPadLeftMargin(0.16)
SpartyStyle.SetTitleOffset(1.4, 'x')
SpartyStyle.SetTitleOffset(1.4, 'y')
# stat box
SpartyStyle.SetOptStat(0)
#SpartyStyle.SetOptStat(1110)
SpartyStyle.SetStatH(0.2)
SpartyStyle.SetStatW(0.2)
SpartyStyle.SetStatX(0.99)
SpartyStyle.SetTitleColor(1)
# title
SpartyStyle.SetTitleFillColor(0)
SpartyStyle.SetTitleY(0.99)
SpartyStyle.SetTitleX(.1)
# thick lines
SpartyStyle.SetHistLineWidth(2)
# font
font = 132 # regular Times New Roman (bold is 22)
SpartyStyle.SetTextFont(font)
SpartyStyle.SetStatFont(font)
SpartyStyle.SetLabelFont(font, 'xyz')
SpartyStyle.SetTitleFont(font, 'xyz')
SpartyStyle.SetTitleFont(font, 't')
# font size
size = 0.06
SpartyStyle.SetTextSize(size)
SpartyStyle.SetStatFontSize(size)
SpartyStyle.SetLabelSize(size, 'xyz')
SpartyStyle.SetTitleSize(size, 'xyz')
SpartyStyle.SetTitleSize(size, 't')
  
gROOT.SetStyle("SpartyJet")
gROOT.ForceStyle()
