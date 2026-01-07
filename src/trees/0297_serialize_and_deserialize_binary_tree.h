#pragma once

#include <queue>
#include <sstream>
#include <string>

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;

  TreeNode() : val(0), left(nullptr), right(nullptr) {}

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

  TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Codec {
 public:
  // Time: O(n) | Space: O(n)
  // Encodes a tree to a single string using level-order traversal (BFS)
  std::string serialize(TreeNode* root) {
    if (root == nullptr) {
      return "";
    }

    std::string res;
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
      TreeNode* node = queue.front();
      queue.pop();

      if (node) {
        res += std::to_string(node->val) + " ";
        queue.push(node->left);
        queue.push(node->right);
      } else {
        res += "# ";
      }
    }

    //    1
    //   / \
    //  2   3
    //     / \
    //    4   5
    // Final string look like: "1 2 3 # # 4 5 # # # # "
    // Remove trailing space
    if (!res.empty()) {
      res.pop_back();
    }

    return res;
  }

  // Time: O(n) | Space: O(n)
  // Decodes your encoded data to tree using level-order traversal (BFS)
  TreeNode* deserialize(std::string data) {
    if (data.empty()) {
      return nullptr;
    }

    std::stringstream ss(data);
    std::string token;
    ss >> token;  // Read the first token (root value)

    TreeNode* root = new TreeNode(std::stoi(token));
    std::queue<TreeNode*> queue;
    queue.push(root);

    while (!queue.empty()) {
      TreeNode* node = queue.front();
      queue.pop();

      // Read left child
      // >> automatically skips spaces
      ss >> token;
      if (token != "#") {
        node->left = new TreeNode(std::stoi(token));
        queue.push(node->left);
      }

      // Read right child
      ss >> token;
      if (token != "#") {
        node->right = new TreeNode(std::stoi(token));
        queue.push(node->right);
      }
    }

    return root;
  }

  // Time: O(n) | Space: O(n)
  // Encodes a tree to a single string using preorder traversal (DFS)
  std::string serialize2(TreeNode* root) {
    if (root == nullptr) {
      return "";
    }
    std::string res;
    serializeDFS(root, res);
    //    1
    //   / \
    //  2   3
    //     / \
    //    4   5
    // Final string look like: "1 2 # # 3 4 # # 5 # # "
    // Remove trailing space
    if (!res.empty()) {
      res.pop_back();
    }
    return res;
  }

  // Time: O(n) | Space: O(n)
  // Decodes your encoded data to tree using preorder traversal (DFS)
  TreeNode* deserialize2(std::string data) {
    if (data.empty()) {
      return nullptr;
    }
    std::stringstream ss(data);
    return deserializeDFS(ss);
  }

 private:
  void serializeDFS(TreeNode* root, std::string& result) {
    if (root == nullptr) {
      result += "# ";
      return;
    }

    // Preorder: root -> left -> right
    result += std::to_string(root->val) + " ";
    serializeDFS(root->left, result);
    serializeDFS(root->right, result);
  }

  TreeNode* deserializeDFS(std::stringstream& ss) {
    std::string token;
    ss >> token;

    if (token == "#") {
      return nullptr;
    }

    // Preorder: root -> left -> right
    TreeNode* root = new TreeNode(std::stoi(token));
    root->left = deserializeDFS(ss);
    root->right = deserializeDFS(ss);

    return root;
  }
};