#pragma once

#include <algorithm>
#include <unordered_set>
#include <vector>

using std::size_t;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (auto num : nums) {
      if (s.contains(num))
        return true;
      s.insert(num);
    }
    return false;
  }

  // Time: O(n) | Space: O(n)
  // Compare size
  bool containsDuplicate2(vector<int>& nums) {
    unordered_set<int> s(nums.begin(), nums.end());
    return s.size() != nums.size();
  }

  // Time: O(n log n) | Space: O(1)
  // Sort and check two numbers next to each other
  bool containsDuplicate3(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size() - 1; ++i)
      if (nums[i] == nums[i + 1])
        return true;

    return false;
  }
};
