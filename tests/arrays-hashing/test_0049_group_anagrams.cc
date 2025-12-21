#include <gtest/gtest.h>
#include <algorithm>
#include "../../src/arrays-hashing/0049_group_anagrams.cc"

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

TEST_F(GroupAnagramsTest, BasicExample) {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto result = solution.groupAnagrams(strs);
  
  EXPECT_EQ(result.size(), 3);
  
  // Sort for comparison
  sortResult(result);
  
  // Check that anagrams are grouped together
  bool foundEatGroup = false, foundTanGroup = false, foundBatGroup = false;
  for (const auto& group : result) {
    if (group.size() == 3) {
      // Should be eat, tea, ate
      foundEatGroup = true;
    } else if (group.size() == 2) {
      // Should be tan, nat
      foundTanGroup = true;
    } else if (group.size() == 1 && group[0] == "bat") {
      foundBatGroup = true;
    }
  }
  
  EXPECT_TRUE(foundEatGroup);
  EXPECT_TRUE(foundTanGroup);
  EXPECT_TRUE(foundBatGroup);
}

TEST_F(GroupAnagramsTest, EmptyInput) {
  std::vector<std::string> strs = {};
  auto result = solution.groupAnagrams(strs);
  EXPECT_EQ(result.size(), 0);
}

TEST_F(GroupAnagramsTest, SingleString) {
  std::vector<std::string> strs = {"a"};
  auto result = solution.groupAnagrams(strs);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0].size(), 1);
  EXPECT_EQ(result[0][0], "a");
}

TEST_F(GroupAnagramsTest, NoAnagrams) {
  std::vector<std::string> strs = {"abc", "def", "ghi"};
  auto result = solution.groupAnagrams(strs);
  EXPECT_EQ(result.size(), 3);
}

TEST_F(GroupAnagramsTest, AllSameAnagrams) {
  std::vector<std::string> strs = {"abc", "bca", "cab"};
  auto result = solution.groupAnagrams(strs);
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0].size(), 3);
}

TEST_F(GroupAnagramsTest, Method2_BasicExample) {
  std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
  auto result = solution.groupAnagrams2(strs);
  
  EXPECT_EQ(result.size(), 3);
  sortResult(result);
  
  bool foundEatGroup = false, foundTanGroup = false, foundBatGroup = false;
  for (const auto& group : result) {
    if (group.size() == 3) {
      foundEatGroup = true;
    } else if (group.size() == 2) {
      foundTanGroup = true;
    } else if (group.size() == 1 && group[0] == "bat") {
      foundBatGroup = true;
    }
  }
  
  EXPECT_TRUE(foundEatGroup);
  EXPECT_TRUE(foundTanGroup);
  EXPECT_TRUE(foundBatGroup);
}
