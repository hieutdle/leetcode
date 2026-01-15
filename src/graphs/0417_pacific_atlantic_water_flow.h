#pragma once

#include <functional>
#include <queue>
#include <vector>

using std::function;
using std::pair;
using std::queue;
using std::vector;

class Solution {
 public:
  // Instead of simulating water flow from each cell to the oceans,
  // we reverse the process: we start from the oceans and mark all cells

  // Time: O(m * n) | Space: O(m * n)
  // DFS approach from both oceans
  vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    if (heights.empty() || heights[0].empty()) {
      return {};
    }

    int m = heights.size();
    int n = heights[0].size();

    // Track cells that can reach each ocean
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    // Directions for neighbors (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // DFS to mark all reachable cells
    function<void(int, int, vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& visited) -> void {
      visited[r][c] = true;

      for (auto [x, y] : directions) {
        int new_r = r + x;
        int new_c = c + y;

        // Out of bounds check
        if (new_r < 0 || new_r >= m || new_c < 0 || new_c >= n) {
          continue;
        }

        // Skip if already visited or water can't flow (height is lower)
        if (visited[new_r][new_c] || heights[new_r][new_c] < heights[r][c]) {
          continue;
        }

        dfs(new_r, new_c, visited);
      }
    };

    // Start DFS from Pacific Ocean borders (top and left)
    for (int r = 0; r < m; ++r) {
      dfs(r, 0, pacific);  // left border
    }
    for (int c = 0; c < n; ++c) {
      dfs(0, c, pacific);  // top border
    }

    // Start DFS from Atlantic Ocean borders (bottom and right)
    for (int r = 0; r < m; ++r) {
      dfs(r, n - 1, atlantic);  // right border
    }
    for (int c = 0; c < n; ++c) {
      dfs(m - 1, c, atlantic);  // bottom border
    }

    // Find cells that can reach both oceans
    vector<vector<int>> res;
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (pacific[r][c] && atlantic[r][c]) {
          res.push_back({r, c});
        }
      }
    }

    return res;
  }

  // Time: O(m * n) | Space: O(m * n)
  // BFS approach from both oceans
  vector<vector<int>> pacificAtlantic2(vector<vector<int>>& heights) {
    if (heights.empty() || heights[0].empty()) {
      return {};
    }

    int m = heights.size();
    int n = heights[0].size();

    // Track cells that can reach each ocean
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));

    // Directions for neighbors (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // BFS to mark all reachable cells
    auto bfs = [&](queue<pair<int, int>>& q, vector<vector<bool>>& visited) -> void {
      while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        visited[r][c] = true;

        for (auto [dx, dy] : directions) {
          int new_r = r + dx;
          int new_c = c + dy;

          // Out of bounds check
          if (new_r < 0 || new_r >= m || new_c < 0 || new_c >= n) {
            continue;
          }

          // Skip if already visited or water can't flow (height is lower)
          if (visited[new_r][new_c] || heights[new_r][new_c] < heights[r][c]) {
            continue;
          }

          q.push({new_r, new_c});
        }
      }
    };

    // Initialize queues with ocean borders
    queue<pair<int, int>> pacific_queue;
    queue<pair<int, int>> atlantic_queue;

    for (int r = 0; r < m; ++r) {
      pacific_queue.push({r, 0});       // left border
      atlantic_queue.push({r, n - 1});  // right border
    }
    for (int c = 0; c < n; ++c) {
      pacific_queue.push({0, c});       // top border
      atlantic_queue.push({m - 1, c});  // bottom border
    }

    // Run BFS from both oceans
    bfs(pacific_queue, pacific);
    bfs(atlantic_queue, atlantic);

    // Find cells that can reach both oceans
    vector<vector<int>> res;
    for (int r = 0; r < m; ++r) {
      for (int c = 0; c < n; ++c) {
        if (pacific[r][c] && atlantic[r][c]) {
          res.push_back({r, c});
        }
      }
    }

    return res;
  }
};
