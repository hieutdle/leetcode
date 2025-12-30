#include <gtest/gtest.h>

#include "0153_find_minimum_in_rotated_sorted_array.h"

class FindMinimumInRotatedSortedArrayTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(FindMinimumInRotatedSortedArrayTest, TestCase1) {
  std::vector<int> nums = {3, 4, 5, 1, 2};
  int expected = 1;

  int output = solution.findMin(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(FindMinimumInRotatedSortedArrayTest, TestCase2) {
  std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int expected = 0;

  int output = solution.findMin(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(FindMinimumInRotatedSortedArrayTest, TestCase3) {
  std::vector<int> nums = {11, 13, 15, 17};
  int expected = 11;

  int output = solution.findMin(nums);
  EXPECT_EQ(output, expected);
}