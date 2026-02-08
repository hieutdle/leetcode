#include <gtest/gtest.h>

#include "0169_majority_element.h"

class MajorityElementTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(MajorityElementTest, TestCase1) {
  std::vector<int> nums = {3, 2, 3};
  int expected = 3;

  auto output = solution.majorityElement(nums);
  EXPECT_EQ(output, expected);

  auto output2 = solution.majorityElement2(nums);
  EXPECT_EQ(output2, expected);
}

TEST_F(MajorityElementTest, TestCase2) {
  std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
  int expected = 2;

  auto output = solution.majorityElement(nums);
  EXPECT_EQ(output, expected);

  auto output2 = solution.majorityElement2(nums);
  EXPECT_EQ(output2, expected);
}