#
# @lc app=leetcode id=191 lang=python3
#
# [191] Number of 1 Bits
#
# https://leetcode.com/problems/number-of-1-bits/description/
#
# algorithms
# Easy (73.27%)
# Likes:    6699
# Dislikes: 1345
# Total Accepted:    1.7M
# Total Submissions: 2.3M
# Testcase Example:  '11'
#
# Given a positive integer n, write a function that returns the number of set
# bits in its binary representation (also known as the Hamming weight).
#
#
# Example 1:
#
#
# Input: n = 11
#
# Output: 3
#
# Explanation:
#
# The input binary string 1011 has a total of three set bits.
#
#
# Example 2:
#
#
# Input: n = 128
#
# Output: 1
#
# Explanation:
#
# The input binary string 10000000 has a total of one set bit.
#
#
# Example 3:
#
#
# Input: n = 2147483645
#
# Output: 30
#
# Explanation:
#
# The input binary string 1111111111111111111111111111101 has a total of thirty
# set bits.
#
#
#
# Constraints:
#
#
# 1 <= n <= 2^31 - 1
#
#
#
# Follow up: If this function is called many times, how would you optimize it?
#


class Solution:
    def hammingWeight(self, n: int) -> int:
        ans = 0

        # https://www.youtube.com/watch?v=5Km3utixwZs&t=80s&ab_channel=NeetCode

        # n = n & (n - 1)
        #   100001
        # & 100000
        #   100000 (gets rid of the 1 if it is on the left)
        # & 011111 introduces more 1s but gets rid of the right 1
        #   000000 (we know all the bits to the right are now only 0s)
        #   and 0 & 1 cancels out
        while n:
            n = n & (n - 1)
            ans += 1

        # Modulo and shift
        # We have to check all the bits
        # while n:
        #     # 1011 % 2 = 1
        #     ans += n % 2
        #     # 1011 -> 101 -> 10 -> 1 -> 0
        #     n = n >> 1

        return ans


# @lc code=end
