/*
 * @lc app=leetcode id=1 lang=rust
 *
 * [1] Two Sum
 */

// @lc code=start
use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map = HashMap::new();
        for (i, &value) in nums.iter().enumerate() {
            let complement = target - value;
            if map.contains_key(&complement) {
                return vec![*map.get(&complement).unwrap() as i32, i as i32];
            }
            map.insert(value, i);
        }
        vec![]
    }
}
// @lc code=end
