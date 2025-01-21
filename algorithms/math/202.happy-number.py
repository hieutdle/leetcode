#
# @lc app=leetcode id=202 lang=python3
#
# [202] Happy Number
#
# https://leetcode.com/problems/happy-number/description/
#
# algorithms
# Easy (57.28%)
# Likes:    10819
# Dislikes: 1536
# Total Accepted:    1.7M
# Total Submissions: 3M
# Testcase Example:  '19'
#
# Write an algorithm to determine if a number n is happy.
#
# A happy number is a number defined by the following process:
#
#
# Starting with any positive integer, replace the number by the sum of the
# squares of its digits.
# Repeat the process until the number equals 1 (where it will stay), or it
# loops endlessly in a cycle which does not include 1.
# Those numbers for which this process ends in 1 are happy.
#
#
# Return true if n is a happy number, and false if not.
#
#
# Example 1:
#
#
# Input: n = 19
# Output: true
# Explanation:
# 1^2 + 9^2 = 82
# 8^2 + 2^2 = 68
# 6^2 + 8^2 = 100
# 1^2 + 0^2 + 0^2 = 1
#
#
# Example 2:
#
#
# Input: n = 2
# Output: false
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


# @lc code=start
class Solution:
    def isHappy(self, n: int) -> bool:
        # Floyd's Cycle Detection Algorithm

        slow = n
        fast = self.sumOfSquare(n)

        while slow != fast:
            slow = self.sumOfSquare(slow)
            fast = self.sumOfSquare(self.sumOfSquare(fast))

        return slow == 1

        # Extra storage

        # visited: set[int] = set()

        # #  Check if we ever visit a number twice
        # while n not in visited:
        #     visited.add(n)
        #     n = self.sumOfSquare(n)
        #     if n == 1:
        #         return True

        # return False

    def sumOfSquare(self, n: int) -> int:
        output = 0
        # 19 -> 1^2 + 9^2 = 82
        # 19 % 10 = 9, 19 // 10 = 1
        # 1 % 10 = 1, 1 // 10 = 0 -> finish
        while n > 0:
            output += (n % 10) ** 2
            n //= 10  # next digit
        return output


# @lc code=end
