#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  // Time: O(n^2) | Space: O(n^2)
  // DP approach
  string longestPalindrome(string s) {
    if (s.empty()) {
      return "";
    }

    int n = s.size();

    // dp[i][j] represents whether substring s[i...j] is a palindrome
    // Initialize all to true (single characters and empty strings are palindromes)
    vector<vector<bool>> dp(n, vector<bool>(n, true));

    // Variables to track the longest palindrome found
    int start = 0;  // Starting index of longest palindrome
    int res = 1;    // Length of longest palindrome (at least 1)

    // Build the DP table bottom-up
    // Start from the second-to-last row and move upward
    for (int i = n - 2; i >= 0; --i) {
      // For each starting position i, check all ending positions j > i
      for (int j = i + 1; j < n; ++j) {
        // Initially assume substring s[i...j] is not a palindrome
        dp[i][j] = false;

        // Check if first and last characters match
        if (s[i] == s[j]) {
          // If they match, the substring is a palindrome if:
          // - The inner substring s[i+1...j-1] is also a palindrome
          // - For substrings of length 2, this is automatically true

          // When you’re at dp[i][j] (substring s[i..j]),
          // you don’t need to check the inner substring again
          // you just reuse the previously computed value (s[i+1..j-1])

          // i = 1, j = 3 → "aba"
          // s[1] == s[3] → true
          // Check inner: dp[2][2] → "b" → true
          // So dp[1][3] = true
          // we never recomputed "b", we reused dp[2][2]

          //   j 0 1 2 3 4
          // i ┌──────────────────
          // 0 │ T ✗ ★ ✗ ✗
          // 1 │   T ✗[★] ✗
          // 2 │    [T]✗ ✗
          // 3 │       T ✗
          // 4 │         T
          dp[i][j] = dp[i + 1][j - 1];

          // Update longest palindrome if current one is longer
          if (dp[i][j] && res < j - i + 1) {
            res = j - i + 1;
            start = i;
          }
        }
      }
    }

    // Return the longest palindromic substring
    return s.substr(start, res);
  }

  // Time: O(n^2) | Space: O(1)
  // Expand around center approach
  string longestPalindrome2(string s) {
    if (s.empty()) {
      return "";
    }

    int start = 0;
    int res = 0;

    for (int i = 0; i < s.length(); i++) {
      // Check for odd-length palindromes (center is a single character)
      int len1 = expandAroundCenter(s, i, i);
      // Check for even-length palindromes (center is two characters)
      int len2 = expandAroundCenter(s, i, i + 1);
      int len = std::max(len1, len2);

      if (len > res) {
        res = len;
        start = i - (len - 1) / 2;
      }
    }

    return s.substr(start, res);
  }

 private:
  int expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      left--;
      right++;
    }
    // Return the length of the palindrome
    return right - left - 1;
  }
};
