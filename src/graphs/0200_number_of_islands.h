#pragma once

#include <functional>
#include <vector>
#include <utility>

using std::function;
using std::vector;
using std::pair;

class Solution {
 public:
  // Time: O(m * n) | Space: O(min(m, n))
  // DFS approach to mark visited cells
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int m = grid.size();
    int n = grid[0].size();
    int res = 0;

    // Directions for neighbors (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    // DFS to mark all connected land cells as visited
    function<void(int, int)> dfs = [&](int r, int c) -> void {
      // Out of bounds check
      if (r < 0 || r >= m || c < 0 || c >= n) {
        return;
      }
      
      // If it's water or already visited
      if (grid[r][c] == '0') {
        return;
      }

      // Mark as visited
      grid[r][c] = '0';

      for (auto [x, y] : directions) {
        dfs(r + x, c + y);
      }
    };

    // Iterate through each cell
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        // If we find a land cell, it's a new island
        if (grid[r][c] == '1') {
          ++res;
          // Mark all connected land cells as visited
          dfs(r, c);
        }
      }
    }

    return res;
  }
};
