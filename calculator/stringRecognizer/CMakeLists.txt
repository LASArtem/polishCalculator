cmake_minimum_required(VERSION 3.5.1)

if (NOT DEFINED PRODUCT_VERSION)
    set(PRODUCT_VERSION "1.0.0")
endif()

project(StringRecognizer LANGUAGES CXX VERSION ${PRODUCT_VERSION})
set(LIB_NAME "Recognizer_${PROJECT_VERSION}")
message("========== == == Start cmake : ${PROJECT_NAME} ${PROJECT_VERSION} will create lib${LIB_NAME}.a")

#----------------------------------------------------------------------------------------
message("=== PROJECT_NAME      : ${PROJECT_NAME}")
message("=== CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
message("=== PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("=== PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")


if (NOT DEFINED CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
endif()
message("=== BIN_OUTPUT_DIR    : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

if (NOT DEFINED CMAKE_LIBRARY_OUTPUT_DIRECTORY)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
endif()
message("=== LIB_OUTPUT_DIR    : ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

if (NOT DEFINED CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
endif()
message("=== ARC_OUTPUT_DIR    : ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

#----------------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 11 )
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

add_library(${LIB_NAME} STATIC StringRecognizer.cpp StringRecognizer.hpp)
#set_target_properties(${LIB_NAME} PROPERTIES
#                      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}"
#                      LIBRARY_OUTPUT_DIRECTORY "${CMAKE_LIBRARY_OUTPUT_DIRECTORY}"
#                      ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}"
#                      )
message("========== == == Finish cmake : ${PROJECT_NAME}")