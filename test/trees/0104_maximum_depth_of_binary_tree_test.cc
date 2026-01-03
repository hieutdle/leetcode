#include <gtest/gtest.h>

#include "0104_maximum_depth_of_binary_tree.h"
#include "tree_test_utils.h"

class MaximumDepthOfBinaryTreeTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Test recursive solution (maxDepth)
TEST_F(MaximumDepthOfBinaryTreeTest, RecursiveDFSTestCase1) {
  TreeNode* root = createTree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  EXPECT_EQ(solution.maxDepth(root), 3);
  deleteTree(root);
}

TEST_F(MaximumDepthOfBinaryTreeTest, RecursiveDFSTestCase2) {
  TreeNode* root = createTree({1, std::nullopt, 2});
  EXPECT_EQ(solution.maxDepth(root), 2);
  deleteTree(root);
}

// Test iterative BFS solution (maxDepth2)
TEST_F(MaximumDepthOfBinaryTreeTest, IterativeBFSTestCase1) {
  TreeNode* root = createTree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  EXPECT_EQ(solution.maxDepth2(root), 3);
  deleteTree(root);
}

TEST_F(MaximumDepthOfBinaryTreeTest, IterativeBFSTestCase2) {
  TreeNode* root = createTree({1, std::nullopt, 2});
  EXPECT_EQ(solution.maxDepth2(root), 2);
  deleteTree(root);
}
