#pragma once
#include <string>

using std::string;

class Solution {
 public:
  // Time: O(n^2) | Space: O(1)
  // Expand around center approach
  string longestPalindrome(string s) {
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
