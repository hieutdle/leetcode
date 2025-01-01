/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 */

#include <string>
// @lc code=start
class Solution {
public:
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size())
      return false;

    int counts[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      counts[s[i] - 'a']++;
      counts[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
      if (counts[i] != 0)
        return false;

    return true;
  }
};
// @lc code=end
