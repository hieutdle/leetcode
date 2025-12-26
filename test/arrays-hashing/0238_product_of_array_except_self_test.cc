#include <gtest/gtest.h>

#include "0238_product_of_array_except_self.h"

class ProductOfArrayExceptSelfTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ProductOfArrayExceptSelfTest, TestCase1) {
  std::vector<int> nums = {1, 2, 3, 4};
  std::vector<int> expected = {24, 12, 8, 6};

  auto output = solution.productExceptSelf(nums);
  EXPECT_EQ(output, expected);

  auto output2 = solution.productExceptSelf2(nums);
  EXPECT_EQ(output2, expected);
}

TEST_F(ProductOfArrayExceptSelfTest, TestCase2) {
  std::vector<int> nums = {-1, 1, 0, -3, 3};
  std::vector<int> expected = {0, 0, 9, 0, 0};

  auto output = solution.productExceptSelf(nums);
  EXPECT_EQ(output, expected);

  auto output2 = solution.productExceptSelf2(nums);
  EXPECT_EQ(output2, expected);
}