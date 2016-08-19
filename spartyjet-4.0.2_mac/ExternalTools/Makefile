include ../MakefileCommonOpt


CSUFF = cc
HSUFF = hh

LIBDIR  = ../lib
HEADERS = $(wildcard *.$(HSUFF) */*.$(HSUFF))
SRCS    = $(wildcard *.$(CSUFF) */*.$(CSUFF))
OBJS    = $(patsubst %.$(CSUFF),%.o,$(SRCS))
NAME    = ExternalTools
DYNLIB  = lib$(NAME).so

HEADERS := $(filter-out HEPTopTagger.hh Dipolarity.hh,$(HEADERS))

# this sets the path for the objects files :
vpath %.o $(LIBDIR)
vpath %.so $(LIBDIR)

all : $(DYNLIB)
.PHONY: clean


$(DYNLIB): $(OBJS) $(NAME)Dict.o
	@echo "Building shared object library: ../libs/$@"
	$(LD) $(SOFLAGS) $(LDFLAGS) $(patsubst %,$(LIBDIR)/%,$^)  $(OutPutOpt) $(LIBDIR)/$@
	@echo "$@ done"

$(NAME)Dict.cpp: $(HEADERS) $(NAME)LinkDef.hpp
	@echo "Generating dictionary: $@"
	rootcint -f $@ -c -p $(INCLUDE) $^
	@echo "$@ done"

$(NAME)Dict.o: $(NAME)Dict.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $(LIBDIR)/$@


%.o : %.$(CSUFF)
	@mkdir -p $(LIBDIR)/Qjets
	@mkdir -p $(LIBDIR)/Njettiness
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $(LIBDIR)/$@

clean:
	rm -f *.o *.so	*Dict.*
	rm -f $(patsubst %, $(LIBDIR)/%, $(OBJS)) $(LIBDIR)/$(NAME)Dict.o $(LIBDIR)/$(DYNLIB)
