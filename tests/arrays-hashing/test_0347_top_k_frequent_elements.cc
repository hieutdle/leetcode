#include <gtest/gtest.h>
#include <algorithm>
#include "../../src/arrays-hashing/0347_top_k_frequent_elements.cc"

class TopKFrequentElementsTest : public ::testing::Test {
 protected:
  Solution solution;
  
  // Helper to check if result contains expected elements (order may vary)
  bool containsSameElements(const std::vector<int>& result, 
                            const std::vector<int>& expected) {
    if (result.size() != expected.size()) return false;
    std::vector<int> sorted_result = result;
    std::vector<int> sorted_expected = expected;
    std::sort(sorted_result.begin(), sorted_result.end());
    std::sort(sorted_expected.begin(), sorted_expected.end());
    return sorted_result == sorted_expected;
  }
};

TEST_F(TopKFrequentElementsTest, BasicExample) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  auto result = solution.topKFrequent(nums, k);
  std::vector<int> expected = {1, 2};
  EXPECT_TRUE(containsSameElements(result, expected));
}

TEST_F(TopKFrequentElementsTest, SingleElement) {
  std::vector<int> nums = {1};
  int k = 1;
  auto result = solution.topKFrequent(nums, k);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0], 1);
}

TEST_F(TopKFrequentElementsTest, AllSameFrequency) {
  std::vector<int> nums = {1, 2, 3, 4};
  int k = 2;
  auto result = solution.topKFrequent(nums, k);
  EXPECT_EQ(result.size(), 2);
}

TEST_F(TopKFrequentElementsTest, KEqualsSize) {
  std::vector<int> nums = {1, 1, 2, 2, 3};
  int k = 3;
  auto result = solution.topKFrequent(nums, k);
  std::vector<int> expected = {1, 2, 3};
  EXPECT_TRUE(containsSameElements(result, expected));
}

TEST_F(TopKFrequentElementsTest, Method2_BasicExample) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  auto result = solution.topKFrequent2(nums, k);
  std::vector<int> expected = {1, 2};
  EXPECT_TRUE(containsSameElements(result, expected));
}

TEST_F(TopKFrequentElementsTest, Method3_BasicExample) {
  std::vector<int> nums = {1, 1, 1, 2, 2, 3};
  int k = 2;
  auto result = solution.topKFrequent3(nums, k);
  std::vector<int> expected = {1, 2};
  EXPECT_TRUE(containsSameElements(result, expected));
}
