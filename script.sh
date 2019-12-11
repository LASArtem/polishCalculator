#!/bin/bash

rm -r build
mkdir build
cd build
cmake .. && make -j4 

echo "------------------------------"
echo "-----  execute test     ------"
echo "------------------------------"
./test/ProjectTest

echo "------------------------------"
echo "-----  execute project  ------"
echo "------------------------------"
./project
echo "------------------------------" 
