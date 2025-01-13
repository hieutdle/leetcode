/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (72.71%)
 * Likes:    10142
 * Dislikes: 209
 * Total Accepted:    984.8K
 * Total Submissions: 1.4M
 * Testcase Example:
 * '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
 *
 * You are given an m x n binary matrix grid. An island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 *
 * The area of an island is the number of cells with a value 1 in the island.
 *
 * Return the maximum area of an island in grid. If there is no island, return
 * 0.
 *
 *
 * Example 1:
 *
 *
 * Input: grid =
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * Output: 6
 * Explanation: The answer is not 11, because the island must be connected
 * 4-directionally.
 *
 *
 * Example 2:
 *
 *
 * Input: grid = [[0,0,0,0,0,0,0,0]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 50
 * grid[i][j] is either 0 or 1.
 *
 *
 */

#include <algorithm>  // For std::max
// #include <queue>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) return 0;
    int max_row = grid.size();
    int max_col = grid[0].size();
    int res = 0;

    // Directions for neighbors (right, left, down, up)
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // BFS function
    // auto bfs = [&](int i, int j) {
    //   int area = 1;
    //   queue<pair<int, int>> q;
    //   q.push({i, j});
    //   grid[i][j] = '0';  // Mark as visited by changing to '0'

    //   while (!q.empty()) {
    //     auto [x, y] = q.front();
    //     q.pop();
    //     for (auto [dx, dy] : directions) {
    //       int new_x = x + dx, new_y = y + dy;
    //       if (new_x >= 0 && new_x < max_row && new_y >= 0 && new_y < max_col && grid[new_x][new_y] == 1) {
    //         q.push({new_x, new_y});
    //         grid[new_x][new_y] = '0';  // Mark as visited
    //         area++;
    //       }
    //     }
    //   }

    //   return area;
    // };

    // // Iterate over all cells for BFS
    // for (int x = 0; x < max_row; ++x) {
    //   for (int y = 0; y < max_col; ++y) {
    //     if (grid[x][y] == 1) {
    //       res = max(res, bfs(x, y));
    //     }
    //   }
    // }
    // return res;

    // DFS

    function<int(int, int)> dfs = [&](int i, int j) {
      if (i < 0 || j < 0 || i >= max_row || j >= max_col || grid[i][j] == 0) return 0;

      grid[i][j] = 0;  // Mark as visited

      return (1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1));
    };

    // Iterate over all cells for DFS
    for (int x = 0; x < max_row; ++x) {
      for (int y = 0; y < max_col; ++y) {
        if (grid[x][y] == 1) {
          res = max(res, dfs(x, y));
        }
      }
    }

    return res;
  }
};
// @lc code=end
