#include <gtest/gtest.h>

#include "0572_subtree_of_another_tree.h"
#include "tree_test_utils.h"

class SubtreeOfAnotherTreeTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(SubtreeOfAnotherTreeTest, TestCase1) {
  TreeNode* root = createTree({3, 4, 5, 1, 2});
  TreeNode* subRoot = createTree({4, 1, 2});

  EXPECT_TRUE(solution.isSubtree(root, subRoot));

  deleteTree(root);
  deleteTree(subRoot);
}

TEST_F(SubtreeOfAnotherTreeTest, TestCase2) {
  TreeNode* root = createTree({3, 4, 5, 1, 2, std::nullopt, std::nullopt, std::nullopt, std::nullopt, 0});
  TreeNode* subRoot = createTree({4, 1, 2});

  EXPECT_FALSE(solution.isSubtree(root, subRoot));

  deleteTree(root);
  deleteTree(subRoot);
}