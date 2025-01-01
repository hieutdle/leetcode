/*
 * @lc app=leetcode id=217 lang=cpp
 *
 * [217] Contains Duplicate
 */

#include <unordered_set>
#include <vector>

// @lc code=start
class Solution {
public:
  bool containsDuplicate(std::vector<int> &nums) {
    // Early exit compare to the other solution
    std::unordered_set<int> s;
    for (const int num : nums)
      if (!s.insert(num).second)
        return true;

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
