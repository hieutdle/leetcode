#pragma once

#include <climits>
#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class Solution {
 public:
  // Time: O(m + n) | Space: O(128)
  // Where m is the length of s and n is the length of t
  string minWindow(string s, string t) {
    if (s.empty() || t.empty() || s.size() < t.size()) {
      return "";
    }

    // Number of characters from t still needed to form a valid window.
    int required = t.length();
    // Left index of the best window found.
    int bestLeft = -1;
    // Length of the best window.
    int minLength = s.length() + 1;

    // Count characters in t
    unordered_map<char, int> count;
    for (char c : t) {
      ++count[c];
    }

    for (int l = 0, r = 0; r < s.length(); ++r) {
      // If the count is still ≥ 0, then this character is needed.
      // Reduce the required count.
      if (--count[s[r]] >= 0)
        --required;
      // The window contains all characters of t
      while (required == 0) {
        // Update best answer
        if (r - l + 1 < minLength) {
          bestLeft = l;
          minLength = r - l + 1;
        }
        // Try removing characters from the left
        // If it becomes positive, we just removed a required character
        // window invalid again
        if (++count[s[l++]] > 0)
          ++required;
      }
    }

    return bestLeft == -1 ? "" : s.substr(bestLeft, minLength);
  }
};
