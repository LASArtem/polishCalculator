#!/bin/bash

source clear.sh

mkdir "${TEMP_BUILD_DIR}"
cd "${TEMP_BUILD_DIR}"

echo "=============================================="
echo "============ command: cmake =================="
cmake .. 
echo "=============================================="
echo "============ command: make ==================="
make
echo "=============================================="

#echo "--------------------------------"
#echo "---  execute TestCalculator  ---"
#echo "--------------------------------"
#${TEST_DIR}/TestCalculator

#echo "--------------------------------"
#echo "---  execute TestMath        ---"
#echo "--------------------------------"
#${TEST_DIR}/TestMath

#echo "--------------------------------"
#echo "---  execute TestParser      ---"
#echo "--------------------------------"
#${TEST_DIR}/TestParser

#echo "------------------------------"
#echo "-----  execute project  ------"
#echo "------------------------------"
#./bin/main
#echo "------------------------------"
