#include <gtest/gtest.h>

#include "2d-dynamic-programming/0062_unique_paths.h"

class UniquePathsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(UniquePathsTest, TestCase1) {
  int m = 3;
  int n = 7;
  int expected = 28;

  int output = solution.uniquePaths(m, n);
  EXPECT_EQ(output, expected);

  int output2 = solution.uniquePaths2(m, n);
  EXPECT_EQ(output2, expected);
}

TEST_F(UniquePathsTest, TestCase2) {
  int m = 3;
  int n = 2;
  int expected = 3;

  int output = solution.uniquePaths(m, n);
  EXPECT_EQ(output, expected);

  int output2 = solution.uniquePaths2(m, n);
  EXPECT_EQ(output2, expected);
}
