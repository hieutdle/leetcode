#include <gtest/gtest.h>

#include "0001_two_sum.h"

class TwoSumTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(TwoSumTest, TestCase1) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  std::vector<int> output = solution.twoSum(nums, target);
  std::vector<int> expected = {0, 1};

  EXPECT_EQ(output, expected);
}

TEST_F(TwoSumTest, TestCase2) {
  std::vector<int> nums = {3, 2, 4};
  int target = 6;

  std::vector<int> output = solution.twoSum(nums, target);
  std::vector<int> expected = {1, 2};

  EXPECT_EQ(output, expected);
}

TEST_F(TwoSumTest, TestCase3) {
  std::vector<int> nums = {3, 3};
  int target = 6;
  std::vector<int> output = solution.twoSum(nums, target);
  std::vector<int> expected = {0, 1};

  EXPECT_EQ(output, expected);
}