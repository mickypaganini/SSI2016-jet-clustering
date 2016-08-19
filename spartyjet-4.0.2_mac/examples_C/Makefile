include ../MakefileCommonOpt

# Needed on some platforms
ROOTLIBS += -lMLP -lXMLIO -lTreePlayer

SJLIBS = $(wildcard ../lib/lib*.so)
FJLIBS = $(shell $(FASTJETDIR)/bin/fastjet-config --libs --plugins)

all : FJToolExample.exe FJExample.exe FourVecExample.exe

%.exe : %.cc
	@echo "Compiling: $@"
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c -o $(patsubst %.cc,%.o,$^) $^
	$(CXX) $(LDFLAGS) $(patsubst %.cc,%.o,$^) $(SJLIBS) $(ROOTLIBS) $(ROOTAUXLIBS) $(FJLIBS) -o $@ 

clean:
	rm -f *.o *.exe
