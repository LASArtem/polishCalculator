cmake_minimum_required(VERSION 3.5.1)

if (NOT DEFINED PRODUCT_VERSION)
    set(PRODUCT_VERSION "1.0.0")
endif()

project(Main LANGUAGES CXX VERSION ${PRODUCT_VERSION})
set(EXEC_NAME "Main_${PROJECT_VERSION}")
message("========== Start cmake : ${PROJECT_NAME} ${PROJECT_VERSION} will create ${EXEC_NAME}")

#----------------------------------------------------------------------------------------
message("= PROJECT_NAME      : ${PROJECT_NAME}")
message("= CMAKE_PROJECT_NAME: ${CMAKE_PROJECT_NAME}")
message("= PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
message("= PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

if (NOT DEFINED CMAKE_RUNTIME_OUTPUT_DIRECTORY)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
endif()
message("= BIN_OUTPUT_DIR    : ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

if (NOT DEFINED CMAKE_LIBRARY_OUTPUT_DIRECTORY)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
endif()
message("= LIB_OUTPUT_DIR    : ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

if (NOT DEFINED CMAKE_ARCHIVE_OUTPUT_DIRECTORY)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
endif()
message("=== ARC_OUTPUT_DIR    : ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}")

#----------------------------------------------------------------------------------------

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall")

include_directories(${PROJECT_SOURCE_DIR}/calculator)

set(EXEC_DEPENDENCY
    PolishCalculator_${PROJECT_VERSION}
    Recognizer_${PROJECT_VERSION}
)


add_executable(${EXEC_NAME} main.cpp)
add_dependencies (${EXEC_NAME} ${EXEC_DEPENDENCY})
target_link_libraries(${EXEC_NAME} ${EXEC_DEPENDENCY})

add_subdirectory(${PROJECT_SOURCE_DIR}/calculator)

#list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
#enable_testing()
#add_subdirectory(tests)

message("========== Finish cmake : ${PROJECT_NAME}")
