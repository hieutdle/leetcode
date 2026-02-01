#pragma once

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;

    for (auto& interval : intervals) {
      // Case 1: If new interval is before the current interval
      // After adding new interval
      // keep updating new interval to add the remaining intervals
      if (newInterval[1] < interval[0]) {
        res.push_back(newInterval);
        newInterval = interval;
      }  // Case 2: If new interval is after the current interval
      else if (newInterval[0] > interval[1]) {
        res.push_back(interval);
      }  // Case 3: Overlapping interval
      else {
        newInterval[0] = std::min(newInterval[0], interval[0]);
        newInterval[1] = std::max(newInterval[1], interval[1]);
      }
    }
    res.push_back(newInterval);

    return res;
  }
};
