#include <gtest/gtest.h>
#include "../../src/arrays-hashing/0238_product_of_array_except_self.cc"

class ProductOfArrayExceptSelfTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ProductOfArrayExceptSelfTest, BasicExample) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> expected = {24, 12, 8, 6};
  auto result = solution.productExceptSelf(nums);
  EXPECT_EQ(result, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, WithZero) {
  std::vector<int> nums = {-1, 1, 0, -3, 3};
  std::vector<int> expected = {0, 0, 9, 0, 0};
  auto result = solution.productExceptSelf(nums);
  EXPECT_EQ(result, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, TwoElements) {
  std::vector<int> nums = {1, 2};
  std::vector<int> expected = {2, 1};
  auto result = solution.productExceptSelf(nums);
  EXPECT_EQ(result, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, NegativeNumbers) {
  std::vector<int> nums = {-1, -2, -3};
  std::vector<int> expected = {6, 3, 2};
  auto result = solution.productExceptSelf(nums);
  EXPECT_EQ(result, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, Method2_BasicExample) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> expected = {24, 12, 8, 6};
  auto result = solution.productExceptSelf2(nums);
  EXPECT_EQ(result, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, Method2_WithZero) {
  std::vector<int> nums = {-1, 1, 0, -3, 3};
  std::vector<int> expected = {0, 0, 9, 0, 0};
  auto result = solution.productExceptSelf2(nums);
  EXPECT_EQ(result, expected);
}
