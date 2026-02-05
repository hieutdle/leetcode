#pragma once

class Solution {
 public:
  // Time: O(1) | Space: O(1)
  // XOR, AND + shift for carry
  int getSum(int a, int b) {
    // Iterate until there's no carry left
    while (b != 0) {
      // Carry records where carry happens
      // 0101 & 0011 = 0001 (carry at bit 0)
      // (0110 & 0010 = 0010 (carry at bit 1))
      int carry = a & b;
      // ^ works like + without handling carry bits.
      // 0101 ^ 0011 = 0110
      a = a ^ b;
      // Move carry one position to the left
      // 0001 << 1 = 0010
      // Now it’s in the correct place for the next addition step
      b = (unsigned)carry << 1;
    }
    return a;
  }
};
