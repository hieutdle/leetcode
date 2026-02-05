#include <gtest/gtest.h>

#include "0191_number_of_1_bits.h"

class NumberOf1BitsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(NumberOf1BitsTest, TestCase1) {
  // binary: 1011
  int n = 11;
  int expected = 3;

  int output = solution.hammingWeight(11);
  EXPECT_EQ(output, expected);

  int output2 = solution.hammingWeight2(11);
  EXPECT_EQ(output2, expected);

  int output3 = solution.hammingWeight3(11);
  EXPECT_EQ(output3, expected);
}

TEST_F(NumberOf1BitsTest, TestCase2) {
  // binary: 10000000
  int n = 128;
  int expected = 1;

  int output = solution.hammingWeight(128);
  EXPECT_EQ(output, expected);

  int output2 = solution.hammingWeight2(128);
  EXPECT_EQ(output2, expected);

  int output3 = solution.hammingWeight3(128);
  EXPECT_EQ(output3, expected);
}

TEST_F(NumberOf1BitsTest, TestCase3) {
  // binary: 1111111111111111111111111111101
  int n = 2147483645;
  int expected = 30;

  int output = solution.hammingWeight(2147483645);
  EXPECT_EQ(output, expected);

  int output2 = solution.hammingWeight2(2147483645);
  EXPECT_EQ(output2, expected);

  int output3 = solution.hammingWeight3(2147483645);
  EXPECT_EQ(output3, expected);
}
