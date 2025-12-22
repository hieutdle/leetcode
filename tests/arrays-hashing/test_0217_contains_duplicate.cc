#include <gtest/gtest.h>

#include "../../src/arrays-hashing/0217_contains_duplicate.cc"

class ContainsDuplicateTest : public ::testing::Test {
protected:
  Solution solution;
};

TEST_F(ContainsDuplicateTest, Cases1) {
  std::vector<int> nums = {1, 2, 3, 1};
  EXPECT_TRUE(solution.containsDuplicate(nums));
}

TEST_F(ContainsDuplicateTest, Case2) {
  std::vector<int> nums = {1, 2, 3, 4};
  EXPECT_FALSE(solution.containsDuplicate(nums));
}

TEST_F(ContainsDuplicateTest, Case3) {
  std::vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
  EXPECT_TRUE(solution.containsDuplicate(nums));
}
