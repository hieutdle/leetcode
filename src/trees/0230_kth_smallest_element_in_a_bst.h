#pragma once

#include <stack>
#include <vector>

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
  // Time: O(n) | Space: O(n)
  // Recursive in-order traversal approach
  int kthSmallest(TreeNode* root, int k) {
    std::vector<int> res;
    inorderTraversal(root, res);
    return res[k - 1];
  }

  // Time: O(n) | Space: O(h)
  // Iterative in-order traversal approach
  int kthSmallest2(TreeNode* root, int k) {
    std::stack<TreeNode*> stack;
    TreeNode* curr = root;
    int count = 0;

    while (curr != nullptr || !stack.empty()) {
      // Go to the leftmost node
      while (curr != nullptr) {
        stack.push(curr);
        curr = curr->left;
      }

      // Process current node
      curr = stack.top();
      stack.pop();
      count++;

      if (count == k) {
        return curr->val;
      }

      // Move to right subtree
      curr = curr->right;
    }

    return -1;  // Should never reach here if k is valid
  }

  // Time: O(n) | Space: O(h)
  // Recursive in-order traversal with early termination
  int kthSmallest3(TreeNode* root, int k) {
    int res = -1;
    int rank = 0;
    inorderTraversalOptimized(root, k, rank, res);
    return res;
  }

 private:
  void inorderTraversal(TreeNode* node, std::vector<int>& res) {
    if (node == nullptr) {
      return;
    }

    inorderTraversal(node->left, res);
    res.push_back(node->val);
    inorderTraversal(node->right, res);
  }

  void inorderTraversalOptimized(TreeNode* node, int k, int& rank, int& res) {
    if (node == nullptr) {
      return;
    }

    inorderTraversalOptimized(node->left, k, rank, res);

    rank++;
    if (rank == k) {
      res = node->val;
      return;
    }

    inorderTraversalOptimized(node->right, k, rank, res);
  }
};
