#
# @lc app=leetcode id=2185 lang=python3
#
# [2185] Counting Words With a Given Prefix
#
# https://leetcode.com/problems/counting-words-with-a-given-prefix/description/
#
# algorithms
# Easy (78.75%)
# Likes:    1015
# Dislikes: 32
# Total Accepted:    235.9K
# Total Submissions: 280.1K
# Testcase Example:  '["pay","attention","practice","attend"]\n"at"'
#
# You are given an array of strings words and a string pref.
#
# Return the number of strings in words that contain pref as a prefix.
#
# A prefix of a string s is any leading contiguous substring of s.
#
#
# Example 1:
#
#
# Input: words = ["pay","attention","practice","attend"], pref = "at"
# Output: 2
# Explanation: The 2 strings that contain "at" as a prefix are: "attention" and
# "attend".
#
#
# Example 2:
#
#
# Input: words = ["leetcode","win","loops","success"], pref = "code"
# Output: 0
# Explanation: There are no strings that contain "code" as a prefix.
#
#
#
# Constraints:
#
#
# 1 <= words.length <= 100
# 1 <= words[i].length, pref.length <= 100
# words[i] and pref consist of lowercase English letters.
#
#
#

from typing import List

# @lc code=start


class TrieNode:
    def __init__(self):
        self.children = {}
        self.count = 0


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        node = self.root

        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()

            node = node.children[char]
            # Count the number of times this point is reached
            node.count += 1

    def count(self, pref: str) -> int:
        node = self.root

        for char in pref:
            if char not in node.children:
                return 0

            node = node.children[char]

        return node.count


class Solution:
    def prefixCount(self, words: List[str], pref: str) -> int:
        # Trie
        trie = Trie()

        for word in words:
            trie.insert(word)

        return trie.count(pref)

        # Brute Force
        # ans = 0
        # n = len(pref)

        # for word in words:
        #     if len(word) < n:
        #         continue

        #     for i in range(n):
        #         if word[i] != pref[i]:
        #             break

        #         if i == n - 1:
        #             ans += 1

        # return ans

        # Short Python
        # return sum(w.startswith(pref) for w in words)


# @lc code=end
