# emacs, this is a -*- Makefile -*-
include ../MakefileCommonOpt

NAME = FastJetTools

CSUFF = cc
HSUFF = hh

LIBDIR  = ../lib
HEADERS = $(wildcard *.$(HSUFF))
SRCS    = $(wildcard *.$(CSUFF))
OBJS    = $(patsubst %.$(CSUFF),%.o,$(SRCS))
DYNLIB  = lib$(NAME).so

# this sets the path for the objects files :
vpath %.o $(LIBDIR)
vpath %.so $(LIBDIR)

all : $(LIBDIR) $(DYNLIB)

$(LIBDIR) :
	@mkdir $(LIBDIR)

$(DYNLIB): $(OBJS) $(NAME)Dict.o
	@echo "Building shared object library: ../libs/$@"
	$(LD) $(SOFLAGS) $(LDFLAGS) $(patsubst %,$(LIBDIR)/%,$^) $(ROOTLIBS)  $(OutPutOpt) $(LIBDIR)/$@ $(EXPLLINKLIBS)
	@echo "$@ done"

$(NAME)Dict.cpp: $(HEADERS) $(NAME)LinkDef.hpp
	@echo "Generating dictionary: $@"
	rootcint -f $@ -c -p $(INCLUDE) $^
	@echo "$@ done"

$(NAME)Dict.o: $(NAME)Dict.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $(LIBDIR)/$@

%.o : %.$(CSUFF)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $(LIBDIR)/$@

clean:
	rm -f *.o *Dict.*
	rm -f $(patsubst %, $(LIBDIR)/%, $(OBJS)) $(LIBDIR)/$(NAME)Dict.o $(LIBDIR)/$(DYNLIB)
