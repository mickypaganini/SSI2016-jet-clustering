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

from spartyjet import SpartyJet as SJ, SPARTYJETDIR
import os.path

# Python < 2.7  don't include ordered dictionaries
try:
    # try built-in (2.7+)
    from collections import OrderedDict
except:
    # use drop-in from The Internet (see display/OrderedDict.py)
    from OrderedDict import OrderedDict

import ROOT

from JetRetrieverFile import PyJetRetrieverFile
from spartyjet.analyses import ListOfAnalyses
import JetRetrieverLive
import JetHistoryGui
from LineStyleCache import LineStyleCache

EventViewBase = ROOT.SpartyJet.EventViewBase

from ROOT import kVerticalFrame, kHorizontalFrame, kLHintsLeft, kLHintsTop, kLHintsExpandX, kLHintsExpandY
expandx_layout = ROOT.TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandX, 2, 2, 2, 2)


class JetCollItems(object):
    retriever = None
    button = None
    def __init__(self,name, r=None, b=None, title='' ):
        self.name = name
        self.retriever = r
        self.button  = b
        self.jetcoll = None
        self.inputcoll = None
        self.input_retriever = None
        if title:
          self.title = title
        else:
          self.title = name

    def add_input_retriever(self, ret):
        self.input_retriever = ret

    def __str__(self):
        return "JetCollection %s (jetcoll= %s, retriever=%s, input_retriever=%s) "%(self.name, self.jetcoll, self.retriever, self.input_retriever)

    def show(self):
        print 'JetCollection ',self.name
        print '              jetcoll   =',self.jetcoll
        print '              inputcoll =',self.inputcoll
        print '              retriever =',self.retriever
        print '              input_retriever =',self.input_retriever

class ViewerItem(object):
    def __init__(self, view=None, b=None):
        self.button  = b
        self.viewer = view
        # guess a name from the viewer class str (someting like <ROOT.SpartyJet::Event2DView object at 0x99515b8>)
        s = str(view)
        self.name = s[ s.find('::')+2 : s.find(' o')]


_dispatchers = []
def ConnectDispatcher(element, signal, callback, *args):
    """ Global helper function to wrap TPyDispatcher"""
    if isinstance(callback , SJCallBack):
        callback.element = element
    disp = ROOT.TPyDispatcher(callback)
    _dispatchers.append(disp)
    element.Connect(signal, "TPyDispatcher", disp, "Dispatch()")
        

class LiveAnalysisFrame(ROOT.TGGroupFrame):
    def __init__(self, parent_frame, gui, analysis_list):
        ROOT.TGGroupFrame.__init__(self, parent_frame, "On-the-fly algorithm setup")
        self.gui = gui
        self.analysis_list = analysis_list

        self.analysis_select = ROOT.TGComboBox(self, 'Analysis')
        for i,a in enumerate(self.analysis_list):
            self.analysis_select.AddEntry(a.__name__.replace('Analysis', ''), i)
        self.analysis_select.SetHeight(20)
        self.analysis_select.SetEditable(False)
        self.AddFrame(self.analysis_select, expandx_layout)
        ConnectDispatcher(self.analysis_select, "Selected(Int_t)", self.setup_params)
        
        self.param_group = ROOT.TGHorizontalFrame(self, 500, 60)
        self.AddFrame(self.param_group, expandx_layout)

        self.file_select = ROOT.TGComboBox(self, 'Input file')
        # combo box options are set of file names loaded
        for i,f in enumerate(self.gui.JetCollections.iterkeys()):
            self.file_select.AddEntry(f, i)
        self.file_select.SetHeight(20)
        self.file_select.SetEditable(False)
        self.AddFrame(self.file_select, expandx_layout)

        name_group = ROOT.TGHorizontalFrame(self)
        self.name_entry = ROOT.TGTextEntry(name_group)
        name_group.AddFrame(self.name_entry, expandx_layout)
        name_group.AddFrame(ROOT.TGLabel(name_group, "Unique label for analysis"), expandx_layout)
        self.AddFrame(name_group)
            
        self.create_button = ROOT.TGTextButton(self, "Create", 991199)
        self.AddFrame(self.create_button)
        ConnectDispatcher(self.create_button, "Clicked()", self.add_analysis)
        
    def add_analysis(self):
        ''' Set up the selected analysis and add a button for it.
        
        This function is too closely coupled to the GUI; need to bring some of
        this stuff inside this class.
        '''
        ialg = self.analysis_select.GetSelected()
        params = dict([ (entry.GetName(), float(entry.GetText())) for entry in self.param_entries ])
        analysis = self.analysis_list[ialg](**params)
        analysis.set_name(self.name_entry.GetText())
        print 'Created analysis',analysis.name(),'with params',params
        jretrieve = JetRetrieverLive.PyJetRetrieverLive(analysis)
        jbutton = self.gui.add_check_button(self, analysis.name() , 991199, SJCallBack())
        jcitem = JetCollItems(analysis.name(), jretrieve, jbutton)
        
        # get input retriever
        #  (only do this warning if we're actually doing an OTF analysis!)
        if (len(self.gui.JetCollections) != len(self.gui.inputJetItem)):
            print 'Warning: Input file selection for on-the-fly algorithms broken if not all files have identified inputs!'
        file_index = self.file_select.GetSelected()
        jcitem.inputcoll = self.gui.inputJetItem[file_index].inputcoll
        jcitem.jetcoll   = ROOT.SpartyJet.JetCollExtended()
        jcitem.add_input_retriever(self.gui.inputJetItem[file_index].retriever)
        self.gui.JetCollectionsLive[analysis.name()] = jcitem

        jbutton.MapWindow()
        self.gui.Layout()
    
    
    def setup_params(self):
        ''' Set up the parameter entry boxes for the selected analysis.'''
        ialg = self.analysis_select.GetSelected()
        analysis = self.analysis_list[ialg]
        print 'Setting up params for analysis',analysis.__name__
        
        self.name_entry.SetText(analysis.__name__)
        
        nParams = len(analysis.parameters())
        
        self.param_group.RemoveAll()
        #self.param_group.Resize(self.param_group.GetDefaultSize())
        #self.param_group.Layout()
        # BUG: Clean up somehow!!
        
        self.param_entries = []
        for param in analysis.parameters():
            entry = ROOT.TGTextEntry(self.param_group)
            entry.SetName(param.name)
            entry.SetText(str(param.value))
            entry.SetWidth(85)
            self.param_group.AddFrame(entry)
            self.param_entries.append(entry)
        # labels
        for param in analysis.parameters():
            label = ROOT.TGLabel(self.param_group, param.name+ " "*(18-len(param.name)))
            self.param_group.AddFrame(label)
            
        self.param_group.SetLayoutManager(ROOT.TGMatrixLayout(self.param_group, 0, nParams))
        self.gui.MapSubwindows()
        self.gui.Layout()
        self.gui.MapWindow()


