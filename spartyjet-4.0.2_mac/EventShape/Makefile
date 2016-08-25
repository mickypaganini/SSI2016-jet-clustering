include ../MakefileCommonOpt

CSUFF = cc
HSUFF = hh

LIBDIR = ../lib
SRCS = $(wildcard *.$(CSUFF))
OBJS = $(patsubst %.$(CSUFF),%.o,$(SRCS)) 
HEADERS = $(patsubst %.$(CSUFF),%.$(HSUFF),$(SRCS)) 
NAME	= EventShape
DYNLIB	= lib$(NAME).so

#OBJS  += $(NAME)Dict.o

# this sets the path for the objects files :
vpath %.o $(LIBDIR)
vpath %.so $(LIBDIR)

all : $(DYNLIB)


$(DYNLIB): $(OBJS) $(NAME)Dict.o
	$(LD) $(SOFLAGS) $(LDFLAGS) $(patsubst %,$(LIBDIR)/%,$^)  $(OutPutOpt) $(LIBDIR)/$@ $(EXPLLINKLIBS) 
	@echo "$@ done"


.SUFFIXES: .$(CSUFF)

$(NAME)Dict.cpp:  $(HEADERS) $(NAME)LinkDef.hpp
	@echo "Generating dictionary $@...  $^"
	@rootcint   -f $@ -c -p $(INCLUDE)  $^


$(NAME)Dict.o:	$(NAME)Dict.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $(LIBDIR)/$@


%.o : %.$(CSUFF) %.$(HSUFF) 
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $(LIBDIR)/$@


clean: 
	rm -f *.o *.so	*Dict.*
	rm -f $(patsubst %, $(LIBDIR)/%, $(OBJS)) $(LIBDIR)/$(NAME)Dict.o $(LIBDIR)/$(DYNLIB)
