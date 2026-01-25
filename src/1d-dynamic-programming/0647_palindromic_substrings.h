#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  // Time: O(n^2) | Space: O(1)
  // Expand around center approach
  int countSubstrings(string s) {
    if (s.empty()) {
      return 0;
    }

    int res = 0;

    for (int i = 0; i < s.length(); i++) {
      // Check for odd-length palindromes (center is a single character)
      res += expandAroundCenter(s, i, i);
      // Check for even-length palindromes (center is between two characters)
      res += expandAroundCenter(s, i, i + 1);
    }

    return res;
  }

 private:
  int expandAroundCenter(const string& s, int left, int right) {
    int count = 0;
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      count++;
      left--;
      right++;
    }
    return count;
  }
};
