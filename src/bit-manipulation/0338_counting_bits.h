#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  // DP using dp[i] = dp[i >> 1] + (i & 1)
  vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      // dp[i] = dp[i/2] + (i % 2);
      dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
  }

  // Time: O(n) | Space: O(n)
  // DP using dp[i] = dp[i & (i - 1)] + 1
  vector<int> countBits2(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i & (i - 1)] + 1;
    }
    return dp;
  }

  // Time: O(n) | Space: O(n)
  // Built-in
  vector<int> countBits3(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      dp[i] = __builtin_popcount(i);
    }
    return dp;
  }
};
