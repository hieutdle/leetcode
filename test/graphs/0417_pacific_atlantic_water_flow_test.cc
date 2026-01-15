#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "0417_pacific_atlantic_water_flow.h"

class PacificAtlanticWaterFlowTest : public ::testing::Test {
 protected:
  Solution solution;

  // Helper function to sort results for comparison
  void sortResult(vector<vector<int>>& result) {
    std::sort(result.begin(), result.end(), [](const vector<int>& a, const vector<int>& b) {
      if (a[0] != b[0])
        return a[0] < b[0];
      return a[1] < b[1];
    });
  }
};

TEST_F(PacificAtlanticWaterFlowTest, TestCase1) {
  vector<vector<int>> heights = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
  vector<vector<int>> expected = {{0, 4}, {1, 3}, {1, 4}, {2, 2}, {3, 0}, {3, 1}, {4, 0}};
  sortResult(expected);

  vector<vector<int>> output = solution.pacificAtlantic(heights);
  sortResult(output);
  EXPECT_EQ(output, expected);

  vector<vector<int>> output2 = solution.pacificAtlantic2(heights);
  sortResult(output2);
  EXPECT_EQ(output2, expected);
}

TEST_F(PacificAtlanticWaterFlowTest, TestCase2) {
  vector<vector<int>> heights = {{1}};
  vector<vector<int>> expected = {{0, 0}};
  sortResult(expected);

  vector<vector<int>> output = solution.pacificAtlantic(heights);
  sortResult(output);
  EXPECT_EQ(output, expected);

  vector<vector<int>> output2 = solution.pacificAtlantic2(heights);
  sortResult(output2);
  EXPECT_EQ(output2, expected);
}