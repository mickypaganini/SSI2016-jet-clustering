include ../../MakefileCommonOpt

OBJ = ../../lib/wtag.o

all: $(OBJ)

$(OBJ): src/wtag.cc include/wtag.h
	$(CXX) $(CXXFLAGS) $(INCLUDE) -Iinclude -o $@ -c $<
