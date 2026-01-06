#include <gtest/gtest.h>

#include "0104_maximum_depth_of_binary_tree.h"
#include "tree_test_utils.h"

class MaximumDepthOfBinaryTreeTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(MaximumDepthOfBinaryTreeTest, TestCase1) {
  TreeNode* root = createTree({3, 9, 20, std::nullopt, std::nullopt, 15, 7});
  int expected = 3;

  /// Test maxDepth (DFS recursive)
  int output = solution.maxDepth(root);
  EXPECT_EQ(output, expected);

  // Test maxDepth2 (BFS iterative)
  int output2 = solution.maxDepth2(root);
  EXPECT_EQ(output2, expected);

  deleteTree(root);
}

TEST_F(MaximumDepthOfBinaryTreeTest, TestCase2) {
  TreeNode* root = createTree({1, std::nullopt, 2});
  int expected = 2;

  int output = solution.maxDepth(root);
  EXPECT_EQ(output, expected);

  int output2 = solution.maxDepth2(root);
  EXPECT_EQ(output2, expected);

  deleteTree(root);
}
