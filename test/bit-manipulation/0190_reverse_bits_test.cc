#include <gtest/gtest.h>

#include "0190_reverse_bits.h"

class ReverseBitsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ReverseBitsTest, TestCase1) {
  // Input: 00000010100101000001111010011100
  // Output: 00111001011110000010100101000000
  uint32_t n = 43261596;
  uint32_t expected = 964176192;

  auto output = solution.reverseBits(n);
  EXPECT_EQ(output, expected);

  auto output2 = solution.reverseBits2(n);
  EXPECT_EQ(output2, expected);
}

TEST_F(ReverseBitsTest, TestCase2) {
  // Input: 11111111111111111111111111111101
  // Output: 10111111111111111111111111111111
  uint32_t n = 4294967293;
  uint32_t expected = 3221225471;

  auto output = solution.reverseBits(n);
  EXPECT_EQ(output, expected);

  auto output2 = solution.reverseBits2(n);
  EXPECT_EQ(output2, expected);
}

TEST_F(ReverseBitsTest, TestCase3) {
  uint32_t n = 0;
  uint32_t expected = 0;

  auto output = solution.reverseBits(n);
  EXPECT_EQ(output, expected);

  auto output2 = solution.reverseBits2(n);
  EXPECT_EQ(output2, expected);
}
