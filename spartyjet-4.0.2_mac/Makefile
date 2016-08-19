include MakefileCommonOpt

DIRS = External IO JetCore FastJetTools JetTools ExternalTools EventShape SpartyDisplay UserPlugins examples_C
DIRSC = $(patsubst %, %C, $(DIRS))

.PHONY : $(DIRS) $(DIRSC) config

all :  config $(DIRS)
	@echo Done !

$(DIRS) : 
	@echo $@ 
	$(MAKE) -C $@

$(DIRSC) :
	@echo $@
	$(MAKE) -C $(patsubst %C,% ,$@) clean

fastjet:	
	@echo "Installing fastjet ($(version)) in $(FASTJETDIR)"
#	@cd External && curl http://www.lpthe.jussieu.fr/~salam/fastjet/repo/fastjet-$(version).tar.gz > fastjet-$(version).tar.gz && tar -xvzf fastjet-$(version).tar.gz
	@echo "Compiling fastjet:"
	@cd External/fastjet-$(version) && ./configure --enable-allcxxplugins --with-pic --prefix=$(FASTJETDIR) && make && make install
	@echo "Fastjet install complete"

clean : $(DIRSC)

distclean : clean
	@rm -f python/*.pyc
	@rm -f SpartyDisplay/*.pyc
	@rm -f data/output/*
	@rm -rf External/fastjet*/
	@rm -f External/fastjet*gz
	@rm -rf External/wtag-1.00/ 
	@rm -f SJconfig.h 

# hack of a config file implementation to fake CMake's config file
config:
	@rm -f SJconfig.h
	@echo "#define SPARTYJET_VERSION_MAJOR 4"      >> SJconfig.h
	@echo "#define SPARTYJET_VERSION_MINOR 0"      >> SJconfig.h
	@echo "#define SPARTYJET_DIR \"$(shell pwd)\"" >> SJconfig.h
ifneq (,$(DO_STDHEP))
	@echo "#define DO_STDHEP" >> SJconfig.h
endif
