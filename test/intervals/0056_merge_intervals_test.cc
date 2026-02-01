#include <gtest/gtest.h>

#include "0056_merge_intervals.h"

class MergeIntervalsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(MergeIntervalsTest, TestCase1) {
  std::vector<std::vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  std::vector<std::vector<int>> expected = {{1, 6}, {8, 10}, {15, 18}};

  auto output = solution.merge(intervals);
  EXPECT_EQ(output, expected);
}

TEST_F(MergeIntervalsTest, TestCase2) {
  std::vector<std::vector<int>> intervals = {{1, 4}, {4, 5}};
  std::vector<std::vector<int>> expected = {{1, 5}};

  auto output = solution.merge(intervals);
  EXPECT_EQ(output, expected);
}

TEST_F(MergeIntervalsTest, TestCase3) {
  std::vector<std::vector<int>> intervals = {{4, 7}, {1, 4}};
  std::vector<std::vector<int>> expected = {{1, 7}};

  auto output = solution.merge(intervals);
  EXPECT_EQ(output, expected);
}