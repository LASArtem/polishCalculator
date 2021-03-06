#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <string>

#include "Math.hpp"

namespace dev {
namespace testing {

class TestMath : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  dev::Math mMath;
};

//---  SUM  -------------------------------------------------------------------
TEST_F(TestMath, SumOfPositiveIntegerNumberAndPositiveIntegerNumber) {
    std::string result = "";
    std::string a = "15";
    std::string b = "35";
    std::string expectedResult = "50";
    EXPECT_TRUE(mMath.sum(result, a, b));
    EXPECT_EQ(expectedResult, result);
}

TEST_F(TestMath, SumOfNegativeIntegerNumberAndPositiveIntegerNumber) {
    std::string result = "";
    std::string a = "-15";
    std::string b = "35";
    std::string expectedResult = "20";
    EXPECT_TRUE(mMath.sum(result, a, b));
    EXPECT_EQ(expectedResult, result);
}

TEST_F(TestMath, SumOfPositiveIntegerNumberAndNegativeIntegerNumber) {
    std::string result = "";
    std::string a = "15";
    std::string b = "-35";
    std::string expectedResult = "-20";
    EXPECT_TRUE(mMath.sum(result, a, b));
    EXPECT_EQ(expectedResult, result);
}

TEST_F(TestMath, SumOfSpecialAndPositiveIntegerNumber) {
    std::string result = "";
    std::string a = "!!";
    std::string b = "35";
    std::string expectedResult = "50";
    EXPECT_FALSE(mMath.sum(result, a, b));
    EXPECT_NE(expectedResult, result);
}

TEST_F(TestMath, SumOfPositiveIntegerNumberAndSpecial) {
    std::string result = "";
    std::string a = "15";
    std::string b = "!!";
    std::string expectedResult = "50";
    EXPECT_FALSE(mMath.sum(result, a, b));
    EXPECT_NE(expectedResult, result);
}

//---  DIFF -------------------------------------------------------------------
TEST_F(TestMath, diffOfNumberAndNumber) {
    std::string result = "";
    std::string a = "65";
    std::string b = "15";
    std::string realResult = "50";
    const bool success = mMath.diff(result, a, b);
    EXPECT_EQ(realResult, result);
}

TEST_F(TestMath, diffOfNotNumberAndNumber) {
    std::string result = "";
    std::string a = "!!";
    std::string b = "15";
    std::string realResult = "50";
    const bool success = mMath.diff(result, a, b);
    EXPECT_NE(realResult, result);
}

TEST_F(TestMath, diffOfNumberAndNotNumber) {
    std::string result = "";
    std::string a = "65";
    std::string b = "!!";
    std::string realResult = "50";
    const bool success = mMath.diff(result, a, b);
    EXPECT_NE(realResult, result);
}

//---  MULTIPLICATION ---------------------------------------------------------
TEST_F(TestMath, multiplicationOfNumberAndNumber) {
    std::string result = "";
    std::string a = "10";
    std::string b = "5";
    std::string realResult = "50";
    const bool success = mMath.multiplication(result, a, b);
    EXPECT_EQ(realResult, result);
}

TEST_F(TestMath, multiplicationOfNotNumberAndNumber) {
    std::string result = "";
    std::string a = "!!";
    std::string b = "5";
    std::string realResult = "50";
    const bool success = mMath.multiplication(result, a, b);
    EXPECT_NE(realResult, result);
}

TEST_F(TestMath, multiplicationOfNumberAndNotNumber) {
    std::string result = "";
    std::string a = "10";
    std::string b = "!!";
    std::string realResult = "50";
    const bool success = mMath.multiplication(result, a, b);
    EXPECT_NE(realResult, result);
}

//---  DIVISION ---------------------------------------------------------------
TEST_F(TestMath, divisionOfNumberAndNumber) {
    std::string result = "";
    std::string a = "250";
    std::string b = "5";
    std::string realResult = "50";
    const bool success = mMath.division(result, a, b);
    EXPECT_EQ(realResult, result);
}

TEST_F(TestMath, divisionOfNotNumberAndNumber) {
    std::string result = "";
    std::string a = "!!";
    std::string b = "5";
    std::string realResult = "50";
    const bool success = mMath.division(result, a, b);
    EXPECT_NE(realResult, result);
}

TEST_F(TestMath, divisionnOfNumberAndNotNumber) {
    std::string result = "";
    std::string a = "250";
    std::string b = "!!";
    std::string realResult = "50";
    const bool success = mMath.division(result, a, b);
    EXPECT_NE(realResult, result);
}

}  // namespace testing
}  // namespace dev
