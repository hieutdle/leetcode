#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "0039_combination_sum.h"

class CombinationSumTest : public ::testing::Test {
 protected:
  Solution solution;

  // Helper function to sort and compare 2D vectors
  bool compareResults(vector<vector<int>> a, vector<vector<int>> b) {
    if (a.size() != b.size())
      return false;

    // Sort each inner vector
    for (auto& vec : a) {
      std::sort(vec.begin(), vec.end());
    }
    for (auto& vec : b) {
      std::sort(vec.begin(), vec.end());
    }

    // Sort the outer vectors
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    return a == b;
  }
};

TEST_F(CombinationSumTest, TestCase1) {
  vector<int> candidates = {2, 3, 6, 7};
  int target = 7;
  vector<vector<int>> expected = {{2, 2, 3}, {7}};

  vector<vector<int>> output = solution.combinationSum(candidates, target);
  EXPECT_TRUE(compareResults(output, expected));

  vector<vector<int>> output2 = solution.combinationSum2(candidates, target);
  EXPECT_TRUE(compareResults(output2, expected));
}

TEST_F(CombinationSumTest, TestCase2) {
  vector<int> candidates = {2, 3, 5};
  int target = 8;
  vector<vector<int>> expected = {{2, 2, 2, 2}, {2, 3, 3}, {3, 5}};

  vector<vector<int>> output = solution.combinationSum(candidates, target);
  EXPECT_TRUE(compareResults(output, expected));

  vector<vector<int>> output2 = solution.combinationSum2(candidates, target);
  EXPECT_TRUE(compareResults(output2, expected));
}

TEST_F(CombinationSumTest, TestCase3) {
  vector<int> candidates = {2};
  int target = 1;
  vector<vector<int>> expected = {};

  vector<vector<int>> output = solution.combinationSum(candidates, target);
  EXPECT_TRUE(compareResults(output, expected));

  vector<vector<int>> output2 = solution.combinationSum2(candidates, target);
  EXPECT_TRUE(compareResults(output2, expected));
}