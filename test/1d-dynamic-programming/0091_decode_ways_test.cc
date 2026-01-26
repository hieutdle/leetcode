#include <gtest/gtest.h>

#include "0091_decode_ways.h"

class DecodeWaysTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(DecodeWaysTest, TestCase1) {
  string s = "12";
  int expected = 2;  // "12" can be decoded as "AB" (1 2) or "L" (12)

  int output = solution.numDecodings(s);
  EXPECT_EQ(output, expected);
}

TEST_F(DecodeWaysTest, TestCase2) {
  string s = "226";
  int expected = 3;  // "226" can be decoded as "BZ" (2 26), "VF" (22 6), or
                     // "BBF" (2 2 6)

  int output = solution.numDecodings(s);
  EXPECT_EQ(output, expected);
}

TEST_F(DecodeWaysTest, TestCase3) {
  string s = "06";
  int expected = 0;  // "06" cannot be decoded (leading zero)

  int output = solution.numDecodings(s);
  EXPECT_EQ(output, expected);
}
