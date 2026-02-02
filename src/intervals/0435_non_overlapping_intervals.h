#pragma once

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n log n) | Space: O(1)
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    // Sort intervals by end time (greedy strategy)
    std::sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] < b[1];
    });

    int res = 0;
    int prev_end = intervals[0][1];

    // Iterate through sorted intervals
    for (int i = 1; i < intervals.size(); i++) {
      // If current interval starts before previous ends, there's an overlap
      // Note that prev_end ≤ intervals[i][1]
      // We remove the current interval, which comes later and also ends later
      if (intervals[i][0] < prev_end) {
        res++;  // Remove current interval
      } else {
        // No overlap, update the previous end
        prev_end = intervals[i][1];
      }
    }

    return res;
  }
};
