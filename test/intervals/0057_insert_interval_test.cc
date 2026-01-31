#include <gtest/gtest.h>

#include "0057_insert_interval.h"

class InsertIntervalTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(InsertIntervalTest, TestCase1) {
  std::vector<std::vector<int>> intervals = {{1, 3}, {6, 9}};
  std::vector<int> new_interval = {2, 5};
  std::vector<std::vector<int>> expected = {{1, 5}, {6, 9}};

  auto output = solution.insert(intervals, new_interval);
  EXPECT_EQ(output, expected);
}

TEST_F(InsertIntervalTest, TestCase2) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {3, 5}, {6, 7}, {8, 10}, {12, 16}};
  std::vector<int> new_interval = {4, 8};
  std::vector<std::vector<int>> expected = {{1, 2}, {3, 10}, {12, 16}};

  auto output = solution.insert(intervals, new_interval);
  EXPECT_EQ(output, expected);
}