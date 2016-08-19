# emacs, this is a -*- Makefile -*-
include ../../MakefileCommonOpt

# This Makefile builds a dictionary for a dummty FastJet plugin: ExamplePlugin
#   FastJet should already be built
#
# You can make your own dictionaries/libaries in the same way.  Note that these
#   are only needed if you want to use a plugin in a Python or ROOT script.
#
# The key steps are:
#  1) Create a ROOT dictionary, including all necessary classes.
#  2) Create a shared object that includes this dictionary as well as the
#       code for the plugin (these are extracted from FastJet's Example libs
#       below).
#  3) In your script, call "gSystem.Load('path-to-lib/libYourPluginName.so')"

NAME = ExamplePlugin

CSUFF = cc
HSUFF = hh

HEADERS = ExamplePlugin.hh
OBJS    = ExamplePlugin.o

DICT 		= $(NAME)Dict.o
## Dynamic (shared object) library
DYNLIB	= lib$(NAME).so
## Static library (not built by default)
LIB			= lib$(NAME).a

all : $(DYNLIB) # $(LIB)

$(DYNLIB):  $(OBJS) $(DICT)
	@echo "Building shared object library: $@"
	@$(LD) $(SOFLAGS) $(LDFLAGS) `ls *.o`  $(OutPutOpt) $@
	@echo "$@ done"

## This can be used to create a static library and 
## have SpartyJet automatically include it in libExternalTools.so
#$(LIB): $(OBJS)
#	@echo "Building static library: $@"
#	@ar cru $@ $(OBJS)
#	@ranlib $@
#	@cp $(HEADERS) ../include/fastjet
#	@cp $(LIB) ../lib
#	@echo "$@ done"

$(NAME)Dict.cpp: ExamplePlugin.hh $(NAME)LinkDef.hpp
	@echo "Generating dictionary $@...  $^"
	@rootcint -f $@ -c -p  $(INCLUDE) $^
	@echo "$@ done"

$(DICT):	$(NAME)Dict.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $@

%.o : %.$(CSUFF)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean: 
	rm -f *.o *Dict* $(DYNLIB) $(LIB)
	
