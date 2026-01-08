#pragma once

#include <algorithm>
#include <functional>
#include <vector>

using std::function;
using std::vector;

class Solution {
 public:
  // Time: O(2^n * n) | Space: O(n)
  // Sorting + Pruning + Backtracking
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    // Current combination being built
    vector<int> curr;

    // Define recursive backtracking function using lambda
    // Parameters: i - current position in candidates array
    //             s - remaining target sum to achieve
    function<void(int, int)> dfs = [&](int i, int s) {
      if (s == 0) {
        res.push_back(curr);
        return;
      }

      // Pruning: remaining sum is less than smallest available candidate
      if (s < candidates[i]) {
        return;
      }

      // Try each candidate starting from current index
      // Allow reuse by starting from same index (j) in recursive call
      for (int j = i; j < candidates.size(); ++j) {
        // Choose current candidate
        curr.push_back(candidates[j]);
        // Explore with this choice (allow reuse by passing j, not j+1)
        dfs(j, s - candidates[j]);
        // Backtrack: remove current candidate for next iteration
        curr.pop_back();
      }
    };

    dfs(0, target);
    return res;
  }

  // Time: O(2^n * n) | Space: O(n)
  // Neetcode solution
  // Sorting + Pruning + Backtracking(Another Form)
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    // Current combination being built
    vector<int> curr;

    // Define recursive backtracking function using lambda
    // Parameters: i - current position in candidates array
    //             s - remaining target sum to achieve
    function<void(int, int)> dfs = [&](int i, int s) {
      if (s == 0) {
        res.push_back(curr);
        return;
      }

      // Pruning: remaining sum is less than smallest available candidate
      if (i >= candidates.size() || s < candidates[i]) {
        return;
      }
      // Choose current candidate
      curr.push_back(candidates[i]);
      // Explore with this choice (allow reuse by passing i)
      dfs(i, s - candidates[i]);
      // Backtrack: remove current candidate
      curr.pop_back();
      // Explore without choosing current candidate
      dfs(i + 1, s);
    };

    dfs(0, target);
    return res;
  }
};
