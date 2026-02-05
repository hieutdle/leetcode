#include <gtest/gtest.h>

#include "0268_missing_number.h"

class MissingNumberTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(MissingNumberTest, TestCase1) {
  std::vector<int> nums = {3, 0, 1};
  int expected = 2;

  int output = solution.missingNumber(nums);
  EXPECT_EQ(output, expected);

  int output2 = solution.missingNumber2(nums);
  EXPECT_EQ(output2, expected);
}

TEST_F(MissingNumberTest, TestCase2) {
  std::vector<int> nums = {0, 1};
  int expected = 2;

  int output = solution.missingNumber(nums);
  EXPECT_EQ(output, expected);

  int output2 = solution.missingNumber2(nums);
  EXPECT_EQ(output2, expected);
}

TEST_F(MissingNumberTest, TestCase3) {
  std::vector<int> nums = {9, 6, 4, 2, 3, 5, 7, 0, 1};
  int expected = 8;

  int output = solution.missingNumber(nums);
  EXPECT_EQ(output, expected);

  int output2 = solution.missingNumber2(nums);
  EXPECT_EQ(output2, expected);
}