#include <gtest/gtest.h>

#include "0139_word_break.h"

class WordBreakTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(WordBreakTest, TestCase1) {
  std::string s = "leetcode";
  std::vector<std::string> wordDict = {"leet", "code"};
  bool expected = true;

  bool output = solution.wordBreak(s, wordDict);
  EXPECT_EQ(output, expected);

  bool output2 = solution.wordBreak2(s, wordDict);
  EXPECT_EQ(output2, expected);
}

TEST_F(WordBreakTest, TestCase2) {
  std::string s = "applepenapple";
  std::vector<std::string> wordDict = {"apple", "pen"};
  bool expected = true;

  bool output = solution.wordBreak(s, wordDict);
  EXPECT_EQ(output, expected);

  bool output2 = solution.wordBreak2(s, wordDict);
  EXPECT_EQ(output2, expected);
}

TEST_F(WordBreakTest, TestCase3) {
  std::string s = "catsandog";
  std::vector<std::string> wordDict = {"cats", "dog", "sand", "and", "cat"};
  bool expected = false;

  bool output = solution.wordBreak(s, wordDict);
  EXPECT_EQ(output, expected);

  bool output2 = solution.wordBreak2(s, wordDict);
  EXPECT_EQ(output2, expected);
}