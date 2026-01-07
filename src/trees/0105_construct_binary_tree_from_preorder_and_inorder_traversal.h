#pragma once

#include <functional>
#include <unordered_map>
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
  // Hashmap + recursion
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    int n = preorder.size();
    // Build hashmap for quick index lookup in inorder array
    std::unordered_map<int, int> inorderMap;
    for (int i = 0; i < n; i++) {
      inorderMap[inorder[i]] = i;
    }

    // Recursive function to build the tree
    // Parameters:
    // - preorderStart: starting index in preorder array
    // - inorderStart: starting index in inorder array
    // - subtreeSize: number of nodes in current subtree
    std::function<TreeNode*(int, int, int)> build = [&](int preorderStart, int inorderStart,
                                                        int subtreeSize) -> TreeNode* {
      // Base case: empty subtree
      if (subtreeSize <= 0) {
        return nullptr;
      }
      
      //       3
      //      / \
      //     9  20
      //        /  \
      //      15    7

      // [ 3, 9, 20, 15, 7 ]  preorder
      // [ 9, 3, 15, 20, 7 ]  inorder

      // The first element in preorder range is always the root
      // [ |3| 9, 20, 15, 7 ]
      int rootValue = preorder[preorderStart];

      // Find root's position in inorder array
      // [ 9, |3|, 15, 20, 7 ]
      int rootIndexInInorder = inorderMap[rootValue];

      // Calculate size of left subtree
      int leftSubtreeSize = rootIndexInInorder - inorderStart;

      // Recursively build left subtree
      // Left subtree in preorder: starts right after root
      // [ 3, |9, 20, 15, 7| ]
      // Left subtree in inorder: from inorderStart to rootIndexInInorder-1
      // [ |9|, 3, 15, 20, 7 ]
      TreeNode* left = build(preorderStart + 1, inorderStart, leftSubtreeSize);

      // Recursively build right subtree
      // Right subtree in preorder: starts after root and left subtree
      // [ 3, 9, |20, 15, 7| ]
      // Right subtree in inorder: starts right after root
      // [ 9, 3, |15, 20, 7| ]
      // Right subtree size: total - 1(root) - leftSubtreeSize
      TreeNode* right =
          build(preorderStart + 1 + leftSubtreeSize, rootIndexInInorder + 1, subtreeSize - 1 - leftSubtreeSize);

      // Create and return the root node with its children
      return new TreeNode(rootValue, left, right);
    };

    // Build the entire tree starting from index 0 with all nodes
    return build(0, 0, n);
  }
};
