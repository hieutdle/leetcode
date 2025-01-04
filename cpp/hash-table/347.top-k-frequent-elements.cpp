/*
 * @lc app=leetcode id=347 lang=cpp
 *
 * [347] Top K Frequent Elements
 *
 * https://leetcode.com/problems/top-k-frequent-elements/description/
 *
 * algorithms
 * Medium (63.75%)
 * Likes:    17846
 * Dislikes: 692
 * Total Accepted:    2.5M
 * Total Submissions: 4M
 * Testcase Example:  '[1,1,1,2,2,3]\n2'
 *
 * Given an integer array nums and an integer k, return the k most frequent
 * elements. You may return the answer in any order.
 *
 *
 * Example 1:
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 * Input: nums = [1], k = 1
 * Output: [1]
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 * k is in the range [1, the number of unique elements in the array].
 * It is guaranteed that the answer is unique.
 *
 *
 *
 * Follow up: Your algorithm's time complexity must be better than O(n log n),
 * where n is the array's size.
 *
 */

#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<int> topKFrequent(vector<int> &nums, int k) {
    // Hashmap to store the number as a key, and store the frequency as a value
    unordered_map<int, int> m;
    vector<int> result;

    // Loop through the vector
    for (auto &num : nums) {
      // Store the number and the frequency in the map
      m[num]++;
    }

    // Approach 1: Min Heap / Priority Queue
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (auto &[num, freq] : m) {
      pq.push({freq, num});
      if (pq.size() > k) {
        pq.pop();
      }
    }

    while (!pq.empty()) {
      result.push_back(pq.top().second);
      pq.pop();
    }

    // Approach 2: Bucket Sort¶
    // Create a vector of vector to store the frequency and the number
    // In the worst case, the frequency of the number is the same as the size of
    // the vector. And we have to store the 0 frequency number as well.
    // vector<vector<int>> bucket(nums.size() + 1);

    // for (auto &[num, freq] : m) {
    //   bucket[freq].push_back(num);
    // }

    // for (int i = bucket.size() - 1; i >= 0; i--) {
    //   for (const int &num : bucket[i]) {
    //     result.push_back(num);
    //     if (result.size() == k) {
    //       return result;
    //     }
    //   }
    // }

    return result;
  }
};

// @lc code=end
