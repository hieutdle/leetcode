#include <gtest/gtest.h>

#include "0647_palindromic_substrings.h"

class PalindromicSubstringsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(PalindromicSubstringsTest, TestCase1) {
  string s = "abc";
  int expected = 3;  // "a", "b", "c"

  int output = solution.countSubstrings(s);
  EXPECT_EQ(output, expected);
}

TEST_F(PalindromicSubstringsTest, TestCase2) {
  string s = "aaa";
  int expected = 6;  // "a", "a", "a", "aa", "aa", "aaa"

  int output = solution.countSubstrings(s);
  EXPECT_EQ(output, expected);
}