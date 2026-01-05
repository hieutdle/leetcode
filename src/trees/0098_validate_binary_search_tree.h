#pragma once

#include <climits>
#include <functional>

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
  // Recursive approach with valid range tracking
  // Top-down
  bool isValidBST(TreeNode* root) {
    return validate(root, nullptr, nullptr);
  }

  // Time : O(n) | Space: O(n)
  // In-order traversal approach
  // Left -> Node -> Right
  bool isValidBST2(TreeNode* root) {
    // Keep track of the previous node in in-order traversal
    TreeNode* prev = nullptr;

    // Lambda function for in-order traversal validation
    // In a valid BST, in-order traversal yields values in strictly ascending order
    std::function<bool(TreeNode*)> inOrderValidate = [&](TreeNode* curr) -> bool {
      // Base case: empty node is valid
      if (!curr) {
        return true;
      }

      // Recursively validate left subtree
      if (!inOrderValidate(curr->left)) {
        return false;
      }

      // Check BST property: current node value must be greater than previous node value
      if (prev && prev->val >= curr->val) {
        return false;
      }

      // Update previous node for next comparison
      prev = curr;

      // Recursively validate right subtree
      return inOrderValidate(curr->right);
    };

    // Start validation from root
    return inOrderValidate(root);
  }

 private:
  bool validate(TreeNode* node, TreeNode* left, TreeNode* right) {
    if (node == nullptr) {
      return true;
    }

    // Check current node value against valid range
    if ((left != nullptr && node->val <= left->val) || (right != nullptr && node->val >= right->val)) {
      return false;
    }

    // Recursively validate left and right subtrees with updated ranges
    return validate(node->left, left, node) && validate(node->right, node, right);
  }
};
