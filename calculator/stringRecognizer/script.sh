#!/bin/bash

TEMP_BUILD_DIR="$(pwd)/build"
TEMP_TEST_DIR="$(pwd)/tests"
TEMP_BIN_DIR="$(pwd)/bin"
TEMP_LIB_DIR="$(pwd)/lib"

if [ -d "${TEMP_BIN_DIR}" ]
then
    rm -r "${TEMP_BIN_DIR}"
fi

if [ -d "${TEMP_LIB_DIR}" ]
then
    rm -r "${TEMP_LIB_DIR}"
fi

if [ -d "${TEMP_BUILD_DIR}" ]
then
    rm -r "${TEMP_BUILD_DIR}"
fi

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
