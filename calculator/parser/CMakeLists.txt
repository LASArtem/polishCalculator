cmake_minimum_required(VERSION 3.5.1)
project(parser)

message("============== Start cmake : ${PROJECT_NAME}")
message("============== CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message("============== PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 14)

set(PROJECT_SOURCE Parser.cpp)
add_executable(parser ${PROJECT_SOURCE})

message("============== Finish cmake : ${PROJECT_NAME}")