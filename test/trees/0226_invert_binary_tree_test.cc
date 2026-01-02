#include <gtest/gtest.h>

#include "0226_invert_binary_tree.h"
#include "tree_test_utils.h"

class InvertBinaryTreeTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Test recursive solution (invertTree)
TEST_F(InvertBinaryTreeTest, RecursiveTestCase1) {
  TreeNode* root = createTree({4, 2, 7, 1, 3, 6, 9});
  std::vector<int> expected = {4, 7, 2, 9, 6, 3, 1};

  TreeNode* output = solution.invertTree(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

TEST_F(InvertBinaryTreeTest, RecursiveTestCase2) {
  TreeNode* root = createTree({2, 1, 3});
  std::vector<int> expected = {2, 3, 1};

  TreeNode* output = solution.invertTree(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

TEST_F(InvertBinaryTreeTest, RecursiveTestCase3) {
  TreeNode* root = createTree({});
  std::vector<int> expected = {};

  TreeNode* output = solution.invertTree(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

TEST_F(InvertBinaryTreeTest, RecursiveTestCase4) {
  TreeNode* root = createTree({1});
  std::vector<int> expected = {1};

  TreeNode* output = solution.invertTree(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

// Test iterative BFS solution (invertTree2)
TEST_F(InvertBinaryTreeTest, IterativeBFSTestCase1) {
  TreeNode* root = createTree({4, 2, 7, 1, 3, 6, 9});
  std::vector<int> expected = {4, 7, 2, 9, 6, 3, 1};

  TreeNode* output = solution.invertTree2(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

TEST_F(InvertBinaryTreeTest, IterativeBFSTestCase2) {
  TreeNode* root = createTree({2, 1, 3});
  std::vector<int> expected = {2, 3, 1};

  TreeNode* output = solution.invertTree2(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

TEST_F(InvertBinaryTreeTest, IterativeBFSTestCase3) {
  TreeNode* root = createTree({});
  std::vector<int> expected = {};

  TreeNode* output = solution.invertTree2(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

// Test iterative DFS solution (invertTree3)
TEST_F(InvertBinaryTreeTest, IterativeDFSTestCase1) {
  TreeNode* root = createTree({4, 2, 7, 1, 3, 6, 9});
  std::vector<int> expected = {4, 7, 2, 9, 6, 3, 1};

  TreeNode* output = solution.invertTree3(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

TEST_F(InvertBinaryTreeTest, IterativeDFSTestCase2) {
  TreeNode* root = createTree({2, 1, 3});
  std::vector<int> expected = {2, 3, 1};

  TreeNode* output = solution.invertTree3(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

TEST_F(InvertBinaryTreeTest, IterativeDFSTestCase3) {
  TreeNode* root = createTree({});
  std::vector<int> expected = {};

  TreeNode* output = solution.invertTree3(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}
