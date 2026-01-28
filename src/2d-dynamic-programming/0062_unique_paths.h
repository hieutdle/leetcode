#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(m * n) | Space: O(m * n)
  // 2D DP
  int uniquePaths(int m, int n) {
    // Create a 2D DP table to store the number of unique paths
    vector<vector<int>> dp(m, vector<int>(n));

    // Initialize first row - only one way to reach any cell in first row
    for (int i = 0; i < m; i++) {
      dp[i][0] = 1;
    }
    // Initialize first column - only one way to reach any cell in first column
    for (int j = 0; j < n; j++) {
      dp[0][j] = 1;
    }

    // Fill the DP table
    // dp[i][j] = number of ways to reach cell (i, j)
    // We can only reach (i, j) from (i-1, j) or (i, j-1)
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
      }
    }

    return dp[m - 1][n - 1];
  }

  // Time: O(m * n) | Space: O(n)
  // Space-optimized 1D DP
  int uniquePaths2(int m, int n) {
    // Only need to store one row at a time
    // Initialize first row with all 1s
    vector<int> dp(n, 1);

    // Process each row starting from the second row
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        // dp[j] (before update) represents the cell above
        // dp[j-1] represents the cell to the left
        // dp[j] represents current cell
        dp[j] = dp[j] + dp[j - 1];
      }
    }

    return dp[n - 1];
  }
};
