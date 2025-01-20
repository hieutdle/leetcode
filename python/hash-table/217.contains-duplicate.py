#
# @lc app=leetcode id=217 lang=python3
#
# [217] Contains Duplicate
#
# https://leetcode.com/problems/contains-duplicate/description/
#
# algorithms
# Easy (62.55%)
# Likes:    12465
# Dislikes: 1315
# Total Accepted:    4.7M
# Total Submissions: 7.4M
# Testcase Example:  '[1,2,3,1]'
#
# Given an integer array nums, return true if any value appears at least twice
# in the array, and return false if every element is distinct.
#
#
# Example 1:
#
#
# Input: nums = [1,2,3,1]
#
# Output: true
#
# Explanation:
#
# The element 1 occurs at the indices 0 and 3.
#
#
# Example 2:
#
#
# Input: nums = [1,2,3,4]
#
# Output: false
#
# Explanation:
#
# All elements are distinct.
#
#
# Example 3:
#
#
# Input: nums = [1,1,1,3,3,4,3,2,4,2]
#
# Output: true
#
#
#
# Constraints:
#
#
# 1 <= nums.length <= 10^5
# -10^9 <= nums[i] <= 10^9
#
#
#

# @lc code=start
from typing import List, Set


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Early exit
        s: Set[int] = set()
        for num in nums:
            if num in s:
                return True
            s.add(num)
        return False

        # Compare size
        # return len(set(nums)) != len(nums)

        # Check two numbers next to each other
        # nums.sort()
        # for i in range(len(nums) - 1):
        #     if nums[i] == nums[i + 1]:
        #         return True
        # return False


# @lc code=end
