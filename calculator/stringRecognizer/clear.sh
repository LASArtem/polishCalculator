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
