#include <gtest/gtest.h>

#include "0338_counting_bits.h"

class CountingBitsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(CountingBitsTest, TestCase1) {
  int n = 2;
  std::vector<int> expected = {0, 1, 1};

  auto output = solution.countBits(n);
  EXPECT_EQ(output, expected);

  auto output2 = solution.countBits2(n);
  EXPECT_EQ(output2, expected);

  auto output3 = solution.countBits3(n);
  EXPECT_EQ(output3, expected);
}

TEST_F(CountingBitsTest, TestCase2) {
  int n = 5;
  std::vector<int> expected = {0, 1, 1, 2, 1, 2};

  auto output = solution.countBits(n);
  EXPECT_EQ(output, expected);

  std::vector<int> output2 = solution.countBits2(n);
  EXPECT_EQ(output2, expected);

  auto output3 = solution.countBits3(n);
  EXPECT_EQ(output3, expected);
}

TEST_F(CountingBitsTest, TestCase3) {
  int n = 0;
  std::vector<int> expected = {0};

  auto output = solution.countBits(n);
  EXPECT_EQ(output, expected);

  auto output2 = solution.countBits2(n);
  EXPECT_EQ(output2, expected);

  auto output3 = solution.countBits3(n);
  EXPECT_EQ(output3, expected);
}
