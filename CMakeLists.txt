cmake_minimum_required(VERSION 3.5.1)
project(project_main)
message("========== Start cmake : ${PROJECT_NAME}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(${PROJECT_SOURCE_DIR}/calculator)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${PROJECT_SOURCE_DIR}/calculator)

add_executable(main main.cpp)
add_dependencies (main PolishCalculator Recognizer)
#target_link_libraries(main ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/PolishCalculator)
#target_link_libraries(main ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}/Recognizer)
include_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
target_link_libraries(main Recognizer PolishCalculator)


#list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
#enable_testing()
#add_subdirectory(tests)

message("========== Finish cmake : ${PROJECT_NAME}")
