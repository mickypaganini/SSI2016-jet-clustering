#!/bin/bash
# invoke from spartyjet dir as :
# utils/package_spartyjet.sh XXX
# where XXX is the desired number version.

newdir=spartyjet_$1
dirlist="$newdir/data $newdir/doc $newdir/cmake $newdir/EventShape $newdir/JetTools $newdir/UserPlugins $newdir/JetCore $newdir/FastJetTools $newdir/examples_C $newdir/examples_py  $newdir/SpartyDisplay $newdir/python $newdir/External $newdir/ExternalTools $newdir/IO"
ln -s . $newdir

tar -czv --exclude=*.so --exclude=*.a --exclude=*.la --exclude=*Dict.?pp --exclude=*.o --exclude=*.lo --exclude=CVS --exclude=*svn* --exclude=.libs --exclude=.deps -f $newdir.tar.gz $dirlist $newdir/Make* $newdir/setup.*sh $newdir/README $newdir/COPYING $newdir/CMakeLists.txt $newdir/SJconfig.h.in

rm $newdir
