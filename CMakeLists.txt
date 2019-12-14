cmake_minimum_required(VERSION 3.5.1)
project(project_main)

message("========== Start cmake : ${PROJECT_NAME}")
message("========== CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
message("========== PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")

set(CMAKE_CXX_STANDARD 14)
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

add_subdirectory(${PROJECT_SOURCE_DIR}/calculator)
include_directories(${PROJECT_SOURCE_DIR}/calculator)
set(PROJECT_SOURCE main.cpp)
add_executable(main ${PROJECT_SOURCE})

target_link_libraries(main polishCalculator)


#set(SOURCES Calculator.cpp Math.cpp Parser.cpp)
#add_library(ProjectLib ${SOURCES})

#add_executable(project main.cpp)
#target_link_libraries(project ProjectLib)

#enable_testing()
#add_subdirectory(tests)

message("========== Finish cmake : ${PROJECT_NAME}")