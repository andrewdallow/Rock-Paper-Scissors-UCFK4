#!/bin/sh
 
# File: build_project.sh
rm Makefile Makefile.test
cp -r ../ence260-2014-team102 ../../apps/
cd ../../etc
make
cd ../assignment/ence260-2014-team102 
cp ../../apps/ence260-2014-team102/Makefile ./
cp ../../apps/ence260-2014-team102/Makefile.test ./
rm -rf ../../apps/ence260-2014-team102/
