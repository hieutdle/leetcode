#
# @lc app=leetcode id=347 lang=python3
#
# [347] Top K Frequent Elements
#
# https://leetcode.com/problems/top-k-frequent-elements/description/
#
# algorithms
# Medium (63.75%)
# Likes:    17846
# Dislikes: 692
# Total Accepted:    2.5M
# Total Submissions: 4M
# Testcase Example:  '[1,1,1,2,2,3]\n2'
#
# Given an integer array nums and an integer k, return the k most frequent
# elements. You may return the answer in any order.
#
#
# Example 1:
# Input: nums = [1,1,1,2,2,3], k = 2
# Output: [1,2]
# Example 2:
# Input: nums = [1], k = 1
# Output: [1]
#
#
# Constraints:
#
#
# 1 <= nums.length <= 10^5
# -10^4 <= nums[i] <= 10^4
# k is in the range [1, the number of unique elements in the array].
# It is guaranteed that the answer is unique.
#
#
#
# Follow up: Your algorithm's time complexity must be better than O(n log n),
# where n is the array's size.
#
#

from typing import List
# from collections import Counter
# from heapq import heappush, heappop


# @lc code=start
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Bucket sort solution

        # Hash table to count the frequency of each number
        count = {}
        for num in nums:
            # Get the current count of the number (or 0) and increment it
            count[num] = count.get(num, 0) + 1

        # Store the numbers in a bucket where the index is the frequency
        # Initialize the bucket with empty lists
        bucket = [[] for _ in range(len(nums) + 1)]
        for num, freq in count.items():
            bucket[freq].append(num)

        res = []

        for i in range(len(bucket) - 1, 0, -1):
            for num in bucket[i]:
                res.append(num)
                if len(res) == k:
                    return res

        # Python doesn't check all control paths
        # return res

        # Short solution using most_common
        # cnt = Counter(nums)
        # return [x for x, _ in cnt.most_common(k)]

        # Min heap solution

        # # Count the frequency of each number in nums using Counter.
        # num_frequencies = Counter(nums)

        # # Initialize a min heap to keep track of top k elements.
        # min_heap = []

        # # Iterate over the number-frequency pairs.
        # for num, freq in num_frequencies.items():
        #     # Push a tuple of (frequency, number) onto the heap.
        #     # Python's heapq module creates a min-heap by default.
        #     heappush(min_heap, (freq, num))

        #     # If the heap size exceeds k, remove the smallest frequency element.
        #     if len(min_heap) > k:
        #         heappop(min_heap)

        # # Extract the top k frequent numbers by taking the second element of each tuple.
        # return [pair[1] for pair in min_heap]


# @lc code=end
