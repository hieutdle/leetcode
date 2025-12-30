#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(log n) | Space: O(1)
  int findMin(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;

    while (l < r) {
      int mid = l + (r - l) / 2;

      // If mid element is greater than the rightmost element,
      // the minimum must be in the right half
      // [ 3 4 |5| 1 2 ] 5 > 2
      if (nums[mid] > nums[r]) {
        l = mid + 1;
      } else {
        // Otherwise, the minimum is in the left half (including mid)
        r = mid;
      }
    }

    // When left == right, we've found the minimum
    return nums[l];
  }
};
