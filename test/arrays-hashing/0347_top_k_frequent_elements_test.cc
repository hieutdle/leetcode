#include <gtest/gtest.h>

#include <algorithm>

#include "0347_top_k_frequent_elements.h"

class TopKFrequentElementsTest : public ::testing::Test {
 protected:
  Solution solution;

  // Helper to check if result contains expected elements (order may vary)
  bool containsSameElements(const std::vector<int>& result, const std::vector<int>& expected) {
    if (result.size() != expected.size())
      return false;
    std::vector<int> sorted_result = result;
    std::vector<int> sorted_expected = expected;
    std::sort(sorted_result.begin(), sorted_result.end());
    std::sort(sorted_expected.begin(), sorted_expected.end());
    return sorted_result == sorted_expected;
  }
};

TEST_F(TopKFrequentElementsTest, TestCase1) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;

  auto output = solution.topKFrequent(nums, k);
  auto output2 = solution.topKFrequent2(nums, k);

  std::vector<int> expected = {1, 2};

  EXPECT_TRUE(containsSameElements(output, expected));
  EXPECT_TRUE(containsSameElements(output2, expected));
}

TEST_F(TopKFrequentElementsTest, TestCase2) {
  std::vector<int> nums = {1};
  int k = 1;

  auto output = solution.topKFrequent(nums, k);
  auto output2 = solution.topKFrequent2(nums, k);

  std::vector<int> expected = {1};

  EXPECT_TRUE(containsSameElements(output, expected));
  EXPECT_TRUE(containsSameElements(output2, expected));
}

TEST_F(TopKFrequentElementsTest, TestCase3) {
  std::vector<int> nums = {1, 2, 1, 2, 1, 2, 3, 1, 3, 2};
  int k = 2;

  auto output = solution.topKFrequent(nums, k);
  auto output2 = solution.topKFrequent2(nums, k);

  std::vector<int> expected = {1, 2};

  EXPECT_TRUE(containsSameElements(output, expected));
  EXPECT_TRUE(containsSameElements(output2, expected));
}
