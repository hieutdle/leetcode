#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  // Dynamic Programming
  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') {
      return 0;
    }

    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;  // Empty string has 1 way to decode
    dp[1] = 1;  // First character (already checked it's not '0')

    for (int i = 2; i <= n; i++) {
      // Single digit decode: Check if current digit (s[i-1]) is valid (1-9)
      // If we have a valid single digit decode, the ways do not increase
      int oneDigit = s[i - 1] - '0';
      if (oneDigit >= 1 && oneDigit <= 9) {
        dp[i] = dp[i - 1];
      }

      // Two digit decode: Check if previous two digits (s[i-2] and s[i-1]) form a valid number (10-26)
      // If we have a valid two digit decode, the ways increase
      // We create a new branch here by adding dp[i-2] to dp[i]
      int twoDigits = (s[i - 2] - '0') * 10 + (s[i - 1] - '0');
      if (twoDigits >= 10 && twoDigits <= 26) {
        dp[i] += dp[i - 2];
      }
    }

    return dp[n];
  }
};
