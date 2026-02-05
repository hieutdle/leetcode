#include <gtest/gtest.h>

#include "0371_sum_of_two_integers.h"

class SumOfTwoIntegersTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(SumOfTwoIntegersTest, TestCase1) {
  int a = 1;
  int b = 2;
  int expected = 3;

  int output = solution.getSum(a, b);
  EXPECT_EQ(output, expected);
}

TEST_F(SumOfTwoIntegersTest, TestCase2) {
  int a = 2;
  int b = 3;
  int expected = 5;

  int output = solution.getSum(a, b);
  EXPECT_EQ(output, expected);
}