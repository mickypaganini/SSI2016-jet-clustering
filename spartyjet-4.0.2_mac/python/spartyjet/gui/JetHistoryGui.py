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
EventViewBase = ROOT.SpartyJet.EventViewBase

def vector_iterate(vec):
    for i in xrange(vec.size()):
        yield vec.at(i)

def jetview_iterate(vec):
    for i in xrange(vec.size()):
        yield vec.finalJet(i)

def isValid(pointer):
    return bool(pointer.__nonzero__())

class HistoryNavigator(object):
    def __init__(self, canvas , textbox):
        self.canvas = canvas
        self.textbox = textbox

    def setup(self , o ):
        if isinstance(o , ROOT.SpartyJet.JetHistoryView):
            jv = o
            history = jv.fullHistory()            
            self.history = history
            if history.size() == 0:
                history.push_back(jv)
            self.header = 'Jet History. Step %d /'+str(history.size()) +'. Jet Pt=%8.2f'%(o.jet().pt(),)
            print 'Setting up single jet navigation for ',jv, ' size =' ,history.size()
        elif isinstance(o, ROOT.SpartyJet.JetHistViewCollection):            
            self.history = o.historyNoConstituent()
            self.header = 'Event History. Step %d /'+str(history.size()) 
            print 'Setting up event navigation for ',o, ' size =' ,self.history.size()            
        self.pos = -1
        # copy the default attributes of markers
        # assuming they are all the same
        self.defaultMarker = ROOT.TAttMarker()
        #ROOT.TAttMarker.Copy(self.history[0] , self.defaultMarker) 

    def dump(self):
        f=lambda jv : jv.jet().pt()
        for jv in vector_iterate(self.history):
            print jv,'  p1,p2', isValid(jv.parent1()) , isValid(jv.parent2())
            print '  pt ',f(jv) , ' pt1', f(jv.parent1() ), ' pt2', f(jv.parent2() )
    def resetMarker(self):
        prev = self.history[self.pos]
        prev.setConstitutentAtt(self.defaultMarker)
        prev.SetMarkerSize(0)

    def prev(self):
        if self.pos < 1:
            return
        self.resetMarker()
        self.pos = self.pos-1

        prev = self.history[self.pos]
        self.updateStep(prev)
                    
        
    def next(self):
        # reset previous markers :
        if self.pos > -1:
            if self.pos >= self.history.size()-1:
                return
            self.resetMarker()
        self.pos = self.pos+1
        next = self.history[self.pos]
        self.updateStep(next)

    def goTo(self,pos):
        if self.pos == pos :
            return
        self.resetMarker()
        self.pos = pos 
        self.updateStep(next = self.history[pos])

    def first(self):
        self.goTo(0)

    def last(self):
        self.goTo(self.history.size()-1)

    def updateStep(self, next):
        textbox = self.textbox
        textbox.Clear()
        textbox.AddLineFast(self.header%(self.pos,))
        textbox.AddLineFast('')
        jet = next.jet()
        textbox.AddLineFast('new jet at  (%2.3f , %2.3f) pt=%8.2f'%(jet.eta() ,jet.phi() ,jet.pt() ))
        textbox.AddLineFast('constituents are :')
        #print ' next is ', next.GetX(), next.GetY(), 'p1 = ',next.parent1() , 'p2=', next.parent2()
        def drawparent(p,c):
            #p.setConstitutentSize(size*2)
            p.setConstitutentStyle(20)
            p.setConstitutentColor(c)
            jet = p.jet()
            nc = jet.getConstituentNum()
            if nc<1: nc=1
            textbox.AddLineFast('     (%2.3f , %2.3f) pt=%8.2f  num constit=%d'%(jet.eta() ,jet.phi() ,jet.pt(), nc))

        if isValid( next.parent1() ) :
            drawparent(next.parent1(), ROOT.kRed )
        else: # is a constituent
            self.next()
            pass
        # self.next()

        if isValid(next.parent2()) :
            drawparent(next.parent2(), ROOT.kBlue )

        textbox.Update()
        next.drawJet(ROOT.kBlack,2,3)
        self.canvas.Update()
        self.canvas.Modified()


HGUI_WIDTH= 1000
HGUI_HEIGHT= 700

