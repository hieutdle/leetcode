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
    std::unordered_set<int> s;
    for (const int num : nums)
      if (!s.insert(num).second)
        return true;

    return false;
  }
};
// @lc code=end
