#pragma once

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
  // Time: O(h) | Space: O(h)
  // Recursive
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
      return nullptr;
    }

    // If both nodes are in the left subtree
    if (p->val < root->val && q->val < root->val) {
      return lowestCommonAncestor(root->left, p, q);
    }
    // If both nodes are in the right subtree
    else if (p->val > root->val && q->val > root->val) {
      return lowestCommonAncestor(root->right, p, q);
    }

    // Found the split point (LCA)
    return root;
  }

  // Time: O(h) | Space: O(1)
  // Iterative
  TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != nullptr) {
      // If both nodes are in the left subtree
      if (p->val < root->val && q->val < root->val) {
        root = root->left;
      }
      // If both nodes are in the right subtree
      else if (p->val > root->val && q->val > root->val) {
        root = root->right;
      }
      // Found the split point (LCA)
      else {
        return root;
      }
    }
    return nullptr;
  }
};
