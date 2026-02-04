#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(m * n) | Space: O(1)
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    if (matrix.empty()) {
      return res;
    }

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
      // Traverse right along top row
      for (int j = left; j <= right; j++) {
        res.push_back(matrix[top][j]);
      }
      top++;

      // Traverse down along right column
      for (int i = top; i <= bottom; i++) {
        res.push_back(matrix[i][right]);
      }
      right--;

      // Traverse left along bottom row (if still valid)
      if (top <= bottom) {
        for (int j = right; j >= left; j--) {
          res.push_back(matrix[bottom][j]);
        }
        bottom--;
      }

      // Traverse up along left column (if still valid)
      if (left <= right) {
        for (int i = bottom; i >= top; i--) {
          res.push_back(matrix[i][left]);
        }
        left++;
      }
    }

    return res;
  }
};
