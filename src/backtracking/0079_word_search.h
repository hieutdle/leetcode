#pragma once

#include <functional>
#include <string>
#include <vector>

using std::function;
using std::string;
using std::vector;

class Solution {
 public:
  // Time: O(m * n * 3^k) | Space: O(min(m*n, k))
  // where m is rows, n is cols, k is length of word
  // DFS + Backtracking
  bool exist(vector<vector<char>>& board, string word) {
    if (board.empty() || board[0].empty())
      return false;

    int m = board.size();
    int n = board[0].size();

    function<bool(int, int, int)> dfs = [&](int r, int c, int i) -> bool {
      // Base case: we've matched all characters
      if (i == word.length()) {
        return true;
      }

      // Out of bounds check
      if (r < 0 || r >= m || c < 0 || c >= n) {
        return false;
      }

      // Character doesn't match or cell already visited (marked as '#')
      if (board[r][c] != word[i]) {
        return false;
      }

      // Save the current character and mark as visited
      char temp = board[r][c];
      board[r][c] = '#';

      // Explore all 4 directions: up, down, left, right
      bool found = dfs(r + 1, c, i + 1) ||  // down
                   dfs(r - 1, c, i + 1) ||  // up
                   dfs(r, c + 1, i + 1) ||  // right
                   dfs(r, c - 1, i + 1);    // left

      // Backtrack: restore the character
      board[r][c] = temp;

      return found;
    };

    // Try starting from each cell
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (dfs(r, c, 0)) {
          return true;
        }
      }
    }

    return false;  // Not found
  }
};
