#pragma once

#include <queue>
#include <stack>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  // Time: O(n) | Space: O(h) where h is height (recursion stack)
  // Recursive approach
  TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }

    // Swap the left and right children
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert the subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
  }

  // Time: O(n) | Space: O(n)
  // Iterative approach using a queue (BFS)
  TreeNode* invertTree2(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }

    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
      TreeNode* node = queue.front();
      queue.pop();

      // Swap children
      TreeNode* temp = node->left;
      node->left = node->right;
      node->right = temp;

      // Add children to queue
      if (node->left != nullptr) {
        queue.push(node->left);
      }
      if (node->right != nullptr) {
        queue.push(node->right);
      }
    }

    return root;
  }

  // Time: O(n) | Space: O(n)
  // Iterative approach using a stack (DFS)
  TreeNode* invertTree3(TreeNode* root) {
    if (root == nullptr) {
      return nullptr;
    }

    std::stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
      TreeNode* node = stack.top();
      stack.pop();

      // Swap children
      TreeNode* temp = node->left;
      node->left = node->right;
      node->right = temp;

      // Add children to stack
      if (node->left != nullptr) {
        stack.push(node->left);
      }
      if (node->right != nullptr) {
        stack.push(node->right);
      }
    }

    return root;
  }
};
