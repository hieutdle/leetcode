#pragma once

#include <cstdint>

class Solution {
 public:
  // Time: O(1) | Space: O(1)
  // Bit by bit reversal
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    for (int i = 0; i < 32; ++i) {
      // Extract the least significant bit (LSB) of n
      // Place it at position (31 - i) in the result
      // << left shift operator
      // x << 3
      // 0001 => 1000
      // | — bitwise OR
      res |= (n & 1) << (31 - i);
      n >>= 1;
    }
    return res;
  }

  // Time: O(1) | Space: O(1)
  // Divide and conquer approach
  uint32_t reverseBits2(uint32_t n) {
    // Swap the left and right 16 bits
    n = (n >> 16) | (n << 16);
    // Before:  [ B3 ][ B2 ][ B1 ][ B0 ]
    // After:   [ B2 ][ B3 ][ B0 ][ B1 ]
    // n & 0xff00ff00  →  [ B3 ][ 00 ][ B1 ][ 00 ]
    // n & 0x00ff00ff  →  [ 00 ][ B2 ][ 00 ][ B0 ]
    // >> 8 → [ 00 ][ B3 ][ 00 ][ B1 ]
    // << 8 → [ B2 ][ 00 ][ B0 ][ 00 ]
    // | →   [ B2 ][ B3 ][ B0 ][ B1 ]
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
  }
};
