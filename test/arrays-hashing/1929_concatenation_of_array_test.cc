#include <gtest/gtest.h>

#include "1929_concatenation_of_array.h"

class ConcatenationOfArrayTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ConcatenationOfArrayTest, TestCase1) {
  std::vector<int> nums = {1, 2, 1};
  std::vector<int> expected = {1, 2, 1, 1, 2, 1};

  auto output = solution.getConcatenation(nums);
  EXPECT_EQ(output, expected);

  auto output2 = solution.getConcatenation2(nums);
  EXPECT_EQ(output2, expected);
}

TEST_F(ConcatenationOfArrayTest, TestCase2) {
  std::vector<int> nums = {1, 3, 2, 1};
  std::vector<int> expected = {1, 3, 2, 1, 1, 3, 2, 1};

  auto output = solution.getConcatenation(nums);
  EXPECT_EQ(output, expected);

  auto output2 = solution.getConcatenation2(nums);
  EXPECT_EQ(output2, expected);
}