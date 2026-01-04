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
  // Time: O(n * m) | Space: O(h)
  // n is nodes in root, m is nodes in subRoot, h is height of tree
  bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) {
      return false;
    }

    // Check if current tree matches subRoot
    if (isSameTree(root, subRoot)) {
      return true;
    }

    // Recursively check left and right subtrees
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }

 private:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    if (p->val != q->val) {
      return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
  }
};
