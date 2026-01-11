#include <gtest/gtest.h>

#include <algorithm>
#include <vector>

#include "0212_word_search_ii.h"

class WordSearchIITest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(WordSearchIITest, TestCase1) {
  vector<vector<char>> board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
  vector<string> words = {"oath", "pea", "eat", "rain"};
  vector<string> expected = {"eat", "oath"};

  vector<string> output = solution.findWords(board, words);
  // Sort both vectors for comparison
  std::sort(output.begin(), output.end());
  std::sort(expected.begin(), expected.end());
  EXPECT_EQ(output, expected);
}

TEST_F(WordSearchIITest, TestCase2) {
  vector<vector<char>> board = {{'a', 'b'}, {'c', 'd'}};
  vector<string> words = {"abcb"};
  vector<string> expected = {};

  vector<string> output = solution.findWords(board, words);
  EXPECT_EQ(output, expected);
}