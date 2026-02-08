#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  vector<int> getConcatenation(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(2 * n);

    for (int i = 0; i < n; ++i) {
      res[i] = nums[i];
      res[i + n] = nums[i];
    }

    return res;
  }

  // Time: O(n) | Space: O(n)
  vector<int> getConcatenation2(vector<int>& nums) {
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      nums.push_back(nums[i]);
    }

    return nums;
  }
};