class SpartyGui(ROOT.TGMainFrame) :

    def __init__(self, p, ):
        ROOT.TGMainFrame.__init__(self,p,1000,800)
        self.currentEvent = 0
        self.totalEvents = 0
        self.runPad = 1 # tracks which pad is active for run plots
        self.run_histos = []

        self.names = ["bla", 'blu','bli', 'ble', 'blo']
        self.lineStyles = LineStyleCache() # TODO: let user control this!
        self.optionToggles = {} # buttons for option toggling, e.g. optionToggles["Norm"].IsOn()

        self.runPlotRadioButtons = []
        self.algSelectCheckButtons = []
        self.jobSelectCheckButtons = []

        self.dispatchers = []

        self.JetCollections = OrderedDict() # dictionary of dictionaries; JC[fileName][jcName] is a JetCollection
        self.JetCollectionsLive = OrderedDict()

        self.viewer_items = []
        self.inputJetItem = []
        
        self.momentNames = set() # set of all available jet moments to plot

    def __del__(self):
        print "Deleting SpartyGui"
        self.Cleanup()

    def init(self):
        
        self.canvas =  ROOT.TCanvas("SpartyCanvas")
        p = self.canvas.cd()
        #self.drawer.set_pad(p)
        self.current_subpad = 0
        self.ndivX = 1
        self.ndivY = 1
        

        vert_layout =  ROOT.TGVerticalLayout(self)
        self.SetLayoutManager(vert_layout)

        self.fLayout = ROOT.TGLayoutHints()

        # First group for canvas manipulation ************************************************
        #canvas_group =  ROOT.TGGroupFrame(self,"canvas_group",kHorizontalFrame,ROOT.TGGroupFrame.GetDefaultGC()(),ROOT.TGGroupFrame.GetDefaultFontStruct())
        topcanvas_group =  ROOT.TGGroupFrame(self, "canvas_group", kHorizontalFrame, ROOT.TGGroupFrame.GetDefaultGC()(), ROOT.TGGroupFrame.GetDefaultFontStruct())
        canvas_group =  ROOT.TGCompositeFrame(self, kHorizontalFrame, ROOT.TGGroupFrame.GetDefaultGC()(), ROOT.TGGroupFrame.GetDefaultFontStruct())

        topcanvas_group.AddFrame(canvas_group, expandx_layout)

        topcanvas_group.AddFrame(ROOT.TGIcon(topcanvas_group, os.path.join(SPARTYJETDIR, "SpartyDisplay", "block-S.gif")), ROOT.TGLayoutHints(kLHintsLeft))
        self.AddFrame(topcanvas_group, expandx_layout)
        

        self.ndivx_entry = ROOT.TGNumberEntry(canvas_group, 1, 6, 991199, 0, 2)
        canvas_group.AddFrame(self.ndivx_entry, ROOT.TGLayoutHints(kLHintsLeft|kLHintsTop, 2, 2, 2,2))
        ConnectDispatcher(self.ndivx_entry, "ValueSet(Long_t)", self.clear_canvas)

        self.ndivy_entry = ROOT.TGNumberEntry(canvas_group, 1.0, 6, 991199, 0, 2)
        canvas_group.AddFrame(self.ndivy_entry, ROOT.TGLayoutHints(kLHintsLeft|kLHintsTop, 2, 2, 2, 2))
        ConnectDispatcher(self.ndivy_entry, "ValueSet(Long_t)", self.clear_canvas)

        canvas_group.AddFrame(ROOT.TGLabel(canvas_group, "num cols"), self.fLayout)
        canvas_group.AddFrame(ROOT.TGLabel(canvas_group, "num rows"), self.fLayout)


        c_reset_button = ROOT.TGTextButton(canvas_group,"Reset",991199)
        canvas_group.AddFrame(c_reset_button, ROOT.TGLayoutHints(kLHintsLeft|kLHintsTop, 2, 2, 2, 2))
        #c_reset_button.Connect("Clicked()","TGTextButton",self.canvas, "Clear()") 
        ConnectDispatcher(c_reset_button, "Clicked()", self.reset_canvas)

        c_clear_button = ROOT.TGTextButton(canvas_group, "Clear", 991199)
        canvas_group.AddFrame(c_clear_button, ROOT.TGLayoutHints(kLHintsLeft|kLHintsTop, 2, 2, 2, 2))
        #c_clear_button.Connect("Clicked()","TGTextButton",self.canvas, "Clear()") 
        ConnectDispatcher(c_clear_button, "Clicked()", self.clear_canvas)

        c_reset_line_styles_button = ROOT.TGTextButton(canvas_group, "Reset Line Styles", 991199)
        canvas_group.AddFrame(c_reset_line_styles_button, ROOT.TGLayoutHints(kLHintsLeft|kLHintsTop, 2, 2, 2, 2))
        ConnectDispatcher(c_reset_line_styles_button, "Clicked()", self.reset_line_styles)        

        canvas_group.SetLayoutManager(ROOT.TGMatrixLayout(canvas_group, 0, 2, 2, 0))

        # end canvas manipulation ************************************************





        # ###############/
        # Check buttons for algorithms
        # ###############/
        
        # Add a box for each file
        for filename in self.JetCollections.iterkeys():
          # box for this file
          jetcoll_frame =  ROOT.TGGroupFrame(self,"JetCollections from "+filename)
          
          # label for this file in legends
          '''
          label_frame = ROOT.TGHorizontalFrame(jetcoll_frame)
          jetcoll_frame.AddFrame(label_frame, expandx_layout)
          label = ROOT.TGTextEntry(label_frame, "bar")
          label.SetText("foo")
          label_frame.AddFrame(label, expandx_layout)
          label_frame.AddFrame(ROOT.TGLabel(label_frame, "Label for this file in legends"+175*" "))
          '''
          
          jetcoll_algs = ROOT.TGHorizontalFrame(jetcoll_frame)
          NColumn = 6
          jetcoll_algs.SetLayoutManager(ROOT.TGMatrixLayout(jetcoll_algs, 0, NColumn))
          jetcoll_frame.AddFrame(jetcoll_algs, expandx_layout)
          
          for name, jetitem in self.JetCollections[filename].iteritems():
            button = self.add_check_button(jetcoll_algs, jetitem.name, 991199, JetCollCheckButton())
            jetitem.button = button
          
          ncomplete = (NColumn - len(self.JetCollections[filename])%NColumn) % NColumn # complete to a multiple of NCollumn
          for a in range(ncomplete):
            # just fill with void frame
            jetcoll_algs.AddFrame(ROOT.TGFrame(jetcoll_algs),self.fLayout)

          self.AddFrame(jetcoll_frame, expandx_layout)
        # end jetcoll manipulation ************************************************



        # A horizontal frame 
        hframe =  ROOT.TGHorizontalFrame(self) 
        
        # define groups for event by event operations
        event_plots_group = ROOT.TGGroupFrame(hframe,"Event by Event plots")
        hframe.AddFrame(event_plots_group, ROOT.TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandY | kLHintsExpandX))

        # define groups for run operations
        run_plots_group = ROOT.TGGroupFrame(hframe,"Run plots")
        hframe.AddFrame(run_plots_group, ROOT.TGLayoutHints(kLHintsLeft | kLHintsTop | kLHintsExpandY | kLHintsExpandX))
        
        self.AddFrame(hframe, ROOT.TGLayoutHints(kLHintsLeft |kLHintsTop | kLHintsExpandX | kLHintsExpandY))
        
        # All event operations ********************************************************
        evbyev_frame =  ROOT.TGVerticalFrame(event_plots_group)
        evbyev_frame.SetLayoutManager( ROOT.TGMatrixLayout(evbyev_frame,0,3))
        event_plots_group.AddFrame(evbyev_frame, expandx_layout)


        self.PreviousEventButton =  ROOT.TGTextButton(evbyev_frame,"Previous Event",991199)
        #self.PreviousEventButton.Associate(self)
        evbyev_frame.AddFrame(self.PreviousEventButton,self.fLayout)



        self.EventNumEntry =  ROOT.TGNumberEntry(evbyev_frame,self.currentEvent,10,991199,
                                                    ROOT.TGNumberFormat.kNESInteger,
                                                    ROOT.TGNumberFormat.kNEANonNegative,
                                                    ROOT.TGNumberFormat.kNELLimitMinMax, 0, self.totalEvents-1)
        self.EventNumEntry.Associate(self)
        evbyev_frame.AddFrame(self.EventNumEntry,self.fLayout)


        self.NextEventButton =  ROOT.TGTextButton(evbyev_frame,"Next Event",991199)
        self.NextEventButton.Associate(self)
        evbyev_frame.AddFrame(self.NextEventButton,self.fLayout)


        ConnectDispatcher(self.EventNumEntry, "ValueSet(Long_t)", self.update_event_number)
        self.NextEventButton.Connect("Clicked()","TGNumberEntry", self.EventNumEntry, "IncreaseNumber()")
        self.PreviousEventButton.Connect("Clicked()","TGNumberEntry", self.EventNumEntry, "IncreaseNumber(=0,-1,false)")
        ConnectDispatcher(self.NextEventButton, "Clicked()", self.update_event_number)
        ConnectDispatcher(self.PreviousEventButton, "Clicked()", self.update_event_number)



        self.viewer_items = [
            ViewerItem(ROOT.SpartyJet.LegoView()),
            ViewerItem(ROOT.SpartyJet.Event2DView()),
            ViewerItem(ROOT.SpartyJet.SnowMassView()),
            ViewerItem(ROOT.SpartyJet.ParamSpace()),
            ViewerItem(ROOT.SpartyJet.PrintEvent()),
            ]
        for vit in self.viewer_items :
            vit.button = self.add_check_button(event_plots_group, vit.viewer.title() , 991199, SJCallBack())
            setattr(self, vit.name, vit.viewer) # this creates shortcuts to the viewer classes

        self.perform_evbyev_b =  ROOT.TGTextButton(event_plots_group, "Draw", 991199)
        ConnectDispatcher(self.perform_evbyev_b, "Clicked()", self.draw_current_event)
        event_plots_group.AddFrame(self.perform_evbyev_b, self.fLayout)

        # These buttons aren't being used!!
        #evbyev_options =  ROOT.TGTextButton(event_plots_group,"Options",991199)
        #evbyev_options.Associate(self)
        #event_plots_group.AddFrame(evbyev_options,self.fLayout)

        #history_button = ROOT.TGTextButton(event_plots_group,"View History",991199)
        #event_plots_group.AddFrame(history_button,self.fLayout)
        #ConnectDispatcher(history_button, "Clicked()", self.view_history)
        
        
        # on the fly algorithms ---------------------------------

        onthefly_group = LiveAnalysisFrame(event_plots_group, self, ListOfAnalyses)
        event_plots_group.AddFrame(onthefly_group, expandx_layout)
        
        # end event operations ********************************************************

        

        # full run operations ********************************************************

        run_vars_hframe = ROOT.TGHorizontalFrame(run_plots_group)
        # box for moments
        run_moments_hframe =  ROOT.TGGroupFrame(run_plots_group,"Jet moments found (not all analyses have all moments)",kHorizontalFrame,ROOT.TGGroupFrame.GetDefaultGC()(),ROOT.TGGroupFrame.GetDefaultFontStruct())
        NColumn = 5
        run_moments_hframe.SetLayoutManager(ROOT.TGMatrixLayout(run_moments_hframe, 0, NColumn))

        run_plots_group.AddFrame(ROOT.TGLabel(run_plots_group, "Choose a variable to be drawn:") , expandx_layout)
        run_plots_group.AddFrame(run_vars_hframe)
        run_plots_group.AddFrame(run_moments_hframe)
        
        self.run_vars_buttons = []
        self.run_defalt_vars = ['e','pt','eta','phi','mass']
        for vname in self.run_defalt_vars:
            self.run_vars_buttons += [self.add_check_button(run_vars_hframe, vname, 991199, SJCallBack())]

        self.run_moments_buttons = []
        for moment in sorted(self.momentNames):
            self.run_moments_buttons += [self.add_check_button(run_moments_hframe, moment, 991199, SJCallBack())]

        run_plots_group.AddFrame(ROOT.TGHorizontal3DLine(run_plots_group), expandx_layout)
        run_plots_group.AddFrame(ROOT.TGLabel(run_plots_group, "And/or provide the expression(s) to be draw below") , expandx_layout)
        run_plots_group.AddFrame(ROOT.TGLabel(run_plots_group, "(use $$ as a wildcard (ex: $$_pt) to be replaced by checked jets)") , expandx_layout)
        run_plots_group.AddFrame(ROOT.TGLabel(run_plots_group, "Separate multiple variables with '##'.") , expandx_layout)

        run_plots_group.AddFrame(ROOT.TGLabel(run_plots_group, "Expression: (Ex: $$_mass, $$_tau3/$$_tau2, etc.)") , expandx_layout)
        self.run_expr_text = ROOT.TGTextEntry(run_plots_group,"")
        run_plots_group.AddFrame(self.run_expr_text, expandx_layout)

        run_plots_group.AddFrame(ROOT.TGLabel(run_plots_group, "Cuts: (Ex: $$_pt > 100 && $$_pt < 200)") , expandx_layout)
        self.run_sel_text = ROOT.TGTextEntry(run_plots_group,"")
        run_plots_group.AddFrame(self.run_sel_text, expandx_layout)

        run_plots_group.AddFrame(ROOT.TGLabel(run_plots_group, "Legend entries for each curve: (Ex: ttbar##dijet)") , expandx_layout)
        self.run_label_text = ROOT.TGTextEntry(run_plots_group,"")
        run_plots_group.AddFrame(self.run_label_text, expandx_layout)


        run_options_hframe = ROOT.TGHorizontalFrame(run_plots_group)
        run_options_hframe.SetLayoutManager( ROOT.TGMatrixLayout(run_options_hframe,0,2))

        run_plots_drawbutton = ROOT.TGTextButton(run_options_hframe,"Draw",991199)
        run_options_hframe.AddFrame(run_plots_drawbutton,self.fLayout)
        ConnectDispatcher(run_plots_drawbutton, "Clicked()", self.draw_run_plots)        
        
        run_plots_resetbutton = ROOT.TGTextButton(run_options_hframe,"reset",991199)
        run_options_hframe.AddFrame(run_plots_resetbutton,self.fLayout)
        ConnectDispatcher(run_plots_resetbutton, "Clicked()", self.reset_run_plots)
        
        # Run plots options buttons: Normalize, Log Scale X, Log Scale Y, Show Title
        run_plots_opt_frame = ROOT.TGHorizontalFrame(run_plots_group)
        
        run_plots_norm_button = ROOT.TGCheckButton(run_plots_opt_frame, "Normalize", 991199)
        run_plots_opt_frame.AddFrame(run_plots_norm_button, self.fLayout)
        ConnectDispatcher(run_plots_norm_button, "Clicked()", SJCallBack())

        run_plots_logx_button = ROOT.TGCheckButton(run_plots_opt_frame, "LogX", 991199)
        run_plots_opt_frame.AddFrame(run_plots_logx_button, self.fLayout)
        ConnectDispatcher(run_plots_logx_button, "Clicked()", SJCallBack())

        run_plots_logy_button = ROOT.TGCheckButton(run_plots_opt_frame, "LogY", 991199)
        run_plots_opt_frame.AddFrame(run_plots_logy_button, self.fLayout)
        ConnectDispatcher(run_plots_logy_button, "Clicked()", SJCallBack())
 
        run_plots_logz_button = ROOT.TGCheckButton(run_plots_opt_frame, "LogZ", 991199)
        run_plots_opt_frame.AddFrame(run_plots_logz_button, self.fLayout)
        ConnectDispatcher(run_plots_logz_button, "Clicked()", SJCallBack())
 
        run_plots_title_button = ROOT.TGCheckButton(run_plots_opt_frame, "No Title", 991199)
        run_plots_title_button.SetState(ROOT.kButtonDown) # start checked by default
        run_plots_opt_frame.AddFrame(run_plots_title_button, self.fLayout)
        ConnectDispatcher(run_plots_title_button, "Clicked()", SJCallBack())

        run_plots_same_button = ROOT.TGCheckButton(run_plots_opt_frame, "Same Pad", 991199)
        run_plots_opt_frame.AddFrame(run_plots_same_button, self.fLayout)
        ConnectDispatcher(run_plots_same_button, "Clicked()", SJCallBack())
 
        self.optionToggles["Norm"] = run_plots_norm_button
        self.optionToggles["LogX"] = run_plots_logx_button
        self.optionToggles["LogY"] = run_plots_logy_button
        self.optionToggles["LogZ"] = run_plots_logz_button
        self.optionToggles["NoTitle"] = run_plots_title_button
        self.optionToggles["Same"] = run_plots_same_button

        # Add frames
        run_plots_group.AddFrame(run_options_hframe, expandx_layout)
        run_plots_group.AddFrame(run_plots_opt_frame, expandx_layout)


        # load_event(self.currentEvent)

        self.MapSubwindows()
        self.Layout()

        self.SetWindowName("SpartyJet Analysis Tool")
        self.SetIconName("SpartyJet Analysis Tool")

        self.MapWindow()

    def draw_current_event(self, *l):
        #print "draw_current_event",l
        evt = self.currentEvent
        active_jets = [ ji for ji in reduce(lambda x,y:x+y, [d.values() for d in self.JetCollections.values()])+self.JetCollectionsLive.values() if ji.button.IsOn() ]
        active_views = [ view for view in self.viewer_items if view.button.IsOn() ]
        self.clear_canvas()
        p = 1
        # only do this once for each viewer:
        for vi in active_views:
          vi.viewer.clear_graphic_objects()
        for ji in active_jets:
            #ji.show()
            for vi in active_views:
                ji.retriever.fill_collection(ji, evt)
                pad = self.canvas.cd(p)
                EventViewBase.setPad(pad)
                if (self.optionToggles['LogZ'].IsOn()): pad.SetLogz()
                vi.viewer.draw_jets(ji.jetcoll, ji.inputcoll, ji.name, ji.name )
                p = p+vi.viewer.num_pad_used()
        #for i,jitem in enumerate(self.JetCollections):
            
        pass

    def update_event_number(self, *l):
        """ Updates currentEvent (called by EventNumEntry, Prev/Next buttons)
            Draws current event if currentEvent changed """
        next = self.EventNumEntry.GetIntNumber()
        if next != self.currentEvent:
          self.currentEvent = next
          self.draw_current_event()

    def reset_canvas(self, *l):
        self.canvas.Clear()
        self.canvas.Update()
        self.ndivy_entry.SetIntNumber(1)
        self.ndivx_entry.SetIntNumber(1)
        self.run_histos = []
        self.runPad = 1

    def clear_canvas(self,*l):
        c1= self.canvas
        c1.Clear()
        nx , ny = self.ndivx_entry.GetIntNumber() ,self.ndivy_entry.GetIntNumber()
        c1.Divide(nx,ny)
        c1.cd(1)
        c1.Update()
        self.run_histos = []
        self.runPad = 1



  #  Helper function to correctly set-up and associate check-buttons
    def add_check_button(self, container_frame, button_name, id, callback):
        button = ROOT.TGCheckButton(container_frame, button_name, id)  
        container_frame.AddFrame(button, self.fLayout)
        ConnectDispatcher(button, "Clicked()", callback)
        return button


    def add_radio_button(self, container_frame, button_name, id):
        button = TGRadioButton(container_frame, button_name, id)  
        button.Associate(this)  
        container_frame.AddFrame(button, self.fLayout)
        self.runPlotRadioButtons.push_back(button)

        
    def add_text_button(self,container_frame, button_name, id, button_vect):
        button =  TGTextButton(container_frame, button_name, id)  
        button.Associate(this)  
        container_frame.AddFrame(button, self.fLayout)
        if button_vect: button_vect.push_back(button)
        return button


        
    def add_onthefly_algorithm(self):
        ialg = self.onthefly_combo.GetSelected()
        params = [ self.otf_txtentry[i].GetText() for i in range(3) ]
        analysis = ListOfAnalyses[ialg](R=float(params[0])) # TODO: implement other params, add way to set name
        jretrieve = JetRetrieverLive.PyJetRetrieverLive(analysis)
        jbutton = self.add_check_button(self.onthefly_group, analysis.name() , 991199, SJCallBack())
        jcitem = JetCollItems(analysis.name(), jretrieve, jbutton)
        jcitem.inputcoll = self.inputJetItem[0].inputcoll
        jcitem.jetcoll   = ROOT.SpartyJet.JetCollExtended()
        jcitem.add_input_retriever(self.inputJetItem[0].retriever)
        self.JetCollectionsLive[analysis.name()] = jcitem

        #self.onthefly_group.AddFrame(jbutton)
        jbutton.MapWindow()
        self.Layout()


    def view_history(self):
        evt = self.EventNumEntry.GetIntNumber()
        active_jets = [ ji for ji in self.JetCollectionsLive.values() if ji.button.IsOn() ]
        try :
            jetitem = active_jets[0]
        except:
            print "No live jets", active_jets 
            return
        print "History for jets", jetitem.name
        j = JetHistoryGui.JetHistoryGui(ROOT.gClient.GetRoot(), self, jetitem)
        j.init()
        self.historyV = j
        self.canvas.cd()
        pass

  
    def draw_ev_all_jobs():
        self.fill_selected_jobs();
        self.fill_selected_algs();
        npad = self.ndivY * self.ndivX
        count=0

    def reset_run_plots(self):
        self.run_expr_text.SetText("")
        self.run_sel_text.SetText("")
    
    def reset_line_styles(self):
        self.lineStyles.clear()

    def draw_run_plots(self):
        print 'draw_run_plots'
        active_jets = [ji for ji in reduce(lambda x,y:x+y, [d.values() for d in self.JetCollections.values()])+self.JetCollectionsLive.values() if ji.button.IsOn() ]
        
        # Find all variables to draw
        #  Multiple variables can be specified in field, separated by '#'
        vars = []
        # check for user-specified variable(s)
        varText = self.run_expr_text.GetText()
        if varText != "" :
            vars += [s.strip() for s in varText.split('##')]
        # add all checked variables, too
        for i in range(len(self.run_vars_buttons)):
            if self.run_vars_buttons[i].IsOn():
              vars.append("$$_"+self.run_defalt_vars[i])
        for b in self.run_moments_buttons:
            if b.IsOn():
              vars.append("$$_"+b.GetText().GetString())
        
        if vars is []:
            return
        
        cuts = ['']
        cutText = self.run_sel_text.GetText()
        if cutText is not "":
            cuts = [s.strip() for s in cutText.split('##')]
        
        # get legend labels:
        labels = [''] * len(cuts) * len(active_jets)
        labelText = self.run_label_text.GetText()
        if labelText is not "":
            labels = labelText.split('##') # don't strip, so you can add spaces
            if (len(labels) is not len(cuts) * len(active_jets)):
                print 'Wrong number of labels! (Should be # algorithms * # cuts=', len(active_jets), '*', len(cuts),  ')'
                return
        
        for var in vars:
            pad_histos = []
            self.canvas.cd(self.runPad)
            self.runPad += 1

            # if only one histogram is plotted, include stat box; else use legend
            if (len(cuts)*len(active_jets) <= 1):
                # only one hist: draw stat box
                ROOT.gStyle.SetOptStat(1110)
            else:
                ROOT.gStyle.SetOptStat(0)            

            # first, find min and max values (nec. so we can bin everything the same)
            xmin = 10.0e20
            xmax = 0.0
            for cut in cuts:
                for ji in active_jets:
                    expr = var.replace('$$', ji.name)
                    sel = cut.replace('$$', ji.name)
                    tree = ji.retriever.get_tree()
                    tree.Draw(expr, sel, ' goff')
                    h = tree.GetHistogram()
                    xmin = min(xmin, h.GetXaxis().GetXmin())
                    xmax = max(xmax, h.GetXaxis().GetXmax())
            for cut in cuts:
                for ji in active_jets:
                    expr = var.replace('$$', ji.name)
                    sel = cut.replace('$$', ji.name)
                    tree = ji.retriever.get_tree()
                    # draw once with no limits to get norm
                    tree.Draw(expr, '', ' goff')
                    h = tree.GetHistogram()
                    if (issubclass(type(h), ROOT.TH3)):
                        hNorm = h.Integral(0, h.GetNbinsX(), 0, h.GetNbinsY(), 0, h.GetNbinsZ())
                    elif (issubclass(type(h), ROOT.TH2)):
                        hNorm = h.Integral(0, h.GetNbinsX(), 0, h.GetNbinsY())
                    else:
                        hNorm = h.Integral(0, h.GetNbinsX())
                    # TODO: would be better to let user set binning
                    expr = expr+'>>htemp(75,'+str(xmin)+','+str(xmax)+')'
                    tree.Draw(expr, sel, ' goff')
                    h = tree.GetHistogram()
                    h.SetName(ji.title)
                    if self.optionToggles['NoTitle'].IsOn():
                        h.SetTitle('')
                    else:
                        h.SetTitle(var.replace('$$_','Jet ') )
                    # normalize
                    if self.optionToggles['Norm'].IsOn() and hNorm != 0:
                        h.Scale(1.0/hNorm)
                        h.SetYTitle('Fraction of jets')
                    else:
                        h.SetYTitle('Number of jets')              
                    h.SetXTitle(var.replace('$$_',''))
                    pad_histos.append(h)
            
            legH = 0.08 * len(pad_histos)
            leg = ROOT.TLegend(0.75 , 0.99 - legH, 0.99, 0.99)
            leg.SetFillColor(0)

            # set max for first histogram:
            if pad_histos:
              pad_histos[0].SetMaximum(1.1 * max([hist.GetMaximum() for hist in pad_histos]))

            # manipulate full names for legend clarity
            fullNames = [h.GetName() for h in pad_histos]
            # check if all file names are the same; then clip
            fileNames = [name[:name.find(':')].strip() for name in fullNames]
            analysisNames = [name[name.find(':')+1:].strip() for name in fullNames]
            if all([fileName == fileNames[0] for fileName in fileNames]):
                [h.SetName(name) for (h, name) in zip(pad_histos, analysisNames)]
            else:
                for (h, fileName, analysisName) in zip(pad_histos, fileNames, analysisNames):
                    # clip off directory part of file name
                    fileName = fileName[fileName.find('/')+1:].strip()
                    # only take to first hypen or underscore
                    if fileName.find('-') is not -1:
                        fileName = fileName[:fileName.find('-')]
                    if fileName.find('_') is not -1:
                        fileName = fileName[:fileName.find('_')]
                    h.SetName(fileName+': '+analysisName)

            opt = ''
            for h, label in zip(pad_histos, labels):
                 if label is '':
                     label = h.GetName()
                 self.lineStyles.set(h, label)
                 leg.AddEntry(h, label)
                 h.Draw(opt)
                 opt = 'same'

            if (len(pad_histos) > 1):
                leg.Draw()
                pad_histos.append(leg)

            # finally, do some manipulations according to options set
            if self.optionToggles['LogX'].IsOn():
                ROOT.gPad.SetLogx()
            else: ROOT.gPad.SetLogx(0)
            if self.optionToggles['LogY'].IsOn():
                ROOT.gPad.SetLogy()
            else: ROOT.gPad.SetLogy(0)

            self.canvas.Update()
            self.run_histos += pad_histos



    def setLiveAlgFinalCut(self,cut):
        JetRetrieverLive.PyJetRetrieverLive.setFinalCut(cut)

    def IsOptionsOpen():
        return self.OptionsOpen
  
    def SetOptionsOpen(b):
        self.OptionsOpen = x
      
    def viewersOption_use_rapidity(self, b):
        for v in self.viewer_items:
            v.viewer.option_use_rapidity = b
    def viewersOption_min_pt_display(self, pt):
        for v in self.viewer_items:
            v.viewer.option_min_pt_jet_display = pt


    def addTree(self, treename, filename, inputname="GUESS", alias="", filenameShort=""):
        '''Can call this multiple times to add more than one file'''
        ret = PyJetRetrieverFile()
        ret.set_tree_file(treename, filename, 5) # 5 = EtaPhiPtM_vector_float
        if inputname is 'GUESS':
            inputname = ret.guess_input()
            # allow input finding to fail -- some features will break!
            #if inputname is '':
            #    return
        ret.set_input_name(inputname)
        names = ret.find_algs(inputname, alias)
        self.totalEvents = ret.get_numevents()
        assert self.totalEvents > 0, str('Found no input events in tree '+str(treename)+' in file '+filename)
        
        # add to set of stored moment names
        for n in names:
            self.momentNames.update(ret.get_alg_moments(n))
        self.momentNames -= set(['e', 'pt', 'mass', 'eta', 'phi', 'N', 'numC', 'ind'])
        print "Found moments:", self.momentNames
        
        if filenameShort is "":
            from os.path import basename
            filenameShort = basename(filename)
            # take name up to first hyphen or underscore
            if '-' in filenameShort: filenameShort = filenameShort[:filenameShort.find('-')]
            if '_' in filenameShort: filenameShort = filenameShort[:filenameShort.find('_')]
        jetsItems = {}
        for n in names :
            title = filenameShort+': '+n
            ji = JetCollItems(n, ret, title=title)
            ji.jetcoll = ROOT.SpartyJet.JetCollExtended()
            jetsItems[n] = ji

        inputJetItem = JetCollItems(inputname, ret)
        inputJetItem.inputcoll = ROOT.SpartyJet.JetInputCollection()
        for ji in jetsItems.values():
            ji.inputcoll = inputJetItem.inputcoll
        self.JetCollections.update(dict({filename+':'+treename: jetsItems}))
        self.inputJetItem.append(inputJetItem)


class SJCallBack(object):
    def __init__(self, gui=None, element=None):
        self.gui = gui
        self.element = element

    def __call__(self, *l):
        if self.element.IsOn():
            #print self.element, 'on'
            pass
        else:
            #print self.element, 'off'
            pass


class JetCollCheckButton(SJCallBack):
    pass


