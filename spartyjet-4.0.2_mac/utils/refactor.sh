#!/bin/bash

files=`ls */*h`
files=$files"  "`ls */*cc`
files=$files"  "`ls */*cxx`
files=$files"  "`ls */*C`

echo $files
echo
echo $1 $2
for f in $files ; do
    sed -i s/$1/$2/g $f
done