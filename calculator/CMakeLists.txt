cmake_minimum_required(VERSION 3.5.1)

if (NOT DEFINED PRODUCT_VERSION)
    set(PRODUCT_VERSION "1.0.0")
endif()

project(PolishCalculator LANGUAGES CXX VERSION ${PRODUCT_VERSION})
set(LIB_NAME "PolishCalculator_${PROJECT_VERSION}")
message("========== == Start cmake : ${PROJECT_NAME} ${PROJECT_VERSION} will create lib${LIB_NAME}.a")

#----------------------------------------------------------------------------------------
message("== PROJECT_NAME      : ${PROJECT_NAME}")
message("== CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
message("== PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("== PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

if (NOT DEFINED CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
endif()
message("== BIN_OUTPUT_DIR    : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

if (NOT DEFINED CMAKE_LIBRARY_OUTPUT_DIRECTORY)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
endif()
message("== LIB_OUTPUT_DIR    : ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

if (NOT DEFINED CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
endif()
message("=== ARC_OUTPUT_DIR    : ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

#----------------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

set(PROJECT_INCLUDE
    ${PROJECT_SOURCE_DIR}/parser
    ${PROJECT_SOURCE_DIR}/math
    ${PROJECT_SOURCE_DIR}/stringRecognizer
)
include_directories(${PROJECT_INCLUDE})

set(PROJECT_HEADERS
    Calculator.hpp
    ${PROJECT_SOURCE_DIR}/parser/Parser.hpp
    ${PROJECT_SOURCE_DIR}/math/Math.hpp
)

set(PROJECT_SOURCES
    Calculator.cpp
    ${PROJECT_SOURCE_DIR}/parser/Parser.cpp
    ${PROJECT_SOURCE_DIR}/math/Math.cpp
)

set(LIB_DEPENDENCY
    Recognizer_${PROJECT_VERSION}
)

add_library(${LIB_NAME} STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})
add_dependencies(${LIB_NAME} ${LIB_DEPENDENCY})
target_link_libraries(${LIB_NAME} ${LIB_DEPENDENCY})

add_subdirectory(${PROJECT_SOURCE_DIR}/stringRecognizer)

message("========== == Finish cmake : ${PROJECT_NAME}")