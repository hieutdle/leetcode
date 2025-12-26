#pragma once

#include <algorithm>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using std::greater;
using std::pair;
using std::priority_queue;
using std::unordered_map;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  // Bucket Sort
  vector<int> topKFrequent(vector<int>& nums, int k) {
    // Hashmap to store the number as a key, and store the frequency as a value
    unordered_map<int, int> m;
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
      bucket[freq].emplace_back(num);
    }

    for (int i = bucket.size() - 1; i >= 0; i--) {
      for (int num : bucket[i]) {
        res.emplace_back(num);
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
    unordered_map<int, int> m;
    vector<int> res;

    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for (auto& num : nums) {
      m[num]++;
    }

    for (auto& [num, freq] : m) {
      pq.emplace(freq, num);
      if (pq.size() > k) {
        pq.pop();
      }
    }

    while (!pq.empty()) {
      res.emplace_back(pq.top().second);
      pq.pop();
    }

    return res;
  }
};
