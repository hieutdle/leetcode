#include <gtest/gtest.h>

#include "0053_maximum_subarray.h"

class MaximumSubarrayTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(MaximumSubarrayTest, TestCase1) {
  std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int expected = 6;

  int output = solution.maxSubArray(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(MaximumSubarrayTest, TestCase2) {
  std::vector<int> nums = {1};
  int expected = 1;

  int output = solution.maxSubArray(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(MaximumSubarrayTest, TestCase3) {
  std::vector<int> nums = {5, 4, -1, 7, 8};
  int expected = 23;

  int output = solution.maxSubArray(nums);
  EXPECT_EQ(output, expected);
}