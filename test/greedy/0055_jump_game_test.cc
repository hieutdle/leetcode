#include <gtest/gtest.h>

#include "0055_jump_game.h"

class JumpGameTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(JumpGameTest, TestCase1) {
  std::vector<int> nums = {2, 3, 1, 1, 4};
  bool expected = true;

  bool output = solution.canJump(nums);
  EXPECT_EQ(output, expected);
}

TEST_F(JumpGameTest, TestCase2) {
  std::vector<int> nums = {3, 2, 1, 0, 4};
  bool expected = false;

  bool output = solution.canJump(nums);
  EXPECT_EQ(output, expected);
}