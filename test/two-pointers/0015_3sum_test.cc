#include <gtest/gtest.h>

#include "0015_3sum.h"

class ThreeSumTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ThreeSumTest, TestCase1) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  std::vector<std::vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};

  auto output = solution.threeSum(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(ThreeSumTest, TestCase2) {
  std::vector<int> nums = {0, 1, 1};
  std::vector<std::vector<int>> expected = {};

  auto output = solution.threeSum(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(ThreeSumTest, TestCase3) {
  std::vector<int> nums = {0, 0, 0};
  std::vector<std::vector<int>> expected = {{0, 0, 0}};

  auto output = solution.threeSum(nums);
  EXPECT_EQ(output, expected);
}