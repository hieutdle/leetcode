#include <gtest/gtest.h>

#include "0226_invert_binary_tree.h"
#include "tree_test_utils.h"

class InvertBinaryTreeTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(InvertBinaryTreeTest, TestCase1) {
  TreeNode* root = createTree({4, 2, 7, 1, 3, 6, 9});
  std::vector<std::optional<int>> expected = {4, 7, 2, 9, 6, 3, 1};

  TreeNode* output = solution.invertTree(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

TEST_F(InvertBinaryTreeTest, TestCase2) {
  TreeNode* root = createTree({2, 1, 3});
  std::vector<std::optional<int>> expected = {2, 3, 1};

  TreeNode* output = solution.invertTree(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}

TEST_F(InvertBinaryTreeTest, TestCase3) {
  TreeNode* root = createTree({});
  std::vector<std::optional<int>> expected = {};

  TreeNode* output = solution.invertTree(root);
  EXPECT_EQ(treeToVector(output), expected);

  deleteTree(output);
}