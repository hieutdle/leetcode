#
# @lc app=leetcode id=1408 lang=python3
#
# [1408] String Matching in an Array
#
# https://leetcode.com/problems/string-matching-in-an-array/description/
#
# algorithms
# Easy (64.26%)
# Likes:    1158
# Dislikes: 104
# Total Accepted:    165.4K
# Total Submissions: 244.4K
# Testcase Example:  '["mass","as","hero","superhero"]'
#
# Given an array of string words, return all strings in words that is a
# substring of another word. You can return the answer in any order.
#
# A substring is a contiguous sequence of characters within a string
#
#
# Example 1:
#
#
# Input: words = ["mass","as","hero","superhero"]
# Output: ["as","hero"]
# Explanation: "as" is substring of "mass" and "hero" is substring of
# "superhero".
# ["hero","as"] is also a valid answer.
#
#
# Example 2:
#
#
# Input: words = ["leetcode","et","code"]
# Output: ["et","code"]
# Explanation: "et", "code" are substring of "leetcode".
#
#
# Example 3:
#
#
# Input: words = ["blue","green","bu"]
# Output: []
# Explanation: No string of words is substring of another string.
#
#
#
# Constraints:
#
#
# 1 <= words.length <= 100
# 1 <= words[i].length <= 30
# words[i] contains only lowercase English letters.
# All the strings of words are unique.
#
#
#

from typing import List


# @lc code=start
class Solution:
    def stringMatching(self, words: List[str]) -> List[str]:
        result: List[str] = []

        # Bruteforce solution
        for i in range(len(words)):
            for j in range(len(words)):
                if i != j and words[i] in words[j]:
                    result.append(words[i])
                    break

        # Can not use Trie
        # We can check for ma in mass, but can not check for as in mass

        # We can implement a search method that checks if a node has children,
        # but this doesn't handle the fact that substrings can appear anywhere within the string.

        return result


# @lc code=end
