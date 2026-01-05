#include <gtest/gtest.h>

#include "0102_binary_tree_level_order_traversal.h"
#include "tree_test_utils.h"

class BinaryTreeLevelOrderTraversalTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(BinaryTreeLevelOrderTraversalTest, TestCase1) {
  TreeNode* root = createTree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  std::vector<std::vector<int>> expected = {{3}, {9, 20}, {15, 7}};
  EXPECT_EQ(solution.levelOrder(root), expected);
  deleteTree(root);
}

TEST_F(BinaryTreeLevelOrderTraversalTest, TestCase2) {
  TreeNode* root = createTree({1});
  std::vector<std::vector<int>> expected = {{1}};
  EXPECT_EQ(solution.levelOrder(root), expected);
  deleteTree(root);
}

TEST_F(BinaryTreeLevelOrderTraversalTest, TestCase3) {
  TreeNode* root = createTree({});
  std::vector<std::vector<int>> expected = {};
  EXPECT_EQ(solution.levelOrder(root), expected);
  deleteTree(root);
}

TEST_F(BinaryTreeLevelOrderTraversalTest, TestCase4) {
  TreeNode* root = createTree({1, 2, 3, 4, 5, 6, 7});
  std::vector<std::vector<int>> expected = {{1}, {2, 3}, {4, 5, 6, 7}};
  EXPECT_EQ(solution.levelOrder(root), expected);
  deleteTree(root);
}

TEST_F(BinaryTreeLevelOrderTraversalTest, TestCase5) {
  TreeNode* root = createTree({1, 2, std::nullopt, 3});
  std::vector<std::vector<int>> expected = {{1}, {2}, {3}};
  EXPECT_EQ(solution.levelOrder(root), expected);
  deleteTree(root);
}
