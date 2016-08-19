# emacs, this is a -*- Makefile -*-

include ../MakefileCommonOpt

NAME := External

LIBDIR := ../lib
DYNLIB := lib$(NAME).so

# FastJet headers for dictionary generation
FJHEADERS_SAFE := $(FASTJETDIR)/include/fastjet/internal/BasicRandom.hh \
                 $(wildcard $(FASTJETDIR)/include/fastjet/*.hh) \
                 $(wildcard $(FASTJETDIR)/include/fastjet/tools/*.hh) \
                 $(wildcard $(FASTJETDIR)/include/fastjet/*Plugin.hh)
                 
FJHEADERS_UNSAFE := $(FASTJETDIR)/include/fastjet/PseudoJet.hh

FJHEADERS_DEPRECATED := $(FASTJETDIR)/include/fastjet/ActiveAreaSpec.hh \
                        $(FASTJETDIR)/include/fastjet/ClusterSequenceWithArea.hh \
                        $(FASTJETDIR)/include/fastjet/CircularRange.hh \
                        $(FASTJETDIR)/include/fastjet/RangeDefinition.hh

FJHEADERS_SAFE := $(filter-out $(FJHEADERS_DEPRECATED) $(FJHEADERS_UNSAFE),$(FJHEADERS_SAFE))


FJ_HEADERS_LOCAL := $(patsubst $(FASTJETDIR)/include/%,tmp_include/%,$(FJHEADERS_UNSAFE))


FASTJET_LIBS := $(shell $(FASTJETDIR)/bin/fastjet-config --libs --plugins)

STDHEP_LIBS := STDHEP/lib/libstdhepC.a STDHEP/lib/libFmcfio.a

# w-tag code
WTAG := wtag-1.00
WTAG_SRC := $(WTAG)/src/wtag.cc
OBJS += wtag.o
INCLUDE += -I$(WTAG)/include
LDFLAGS += $(shell root-config --libs) -lTMVA -lMinuit
export INCLUDE

# this sets the path for the objects files :
vpath %.o $(LIBDIR)
vpath %.so $(LIBDIR)

all : $(FASTJETDIR) $(STDHEP_LIBS) $(DYNLIB)
.PHONY: clean

$(DYNLIB): $(OBJS) $(NAME)Dict.o
	@echo "Building shared object library: ../lib/$@"
	$(LD) $(SOFLAGS) $(LDFLAGS) $(patsubst %,$(LIBDIR)/%,$^) $(FASTJET_LIBS) $(OutPutOpt) $(LIBDIR)/$@
	@echo "$@ done"

$(NAME)Dict.cpp: $(FASTJETDIR) $(FJ_HEADERS_LOCAL) FJWrapper.hh $(NAME)LinkDef.hpp
	@echo "Generating dictionary: $@"
	rootcint -f $@ -c -p $(CINTFLAGS) -I. $(INCLUDE) $(FJ_HEADERS_LOCAL) FJWrapper.hh $(FJHEADERS_SAFE) $(NAME)LinkDef.hpp
	@echo "$@ done"

$(NAME)Dict.o: $(NAME)Dict.cpp
	$(CXX) $(CXXFLAGS) -Itmp_include $(INCLUDE) -c $^ -o $(LIBDIR)/$@

# So far only PseudoJet.hh needs to be altered; this only works for that
$(FJ_HEADERS_LOCAL): tmp_include/%: $(FASTJETDIR)/include/%
	@mkdir -p tmp_include
	@mkdir -p tmp_include/fastjet
	$(SPARTYJETDIR)/utils/PseudoJet_sanitize.py $< $@

$(STDHEP_LIBS):
ifdef DO_STDHEP
	$(MAKE) -C STDHEP "F77=$(F77)"
endif

# w-tag code
wtag.o: $(FASTJETDIR) $(WTAG_SRC)
	cp Makefile-wtag $(WTAG)/Makefile
	$(MAKE) -e -C $(WTAG)

$(WTAG_SRC):
	tar xzf wtag-1.00.tar.gz

%.o : %.$(CSUFF)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $(LIBDIR)/$@

clean: $(PLUGINSC)
	@rm -f $(patsubst %,$(LIBDIR)/%,$(OBJS) $(NAME)Dict.o) *Dict.*
	@rm -f $(LIBDIR)/$(DYNLIB)
	@rm -rf tmp_include
	@rm -f tmp.hh
	$(MAKE) -C STDHEP clean

$(FASTJETDIR) :
	@echo FASTJET missing.  Please add fastjet/bin to PATH or type 'make fastjet'
	@ls $(FASTJETDIR)