class JetHistoryGui(ROOT.TGTransientFrame) :

    def __init__(self, p, main, jetcollitem):
        ROOT.TGTransientFrame.__init__(self,p,main,HGUI_WIDTH,HGUI_HEIGHT)
        #print 'LArGui : thread = ', thread.get_ident(), 'self= ',self
        self.currentEvent = 0
        self.jetcollitem = jetcollitem
        self.dispatchers = []

        print jetcollitem

        # test
        inputcoll = jetcollitem.inputcoll
        #for i in xrange(inputcoll.size()):
        #    print i,inputcoll.at(i).e()

        print '----- JetHistoryGui dump -------'
        jetcollitem.jetcoll.history_dump()
        print '----- JetHistoryGui build histview -------'
        self.collView = ROOT.SpartyJet.JetHistViewCollection(jetcollitem.jetcoll)
        self.selected_ind = None

        self.default_constit_size = 1.
        self.default_constit_style = 20
        self.default_constit_color = ROOT.kGray
        self.current_circle = ROOT.TArc(0,0,0.4)
        self.current_circle.SetFillStyle(0)        
        print '----- JetHistoryGui __init__ done -------'

    def init(self):

        kVerticalFrame, kHorizontalFrame = ROOT.kVerticalFrame,ROOT.kHorizontalFrame
        kLHintsLeft , kLHintsTop = ROOT.kLHintsLeft , ROOT.kLHintsTop
        kLHintsExpandX, kLHintsExpandY = ROOT.kLHintsExpandX, ROOT.kLHintsExpandY

        self.SetCleanup(ROOT.kDeepCleanup)
        v_layout =  ROOT.TGVerticalLayout( self)
        self.SetLayoutManager(v_layout)

        # Navigation buttons --------------------------------------------------------
        navig_group =  ROOT.TGGroupFrame(self,"History Navigation") #kHorizontalFrame,ROOT.TGGroupFrame.GetDefaultGC()(),ROOT.TGGroupFrame.GetDefaultFontStruct()
        navig_group.SetLayoutManager(ROOT.TGVerticalLayout( navig_group))
        self.AddFrame(navig_group,  ROOT.TGLayoutHints(kLHintsLeft |kLHintsTop | kLHintsExpandX ))

        # mode buttons
        mode_frame = ROOT.TGHorizontalFrame(navig_group)
        navig_group.AddFrame(mode_frame,  ROOT.TGLayoutHints(kLHintsLeft |kLHintsTop | kLHintsExpandX ))

        singlejet_checkB    = ROOT.TGCheckButton(mode_frame,'Single jet' )
        self.connect_dispatcher(singlejet_checkB, 'Clicked()', self.singleJetModeClicked )
        mode_frame.AddFrame(singlejet_checkB)
        self.singlejet_checkB = singlejet_checkB
        event_checkB      = ROOT.TGCheckButton(mode_frame,'Full event' ) 
        mode_frame.AddFrame(event_checkB)
        self.event_checkB = event_checkB
        self.connect_dispatcher(event_checkB, 'Clicked()', self.eventModeClicked )
                
        # Navigation button
        nav_frame = ROOT.TGHorizontalFrame(navig_group)
        navig_group.AddFrame(nav_frame,  ROOT.TGLayoutHints(kLHintsLeft |kLHintsTop | kLHintsExpandX ))
        def build_nav_button(file):
            b = ROOT.TGPictureButton(nav_frame, ROOT.gClient.GetPicture(file))
            nav_frame.AddFrame(b)
            b.SetEnabled(False)
            return b
        self.first_button = build_nav_button('first_t.xpm')
        self.prev_button = build_nav_button('previous_t.xpm')
        self.next_button = build_nav_button('next_t.xpm')
        self.last_button = build_nav_button('last_t.xpm')
        # Navigation buttons ------------------------------------------------
        # --------------------------------------------------------------------


        # Display zone --------------------------------------------------------
        # horizontal frame
        display_frame = ROOT.TGHorizontalFrame(self, ROOT.kFitWidth)
        self.AddFrame(display_frame,  ROOT.TGLayoutHints(kLHintsLeft |kLHintsTop | kLHintsExpandY | kLHintsExpandY ))
        
        # embedded canvas
        self.embCanvas =  ROOT.TRootEmbeddedCanvas("embCanvas",display_frame,700,500)
        display_frame.AddFrame(self.embCanvas,  ROOT.TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2))

        self.canvas = self.embCanvas.GetCanvas()
        
        #PreviousEventButton =  ROOT.TGTextButton(self,"Previous Event",991199)
        #display_frame.AddFrame(PreviousEventButton,  ROOT.TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2))

        fLayout =    ROOT.TGLayoutHints()
        jet_group =  ROOT.TGGroupFrame(display_frame,"Jet selection",kVerticalFrame)
        jet_group.SetMaxWidth(HGUI_WIDTH/3)
        jet_group.SetMinWidth(HGUI_WIDTH/3)
        
        self.jet_group = jet_group
        display_frame.AddFrame(jet_group,  ROOT.TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2))

        jet_group.AddFrame( ROOT.TGLabel(jet_group, "num cols"),fLayout)
        
        # list box ----------------------------------
        jetList =  ROOT.TGListBox(jet_group)
        self.jetList = jetList
        jcoll = self.jetcollitem.jetcoll
        jetList.AddEntry("rank   :     Pt    (eta, phi)    mass",0)
        jetList.AddEntry("--"*20,0)
        for i in xrange(jcoll.size()):
            jet= jcoll.at(i)
            jetList.AddEntry("% 3d   :   %9.1f  (%02.3f, %-2.3f)  %-8.2f"%(i,jet.pt(), jet.eta(), jet.phi(), jet.mass()),i)
            #print "% 3d   :   %9.1f  (%02.3f, %-2.3f)  %-8.2f"%(i,jet.pt(), jet.eta(), jet.phi(), jet.mass())
        jetList.Resize(158,364)
        jet_group.AddFrame(jetList,  ROOT.TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX | kLHintsExpandY,2,2,2,2))

        self.connect_dispatcher(jetList,"Selected(int)",self.jetSelected,int)

        self.infoText =  ROOT.TGTextEdit(jet_group,162,368)
        self.infoText.SetReadOnly( True)
        jet_group.AddFrame(self.infoText,  ROOT.TGLayoutHints(kLHintsExpandX | kLHintsExpandY))

        # Display zone --------------------------------------------------------
        #  --------------------------------------------------------

        self.connect_dispatcher(self,"CloseWindow()", self.close)

        self.MapSubwindows()
        self.Layout()
        self.MapWindow()


        self.canvas.cd(0)            
        self.frameH = ROOT.TH2F("histguiframe",self.jetcollitem.name,500,-5.2,5.2,500,-3.2,3.2);
        self.frameH.SetStats(False)
        self.frameH.SetXTitle('\eta')
        self.frameH.SetYTitle('\phi')
        
        self.genericMode()

        print ' initing HistoryNavigator'
        self.navigator = HistoryNavigator(self.canvas, self.infoText)
        print ' initing HistoryNavigator done'
        # connect navigation button
        self.connect_dispatcher(self.prev_button, 'Clicked()', self.navigator.prev )
        self.connect_dispatcher(self.next_button, 'Clicked()', self.navigator.next )
        self.connect_dispatcher(self.last_button, 'Clicked()', self.navigator.last )
        self.connect_dispatcher(self.first_button, 'Clicked()', self.navigator.first )

    def connect_dispatcher(self, element, signal, callback, argType=None):
        """ callback_class is expected to be inheriting SJCallBack"""

        disp = ROOT.TPyDispatcher( callback )
        self.dispatchers.append(disp)
        if argType == None:
            element.Connect(signal, "TPyDispatcher", disp, "Dispatch()")
        elif argType == int :
            element.Connect(signal, "TPyDispatcher", disp, "Dispatch(Long_t)")

    def genericMode(self):
        self.frameH.Draw('colz')
        self.collView.drawConstituents()
        for i in xrange(self.collView.finalSize()):
            jv = self.collView.finalJet(i)
            jv.drawConstituents( EventViewBase.color_code(i) , 20 , self.default_constit_size)
        self.canvas.Update()
        self.canvas.Modified()


    def jetSelected(self,i):
        if  self.singlejet_checkB.IsOn():
            # just change jet
            self.startJetNavigation()
            return
        elif  self.event_checkB.IsOn():
            return
        print 'Selected jet ',i
        self.canvas.cd(0)            
        if i != self.selected_ind:
            if self.selected_ind != None:
                self.collView.finalJet(self.selected_ind).SetMarkerSize(0)
            self.selected_ind = i
        jv = self.collView.finalJet(i)
        #jv.setConstitutentSize(self.default_constit_size * 4)
        color = EventViewBase.color_code(i)
        self.current_circle.SetX1( jv.GetX() )
        self.current_circle.SetY1( jv.GetY() )
        self.current_circle.SetLineColor( color )
        self.current_circle.Draw()
        jv.drawJet(color,2,3)
        self.canvas.Update()
        self.canvas.Modified()
        
    def close(self):
        del(self.embCanvas)

    def enableButtons(self, enable) :        
        for b in (self.first_button ,self.prev_button ,self.next_button ,self.last_button ):
            b.SetEnabled(enable)

            
    def eventModeClicked(self):
        if self.event_checkB.IsOn():
            self.singlejet_checkB.SetOn(False)
            self.startEventNavigation()
        else:
            self.genericMode()
        
    def singleJetModeClicked(self):
        if self.singlejet_checkB.IsOn():
            self.event_checkB.SetOn(False)
            self.startJetNavigation()
        else:
            self.genericMode()

    def startEventNavigation(self):
        self.canvas.Clear()
        self.frameH.Draw('colz')
        self.collView.drawConstituents()
        self.navigator.setup(self.collView)
        self.enableButtons(True)
        self.navigator.next()
        
    def startJetNavigation(self,):            
        i = self.jetList.GetSelected()
        if i<0: i=0
        jv = self.collView.finalJet(i)
        self.canvas.Clear()
        self.frameH.Draw('colz')
        self.collView.drawConstituents()
        self.navigator.setup(jv)
        self.enableButtons(True)
        self.navigator.next()
