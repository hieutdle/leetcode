#pragma once

#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  // Optimized 1D DP
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }

    // dp[i] represents the maximum amount that can be robbed up to house i
    // We only need to track the last two values
    // Max amount up to house 0
    int prev2 = nums[0];
    // Max amount up to house 1
    // If you have two houses, you can choose to rob house 0 and skip house 1
    int prev1 = max(nums[0], nums[1]);
    if (n == 2) {
      return prev1;
    }

    int res = 0;

    // Build up from house 2 to house n-1
    for (int i = 2; i < n; ++i) {
      // Either rob current house + max from i-2, or skip current and take max from i-1
      res = max(nums[i] + prev2, prev1);
      prev2 = prev1;
      prev1 = res;
    }

    return res;
  }

  // Time : O(n) | Space: O(n)
  // 1D DP
  int rob2(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }

    // dp[i] := the maximum money of robbing nums[0..i]
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; ++i) {
      dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
    }

    return dp[n - 1];
  }

  // Time : O(n) | Space: O(n)
  // Memoization Search
  int rob3(vector<int>& nums) {
    int n = nums.size();
    // dp[i] represents the maximum amount that can be robbed from houses [i, n-1]
    // Initialize with -1 to indicate uncomputed state
    vector<int> dp(n, -1);

    auto dfs = [&](this auto&& dfs, int i) -> int {
      // Base case: if index is out of bounds, no money can be robbed
      if (i >= n) {
        return 0;
      }

      // If not yet computed, calculate the maximum amount
      if (dp[i] < 0) {
        // Two choices at each house:
        // 1. Rob current house and skip next house (nums[i] + dfs(i + 2))
        // 2. Skip current house and move to next house (dfs(i + 1))
        dp[i] = max(nums[i] + dfs(i + 2), dfs(i + 1));
      }

      return dp[i];
    };

    // Start the recursion from the first house (index 0)
    return dfs(0);
  }
};
