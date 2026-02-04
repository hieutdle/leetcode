#include <gtest/gtest.h>

#include "0048_rotate_image.h"

class RotateImageTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(RotateImageTest, TestCase1) {
  std::vector<std::vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  std::vector<std::vector<int>> expected = {{7, 4, 1}, {8, 5, 2}, {9, 6, 3}};

  solution.rotate(matrix);
  EXPECT_EQ(matrix, expected);

  matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  solution.rotate2(matrix);
  EXPECT_EQ(matrix, expected);
}

TEST_F(RotateImageTest, TestCase2) {
  std::vector<std::vector<int>> matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  std::vector<std::vector<int>> expected = {{15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}};

  solution.rotate(matrix);
  EXPECT_EQ(matrix, expected);

  matrix = {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
  solution.rotate2(matrix);
  EXPECT_EQ(matrix, expected);
}