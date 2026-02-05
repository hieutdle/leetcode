#pragma once

#include <bit>
#include <cstdint>

class Solution {
 public:
  // Time: O(1) | Space: O(1)
  // Brian Kernighan's Algorithm
  int hammingWeight(uint32_t n) {
    int res = 0;
    // Keep removing the rightmost set bit until n becomes 0
    // n = 10000001
    // n-1 = 10000000
    // New n = n & (n-1) = 10000000
    // n-1 = 01111111
    // n & n - 1 = 0
    while (n) {
      n &= (n - 1);  // Clear the least significant set bit
      ++res;
    }
    return res;
  }

  // Time: O(1) | Space: O(1)
  // Bit shifting approach
  int hammingWeight2(uint32_t n) {
    int res = 0;
    while (n) {
      // Checks the Least Significant Bit (LSB)
      res += n & 1;
      // Calculates the remainder yield the same result
      //
      n >>= 1;
    }
    return res;
  }

  // Time: O(1) | Space: O(1)
  // Built-in
  int hammingWeight3(uint32_t n) {
    return std::popcount(n);
  }
};
