#include <algorithm>
#include <queue>
#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  // Bucket Sort
  vector<int> topKFrequent(vector<int>& nums, int k) {
        // Hashmap to store the number as a key, and store the frequency as a valueds
    std::unordered_map<int, int> m;
    vector<int> res;

    // Loop through the vector
    for (auto& num : nums) {
            // Store the number and the frequency in the map
      m[num]++;
    }

    // Create a vector of vector to store the frequency and the number
    // In the worst case, the frequency of the number is the same as the size of
    // the vector. And we have to store the 0 frequency number as well.
    vector<vector<int>> bucket(nums.size() + 1);

    for (auto& [num, freq] : m) {
      bucket[freq].push_back(num);
    }

    for (int i = bucket.size() - 1; i >= 0; i--) {
      for (const int& num : bucket[i]) {
        res.push_back(num);
        if (res.size() == k) {
          return res;
        }
      }
    }

    return res;
  }

  // Time: O(n log k) | Space: O(n)
  // Min Heap / Priority Queue
  vector<int> topKFrequent2(vector<int>& nums, int k) {
    std::unordered_map<int, int> m;
    vector<int> res;

    using pii = std::pair<int, int>;
    std::priority_queue<pii, vector<pii>, std::greater<pii>> pq;

    for (auto& num : nums) {
      m[num]++;
    }

    for (auto& [num, freq] : m) {
      pq.push({freq, num});
      if (pq.size() > k) {
        pq.pop();
      }
    }

    while (!pq.empty()) {
      res.push_back(pq.top().second);
      pq.pop();
    }

    return res;
  }

  // Time: O(n log n) | Space: O(n)
  // Reverse count
  vector<int> topKFrequent3(vector<int>& nums, int k) {
    std::unordered_map<int, int> m;
    vector<int> res;

    for (auto& num : nums) {
      m[num]++;
    }

    // Create pairs of {frequency, number} and sort
    vector<std::pair<int, int>> reverseCount;
    for (auto& [num, count] : m) {
      reverseCount.push_back({count, num});
    }

    sort(reverseCount.begin(), reverseCount.end());

    // Extract top k numbers
    for (int i = 0; i < k; i++) {
      res.push_back(reverseCount[i].second);
    }

    return res;
  }
};
