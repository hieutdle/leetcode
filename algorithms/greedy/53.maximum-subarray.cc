/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Medium (51.52%)
 * Likes:    34944
 * Dislikes: 1480
 * Total Accepted:    4.5M
 * Total Submissions: 8.8M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the subarray with the largest sum, and
 * return its sum.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
 * Output: 6
 * Explanation: The subarray [4,-1,2,1] has the largest sum 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1]
 * Output: 1
 * Explanation: The subarray [1] has the largest sum 1.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [5,4,-1,7,8]
 * Output: 23
 * Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 *
 * Follow up: If you have figured out the O(n) solution, try coding another
 * solution using the divide and conquer approach, which is more subtle.
 *
 */

#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int res = nums[0];
    int n = nums.size();

    // Greedy
    int sum = 0;
    for (int i = 0; i < n; i++) {
      // If sum is negative, we can start from the current element
      if (sum < 0) {
        sum = 0;
      }
      sum += nums[i];
      res = max(res, sum);
    }

    // Bruteforce approach
    // for (int i = 0; i < n; i++) {
    //   int sum = 0;
    //   for (int j = i; j < n; j++) {
    //     sum += nums[j];
    //     res = max(res, sum);
    //   }
    // }
    return res;
  }
};
// @lc code=end
