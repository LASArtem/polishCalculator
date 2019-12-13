#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

#include "Calculator.hpp"

namespace dev {
namespace testing {

class TestCalculator : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  dev::Calculator mCalculator;
};


TEST_F(TestCalculator, SumOfPositiveIntegerNumberAndPositiveIntegerNumber) {
    std::string example = "12 3 +";
    std::string expectedResult = "15";
    dev::Result result = mCalculator.resolve(example);
    EXPECT_TRUE(result.isValid);
    EXPECT_EQ(expectedResult, result.answer);
}

TEST_F(TestCalculator, SumOfPositiveIntegerNumberAndNegativeIntegerNumber) {
    std::string example = "12 -3 +";
    std::string expectedResult = "9";
    dev::Result result = mCalculator.resolve(example);
    EXPECT_TRUE(result.isValid);
    EXPECT_EQ(expectedResult, result.answer);
}

TEST_F(TestCalculator, SumOfNegativeIntegerNumberAndPositiveIntegerNumber) {
    std::string example = "-12 3 +";
    std::string expectedResult = "-9";
    dev::Result result = mCalculator.resolve(example);
    EXPECT_TRUE(result.isValid);
    EXPECT_EQ(expectedResult, result.answer);
}

TEST_F(TestCalculator, DiffOfPositiveIntegerNumberAndPositiveIntegerNumber) {
    std::string example = "12 3 -";
    std::string expectedResult = "9";
    dev::Result result = mCalculator.resolve(example);
    EXPECT_TRUE(result.isValid);
    EXPECT_EQ(expectedResult, result.answer);
}

TEST_F(TestCalculator, MultiplicationOfPositiveIntegerNumberAndPositiveIntegerNumber) {
    std::string example = "12 3 *";
    std::string expectedResult = "36";
    dev::Result result = mCalculator.resolve(example);
    EXPECT_TRUE(result.isValid);
    EXPECT_EQ(expectedResult, result.answer);
}

TEST_F(TestCalculator, DivisionOfPositiveIntegerNumberAndPositiveIntegerNumber) {
    std::string example = "12 3 /";
    std::string expectedResult = "4";
    dev::Result result = mCalculator.resolve(example);
    EXPECT_TRUE(result.isValid);
    EXPECT_EQ(expectedResult, result.answer);
}


}  // namespace testing
}  // namespace dev
