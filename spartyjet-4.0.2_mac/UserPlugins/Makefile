# emacs, this is a -*- Makefile -*-

# To install your own FastJet plugins, tools, etc.:
#  1a) Put in a directory under UserPlugins/ (see examples).
#  1b) Put somewhere else, and add top-level directory to $(PLUGINS) below.
#  2) Include any classes you want to use in scripts in ExternalToolsLinkDef.hpp.
#  3) Run 'make' here!
#
#  If your plugin builds a *.a static library, it will be included in
#   libUserPlugins.so and you don't need to do anything else to use it.  If it
#   builds a *.so shared library, you will need to load this library in your
#   scripts (see, e.g., python/spartyjet/__init__.py for how to do this).
#
# This Makefile looks for headers and libraries in standard directories:
#   DIR/ DIR/include DIR/include/fastjet  --  for headers
#   DIR/ DIR/lib                          --  for libraries
# If your plugin has files in other locations, amend $(PLUGININCDIRS) and/or
#  $(PLUGINLIBS) below.

include ../MakefileCommonOpt

NAME = UserPlugins

#********* Setup for UserPlugins ***********************************

PLUGINS := $(shell ls -p | grep /)
PLUGINS := $(subst /,,$(PLUGINS))
PLUGINS := $(filter-out tmplib,$(PLUGINS))
PLUGINSC := $(patsubst %, %C, $(PLUGINS))

# headers might be in DIR, DIR/include, DIR/include/fastjet
# anything else must be added by hand
PLUGIN_INCDIRS := $(patsubst %,%/include,$(PLUGINS))
PLUGIN_INCDIRS += $(patsubst %,%/include/fastjet,$(PLUGINS))

PLUGIN_HEADERS := $(foreach dir,$(PLUGINS) $(PLUGIN_INCDIRS),\
                      $(wildcard $(dir)/*.h $(dir)/*.hh))
# ignore dictionary headers
PLUGIN_HEADERS := $(filter-out %Dict.h,$(PLUGIN_HEADERS))
PLUGIN_LIBS = $(foreach dir,$(PLUGINS),$(wildcard $(dir)/*.a $(dir)/lib/*.a))

INCLUDE += $(patsubst %,-I%,$(PLUGINS) $(PLUGIN_INCDIRS))

.PHONY : clean $(PLUGINS) $(PLUGINSC)


#********************************************************************

LIBDIR  = ../lib
DYNLIB  = lib$(NAME).so

# this sets the path for the objects files :
vpath %.o $(LIBDIR)
vpath %.so $(LIBDIR)

all : $(DYNLIB)

$(DYNLIB): $(OBJS) $(PLUGINS) $(NAME)Dict.o
	@echo "Building shared object library: ../libs/$@"
	@echo "Plugin libs: ${PLUGIN_LIBS}"
	@mkdir -p tmplib
	cd tmplib && for f in $(addprefix ../,$(PLUGIN_LIBS)); do ar x $$f; done
	$(LD) $(SOFLAGS) $(LDFLAGS) `ls tmplib/*.o` $(LIBDIR)/$(NAME)Dict.o  $(OutPutOpt) $(LIBDIR)/$@
	@rm -rf tmplib
	@echo "$@ done"

$(PLUGINS) :
	@echo "Building $@"
	@$(MAKE) -C $@

$(PLUGINSC) :
	@echo $@
	@$(MAKE) -C $(patsubst %C,% ,$@) clean


$(NAME)Dict.cpp: $(HEADERS) $(PLUGIN_HEADERS) $(NAME)LinkDef.hpp
	@echo "Generating dictionary: $@"
	rootcint -f $@ -c -p $(INCLUDE) $^
	@echo "$@ done"

$(NAME)Dict.o: $(NAME)Dict.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $^ -o $(LIBDIR)/$@

%.o : %.$(CSUFF)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $(LIBDIR)/$@

clean: $(PLUGINSC)
	rm -f $(LIBDIR)/$(NAME)Dict.o *Dict.*
	rm -f $(LIBDIR)/$(DYNLIB)
