#include <gtest/gtest.h>

#include "0027_remove_element.h"

class RemoveElementTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(RemoveElementTest, TestCase1) {
  std::vector<int> nums = {3, 2, 2, 3};
  int val = 3;
  int expected = 2;

  auto output = solution.removeElement(nums, val);
  EXPECT_EQ(output, expected);

  // Verify first k elements don't contain val
  for (int i = 0; i < output; ++i) {
    EXPECT_NE(nums[i], val);
  }
}

TEST_F(RemoveElementTest, TestCase2) {
  std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
  int val = 2;
  int expected = 5;

  auto output = solution.removeElement(nums, val);
  EXPECT_EQ(output, expected);

  // Verify first k elements don't contain val
  for (int i = 0; i < output; ++i) {
    EXPECT_NE(nums[i], val);
  }
}