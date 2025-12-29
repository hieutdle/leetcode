#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
 public:
  // Time: O(n) | Space: O(|Σ|) = O(26) = O(1)
  // Where Σ represents the character set (uppercase English letters)
  // Lazy Sliding Window
  int characterReplacement(string s, int k) {
    unordered_map<char, int> count;
    int n = s.size();
    int maxFreq = 0;  // Max frequency of any character in current window
    int l = 0;        // Left pointer of the window
    int res = 0;

    for (int r = 0; r < n; ++r) {
      ++count[s[r]];
      maxFreq = std::max(maxFreq, count[s[r]]);

      // Condition: window size - maxFreq <= k
      // Current window size: right - left + 1
      // Characters to replace: window size - max frequency
      // If replacements needed > k, shrink window from left
      if (r - l + 1 - maxFreq > k) {
        --count[s[l]];
        ++l;
      }
    }

    return n - l;
  }

  // Time: O(n) | Space: O(|Σ|) = O(26) = O(1)
  // Regular Sliding Window
  int characterReplacement2(string s, int k) {
    unordered_map<char, int> count;
    int n = s.size();
    int maxFreq = 0;  // Max frequency of any character in current window
    int l = 0;        // Left pointer of the window
    int res = 0;

    for (int r = 0; r < n; ++r) {
      ++count[s[r]];
      maxFreq = std::max(maxFreq, count[s[r]]);

      // Condition: window size - maxFreq <= k
      // Current window size: right - left + 1
      // Characters to replace: window size - max frequency
      while (r - l + 1 - maxFreq > k) {
        --count[s[l]];
        ++l;
      }

      res = std::max(res, r - l + 1);
    }

    return res;
  }
};
