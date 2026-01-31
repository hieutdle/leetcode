#pragma once

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  // Three phases: 
  // 1. Add intervals before newInterval
  // 2. Merge overlapping ones
  // 3. Add the rest
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int n = intervals.size();
    int i = 0;

    // Add intervals that end before newInterval starts (no overlap)
    while (i < n && intervals[i][1] < newInterval[0]) {
      res.push_back(intervals[i]);
      i++;
    }

    // Merge all intervals that overlap with newInterval
    while (i < n && intervals[i][0] <= newInterval[1]) {
      newInterval[0] = std::min(newInterval[0], intervals[i][0]);
      newInterval[1] = std::max(newInterval[1], intervals[i][1]);
      i++;
    }
    res.push_back(newInterval);

    // Add remaining intervals (start after merged interval)
    while (i < n) {
      res.push_back(intervals[i]);
      i++;
    }

    return res;
  }
};
