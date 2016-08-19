include ../MakefileCommonOpt

NAME   := IO
CSUFF  := cc
HSUFF  := hh
LIBDIR := ../lib

SRCS := $(wildcard *.$(CSUFF))
HEADERS :=

CINTFLAGS :=

ifdef DO_STDHEP
CINTFLAGS += -DDO_STDHEP
STDHEP_LIBS := $(addprefix ../External/STDHEP/lib/lib,stdhepC.a Fmcfio.a)
else
SRCS := $(filter-out StdHepInput.cc,$(SRCS))
endif

ifdef PYTHIA8DIR
PYTHIAHEADER = Pythia.h
INCLUDE += -I$(PYTHIA8DIR)/include -I$(PYTHIA8DIR)/include/pythia8 # former for in-place, latter for external installation
PYTHIALIBS =  -L$(PYTHIA8DIR)/lib -lEG -lEGPythia8 -lpythia8 -llhapdfdummy
CINTFLAGS += -DDO_PYTHIA
else
ifdef PYTHIA6DIR
CINTFLAGS += -DDO_PYTHIA
else
SRCS:= $(filter-out PythiaInput.cc,$(SRCS))
endif
endif

OBJS    := $(patsubst %.$(CSUFF),%.o,$(SRCS)) 
HEADERS += $(patsubst %.$(CSUFF),%.$(HSUFF),$(SRCS))
DYNLIB  := lib$(NAME).so

# this sets the path for the objects files :
vpath %.o $(LIBDIR)
vpath %.so $(LIBDIR)

all : $(DYNLIB)

$(DYNLIB): $(OBJS) $(NAME)Dict.o
	$(LD) $(SOFLAGS) $(LDFLAGS) $(patsubst %,$(LIBDIR)/%,$^) $(PYTHIALIBS) $(STDHEP_LIBS) $(ROOTLIBS) $(OutPutOpt) $(LIBDIR)/$@
	@echo "$@ done"

$(NAME)Dict.cpp:  $(HEADERS) $(NAME)LinkDef.hpp
	@echo "Generating dictionary $@...  $^"
	rootcint -f $@ -c -p $(INCLUDE) $(CINTFLAGS) $(PYTHIAHEADER) $^

$(NAME)Dict.o:	$(NAME)Dict.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $(LIBDIR)/$@

%.o : %.$(CSUFF) %.$(HSUFF) 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $(LIBDIR)/$@

clean: 
	rm -f *.o *.so	*Dict.*
	rm -f $(patsubst %, $(LIBDIR)/%, $(OBJS)) $(LIBDIR)/$(NAME)Dict.o $(LIBDIR)/$(DYNLIB)

