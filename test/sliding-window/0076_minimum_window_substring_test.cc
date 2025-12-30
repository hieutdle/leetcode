#include <gtest/gtest.h>

#include "0076_minimum_window_substring.h"

class MinimumWindowSubstringTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(MinimumWindowSubstringTest, TestCase1) {
  std::string s = "ADOBECODEBANC";
  std::string t = "ABC";
  std::string expected = "BANC";

  auto output = solution.minWindow(s, t);
  EXPECT_EQ(output, expected);
}

TEST_F(MinimumWindowSubstringTest, TestCase2) {
  std::string s = "a";
  std::string t = "a";
  std::string expected = "a";

  auto output = solution.minWindow(s, t);
  EXPECT_EQ(output, expected);
}

TEST_F(MinimumWindowSubstringTest, TestCase3) {
  std::string s = "a";
  std::string t = "aa";
  std::string expected = "";

  auto output = solution.minWindow(s, t);
  EXPECT_EQ(output, expected);
}