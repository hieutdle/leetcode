#include <gtest/gtest.h>

#include "2d-dynamic-programming/1143_longest_common_subsequence.h"

class LongestCommonSubsequenceTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(LongestCommonSubsequenceTest, TestCase1) {
  string text1 = "abcde";
  string text2 = "ace";
  int expected = 3;

  int output = solution.longestCommonSubsequence(text1, text2);
  EXPECT_EQ(output, expected);
}

TEST_F(LongestCommonSubsequenceTest, TestCase2) {
  string text1 = "abc";
  string text2 = "abc";
  int expected = 3;

  int output = solution.longestCommonSubsequence(text1, text2);
  EXPECT_EQ(output, expected);
}

TEST_F(LongestCommonSubsequenceTest, TestCase3) {
  string text1 = "abc";
  string text2 = "def";
  int expected = 0;

  int output = solution.longestCommonSubsequence(text1, text2);
  EXPECT_EQ(output, expected);
}
