#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(log n) | Space: O(1)
  int search(vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;

      if (nums[mid] == target) {
        return mid;
      }

      // Determine which half is sorted
      if (nums[l] <= nums[mid]) {  // nums[l..mid] are sorted.
        // Left half is sorted
        if (nums[l] <= target && target < nums[mid]) {
          // Target is in the sorted left half
          r = mid - 1;
        } else {
          // Target is in the right half
          l = mid + 1;
        }
      } else {
        // Right half is sorted
        if (nums[mid] < target && target <= nums[r]) {
          // Target is in the sorted right half
          l = mid + 1;
        } else {
          // Target is in the left half
          r = mid - 1;
        }
      }
    }

    // Target not found
    return -1;
  }
};
