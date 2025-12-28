#pragma once

#include <string>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(|Σ|) = O(128) = O(1)
  // Where Σ represents the character set, and the size of Σ is 128
  // Sliding Window
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> charSet;
    int n = s.size();
    int res = 0;

    for (int l = 0, r = 0; r < n; ++r) {
      // Shrink window from left while duplicate exists
      while (charSet.contains(s[r])) {
        // Remove leftmost character and move left pointer
        charSet.erase(s[l]);
        ++l;
      }
      charSet.insert(s[r]);
      res = std::max(res, r - l + 1);
    }

    return res;
  }

  // Time: O(n) | Space: O(|Σ|)
  // Last Seen
  int lengthOfLongestSubstring2(string s) {
    int n = s.size();
    int res = 0;
    vector<int> lastSeen(128, -1);

    for (int l = 0, r = 0; r < n; ++r) {
      // Update left pointer to the max of current left or last seen index + 1
      l = std::max(l, lastSeen[s[r]] + 1);
      lastSeen[s[r]] = r;  // Update last seen index
      res = std::max(res, r - l + 1);
    }

    return res;
  }
};
