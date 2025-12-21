#include <gtest/gtest.h>
#include "../../src/arrays-hashing/0001_two_sum.cc"

class TwoSumTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(TwoSumTest, Case1) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> result = solution.twoSum(nums, target);
  
  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
}

TEST_F(TwoSumTest, MultipleSolutions) {
  std::vector<int> nums = {3, 2, 4};
  int target = 6;
  std::vector<int> result = solution.twoSum(nums, target);
  
  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
  // Should return indices [1, 2] (values 2 and 4)
  EXPECT_TRUE((result[0] == 1 && result[1] == 2) || 
              (result[0] == 2 && result[1] == 1));
}

TEST_F(TwoSumTest, SameElementTwice) {
  std::vector<int> nums = {3, 3};
  int target = 6;
  std::vector<int> result = solution.twoSum(nums, target);
  
  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
  EXPECT_NE(result[0], result[1]);
}

TEST_F(TwoSumTest, NegativeNumbers) {
  std::vector<int> nums = {-1, -2, -3, -4, -5};
  int target = -8;
  std::vector<int> result = solution.twoSum(nums, target);
  
  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
}

TEST_F(TwoSumTest, MixedNumbers) {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  int target = 0;
  std::vector<int> result = solution.twoSum(nums, target);
  
  ASSERT_EQ(result.size(), 2);
  EXPECT_EQ(nums[result[0]] + nums[result[1]], target);
}
