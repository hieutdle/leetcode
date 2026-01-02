#pragma once

#include <queue>
#include <vector>

// Forward declaration - TreeNode should be defined in the problem file
struct TreeNode;

// Helper function to create a binary tree from a level-order vector
// Use -1 or any negative number to represent null nodes
inline TreeNode* createTree(const std::vector<int>& values) {
  if (values.empty() || values[0] < 0) {
    return nullptr;
  }

  TreeNode* root = new TreeNode(values[0]);
  std::queue<TreeNode*> queue;
  queue.push(root);

  size_t i = 1;
  while (!queue.empty() && i < values.size()) {
    TreeNode* node = queue.front();
    queue.pop();

    // Left child
    if (i < values.size() && values[i] >= 0) {
      node->left = new TreeNode(values[i]);
      queue.push(node->left);
    }
    i++;

    // Right child
    if (i < values.size() && values[i] >= 0) {
      node->right = new TreeNode(values[i]);
      queue.push(node->right);
    }
    i++;
  }

  return root;
}

// Helper function to convert binary tree to level-order vector
// Use -1 to represent null nodes
inline std::vector<int> treeToVector(TreeNode* root) {
  std::vector<int> result;
  if (root == nullptr) {
    return result;
  }

  std::queue<TreeNode*> queue;
  queue.push(root);

  while (!queue.empty()) {
    TreeNode* node = queue.front();
    queue.pop();

    if (node == nullptr) {
      result.push_back(-1);
    } else {
      result.push_back(node->val);
      queue.push(node->left);
      queue.push(node->right);
    }
  }

  // Remove trailing -1s
  while (!result.empty() && result.back() == -1) {
    result.pop_back();
  }

  return result;
}

// Helper function to delete a binary tree
inline void deleteTree(TreeNode* root) {
  if (root == nullptr) {
    return;
  }

  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}
