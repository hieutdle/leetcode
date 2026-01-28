#include <gtest/gtest.h>

#include "0300_longest_increasing_subsequence.h"

class LongestIncreasingSubsequenceTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(LongestIncreasingSubsequenceTest, TestCase1) {
  vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  int expected = 4;  // [2, 3, 7, 101]

  int output = solution.lengthOfLIS(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(LongestIncreasingSubsequenceTest, TestCase2) {
  vector<int> nums = {0, 1, 0, 3, 2, 3};
  int expected = 4;  // [0, 1, 2, 3]

  int output = solution.lengthOfLIS(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(LongestIncreasingSubsequenceTest, TestCase3) {
  vector<int> nums = {7, 7, 7, 7, 7, 7, 7};
  int expected = 1;  // Single element

  int output = solution.lengthOfLIS(nums);
  EXPECT_EQ(output, expected);
}