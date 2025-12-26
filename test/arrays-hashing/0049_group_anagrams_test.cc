#include <gtest/gtest.h>

#include <algorithm>

#include "0049_group_anagrams.h"

class GroupAnagramsTest : public ::testing::Test {
 protected:
  Solution solution;

  // Helper function to sort the result for comparison
  void sortResult(std::vector<std::vector<std::string>>& result) {
    for (auto& group : result) {
      std::sort(group.begin(), group.end());
    }
    std::sort(result.begin(), result.end());
  }
};

TEST_F(GroupAnagramsTest, TestCase1) {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  std::vector<std::vector<std::string>> expected = {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};
  sortResult(expected);

  auto output = solution.groupAnagrams(strs);
  sortResult(output);
  EXPECT_EQ(output, expected);

  auto output2 = solution.groupAnagrams2(strs);
  sortResult(output2);
  EXPECT_EQ(output2, expected);
}

TEST_F(GroupAnagramsTest, TestCase2) {
  std::vector<std::string> strs = {""};
  std::vector<std::vector<std::string>> expected = {{""}};

  auto output = solution.groupAnagrams(strs);
  EXPECT_EQ(output, expected);

  auto output2 = solution.groupAnagrams2(strs);
  EXPECT_EQ(output2, expected);
}

TEST_F(GroupAnagramsTest, TestCase3) {
  std::vector<std::string> strs = {"a"};
  std::vector<std::vector<std::string>> expected = {{"a"}};

  auto output = solution.groupAnagrams(strs);
  EXPECT_EQ(output, expected);

  auto output2 = solution.groupAnagrams2(strs);
  EXPECT_EQ(output2, expected);
}