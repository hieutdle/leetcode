#include <gtest/gtest.h>

#include "0235_lowest_common_ancestor_of_a_binary_search_tree.h"
#include "tree_test_utils.h"

class LowestCommonAncestorOfBSTTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Recursive solution tests
TEST_F(LowestCommonAncestorOfBSTTest, RecursiveTestCase1) {
  TreeNode* root = createTree({6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5});
  TreeNode* p = root->left;   // Node with value 2
  TreeNode* q = root->right;  // Node with value 8

  TreeNode* result = solution.lowestCommonAncestor(root, p, q);
  EXPECT_EQ(result->val, 6);

  deleteTree(root);
}

TEST_F(LowestCommonAncestorOfBSTTest, RecursiveTestCase2) {
  TreeNode* root = createTree({6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5});
  TreeNode* p = root->left;         // Node with value 2
  TreeNode* q = root->left->right;  // Node with value 4

  TreeNode* result = solution.lowestCommonAncestor(root, p, q);
  EXPECT_EQ(result->val, 2);

  deleteTree(root);
}

TEST_F(LowestCommonAncestorOfBSTTest, RecursiveTestCase3) {
  TreeNode* root = createTree({2, 1});
  TreeNode* p = root;        // Node with value 2
  TreeNode* q = root->left;  // Node with value 1

  TreeNode* result = solution.lowestCommonAncestor(root, p, q);
  EXPECT_EQ(result->val, 2);

  deleteTree(root);
}

// Iterative solution tests
TEST_F(LowestCommonAncestorOfBSTTest, IterativeTestCase1) {
  TreeNode* root = createTree({6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5});
  TreeNode* p = root->left;   // Node with value 2
  TreeNode* q = root->right;  // Node with value 8

  TreeNode* result = solution.lowestCommonAncestor2(root, p, q);
  EXPECT_EQ(result->val, 6);

  deleteTree(root);
}

TEST_F(LowestCommonAncestorOfBSTTest, IterativeTestCase2) {
  TreeNode* root = createTree({6, 2, 8, 0, 4, 7, 9, std::nullopt, std::nullopt, 3, 5});
  TreeNode* p = root->left;         // Node with value 2
  TreeNode* q = root->left->right;  // Node with value 4

  TreeNode* result = solution.lowestCommonAncestor2(root, p, q);
  EXPECT_EQ(result->val, 2);

  deleteTree(root);
}

TEST_F(LowestCommonAncestorOfBSTTest, IterativeTestCase3) {
  TreeNode* root = createTree({2, 1});
  TreeNode* p = root;        // Node with value 2
  TreeNode* q = root->left;  // Node with value 1

  TreeNode* result = solution.lowestCommonAncestor2(root, p, q);
  EXPECT_EQ(result->val, 2);

  deleteTree(root);
}