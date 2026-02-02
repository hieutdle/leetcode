#pragma once

#include <algorithm>
#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n log n) | Space: O(1)
  bool canAttendMeetings(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
      return true;
    }

    // Sort intervals by start time
    std::sort(intervals.begin(), intervals.end());

    // Check if any two consecutive meetings overlap
    for (int i = 1; i < intervals.size(); i++) {
      // If current meeting starts before previous ends, there's overlap
      if (intervals[i][0] < intervals[i - 1][1]) {
        return false;
      }
    }

    return true;
  }
};
