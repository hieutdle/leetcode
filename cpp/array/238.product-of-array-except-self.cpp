/*
 * @lc app=leetcode id=238 lang=cpp
 *
 * [238] Product of Array Except Self
 *
 * https://leetcode.com/problems/product-of-array-except-self/description/
 *
 * algorithms
 * Medium (67.10%)
 * Likes:    23405
 * Dislikes: 1479
 * Total Accepted:    3.2M
 * Total Submissions: 4.8M
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given an integer array nums, return an array answer such that answer[i] is
 * equal to the product of all the elements of nums except nums[i].
 *
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 * You must write an algorithm that runs in O(n) time and without using the
 * division operation.
 *
 *
 * Example 1:
 * Input: nums = [1,2,3,4]
 * Output: [24,12,8,6]
 * Example 2:
 * Input: nums = [-1,1,0,-3,3]
 * Output: [0,0,9,0,0]
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 *
 *
 * Follow up: Can you solve the problem in O(1) extra space complexity? (The
 * output array does not count as extra space for space complexity analysis.)
 *
 */

#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
  vector<int> productExceptSelf(vector<int> &nums) {
    int n = nums.size();
    vector<int> res(n, 1);

    // Go through the array and calculate the product of all the elements to the
    // left of the current element
    int left = 1;
    for (int i = 0; i < n; i++) {
      res[i] = left;
      left *= nums[i];
    }

    // Go through the array again and calculate the product of all the elements
    // to the right of the current element
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
      res[i] *= right;
      right *= nums[i];
    }

    // The result is the product of all the elements to the left and right of
    // the current element
    return res;
  }
};
// @lc code=end
