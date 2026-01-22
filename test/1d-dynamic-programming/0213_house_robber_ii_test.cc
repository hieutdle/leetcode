#include <gtest/gtest.h>

#include "0213_house_robber_ii.h"

class HouseRobberIITest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(HouseRobberIITest, TestCase1) {
  std::vector<int> nums = {2, 3, 2};
  int expected = 3;

  int output = solution.rob(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(HouseRobberIITest, TestCase2) {
  std::vector<int> nums = {1, 2, 3, 1};
  int expected = 4;

  int output = solution.rob(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(HouseRobberIITest, TestCase3) {
  std::vector<int> nums = {1, 2, 3};
  int expected = 3;

  int output = solution.rob(nums);
  EXPECT_EQ(output, expected);
}