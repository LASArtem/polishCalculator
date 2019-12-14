cmake_minimum_required(VERSION 3.5.1)
project(mathematics)

message("============== Start cmake : ${PROJECT_NAME}")
message("============== CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message("============== PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 14)

#set(PROJECT_INCLUDE parser math stringRecognizer)
#include_directories(${PROJECT_INCLUDE})

set(PROJECT_SOURCE Math.cpp)
add_executable(math ${PROJECT_SOURCE})

message("============== Finish cmake : ${PROJECT_NAME}")