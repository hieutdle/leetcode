#include <gtest/gtest.h>

#include "0152_maximum_product_subarray.h"

class MaximumProductSubarrayTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(MaximumProductSubarrayTest, TestCase1) {
  std::vector<int> nums = {2, 3, -2, 4};
  int expected = 6;

  int output = solution.maxProduct(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(MaximumProductSubarrayTest, TestCase2) {
  std::vector<int> nums = {-2, 0, -1};
  int expected = 0;

  int output = solution.maxProduct(nums);
  EXPECT_EQ(output, expected);
}