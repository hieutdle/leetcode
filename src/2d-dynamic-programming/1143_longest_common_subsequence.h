#pragma once

#include <string>
#include <vector>

using std::max;
using std::string;
using std::vector;

class Solution {
 public:
  // Time: O(m * n) | Space: O(m * n)
  // 2D DP
  int longestCommonSubsequence(string text1, string text2) {
    int m = text1.length();
    int n = text2.length();

    // Create a 2D DP table to store LCS length
    // dp[i][j] represents the LCS length of text1[0...i-1] and text2[0...j-1]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill the DP table
    // For each character in text1
    for (int i = 1; i <= m; i++) {
      // For each character in text2
      for (int j = 1; j <= n; j++) {
        // If characters match, extend the LCS from previous diagonal
        if (text1[i - 1] == text2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1] + 1;
        } else {
          // If characters don't match, take the maximum from either:
          // - Excluding current character from text1 (dp[i-1][j])
          // - Excluding current character from text2 (dp[i][j-1])
          dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
    // Return the LCS length of the entire strings
    return dp[m][n];
  }
};
