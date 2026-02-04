#include <gtest/gtest.h>

#include "0073_set_matrix_zeroes.h"

class SetMatrixZeroesTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(SetMatrixZeroesTest, TestCase1) {
  std::vector<std::vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  std::vector<std::vector<int>> expected = {{1, 0, 1}, {0, 0, 0}, {1, 0, 1}};

  solution.setZeroes(matrix);
  EXPECT_EQ(matrix, expected);

  matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  solution.setZeroes2(matrix);
  EXPECT_EQ(matrix, expected);
}

TEST_F(SetMatrixZeroesTest, TestCase2) {
  std::vector<std::vector<int>> matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  std::vector<std::vector<int>> expected = {{0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}};

  solution.setZeroes(matrix);
  EXPECT_EQ(matrix, expected);

  matrix = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};
  solution.setZeroes2(matrix);
  EXPECT_EQ(matrix, expected);
}