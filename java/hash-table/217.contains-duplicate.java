/*
 * @lc app=leetcode id=217 lang=java
 *
 * [217] Contains Duplicate
 *
 * https://leetcode.com/problems/contains-duplicate/description/
 *
 * algorithms Easy (62.58%) Likes: 12508 Dislikes: 1317 Total Accepted: 4.7M Total Submissions: 7.5M
 * Testcase Example: '[1,2,3,1]'
 *
 * Given an integer array nums, return true if any value appears at least twice in the array, and
 * return false if every element is distinct.
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
 * 1 <= nums.length <= 10^5 -10^9 <= nums[i] <= 10^9
 * 
 * 
 */

import java.util.Set;
import java.util.HashSet;
// import java.util.Arrays;

// @lc code=start
class Solution {
    public boolean containsDuplicate(int[] nums) {
        Set<Integer> s = new HashSet<>();

        for (int num : nums) {
            if (s.contains(num)) {
                return true;
            }
            s.add(num);
            // if (!s.add(num)) {
            //     return true;
            // }
        }
        return false;

        // Compare size
        // for (int num : nums) {
        //     s.add(num);
        // }
        // return s.size() != nums.length;

        // Check two numbers next to each other
        // Arrays.sort(nums);
        // for (int i = 0; i < nums.length - 1; i++) {
        //     if (nums[i] == nums[i + 1]) {
        //         return true;
        //     }
        // }
        // return false;
    }
}
// @lc code=end

