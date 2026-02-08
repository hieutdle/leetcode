#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  // Time: O(n * m) | Space: O(1)
  // where n = number of strings, m = length of shortest string
  string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) {
      return "";
    }

    int n = strs.size();
    string res;

    // Iterate character by character of the first string
    for (int i = 0; i < strs[0].length(); i++) {
      // Compare the current character with the corresponding character in other strings
      for (int j = 1; j < n; j++) {
        // If characters don't match or we reach the end of any string, return the result
        if (strs[0][i] != strs[j][i]) {
          return res;
        }
      }
      // If all strings have the same character at position i, add it to the result
      res += strs[0][i];
    }

    return res;
  }
};
