#pragma once

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  int maxArea(vector<int>& height) {
    // Initialize two pointers: left at the beginning, right at the end
    // Because they have the largest width
    int l = 0;
    int r = height.size() - 1;
    int res = 0;

    while (l < r) {
      int width = r - l;
      int h = std::min(height[l], height[r]);
      int area = width * h;
      res = std::max(res, area);

      // Move the pointer with smaller height
      if (height[l] < height[r]) {
        ++l;
      } else {
        --r;
      }
    }

    return res;
  }
};
