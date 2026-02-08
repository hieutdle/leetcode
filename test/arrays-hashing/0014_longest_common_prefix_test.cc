#include <gtest/gtest.h>

#include "0014_longest_common_prefix.h"

class LongestCommonPrefixTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(LongestCommonPrefixTest, TestCase1) {
  std::vector<std::string> strs = {"flower", "flow", "flight"};
  std::string expected = "fl";

  auto output = solution.longestCommonPrefix(strs);
  EXPECT_EQ(output, expected);
}

TEST_F(LongestCommonPrefixTest, TestCase2) {
  std::vector<std::string> strs = {"dog", "racecar", "car"};
  std::string expected = "";

  auto output = solution.longestCommonPrefix(strs);
  EXPECT_EQ(output, expected);
}