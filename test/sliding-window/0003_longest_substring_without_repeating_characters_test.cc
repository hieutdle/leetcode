#include <gtest/gtest.h>

#include "0003_longest_substring_without_repeating_characters.h"

class LongestSubstringWithoutRepeatingCharactersTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(LongestSubstringWithoutRepeatingCharactersTest, TestCase1) {
  std::string s = "abcabcbb";
  int expected = 3;

  auto output = solution.lengthOfLongestSubstring(s);
  EXPECT_EQ(output, expected);
}

TEST_F(LongestSubstringWithoutRepeatingCharactersTest, TestCase2) {
  std::string s = "bbbbb";
  int expected = 1;

  auto output = solution.lengthOfLongestSubstring(s);
  EXPECT_EQ(output, expected);
}

TEST_F(LongestSubstringWithoutRepeatingCharactersTest, TestCase3) {
  std::string s = "pwwkew";
  int expected = 3;

  auto output = solution.lengthOfLongestSubstring(s);
  EXPECT_EQ(output, expected);
}