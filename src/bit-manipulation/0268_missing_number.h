#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  // XOR approach
  // One or the other, but not both
  // 0 ^ 0 = 0, 0 ^ 1 = 1, 1 ^ 0 = 1, 1 ^ 1 = 0
  // Any number XOR 0 is still the original number: a ^ 0 = a
  // Any number XOR itself is 0: a ^ a = 0
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    // Initialize result with n (the largest possible missing number)
    // This handles the case where n itself is missing
    int res = n;
    // The loop is effectively doing:
    // res = n ^ 0 ^ nums[0] ^ 1 ^ nums[1] ^ 2 ^ nums[2] ^ ... ^ (n-1) ^ nums[n-1]
    // you can swap them freely
    // (0 ^ 0) ^ (1 ^ 1) ^ (3 ^ 3) ^ 2
    // res = 2
    for (int i = 0; i < n; ++i) {
      res ^= i ^ nums[i];
    }
    return res;
  }

  // Time: O(n) | Space: O(1)
  // Math
  int missingNumber2(vector<int>& nums) {
    int n = nums.size();
    int expected_sum = n * (n + 1) / 2;
    int actual_sum = 0;
    for (int num : nums) {
      actual_sum += num;
    }
    return expected_sum - actual_sum;
  }
};
