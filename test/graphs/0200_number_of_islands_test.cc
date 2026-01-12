#include <gtest/gtest.h>

#include <vector>

#include "0200_number_of_islands.h"

class NumberOfIslandsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(NumberOfIslandsTest, TestCase1) {
  vector<vector<char>> grid = {
      {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
  int expected = 1;

  int output = solution.numIslands(grid);
  EXPECT_EQ(output, expected);
}

TEST_F(NumberOfIslandsTest, TestCase2) {
  vector<vector<char>> grid = {
      {'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
  int expected = 3;

  int output = solution.numIslands(grid);
  EXPECT_EQ(output, expected);
}