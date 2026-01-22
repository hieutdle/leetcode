#include <gtest/gtest.h>

#include "0198_house_robber.h"

class HouseRobberTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(HouseRobberTest, TestCase1) {
  std::vector<int> nums = {1, 2, 3, 1};
  int expected = 4;

  int output = solution.rob(nums);
  EXPECT_EQ(output, expected);

  int output2 = solution.rob2(nums);
  EXPECT_EQ(output2, expected);

  int output3 = solution.rob(nums);
  EXPECT_EQ(output3, expected);
}

TEST_F(HouseRobberTest, TestCase2) {
  std::vector<int> nums = {2, 7, 9, 3, 1};
  int expected = 12;

  int output = solution.rob(nums);
  EXPECT_EQ(output, expected);

  int output2 = solution.rob2(nums);
  EXPECT_EQ(output2, expected);

  int output3 = solution.rob(nums);
  EXPECT_EQ(output3, expected);
}
