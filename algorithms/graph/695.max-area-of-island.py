#
# @lc app=leetcode id=695 lang=python3
#
# [695] Max Area of Island
#
# https://leetcode.com/problems/max-area-of-island/description/
#
# algorithms
# Medium (72.71%)
# Likes:    10142
# Dislikes: 209
# Total Accepted:    984.8K
# Total Submissions: 1.4M
# Testcase Example:  '[[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]'
#
# You are given an m x n binary matrix grid. An island is a group of 1's
# (representing land) connected 4-directionally (horizontal or vertical.) You
# may assume all four edges of the grid are surrounded by water.
#
# The area of an island is the number of cells with a value 1 in the island.
#
# Return the maximum area of an island in grid. If there is no island, return
# 0.
#
#
# Example 1:
#
#
# Input: grid =
# [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
# Output: 6
# Explanation: The answer is not 11, because the island must be connected
# 4-directionally.
#
#
# Example 2:
#
#
# Input: grid = [[0,0,0,0,0,0,0,0]]
# Output: 0
#
#
#
# Constraints:
#
#
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 50
# grid[i][j] is either 0 or 1.
#
#
#


# @lc code=start
class Solution:
    def maxAreaOfIsland(self, grid: list[list[int]]) -> int:
        if not grid:
            return 0

        max_row, max_col = len(grid), len(grid[0])
        visited: set[tuple[int, int]] = set()

        ans = 0

        # BFS
        # def bfs(i: int, j: int) -> int:
        #     area = 1
        #     queue = [(i, j)]
        #     visited.add((i, j))

        #     while queue:
        #         x, y = queue.pop(0)

        #         directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        #         for dx, dy in directions:
        #             new_x, new_y = x + dx, y + dy
        #             if (
        #                 0 <= new_x < max_row
        #                 and 0 <= new_y < max_col
        #                 and grid[new_x][new_y] == 1
        #                 and (new_x, new_y) not in visited
        #             ):
        #                 queue.append((new_x, new_y))
        #                 visited.add((new_x, new_y))
        #                 area += 1
        #     return area

        # for x in range(max_row):
        #     for y in range(max_col):
        #         if grid[x][y] == 1 and (x, y) not in visited:
        #             ans = max(ans, bfs(x, y))

        # return ans

        # DFS
        def dfs(i: int, j: int) -> int:
            if (
                i < 0
                or j < 0
                or i >= max_row
                or j >= max_col
                or grid[i][j] == 0
                or (i, j) in visited
            ):
                return 0

            visited.add((i, j))

            return 1 + dfs(i + 1, j) + dfs(i - 1, j) + dfs(i, j + 1) + dfs(i, j - 1)

        for i in range(max_row):
            for j in range(max_col):
                if grid[i][j] == 1 and (i, j) not in visited:
                    ans = max(ans, dfs(i, j))

        return ans


# @lc code=end
