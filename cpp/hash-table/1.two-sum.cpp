/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms
 * Easy (54.51%)
 * Likes:    59469
 * Dislikes: 2127
 * Total Accepted:    15.6M
 * Total Submissions: 28.6M
 * Testcase Example:  '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the
 * two numbers such that they add up to target.
 *
 * You may assume that each input would have exactly one solution, and you may
 * not use the same element twice.
 *
 * You can return the answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [3,2,4], target = 6
 * Output: [1,2]
 *
 *
 * Example 3:
 *
 *
 * Input: nums = [3,3], target = 6
 * Output: [0,1]
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= nums.length <= 10^4
 * -10^9 <= nums[i] <= 10^9
 * -10^9 <= target <= 10^9
 * Only one valid answer exists.
 *
 *
 *
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time
 * complexity?
 */

#include <unordered_map>
#include <vector>

// @lc code=start
class Solution {
 public:
  std::vector<int> twoSum(std::vector<int> &nums, int target) {
    // Hashmap to store the number as a key, and store the index as a value
    std::unordered_map<int, int> m;
    std::vector<int> result;

    // Loop through the vector
    for (int i = 0; i < nums.size(); i++) {
      // Check if the corresponding number is already in the map or not.
      if (m.find(target - nums[i]) != m.end()) {
        // Return the index of corresponding number and the index of the current
        // number
        result.push_back(m[target - nums[i]]);
        result.push_back(i);
        break;
      }
      // Store the number and the index in the map
      m.insert({nums[i], i});
    }

    // Brute force solution
    // for (int i = 0; i < nums.size(); i++) {
    //   for (int j = i + 1; j < nums.size(); j++) {
    //     if (nums[i] + nums[j] == target) {
    //       result.push_back(i);
    //       result.push_back(j);
    //       break;
    //     }
    //   }
    // }

    return result;
  }
};
// @lc code=end
