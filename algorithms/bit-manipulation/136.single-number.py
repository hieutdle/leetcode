#
# @lc app=leetcode id=136 lang=python3
#
# [136] Single Number
#
# https://leetcode.com/problems/single-number/description/
#
# algorithms
# Easy (74.88%)
# Likes:    17064
# Dislikes: 774
# Total Accepted:    3.3M
# Total Submissions: 4.5M
# Testcase Example:  '[2,2,1]'
#
# Given a non-empty array of integers nums, every element appears twice except
# for one. Find that single one.
#
# You must implement a solution with a linear runtime complexity and use only
# constant extra space.
#
#
# Example 1:
#
#
# Input: nums = [2,2,1]
#
# Output: 1
#
#
# Example 2:
#
#
# Input: nums = [4,1,2,1,2]
#
# Output: 4
#
#
# Example 3:
#
#
# Input: nums = [1]
#
# Output: 1
#
#
#
# Constraints:
#
#
# 1 <= nums.length <= 3 * 10^4
# -3 * 10^4 <= nums[i] <= 3 * 10^4
# Each element in the array appears twice except for one element which appears
# only once.
#
#
#

from typing import List


# @lc code=start
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        res = 0
        # XOR: same bits give 0 and different bits give 1
        # 0 ^ 0 = 0 (1)
        # 0 ^ 1 = 1 (2)
        # 1 ^ 0 = 1 (3)
        # 1 ^ 1 = 0 (4)
        # XOR of a number with itself is 0 (1, 4)
        # XOR of a number with 0 is the number itself (1, 3)
        # Even number of same numbers will cancel each other
        # The single one will be left
        for num in nums:
            res ^= num
        return res


# @lc code=end
