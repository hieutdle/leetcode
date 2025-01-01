#
# @lc app=leetcode id=242 lang=python3
#
# [242] Valid Anagram
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
