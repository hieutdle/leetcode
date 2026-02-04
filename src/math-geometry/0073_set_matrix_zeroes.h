#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(m * n) | Space: O(1)
  // Mark In Place
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    // Use first row and first column as markers
    bool first_row_zero = false;
    bool first_col_zero = false;

    // Check if first row has any zeros
    for (int j = 0; j < n; j++) {
      if (matrix[0][j] == 0) {
        first_row_zero = true;
        break;
      }
    }

    // Check if first column has any zeros
    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        first_col_zero = true;
        break;
      }
    }

    // Use first row and column to mark zeros for rest of matrix
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    // Set cells to zero based on markers
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    // Zero out first row if needed
    if (first_row_zero) {
      for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
      }
    }

    // Zero out first column if needed
    if (first_col_zero) {
      for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
  }

  // Time: O(m * n) | Space: O(m + n)
  // Vector Mark
  void setZeroes2(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<bool> rows(m, false);
    vector<bool> cols(n, false);

    // First pass to find all zeros
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          rows[i] = true;
          cols[j] = true;
        }
      }
    }

    // Second pass to set zeros
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (rows[i] || cols[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
