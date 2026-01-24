#include <gtest/gtest.h>

#include "0005_longest_palindromic_substring.h"

class LongestPalindromicSubstringTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(LongestPalindromicSubstringTest, TestCase1) {
  string s = "babad";
  // Both "bab" and "aba" are valid answers
  string output = solution.longestPalindrome(s);
  EXPECT_TRUE(output == "bab" || output == "aba");
}

TEST_F(LongestPalindromicSubstringTest, TestCase2) {
  string s = "cbbd";
  string expected = "bb";

  string output = solution.longestPalindrome(s);
  EXPECT_EQ(output, expected);
}
