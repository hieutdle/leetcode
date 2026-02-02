#include <gtest/gtest.h>

#include "0435_non_overlapping_intervals.h"

class NonOverlappingIntervalsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(NonOverlappingIntervalsTest, TestCase1) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  int expected = 1;

  int output = solution.eraseOverlapIntervals(intervals);
  EXPECT_EQ(output, expected);
}

TEST_F(NonOverlappingIntervalsTest, TestCase2) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {1, 2}, {1, 2}};
  int expected = 2;

  int output = solution.eraseOverlapIntervals(intervals);
  EXPECT_EQ(output, expected);
}

TEST_F(NonOverlappingIntervalsTest, TestCase3) {
  std::vector<std::vector<int>> intervals = {{1, 2}, {2, 3}};
  int expected = 0;

  int output = solution.eraseOverlapIntervals(intervals);
  EXPECT_EQ(output, expected);
}
