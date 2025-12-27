#include <gtest/gtest.h>

#include "0011_container_with_most_water.h"

class ContainerWithMostWaterTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ContainerWithMostWaterTest, TestCase1) {
  std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int expected = 49;

  auto output = solution.maxArea(height);
  EXPECT_EQ(output, expected);
}

TEST_F(ContainerWithMostWaterTest, TestCase2) {
  std::vector<int> height = {1, 1};
  int expected = 1;

  auto output = solution.maxArea(height);
  EXPECT_EQ(output, expected);
}