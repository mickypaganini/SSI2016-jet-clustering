# Setup script for spartyjet

#Check if ROOT is setup
type root-config &> /dev/null
if [ $? != "0" ]
then
	echo "Please set up ROOT, then re-source setup.sh."
	return
fi

# Pythia8 setup
if [[ `root-config --has-pythia8` == "yes" ]]
then
	if [[ -z "${PYTHIA8DIR:-}" ]]
	then
		echo "ROOT is pythia8-ready, but \$PYTHIA8DIR undefined. If using PYTHIA8, please define it and re-source setup.sh"
	else
		export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${PYTHIA8DIR}/lib
		export PYTHIA8DATA=${PYTHIA8DIR}/xmldoc
		if [[ `uname -s` == "Darwin" ]]
		then
			export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:${PYTHIA8DIR}/lib
		fi
	fi
else
	export PYTHIA8DIR=
fi

# Pythia6 setup
if [[ `root-config --has-pythia6` == "yes" ]]
then
	if [[ -z "${PYTHIA6DIR:-}" ]]
	then
		echo "ROOT is pythia6-ready, but \$PYTHIA6DIR undefined. If using PYTHIA6, please define it and re-source setup.sh"
	else
		export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${PYTHIA6DIR}
		if [[ `uname -s` == "Darwin" ]]
		then
			export DYLD_LIBRARY_PATH=$DYLD_LIBRARY_PATH:${PYTHIA6DIR}
		fi
	fi
else
	export PYTHIA6DIR=
fi

# Fortran Compiler
type ${F77:-} &> /dev/null
if [[ -z "${F77:-}" && $? == "0" ]]
then
	type gfortran &> /dev/null
	if [ $? == "0" ]
	then
		export F77=gfortran
	else
		type f77 &> /dev/null
		if [ $? == "0" ]
		then
			export F77=f77
		else
			type f77 &> /dev/null
			if [ $? == "0" ]
			then
				export F77=f77
			else
			  F77=
				echo "Could not find FORTRAN compiler => optional StdHep input will be disbaled.  To enable. put gfortran,f77 or g77 in \$PATH"
			fi
		fi
	fi
fi

# Check if fastjet should be installed
type fastjet-config &> /dev/null
if [ $? != "0" ]
then
	export PATH=${PATH}:`pwd`/External/fastjet-install/bin
	export DYLD_LIBRARY_PATH=`pwd`/External/fastjet-install/lib:${DYLD_LIBRARY_PATH}
fi

# Define SpartyJet directory, using existing value if possible
export SPARTYJETDIR=${SPARTYJETDIR:-`pwd`}
export PATH=${PATH}:${SPARTYJETDIR}/bin
export PYTHONPATH=$PYTHONPATH:$SPARTYJETDIR/SpartyDisplay:$SPARTYJETDIR/python
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$SPARTYJETDIR/libs	

# Print Environment
echo "######################################################"
echo "SpartyJet - v3.6"
echo ""
echo "SpartyJet: -------- "$SPARTYJETDIR
echo "ROOT:      -------- "`root-config --prefix`

type fastjet-config &> /dev/null
if [ $? != "0" ]
then
	echo "FastJet:   -------- Using internal fastjet If you have not already done so do: 'make fastjet' then compile spartyjet"
else
	echo "FastJet:   -------- "`fastjet-config --prefix`
fi

if [[ -z "${F77:-}" ]]
then
	echo "StdHep:    -------- disabled"
else
	echo "StdHep:    -------- enabled (using $F77)"
fi

if [[ -z "${PYTHIA6DIR:-}" ]]
then
	echo "Pythia6:   -------- disabled"
else
	echo "Pythia6:   -------- enabled (${PYTHIA6DIR})"
fi

if [[ -z "${PYTHIA8DIR:-}" ]]
then
	echo "Pythia8:   -------- disabled"
else
	echo "Pythia8:   -------- enabled (${PYTHIA8DIR})"
fi
echo "######################################################"

