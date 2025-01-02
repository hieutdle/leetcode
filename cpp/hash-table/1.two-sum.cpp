/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
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
