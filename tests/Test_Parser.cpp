#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <stack>
#include <string>

#include "Parser.hpp"

namespace dev {
namespace testing {

class TestParser : public ::testing::Test {
 public:
  void SetUp() override {}
  void TearDown() override {}
  dev::Parser mParser;
};

//--- Parse line with N elements ----------------------------------------------
TEST_F(TestParser, ParseLineWith_0_elements)
{
    const size_t expectSize = 0;
    const std::string line = "";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    ASSERT_EQ(expectSize, stack.size());
}

TEST_F(TestParser, ParseLineWith_1_elements)
{
    const size_t expectSize = 1;
    const std::string line = "1";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    ASSERT_EQ(expectSize, stack.size());
}

TEST_F(TestParser, ParseLineWith_2_elements)
{
    const size_t expectSize = 2;
    const std::string line = "1 2";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    ASSERT_EQ(expectSize, stack.size());
}

TEST_F(TestParser, ParseLineWith_3_elements)
{
    const size_t expectSize = 3;
    const std::string line = "1 2 3";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    ASSERT_EQ(expectSize, stack.size());
}

TEST_F(TestParser, ParseLineWith_4_elements)
{
    const size_t expectSize = 4;
    const std::string line = "1 2 3 4";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    ASSERT_EQ(expectSize, stack.size());
}

TEST_F(TestParser, ParseLineWith_5_elements)
{
    const size_t expectSize = 5;
    const std::string line = "1 2 3 4 5";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    ASSERT_EQ(expectSize, stack.size());
}

//--- Check Top ---------------------------------------------------------------
TEST_F(TestParser, CheckTopNumber) {
    const std::string expectTop = "123";
    const std::string line = "1 2 123";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    EXPECT_EQ(expectTop, stack.top());
}

TEST_F(TestParser, CheckTopSignOfSum) {
    const std::string expectTop = "+";
    const std::string line = "1 2 +";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    EXPECT_EQ(expectTop, stack.top());
}

TEST_F(TestParser, CheckTopSignOfDiff) {
    const std::string expectTop = "-";
    const std::string line = "1 2 -";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    EXPECT_EQ(expectTop, stack.top());
}

TEST_F(TestParser, CheckTopSignOfMultiplication) {
    const std::string expectTop = "*";
    const std::string line = "1 2 *";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    EXPECT_EQ(expectTop, stack.top());
}

TEST_F(TestParser, CheckTopSignOfDivision) {
    const std::string expectTop = "/";
    const std::string line = "1 2 /";
    std::stack<std::string> stack;
    mParser.parseStringToStringStack(line, stack);
    EXPECT_EQ(expectTop, stack.top());
}

}  // namespace testing
}  // namespace dev
