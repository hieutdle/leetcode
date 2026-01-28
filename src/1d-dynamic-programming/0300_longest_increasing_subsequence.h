#pragma once

#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
 public:
  // Time: O(n^2) | Space: O(n)
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }

    // dp[i] represents the length of the longest increasing subsequence
    // ending at index i
    vector<int> dp(n, 1);
    // The maximum length among all possible ending positions
    int res = 1;

    // For each position i, check all previous positions j
    for (int i = 1; i < n; i++) {
      for (int j = 0; j < i; j++) {
        // If current element is greater than previous element,
        // we can extend the subsequence ending at j
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      res = max(res, dp[i]);
    }

    return res;
  }
};
