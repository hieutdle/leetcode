#pragma once

#include <optional>
#include <queue>
#include <vector>

// Forward declaration - TreeNode should be defined in the problem file
struct TreeNode;

// Helper function to create a binary tree from a level-order vector
// Use std::nullopt to represent null nodes
inline TreeNode* createTree(const std::vector<std::optional<int>>& values) {
  if (values.empty() || !values[0].has_value()) {
    return nullptr;
  }

  TreeNode* root = new TreeNode(values[0].value());
  std::queue<TreeNode*> queue;
  queue.push(root);

  size_t i = 1;
  while (!queue.empty() && i < values.size()) {
    TreeNode* node = queue.front();
    queue.pop();

    // Left child
    if (i < values.size() && values[i].has_value()) {
      node->left = new TreeNode(values[i].value());
      queue.push(node->left);
    }
    i++;

    // Right child
    if (i < values.size() && values[i].has_value()) {
      node->right = new TreeNode(values[i].value());
      queue.push(node->right);
    }
    i++;
  }

  return root;
}

// Helper function to convert binary tree to level-order vector
// Use std::nullopt to represent null nodes
inline std::vector<std::optional<int>> treeToVector(TreeNode* root) {
  std::vector<std::optional<int>> result;
  if (root == nullptr) {
    return result;
  }

  std::queue<TreeNode*> queue;
  queue.push(root);

  while (!queue.empty()) {
    TreeNode* node = queue.front();
    queue.pop();

    if (node == nullptr) {
      result.push_back(std::nullopt);
    } else {
      result.push_back(node->val);
      queue.push(node->left);
      queue.push(node->right);
    }
  }

  // Remove trailing nullopts
  while (!result.empty() && !result.back().has_value()) {
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
