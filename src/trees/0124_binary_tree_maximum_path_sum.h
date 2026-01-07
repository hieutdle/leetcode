#pragma once

#include <algorithm>
#include <climits>
#include <functional>

using std::function;
using std::max;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
 public:
  // Time: O(n) | Space: O(h)
  // DFS recursion
  int maxPathSum(TreeNode* root) {
    // constraints: node values are in range [-1000, 1000]
    int res = -1001;

    // Returns the maximum path sum starting from the current node and going down
    function<int(TreeNode*)> dfs = [&](TreeNode* root) {
      if (root == nullptr) {
        return 0;
      }

      // Recursively get the maximum path sum from left and right subtrees
      // Use max(0, ...) to ignore negative paths
      int left = max(0, dfs(root->left));
      int right = max(0, dfs(root->right));

      // Calculate the maximum path sum that passes through the current node
      // This path includes both left and right subtrees plus the current node value
      res = max(res, left + right + root->val);

      // Return the maximum path sum starting from this node going down
      // We can only choose either left or right path (not both) when extending upward
      return root->val + max(left, right);
    };

    dfs(root);

    return res;
  }
};
