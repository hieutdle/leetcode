#pragma once

#include <algorithm>
#include <vector>

using std::swap;
using std::vector;

class Solution {
 public:
  // Time: O(n^2) | Space: O(1)
  // Reverse
  void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Step 1: Flip the matrix horizontally (reverse rows)
    // Element at [i][j] moves to [n - i - 1][j]
    for (int i = 0; i < n / 2; ++i) {
      for (int j = 0; j < n; ++j) {
        swap(matrix[i][j], matrix[n - 1 - i][j]);
      }
    }

    // Step 2: Transpose the matrix (swap along the diagonal)
    // Element now at [n - i - 1][j] moves to [j][n - i - 1]
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }

  // Time: O(n^2) | Space: O(1)
  // Indexing
  void rotate2(vector<vector<int>>& matrix) {
    int l = 0;
    int r = matrix.size() - 1;
    while (l < r) {
      for (int i = 0; i < r - l; ++i) {
        int top = l;
        int bottom = r;

        // Save the top-left value
        int top_left = matrix[top][l + i];

        // Move bottom-left to top-left
        matrix[top][l + i] = matrix[bottom - i][l];

        // Move bottom-right to bottom-left
        matrix[bottom - i][l] = matrix[bottom][r - i];

        // Move top-right to bottom-right
        matrix[bottom][r - i] = matrix[top + i][r];

        // Move top-left (saved) to top-right
        matrix[top + i][r] = top_left;
      }
      ++l;
      --r;
    }
  }
};
