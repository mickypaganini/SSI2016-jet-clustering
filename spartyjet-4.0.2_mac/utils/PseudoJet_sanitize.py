#!/usr/bin/env python

from sys import argv

infile = open(argv[1])
outfile = open(argv[2], 'w')

lines = infile.readlines()

i = -1
for lineno, line in enumerate(lines):
  if 'SharedPtr<UserInfoBase> & user_info_shared_ptr(){' in line:
    i = lineno
    break

if (i == -1):
  print 'ERROR: Failed to sanitize PseudoJet.hh; couldn\'t find user_info_shared_ptr() function.'
  exit(1)

# bracket user_info_shared_ptr() function in CINT ifndef guards so CINT doesn't
#  see it
outfile.writelines(lines[:i])
outfile.write('#ifndef __CINT__\n')
outfile.writelines(lines[i:i+3])
outfile.write('#endif\n')
outfile.writelines(lines[i+3:])



