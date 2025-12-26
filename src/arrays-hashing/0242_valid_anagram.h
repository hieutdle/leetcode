#pragma once

#include <string>

using std::string;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  bool isAnagram(string s, string t) {
    if (s.size() != t.size())
      return false;

    int counts[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      counts[s[i] - 'a']++;
      counts[t[i] - 'a']--;
    }

    for (auto& count : counts)
      if (count != 0)
        return false;

    return true;
  }
};
