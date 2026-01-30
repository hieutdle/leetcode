#pragma once

#include <algorithm>
#include <vector>

using std::max;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  bool canJump(vector<int>& nums) {
    // Track the farthest index we can reach from the start
    int mx = 0;

    for (int i = 0; i < nums.size(); i++) {
      // If the current index is greater than what we can reach,
      // we have passed the maximum reachable index and cannot reach the end.
      if (mx < i) {
        return false;
      }
      // Update the farthest we can reach from index i
      mx = max(mx, i + nums[i]);
      // Early exit: we can already reach the last index
      if (mx >= static_cast<int>(nums.size()) - 1) {
        return true;
      }
    }
    return true;
  }
};
