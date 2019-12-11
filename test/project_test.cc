#include "Calculator.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
namespace dev {
namespace testing {

/* TODO:
 * rename file: CalculatorTest
 * add: tests for negative numbers
 * add: tests for complex data
 */

class ProjectTest : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  dev::Calculator mCalculator;
};

TEST_F(ProjectTest, SetStack) {
    std::string example = "12 3 +";
    mCalculator.setStack(example);
    ASSERT_EQ(3, mCalculator.getStackSize());
}

TEST_F(ProjectTest, GetStackTop) {
    std::string example = "12 3 +";
    std::string top = "+";
    mCalculator.setStack(example);
    EXPECT_EQ(top, mCalculator.getStackTop());
}

TEST_F(ProjectTest, CheckSum) {
    std::string example = "12 3 +";
    std::string result = "15";
    mCalculator.setStack(example);
    mCalculator.processStackTop();
    EXPECT_EQ(result, mCalculator.getStackTop());
}

TEST_F(ProjectTest, CheckDiff) {
    std::string example = "12 3 -";
    std::string result = "9";
    mCalculator.setStack(example);
    mCalculator.processStackTop();
    EXPECT_EQ(result, mCalculator.getStackTop());
}

TEST_F(ProjectTest, CheckMultiplication) {
    std::string example = "12 3 *";
    std::string result = "36";
    mCalculator.setStack(example);
    mCalculator.processStackTop();
    EXPECT_EQ(result, mCalculator.getStackTop());
}

TEST_F(ProjectTest, CheckDivision) {
    std::string example = "12 3 /";
    std::string result = "4";
    mCalculator.setStack(example);
    mCalculator.processStackTop();
    EXPECT_EQ(result, mCalculator.getStackTop());
}


}  // namespace testing
}  // namespace dev
