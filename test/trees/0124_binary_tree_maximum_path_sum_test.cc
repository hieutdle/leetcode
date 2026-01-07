#include <gtest/gtest.h>

#include "0124_binary_tree_maximum_path_sum.h"
#include "tree_test_utils.h"

class BinaryTreeMaximumPathSumTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(BinaryTreeMaximumPathSumTest, TestCase1) {
  // Tree: [1,2,3]
  //     1
  //    / \
  //   2   3
  TreeNode* root = createTree({1, 2, 3});
  int expected = 6;  // 2 + 1 + 3

  int output = solution.maxPathSum(root);
  EXPECT_EQ(output, expected);

  deleteTree(root);
}

TEST_F(BinaryTreeMaximumPathSumTest, TestCase2) {
  // Tree: [-10,9,20,null,null,15,7]
  //      -10
  //      / \
  //     9  20
  //        / \
  //       15  7
  TreeNode* root = createTree({-10, 9, 20, std::nullopt, std::nullopt, 15, 7});
  int expected = 42;  // 15 + 20 + 7

  int output = solution.maxPathSum(root);
  EXPECT_EQ(output, expected);

  deleteTree(root);
}