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

TEST_F(TestCalculator, SetStack) {
    std::string example = "12 3 +";
    mCalculator.setStack(example);
    ASSERT_EQ(3, mCalculator.getStackSize());
}

TEST_F(TestCalculator, GetStackTop) {
    std::string example = "12 3 +";
    std::string top = "+";
    mCalculator.setStack(example);
    EXPECT_EQ(top, mCalculator.getStackTop());
}

TEST_F(TestCalculator, CheckSum) {
    std::string example = "12 3 +";
    std::string result = "15";
    mCalculator.setStack(example);
    mCalculator.processStackTop();
    EXPECT_EQ(result, mCalculator.getStackTop());
}

TEST_F(TestCalculator, CheckDiff) {
    std::string example = "12 3 -";
    std::string result = "9";
    mCalculator.setStack(example);
    mCalculator.processStackTop();
    EXPECT_EQ(result, mCalculator.getStackTop());
}

TEST_F(TestCalculator, CheckMultiplication) {
    std::string example = "12 3 *";
    std::string result = "36";
    mCalculator.setStack(example);
    mCalculator.processStackTop();
    EXPECT_EQ(result, mCalculator.getStackTop());
}

TEST_F(TestCalculator, CheckDivision) {
    std::string example = "12 3 /";
    std::string result = "4";
    mCalculator.setStack(example);
    mCalculator.processStackTop();
    EXPECT_EQ(result, mCalculator.getStackTop());
}


}  // namespace testing
}  // namespace dev
