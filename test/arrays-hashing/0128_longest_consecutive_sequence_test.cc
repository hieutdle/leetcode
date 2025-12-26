#include <gtest/gtest.h>

#include "0128_longest_consecutive_sequence.h"

class LongestConsecutiveSequenceTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(LongestConsecutiveSequenceTest, TestCase1) {
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};

  int output = solution.longestConsecutive(nums);
  int output2 = solution.longestConsecutive2(nums);

  int expected = 4;

  EXPECT_EQ(output, expected);
  EXPECT_EQ(output2, expected);
}

TEST_F(LongestConsecutiveSequenceTest, TestCase2) {
  std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};

  int output = solution.longestConsecutive(nums);
  int output2 = solution.longestConsecutive2(nums);

  int expected = 9;

  EXPECT_EQ(output, expected);
  EXPECT_EQ(output2, expected);
}

TEST_F(LongestConsecutiveSequenceTest, TestCase3) {
  std::vector<int> nums = {1, 2, 0, 1};

  int output = solution.longestConsecutive(nums);
  int output2 = solution.longestConsecutive2(nums);

  int expected = 3;

  EXPECT_EQ(output, expected);
  EXPECT_EQ(output2, expected);
}