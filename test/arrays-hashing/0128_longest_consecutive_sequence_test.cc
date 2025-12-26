#include <gtest/gtest.h>

#include "0128_longest_consecutive_sequence.h"

class LongestConsecutiveSequenceTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(LongestConsecutiveSequenceTest, TestCase1) {
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  int expected = 4;

  auto output = solution.longestConsecutive(nums);
  EXPECT_EQ(output, expected);

  auto output2 = solution.longestConsecutive2(nums);
  EXPECT_EQ(output2, expected);
}

TEST_F(LongestConsecutiveSequenceTest, TestCase2) {
  std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  int expected = 9;

  auto output = solution.longestConsecutive(nums);
  EXPECT_EQ(output, expected);

  auto output2 = solution.longestConsecutive2(nums);
  EXPECT_EQ(output2, expected);
}

TEST_F(LongestConsecutiveSequenceTest, TestCase3) {
  std::vector<int> nums = {1, 2, 0, 1};
  int expected = 3;

  auto output = solution.longestConsecutive(nums);
  EXPECT_EQ(output, expected);

  auto output2 = solution.longestConsecutive2(nums);
  EXPECT_EQ(output2, expected);
}