#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#
# https://leetcode.com/problems/group-anagrams/description/
#
# algorithms
# Medium (69.93%)
# Likes:    19895
# Dislikes: 658
# Total Accepted:    3.4M
# Total Submissions: 4.9M
# Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
#
# Given an array of strings strs, group the anagrams together. You can return
# the answer in any order.
#
#
# Example 1:
#
#
# Input: strs = ["eat","tea","tan","ate","nat","bat"]
#
# Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
#
# Explanation:
#
#
# There is no string in strs that can be rearranged to form "bat".
# The strings "nat" and "tan" are anagrams as they can be rearranged to form
# each other.
# The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to
# form each other.
#
#
#
# Example 2:
#
#
# Input: strs = [""]
#
# Output: [[""]]
#
#
# Example 3:
#
#
# Input: strs = ["a"]
#
# Output: [["a"]]
#
#
#
# Constraints:
#
#
# 1 <= strs.length <= 10^4
# 0 <= strs[i].length <= 100
# strs[i] consists of lowercase English letters.
#
#
#

from typing import List, Dict
from collections import defaultdict


# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        hash_map: Dict[str, List[str]] = defaultdict(list)
        for s in strs:
            # sort the word
            sorted_word = "".join(sorted(s))
            # Don't need to check if the sorted word is in the dictionary
            hash_map[sorted_word].append(s)
        return list(hash_map.values())

        # Normal dictionary
        # hash_map: Dict[str, List[str]] = {}
        # for s in strs:
        #     # sort the word
        #     sorted_word = "".join(sorted(s))
        #     # if the sorted word is not in the dictionary, add it
        #     if sorted_word not in hash_map:
        #         hash_map[sorted_word] = [s]
        #     else:
        #         hash_map[sorted_word].append(s)
        # return list(hash_map.values())


# @lc code=end
