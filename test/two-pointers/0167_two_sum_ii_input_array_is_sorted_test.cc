#include <gtest/gtest.h>

#include "0167_two_sum_ii_input_array_is_sorted.h"

class TwoSumIIInputArrayIsSortedTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(TwoSumIIInputArrayIsSortedTest, TestCase1) {
  std::vector<int> numbers = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> expected = {1, 2};

  auto output = solution.twoSum(numbers, target);
  EXPECT_EQ(output, expected);

  auto output2 = solution.twoSum2(numbers, target);
  EXPECT_EQ(output2, expected);

  auto output3 = solution.twoSum3(numbers, target);
  EXPECT_EQ(output3, expected);
}

TEST_F(TwoSumIIInputArrayIsSortedTest, TestCase2) {
  std::vector<int> numbers = {2, 3, 4};
  int target = 6;
  std::vector<int> expected = {1, 3};

  auto output = solution.twoSum(numbers, target);
  EXPECT_EQ(output, expected);

  auto output2 = solution.twoSum2(numbers, target);
  EXPECT_EQ(output2, expected);

  auto output3 = solution.twoSum3(numbers, target);
  EXPECT_EQ(output3, expected);
}

TEST_F(TwoSumIIInputArrayIsSortedTest, TestCase3) {
  std::vector<int> numbers = {-1, 0};
  int target = -1;
  std::vector<int> expected = {1, 2};

  auto output = solution.twoSum(numbers, target);
  EXPECT_EQ(output, expected);

  auto output2 = solution.twoSum2(numbers, target);
  EXPECT_EQ(output2, expected);

  auto output3 = solution.twoSum3(numbers, target);
  EXPECT_EQ(output3, expected);
}
