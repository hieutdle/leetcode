#
# @lc app=leetcode id=217 lang=python3
#
# [217] Contains Duplicate
#

# @lc code=start
from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        return len(nums) != len(set(nums))

    # Early exit
    # def containsDuplicate(self, nums: List[int]) -> bool:
    #     seen = set()
    #     for num in nums:
    #         if num in seen:
    #             return True
    #         seen.add(num)
    #     return False


# @lc code=end
