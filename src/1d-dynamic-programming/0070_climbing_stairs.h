#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  // 2D DP
  int climbStairs(int n) {
    if (n <= 2) {
      return n;
    }

    vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
      // Calculate current Fibonacci number: F(i) = F(i-1) + F(i-2)
      dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n - 1];
  }

  // Time : O(n) | Space: O(1)
  // 1D DP
  int climbStairs2(int n) {
    if (n <= 2) {
      return n;
    }

    int prev2 = 1;  // dp[i - 2]
    int prev1 = 2;  // dp[i - 1]

    int res;

    for (int i = 3; i <= n; i++) {
      // Calculate current Fibonacci number: F(i) = F(i-1) + F(i-2)
      res = prev1 + prev2;
      // Shift the window: move forward by one position
      prev2 = prev1;  // F(i-1) becomes F(i-2)
      prev1 = res;    // F(i) becomes F(i-1)
    }

    return res;
  }
};
