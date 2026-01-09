#include <gtest/gtest.h>

#include <vector>

#include "0079_word_search.h"

class WordSearchTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(WordSearchTest, TestCase1) {
  vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCCED";
  EXPECT_TRUE(solution.exist(board, word));
}

TEST_F(WordSearchTest, TestCase2) {
  vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "SEE";
  EXPECT_TRUE(solution.exist(board, word));
}

TEST_F(WordSearchTest, TestCase3) {
  vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
  string word = "ABCB";
  EXPECT_FALSE(solution.exist(board, word));
}