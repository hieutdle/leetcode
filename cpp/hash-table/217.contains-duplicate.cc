/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms
 * Easy (62.55%)
 * Likes:    12465
 * Dislikes: 1315
 * Total Accepted:    4.7M
 * Total Submissions: 7.4M
 * Testcase Example:  '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice
 * in the array, and return false if every element is distinct.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [1,2,3,1]
 *
 * Output: true
 *
 * Explanation:
 *
 * The element 1 occurs at the indices 0 and 3.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [1,2,3,4]
 *
 * Output: false
 *
 * Explanation:
 *
 * All elements are distinct.
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 *
 * Output: true
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

#include <unordered_set>
#include <vector>

// @lc code=start
class Solution {
 public:
  bool containsDuplicate(std::vector<int>& nums) {
    // Early exit compare to the other solution
    std::unordered_set<int> s;
    for (const int num : nums)
      if (!s.insert(num).second) return true;

    return false;

    // Other solution

    // Still early exit
    // std::unordered_set<int> s;
    // for (int i = 0; i < nums.size(); i++) {
    //   if (s.find(nums[i]) != s.end()) {
    //     return true;
    //   }
    //   s.insert(nums[i]);
    // }
    // return false;

    // std::unordered_set<int> s(nums.begin(), nums.end());
    // return s.size() != nums.size();

    //  std::sort(nums.begin(), nums.end());
    //  for (int i = 1; i < nums.size(); ++i)
    //    if (nums[i] == nums[i - 1])
    //      return true;
    //  return false;
  }
};
// @lc code=end
