#pragma once

#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  // The houses are arranged in a circle, so we can't rob both first and last house
  // We can solve this by running the linear house robber twice:
  // 1. Rob houses 0 to n-2 (excluding last house)
  // 2. Rob houses 1 to n-1 (excluding first house)
  // Return the maximum of these two scenarios
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {
      return 0;
    }
    if (n == 1) {
      return nums[0];
    }
    if (n == 2) {
      return max(nums[0], nums[1]);
    }

    // Case 1: Rob houses from 0 to n-2 (exclude last house)
    int max1 = robLinear(nums, 0, n - 2);

    // Case 2: Rob houses from 1 to n-1 (exclude first house)
    int max2 = robLinear(nums, 1, n - 1);

    // Return the maximum of these two scenarios
    return max(max1, max2);
  }

 private:
  // Helper function to rob houses in a linear arrangement
  int robLinear(vector<int>& nums, int start, int end) {
    int prev2 = 0;  // Max amount up to i-2
    int prev1 = 0;  // Max amount up to i-1

    for (int i = start; i <= end; ++i) {
      // Either rob current house + max from i-2, or skip current and take max from i-1
      int curr = max(nums[i] + prev2, prev1);
      prev2 = prev1;
      prev1 = curr;
    }

    return prev1;
  }
};
