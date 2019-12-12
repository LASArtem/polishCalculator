include_directories (${CMAKE_SOURCE_DIR})

include(AddGoogleTest)

add_executable (TestCalculator Test_Calculator.cpp)
add_gtest(TestCalculator)
target_link_libraries(TestCalculator PUBLIC ProjectLib)

add_executable (TestMath Test_Math.cpp)
add_gtest(TestMath)
target_link_libraries(TestMath PUBLIC ProjectLib)

add_executable (TestParser Test_Parser.cpp)
add_gtest(TestParser)
target_link_libraries(TestParser PUBLIC ProjectLib)
