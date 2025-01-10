#
# @lc app=leetcode id=200 lang=python3
#
# [200] Number of Islands
#
# https://leetcode.com/problems/number-of-islands/description/
#
# algorithms
# Medium (61.13%)
# Likes:    23355
# Dislikes: 545
# Total Accepted:    3.1M
# Total Submissions: 5.1M
# Testcase Example:  '[["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]]'
#
# Given an m x n 2D binary grid grid which represents a map of '1's (land) and
# '0's (water), return the number of islands.
#
# An island is surrounded by water and is formed by connecting adjacent lands
# horizontally or vertically. You may assume all four edges of the grid are all
# surrounded by water.
#
#
# Example 1:
#
#
# Input: grid = [
# ⁠ ["1","1","1","1","0"],
# ⁠ ["1","1","0","1","0"],
# ⁠ ["1","1","0","0","0"],
# ⁠ ["0","0","0","0","0"]
# ]
# Output: 1
#
#
# Example 2:
#
#
# Input: grid = [
# ⁠ ["1","1","0","0","0"],
# ⁠ ["1","1","0","0","0"],
# ⁠ ["0","0","1","0","0"],
# ⁠ ["0","0","0","1","1"]
# ]
# Output: 3
#
#
#
# Constraints:
#
#
# m == grid.length
# n == grid[i].length
# 1 <= m, n <= 300
# grid[i][j] is '0' or '1'.
#
#
#

from typing import List


# @lc code=start
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0

        max_row, max_col = len(grid), len(grid[0])
        visited = set()

        ans = 0

        # BFS
        def bfs(i: int, j: int) -> None:
            queue = [(i, j)]
            visited.add((i, j))

            while queue:
                x, y = queue.pop(0)

                directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
                for dx, dy in directions:
                    new_x, new_y = x + dx, y + dy
                    if (
                        0 <= new_x < max_row
                        and 0 <= new_y < max_col
                        and grid[new_x][new_y] == "1"
                        and (new_x, new_y) not in visited
                    ):
                        queue.append((new_x, new_y))
                        visited.add((new_x, new_y))

        for x in range(max_row):
            for y in range(max_col):
                if grid[x][y] == "1" and (x, y) not in visited:
                    bfs(x, y)
                    ans += 1

        return ans

        # DFS
        # def dfs(i: int, j: int) -> None:
        #     if (
        #         i < 0
        #         or j < 0
        #         or i >= max_row
        #         or j >= max_col
        #         or grid[i][j] == "0"
        #         or (i, j) in visited
        #     ):
        #         return

        #     visited.add((i, j))

        #     directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        #     for dx, dy in directions:
        #         new_i, new_j = i + dx, j + dy
        #         dfs(new_i, new_j)

        # for i in range(max_row):
        #     for j in range(max_col):
        #         if grid[i][j] == "1" and (i, j) not in visited:
        #             dfs(i, j)
        #             ans += 1

        # return ans


# @lc code=end
