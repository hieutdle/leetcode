#include <gtest/gtest.h>

#include "0070_climbing_stairs.h"

class ClimbingStairsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ClimbingStairsTest, TestCase1) {
  int n = 2;
  int expected = 2;

  int output = solution.climbStairs(n);
  EXPECT_EQ(output, expected);

  int output2 = solution.climbStairs2(n);
  EXPECT_EQ(output2, expected);
}

TEST_F(ClimbingStairsTest, TestCase2) {
  int n = 3;
  int expected = 3;

  int output = solution.climbStairs(n);
  EXPECT_EQ(output, expected);

  int output2 = solution.climbStairs2(n);
  EXPECT_EQ(output2, expected);
}