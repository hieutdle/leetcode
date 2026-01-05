#include <gtest/gtest.h>

#include "0098_validate_binary_search_tree.h"
#include "tree_test_utils.h"

class ValidateBinarySearchTreeTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ValidateBinarySearchTreeTest, TestCase1) {
  TreeNode* root = createTree({2, 1, 3});

  EXPECT_TRUE(solution.isValidBST(root));
  EXPECT_TRUE(solution.isValidBST2(root));

  deleteTree(root);
}

TEST_F(ValidateBinarySearchTreeTest, TestCase2) {
  TreeNode* root = createTree({5, 1, 4, std::nullopt, std::nullopt, 3, 6});

  EXPECT_FALSE(solution.isValidBST(root));
  EXPECT_FALSE(solution.isValidBST2(root));

  deleteTree(root);
}