#pragma once

#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> res;
    int n = nums.size();

    // Count occurrences of each element
    for (int num : nums) {
      ++res[num];
      // If count exceeds n/2, return this element
      if (res[num] > n / 2) {
        return num;
      }
    }

    // This line should never be reached given the problem constraints
    return 0;
  }

  // Time: O(n) | Space: O(1)
  // Moore Voting Algorithm
  int majorityElement2(vector<int>& nums) {
    // Counter for the current candidate
    int cnt = 0;
    // Current candidate for majority element
    int res = 0;

    // Iterate through all elements in the array
    for (int num : nums) {
      // When count reaches 0, swap the candidate with the current element
      if (cnt == 0) {
        res = num;
      }
      // Increment count if current element matches candidate,
      // otherwise decrement count
      cnt += (num == res) ? 1 : -1;
    }

    // The candidate at the end is guaranteed to be the majority element
    return res;
  }
};
