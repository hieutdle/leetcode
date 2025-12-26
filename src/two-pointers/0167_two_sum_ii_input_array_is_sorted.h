#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  // Two Pointers
  vector<int> twoSum(vector<int>& numbers, int target) {
    int l = 0;
    int r = numbers.size() - 1;

    while (l < r) {
      while (l < r && numbers[l] + numbers[r] > target)
        --r;
      while (l < r && numbers[l] + numbers[r] < target)
        ++l;
      if (numbers[l] + numbers[r] == target)
        return {l + 1, r + 1};
    }

    // This line should never be reached if input guarantees a solution
    return {};
  }

  // Time: O(n log n) | Space: O(1)
  // Binary Search
  vector<int> twoSum2(vector<int>& numbers, int target) {
    // Iterate through each element as the first number
    for (int i = 0; i < numbers.size(); i++) {
      // numbers = [2, 7, 11, 15]
      // search range: [7, 11, 15] (index 1 → end)
      int l = i + 1;
      int r = numbers.size() - 1;

      while (l <= r) {
        int mid = l + (r - l) / 2;
        if (numbers[i] + numbers[mid] == target)
          return {i + 1, mid + 1};
        else if (numbers[i] + numbers[mid] < target)
          l = mid + 1;
        else
          r = mid - 1;
      }
    }

    // Problem guarantees exactly one solution exists
    return {};
  }

  // Time: O(n log n) | Space: O(1)
  // Binary Search with lower_bound
  vector<int> twoSum3(vector<int>& numbers, int target) {
    for (int i = 0, n = numbers.size();; ++i) {
      int x = target - numbers[i];
      int j = lower_bound(numbers.begin() + i + 1, numbers.end(), x) - numbers.begin();
      if (j < n && numbers[j] == x) {
        return {i + 1, j + 1};
      }
    }
    return {};
  }
};
