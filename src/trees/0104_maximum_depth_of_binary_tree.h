#pragma once

#include <algorithm>
#include <queue>

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
  // Time: O(n) | Space: O(1)
  // Recursive DFS approach
  int maxDepth(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }

  // Time: O(n) | Space: O(w)
  // where n is the number of nodes, w is max width of tree
  // Iterative BFS approach
  int maxDepth2(TreeNode* root) {
    if (root == nullptr) {
      return 0;
    }

    std::queue<TreeNode*> queue;
    queue.push(root);
    int depth = 0;

    while (!queue.empty()) {
      int levelSize = queue.size();
      depth++;

      // Process all nodes at current level
      for (int i = 0; i < levelSize; i++) {
        TreeNode* node = queue.front();
        queue.pop();

        if (node->left != nullptr) {
          queue.push(node->left);
        }
        if (node->right != nullptr) {
          queue.push(node->right);
        }
      }
    }

    return depth;
  }
};
