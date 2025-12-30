#include <gtest/gtest.h>

#include "0020_valid_parentheses.h"

class ValidParenthesesTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ValidParenthesesTest, TestCase1) {
  std::string s = "()";
  bool expected = true;

  bool output = solution.isValid(s);
  EXPECT_EQ(output, expected);
}

TEST_F(ValidParenthesesTest, TestCase2) {
  std::string s = "()[]{}";
  bool expected = true;

  bool output = solution.isValid(s);
  EXPECT_EQ(output, expected);
}

TEST_F(ValidParenthesesTest, TestCase3) {
  std::string s = "(]";
  bool expected = false;

  bool output = solution.isValid(s);
  EXPECT_EQ(output, expected);
}

TEST_F(ValidParenthesesTest, TestCase4) {
  std::string s = "([])";
  bool expected = true;

  bool output = solution.isValid(s);
  EXPECT_EQ(output, expected);
}

TEST_F(ValidParenthesesTest, TestCase5) {
  std::string s = "([)]";
  bool expected = false;

  bool output = solution.isValid(s);
  EXPECT_EQ(output, expected);
}