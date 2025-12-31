#include <gtest/gtest.h>

#include "0033_search_in_rotated_sorted_array.h"

class SearchInRotatedSortedArrayTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(SearchInRotatedSortedArrayTest, TestCase1) {
  std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 0;
  int expected = 4;

  int output = solution.search(nums, target);
  EXPECT_EQ(output, expected);
}

TEST_F(SearchInRotatedSortedArrayTest, TestCase2) {
  std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  int target = 3;
  int expected = -1;

  int output = solution.search(nums, target);
  EXPECT_EQ(output, expected);
}

TEST_F(SearchInRotatedSortedArrayTest, TestCase3) {
  std::vector<int> nums = {1};
  int target = 0;
  int expected = -1;

  int output = solution.search(nums, target);
  EXPECT_EQ(output, expected);
}