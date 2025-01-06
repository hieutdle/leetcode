/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (65.78%)
 * Likes:    12593
 * Dislikes: 418
 * Total Accepted:    4.3M
 * Total Submissions: 6.5M
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "anagram", t = "nagaram"
 *
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: s = "rat", t = "car"
 *
 * Output: false
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 *
 */

#include <string>

// @lc code=start
class Solution {
 public:
  bool isAnagram(std::string s, std::string t) {
    if (s.size() != t.size()) return false;

    int counts[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      counts[s[i] - 'a']++;
      counts[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
      if (counts[i] != 0) return false;

    return true;
  }
};
// @lc code=end
