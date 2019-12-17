cmake_minimum_required(VERSION 3.5.1)

project(polish_calculator)
message("========== == Start cmake : ${PROJECT_NAME}")

add_subdirectory(${PROJECT_SOURCE_DIR}/stringRecognizer)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "-Wall")

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
add_library(PolishCalculator STATIC ${PROJECT_SOURCES} ${PROJECT_HEADERS})
add_dependencies (PolishCalculator Recognizer)
#target_link_libraries(PolishCalculator ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Recognizer)
target_link_libraries(PolishCalculator Recognizer)

message("========== == Finish cmake : ${PROJECT_NAME}")