cmake_minimum_required(VERSION 3.5.1)

project(string_recognizer)
message("========== == == Start cmake : ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

add_library(Recognizer STATIC StringRecognizer.cpp StringRecognizer.hpp)

message("========== == == Finish cmake : ${PROJECT_NAME}")