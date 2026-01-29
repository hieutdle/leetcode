#pragma once

#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  int maxSubArray(vector<int>& nums) {
    // Initialize the result with the first element
    int res = nums[0];
    // Track the current sum of the subarray
    int curr = nums[0];

    // Iterate through the array starting from the second element
    for (int i = 1; i < nums.size(); i++) {
      // At each position, we either extend the current subarray or start a new one
      // We start a new subarray if current_sum becomes negative
      curr = max(nums[i], curr + nums[i]);
      // Update the maximum sum found so far
      res = max(res, curr);
    }

    return res;
  }
};
