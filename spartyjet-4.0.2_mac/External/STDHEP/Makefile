#
# main StdHep makefile
#
# to build debug libraries: make DEBUG="-g" all
# to build shared libraries: make BUILD_SHARED="true" all
#
MAKE=make

ifdef DEBUG
  DMAKE = "DEBUG=$(DEBUG)"
endif

DMAKE += " F77=$(F77)"

STDHEP_DIR = .
#------------------------------------------

all: stdhep mcfio

stdhep:
	(cd src/stdhep; $(MAKE) $(DMAKE) all) > logstdhep 2>&1

mcfio:
	(cd mcfio/src; $(MAKE) $(DMAKE) all) > logmcfio 2>&1

clean:
	rm -f log*
	cd mcfio/src; $(MAKE) clean
	cd src/stdhep; $(MAKE) $(DMAKE) clean
	rm -f lib/*.o
	rm -f lib/*.so
	rm -f lib/*.a

realclean:
	rm -f log*
	cd mcfio/src; $(MAKE) realclean
	cd src/stdhep; $(MAKE) realclean
	rm -f lib/*.o
	rm -f lib/*.so
	rm -f lib/*.a

#------------------------------------------

.PHONY: all realclean stdhep spin util display mcfio
