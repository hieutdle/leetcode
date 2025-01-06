/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 *
 * https://leetcode.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Medium (47.70%)
 * Likes:    20787
 * Dislikes: 1081
 * Total Accepted:    2.2M
 * Total Submissions: 4.7M
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * Given an unsorted array of integers nums, return the length of the longest
 * consecutive elements sequence.
 *
 * You must write an algorithm that runs in O(n) time.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [100,4,200,1,3,2]
 * Output: 4
 * Explanation: The longest consecutive elements sequence is [1, 2, 3, 4].
 * Therefore its length is 4.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [0,3,7,2,5,8,4,6,0,1]
 * Output: 9
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 *
 *
 */

#include <unordered_set>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
 public:
  int longestConsecutive(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }

    unordered_set<int> s(nums.begin(), nums.end());

    int res = 0;

    for (auto &num : s) {
      // Check if its the start of a sequence
      if (s.find(num - 1) == s.end()) {
        int length = 0;

        while (s.find(num + length) != s.end()) {
          length += 1;
        }

        res = max(res, length);
      }
    }

    return res;
  }
};
// @lc code=end
