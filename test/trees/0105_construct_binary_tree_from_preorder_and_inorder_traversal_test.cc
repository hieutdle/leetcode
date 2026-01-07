#include <gtest/gtest.h>

#include <vector>

#include "0105_construct_binary_tree_from_preorder_and_inorder_traversal.h"
#include "tree_test_utils.h"

class ConstructBinaryTreeFromPreorderAndInorderTraversalTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ConstructBinaryTreeFromPreorderAndInorderTraversalTest, TestCase1) {
  std::vector<int> preorder = {3, 9, 20, 15, 7};
  std::vector<int> inorder = {9, 3, 15, 20, 7};

  TreeNode* root = solution.buildTree(preorder, inorder);
  std::vector<std::optional<int>> expected = {3, 9, 20, std::nullopt, std::nullopt, 15, 7};

  EXPECT_EQ(treeToVector(root), expected);

  deleteTree(root);
}

TEST_F(ConstructBinaryTreeFromPreorderAndInorderTraversalTest, TestCase2) {
  std::vector<int> preorder = {-1};
  std::vector<int> inorder = {-1};

  TreeNode* root = solution.buildTree(preorder, inorder);
  std::vector<std::optional<int>> expected = {-1};

  EXPECT_EQ(treeToVector(root), expected);

  deleteTree(root);
}