#pragma once

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n^2) | Space: O(log n)
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size();

    if (n < 3)
      return res;

    // Sort the array to use two pointers
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; ++i) {
      // once nums[i] becomes positive, there is no valid triplet left to find
      if (nums[i] > 0)
        break;

      // Skip duplicate values for i
      if (i > 0 && nums[i] == nums[i - 1])
        continue;

      int l = i + 1;
      int r = n - 1;

      while (l < r) {
        int sum = nums[i] + nums[l] + nums[r];

        if (sum == 0) {
          res.push_back({nums[i], nums[l], nums[r]});

          // Skip duplicates for left
          while (l < r && nums[l] == nums[l + 1])
            ++l;
          // Skip duplicates for right
          while (l < r && nums[r] == nums[r - 1])
            --r;

          ++l;
          --r;
        } else if (sum < 0) {
          ++l;
        } else {
          --r;
        }
      }
    }

    return res;
  }
};
