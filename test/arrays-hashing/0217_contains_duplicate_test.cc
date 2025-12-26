#include <gtest/gtest.h>

#include "0217_contains_duplicate.h"

class ContainsDuplicateTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ContainsDuplicateTest, TestCase1) {
  std::vector<int> nums = {1, 2, 3, 1};

  EXPECT_TRUE(solution.containsDuplicate(nums));
  EXPECT_TRUE(solution.containsDuplicate2(nums));
  EXPECT_TRUE(solution.containsDuplicate3(nums));
}

TEST_F(ContainsDuplicateTest, TestCase2) {
  std::vector<int> nums = {1, 2, 3, 4};

  EXPECT_FALSE(solution.containsDuplicate(nums));
  EXPECT_FALSE(solution.containsDuplicate2(nums));
  EXPECT_FALSE(solution.containsDuplicate3(nums));
}

TEST_F(ContainsDuplicateTest, TestCase3) {
  std::vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

  EXPECT_TRUE(solution.containsDuplicate(nums));
  EXPECT_TRUE(solution.containsDuplicate2(nums));
  EXPECT_TRUE(solution.containsDuplicate3(nums));
}