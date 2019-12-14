#!/bin/bash

TMP_DIR="$(pwd)/build"
TEST_DIR="$(pwd)/tests"


if [ -d "${TMP_DIR}" ]
then
    #sudo rm -r "${TMP_DIR}"
    rm -r "${TMP_DIR}"
fi

mkdir "${TMP_DIR}"
cd "${TMP_DIR}"

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
#./project
#echo "------------------------------" 
