#pragma once

#include <algorithm>
#include <vector>

using std::max;
using std::min;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  // Track both max and min product at each position
  // We need to track min because a negative number can turn a minimum into a maximum
  int maxProduct(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    // Initialize with first element
    int maxProd = nums[0];
    int minProd = nums[0];
    int res = nums[0];

    // Iterate through the array starting from the second element
    for (int i = 1; i < nums.size(); ++i) {
      int curr = nums[i];

      // Store current max before updating (needed for min calculation)
      int tempMax = maxProd;

      // For product subarray
      // Adding more elements can:
      // Increase the value
      // Decrease the value
      // Flip the sign
      // Zero everything out
      // So the more elments we add, the bigger the product can get in either direction

      // Update maximum product ending at current position
      // Max product at current position could be:
      // 1. Current number itself (start a new subarray)
      // 2. Current number * previous max (extend previous positive subarray)
      // 3. Current number * previous min (extend previous negative subarray, if curr is negative)
      // For zero, both max and min will reset to zero: curr * maxProd = 0 * maxProd = 0
      maxProd = max({curr, curr * maxProd, curr * minProd});

      // Min product at current position could be:
      // 1. Current number itself (start a new subarray)
      // 2. Current number * previous min (extend previous negative subarray)
      // 3. Current number * previous max (extend previous positive subarray, if curr is negative)
      minProd = min({curr, curr * tempMax, curr * minProd});

      // Update the overall result
      res = max(res, maxProd);
    }

    return res;
  }
};
