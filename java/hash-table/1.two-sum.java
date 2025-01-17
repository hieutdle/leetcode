/*
 * @lc app=leetcode id=1 lang=java
 *
 * [1] Two Sum
 *
 * https://leetcode.com/problems/two-sum/description/
 *
 * algorithms Easy (54.58%) Likes: 59763 Dislikes: 2141 Total Accepted: 15.8M Total Submissions:
 * 28.9M Testcase Example: '[2,7,11,15]\n9'
 *
 * Given an array of integers nums and an integer target, return indices of the two numbers such
 * that they add up to target.
 * 
 * You may assume that each input would have exactly one solution, and you may not use the same
 * element twice.
 * 
 * You can return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,7,11,15], target = 9 Output: [0,1] Explanation: Because nums[0] + nums[1] == 9,
 * we return [0, 1].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,4], target = 6 Output: [1,2]
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: nums = [3,3], target = 6 Output: [0,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= nums.length <= 10^4 -10^9 <= nums[i] <= 10^9 -10^9 <= target <= 10^9 Only one valid answer
 * exists.
 * 
 * 
 * 
 * Follow-up: Can you come up with an algorithm that is less than O(n^2) time complexity?
 */

import java.util.Map;
import java.util.HashMap;

// @lc code=start

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] result = new int[2];

        // Hashmap to store the number as a key, and store the index as a value
        Map<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            // Check if the corresponding number is already in the map or not.
            if (map.containsKey(target - nums[i])) {
                // Return the index of corresponding number
                // and the index of the current number
                result[0] = map.get(target - nums[i]);
                result[1] = i;
                return result;
            }
            // Store the number and the index in the map
            map.put(nums[i], i);
        }

        // Brute force solution
        // for (int i = 0; i < nums.length; i++) {
        //     for (int j = i + 1; j < nums.length; j++) {
        //         if (nums[i] + nums[j] == target) {
        //             result[0] = i;
        //             result[1] = j;
        //             return result;
        //         }
        //     }
        // }

        return result;
    }
}
// @lc code=end
