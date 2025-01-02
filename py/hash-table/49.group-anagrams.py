#
# @lc app=leetcode id=49 lang=python3
#
# [49] Group Anagrams
#

from typing import List
from collections import defaultdict


# @lc code=start
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = defaultdict(list)
        for str in strs:
            # sort the word
            sorted_word = "".join(sorted(str))
            # Don't need to check if the sorted word is in the dictionary
            anagrams[sorted_word].append(str)
        return list(anagrams.values())

        # anagrams = {}
        # for str in strs:
        #     # sort the word
        #     sorted_word = "".join(sorted(str))
        #     # if the sorted word is not in the dictionary, add it
        #     if sorted_word not in anagrams:
        #         anagrams[sorted_word] = [str]
        #     else:
        #         anagrams[sorted_word].append(word)
        # return list(anagrams.values())


# @lc code=end
