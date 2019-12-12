#!/bin/bash

TEST_DIR="./tests"

rm -r build
mkdir build
cd build
cmake .. && make -j4 

echo "--------------------------------"
echo "---  execute TestCalculator  ---"
echo "--------------------------------"
${TEST_DIR}/TestCalculator

echo "--------------------------------"
echo "---  execute TestMath        ---"
echo "--------------------------------"
${TEST_DIR}/TestMath

echo "--------------------------------"
echo "---  execute TestParser      ---"
echo "--------------------------------"
${TEST_DIR}/TestParser

#echo "------------------------------"
#echo "-----  execute project  ------"
#echo "------------------------------"
#./project
echo "------------------------------" 
