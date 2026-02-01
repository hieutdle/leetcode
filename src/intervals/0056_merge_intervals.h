#pragma once

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n log n) | Space: O(n)
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    // Sort intervals by start time
    sort(intervals.begin(), intervals.end());

    vector<vector<int>> res;
    res.push_back(intervals[0]);

    // Iterate through sorted intervals and merge overlapping ones
    for (int i = 1; i < intervals.size(); i++) {
      // If current interval overlaps with the last merged interval
      if (intervals[i][0] <= res.back()[1]) {
        // Merge by extending the end time
        res.back()[1] = std::max(res.back()[1], intervals[i][1]);
      } else {
        // No overlap, add current interval to result
        res.push_back(intervals[i]);
      }
    }

    return res;
  }
};
