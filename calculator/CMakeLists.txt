cmake_minimum_required(VERSION 3.5.1)
project(polish_calculator)

message("============ Start cmake : ${PROJECT_NAME}")
message("============ CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message("============ PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(${PROJECT_SOURCE_DIR}/stringRecognizer)

set(PROJECT_INCLUDE
    ${PROJECT_SOURCE_DIR}/parser
    ${PROJECT_SOURCE_DIR}/math
    ${PROJECT_SOURCE_DIR}/stringRecognizer
)

include_directories(${PROJECT_INCLUDE})

set(PROJECT_SOURCE
    Calculator.cpp
    ${PROJECT_SOURCE_DIR}/parser/Parser.cpp
    ${PROJECT_SOURCE_DIR}/math/Math.cpp
)

add_library(polishCalculator ${PROJECT_SOURCE})

target_link_libraries(polishCalculator recognizer)

message("============ Finish cmake : ${PROJECT_NAME}")