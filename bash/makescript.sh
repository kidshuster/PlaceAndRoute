#!/bin/bash 

echo "build files being reset"
yes | rm -R ../build && 
mkdir ../build && 
cd ../build && 
echo "build files reset"

cmake ../src && 
echo "removing git submodule files" &&
yes | rm -R googletest-src/.git &&
yes | rm googletest-src/.gitignore &&
make &&
ctest -C Debug -V &&

cd ../bash
