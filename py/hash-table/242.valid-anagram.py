#
# @lc app=leetcode id=242 lang=python3
#
# [242] Valid Anagram
#
# https://leetcode.com/problems/valid-anagram/description/
#
# algorithms
# Easy (65.78%)
# Likes:    12593
# Dislikes: 418
# Total Accepted:    4.3M
# Total Submissions: 6.5M
# Testcase Example:  '"anagram"\n"nagaram"'
#
# Given two strings s and t, return true if t is an anagram of s, and false
# otherwise.
#
#
# Example 1:
#
#
# Input: s = "anagram", t = "nagaram"
#
# Output: true
#
#
# Example 2:
#
#
# Input: s = "rat", t = "car"
#
# Output: false
#
#
#
# Constraints:
#
#
# 1 <= s.length, t.length <= 5 * 10^4
# s and t consist of lowercase English letters.
#
#
#
# Follow up: What if the inputs contain Unicode characters? How would you adapt
# your solution to such a case?
#
#

from collections import Counter


# @lc code=start
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count = Counter(s)
        for c in t:
            if count[c] == 0:
                return False
            count[c] -= 1

        return True
        # return sorted(s) == sorted(t)


# @lc code=end
