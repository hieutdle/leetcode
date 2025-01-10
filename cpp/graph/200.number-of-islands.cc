/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 *
 * https://leetcode.com/problems/number-of-islands/description/
 *
 * algorithms
 * Medium (61.13%)
 * Likes:    23355
 * Dislikes: 545
 * Total Accepted:    3.1M
 * Total Submissions: 5.1M
 * Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
 *
 * Given an m x n 2D binary grid grid which represents a map of '1's (land) and
 * '0's (water), return the number of islands.
 *
 * An island is surrounded by water and is formed by connecting adjacent lands
 * horizontally or vertically. You may assume all four edges of the grid are
 * all surrounded by water.
 *
 *
 * Example 1:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","1","1","0"],
 * ⁠ ["1","1","0","1","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","0","0","0"]
 * ]
 * Output: 1
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["1","1","0","0","0"],
 * ⁠ ["0","0","1","0","0"],
 * ⁠ ["0","0","0","1","1"]
 * ]
 * Output: 3
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] is '0' or '1'.
 *
 *
 */

// #include <functional>
#include <functional>
#include <queue>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int max_row = grid.size();
    int max_col = grid[0].size();
    int res = 0;

    // Directions for neighbors (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // BFS function
    auto bfs = [&](int i, int j) {
      queue<pair<int, int>> q;
      q.push({i, j});
      grid[i][j] = '0';  // Mark as visited by changing to '0'

      while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (auto [dx, dy] : directions) {
          int new_x = x + dx, new_y = y + dy;
          if (new_x >= 0 && new_x < max_row && new_y >= 0 && new_y < max_col && grid[new_x][new_y] == '1') {
            q.push({new_x, new_y});
            grid[new_x][new_y] = '0';  // Mark as visited
          }
        }
      }
    };

    // Iterate over all cells for BFS
    for (int x = 0; x < max_row; ++x) {
      for (int y = 0; y < max_col; ++y) {
        if (grid[x][y] == '1') {
          bfs(x, y);
          res++;
        }
      }
    }
    return res;

    // DFS

    // function<void(int, int)> dfs = [&](int i, int j) {
    //   if (i < 0 || j < 0 || i >= max_row || j >= max_col || grid[i][j] == '0') return;

    //   grid[i][j] = '0';  // Mark as visited
    //   for (auto [dx, dy] : directions) {
    //     dfs(i + dx, j + dy);
    //   }
    // };

    // // Iterate over all cells for DFS
    // for (int x = 0; x < max_row; ++x) {
    //   for (int y = 0; y < max_col; ++y) {
    //     if (grid[x][y] == '1') {
    //       dfs(x, y);
    //       res++;
    //     }
    //   }
    // }

    // return res;
  }
};
// @lc code=end
