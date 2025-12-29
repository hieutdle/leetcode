#pragma once

#include <climits>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
 public:
  // Time: O(m + n) | Space: O(m + n)
  // Where m is the length of s and n is the length of t
  // Sliding Window
  string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.size() < t.size()) {
      return "";
    }

    // Count characters in t
    unordered_map<char, int> targetCount;
    for (char c : t) {
      ++targetCount[c];
    }

    // Track characters in current window
    unordered_map<char, int> windowCount;
    int required = targetCount.size();  // Number of unique chars in t
    int formed = 0;                     // Number of unique chars in window with desired frequency

    int l = 0;
    int minLen = INT_MAX;
    int minLeft = 0;

    for (int r = 0; r < s.size(); ++r) {
      char c = s[r];
      ++windowCount[c];

      // Check if frequency of current character matches desired count in t
      if (targetCount.contains(c) && windowCount[c] == targetCount[c]) {
        ++formed;
      }

      // Try to contract the window until it ceases to be 'desirable'
      while (l <= r && formed == required) {
        // Update result if this window is smaller
        if (r - l + 1 < minLen) {
          minLen = r - l + 1;
          minLeft = l;
        }

        // The character at the left pointer is no longer part of the window
        char leftChar = s[l];
        --windowCount[leftChar];
        if (targetCount.contains(leftChar) && windowCount[leftChar] < targetCount[leftChar]) {
          --formed;
        }
        ++l;
      }
    }

    return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
  }
};
