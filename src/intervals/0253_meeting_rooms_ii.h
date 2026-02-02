#pragma once

#include <algorithm>
#include <queue>
#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n log n) | Space: O(n)
  // Two pointers + Sorting
  int minMeetingRooms(vector<vector<int>>& intervals) {
    const int n = intervals.size();
    int res = 0;

    vector<int> starts;
    vector<int> ends;

    for (const vector<int>& interval : intervals) {
      starts.push_back(interval[0]);
      ends.push_back(interval[1]);
    }

    std::sort(starts.begin(), starts.end());
    std::sort(ends.begin(), ends.end());

    for (int i = 0, j = 0; i < n; ++i)
      // If a meeting starts before the earliest ending meeting ends,
      if (starts[i] < ends[j])
        // we need a new room
        ++res;
      else
        // Else, we can reuse a room (move the end pointer)
        ++j;

    return res;
  }

  // Time: O(n log n) | Space: O(n)
  // Difference Hash Map
  int minMeetingRooms2(vector<vector<int>>& intervals) {
    std::map<int, int> m;

    // Build the difference map
    for (const vector<int>& interval : intervals) {
      // At the start time, the number of rooms needed goes up by 1.
      m[interval[0]] += 1;
      // At the end time, the number of rooms needed goes down by 1.
      m[interval[1]] -= 1;
    }

    int res = 0;
    int curr = 0;

    // Traverse the time points in order
    for (const auto& [_, count] : m) {
      curr += count;              // Update current rooms needed
      res = std::max(res, curr);  // Update max rooms needed
    }

    return res;
  }

  // Time: O(n log n) | Space: O(n)
  // Heap to track end times of meetings
  int minMeetingRooms3(vector<vector<int>>& intervals) {
    // Sort intervals by start time
    std::sort(intervals.begin(), intervals.end());

    // Min-heap to track the end times of meetings
    std::priority_queue<int, vector<int>, std::greater<int>> min_heap;

    // Iterate through intervals
    for (const vector<int>& interval : intervals) {
      // If the earliest ending meeting finishes before or when the current starts,
      // we can reuse that room
      if (!min_heap.empty() && interval[0] >= min_heap.top()) {
        min_heap.pop();
      }
      // Add the current meeting's end time to the heap
      min_heap.push(interval[1]);
    }

    // The size of the heap is the number of rooms needed
    return min_heap.size();
  }
};
