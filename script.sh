#!/bin/bash

sudo rm -r build
mkdir build
cd build
cmake .. && make -j4  #&& ./bin/unit_tests

echo "------------------------------"
echo "-----  execute project  ------"
echo "------------------------------"
./project
echo "------------------------------" 
