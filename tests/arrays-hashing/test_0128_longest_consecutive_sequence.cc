#include <gtest/gtest.h>

#include "../../src/arrays-hashing/0128_longest_consecutive_sequence.cc"

class LongestConsecutiveSequenceTest : public ::testing::Test {
protected:
  Solution solution;
};

TEST_F(LongestConsecutiveSequenceTest, BasicExample) {
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  EXPECT_EQ(solution.longestConsecutive(nums), 4);
}

TEST_F(LongestConsecutiveSequenceTest, EmptyInput) {
  std::vector<int> nums = {};
  EXPECT_EQ(solution.longestConsecutive(nums), 0);
}

TEST_F(LongestConsecutiveSequenceTest, SingleElement) {
  std::vector<int> nums = {1};
  EXPECT_EQ(solution.longestConsecutive(nums), 1);
}

TEST_F(LongestConsecutiveSequenceTest, NoConsecutive) {
  std::vector<int> nums = {1, 3, 5, 7};
  EXPECT_EQ(solution.longestConsecutive(nums), 1);
}

TEST_F(LongestConsecutiveSequenceTest, AllConsecutive) {
  std::vector<int> nums = {1, 2, 3, 4, 5};
  EXPECT_EQ(solution.longestConsecutive(nums), 5);
}

TEST_F(LongestConsecutiveSequenceTest, WithDuplicates) {
  std::vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  EXPECT_EQ(solution.longestConsecutive(nums), 9);
}

TEST_F(LongestConsecutiveSequenceTest, NegativeNumbers) {
  std::vector<int> nums = {-1, 0, 1, 2};
  EXPECT_EQ(solution.longestConsecutive(nums), 4);
}

TEST_F(LongestConsecutiveSequenceTest, Method2_BasicExample) {
  std::vector<int> nums = {100, 4, 200, 1, 3, 2};
  EXPECT_EQ(solution.longestConsecutive2(nums), 4);
}

TEST_F(LongestConsecutiveSequenceTest, Method2_EmptyInput) {
  std::vector<int> nums = {};
  EXPECT_EQ(solution.longestConsecutive2(nums), 0);
}
