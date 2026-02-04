#include <gtest/gtest.h>

#include "0054_spiral_matrix.h"

class SpiralMatrixTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(SpiralMatrixTest, TestCase1) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<int> expected = {1, 2, 3, 6, 9, 8, 7, 4, 5};

  std::vector<int> output = solution.spiralOrder(matrix);
  EXPECT_EQ(output, expected);
}

TEST_F(SpiralMatrixTest, TestCase2) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  std::vector<int> expected = {1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};

  std::vector<int> output = solution.spiralOrder(matrix);
  EXPECT_EQ(output, expected);
}