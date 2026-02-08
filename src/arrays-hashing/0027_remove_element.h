#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  int removeElement(vector<int>& nums, int val) {
    int i = 0;  // Index to place non-val elements

    // Iterate through the array
    for (const int num : nums) {
      // If current element is not equal to the value to be removed
      if (num != val) {
        // Place the non-val element at index i and increment i
        nums[i++] = num;
      }
    }

    // Return the count of elements after removal
    return i;
  }
};
