#pragma once

#include <functional>
#include <queue>
#include <utility>
#include <vector>

using std::function;
using std::pair;
using std::queue;
using std::vector;

class Solution {
 public:
  // Time: O(m * n) | Space: O(m, n)
  // DFS
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

  // Time: O(m * n) | Space: O(m, n)
  // BFS
  int numIslands2(vector<vector<char>>& grid) {
    if (grid.empty() || grid[0].empty()) {
      return 0;
    }

    int m = grid.size();
    int n = grid[0].size();
    int res = 0;

    // Directions for neighbors (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // BFS to mark all connected land cells as visited
    function<void(int, int)> bfs = [&](int r, int c) -> void {
      queue<pair<int, int>> q;
      q.push({r, c});
      grid[r][c] = '0';  // Mark as visited

      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (auto [dx, dy] : directions) {
          int new_x = x + dx;
          int new_y = y + dy;

          // Out of bounds check
          if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) {
            continue;
          }

          // If it's land, mark as visited and add to queue
          if (grid[new_x][new_y] == '1') {
            grid[new_x][new_y] = '0';
            q.push({new_x, new_y});
          }
        }
      }
    };

    // Iterate through each cell
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        // If we find a land cell, it's a new island
        if (grid[r][c] == '1') {
          ++res;
          // Mark all connected land cells as visited
          bfs(r, c);
        }
      }
    }

    return res;
  }
};
