#include <gtest/gtest.h>

#include "0100_same_tree.h"
#include "tree_test_utils.h"

class SameTreeTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(SameTreeTest, TestCase1) {
  TreeNode* p = createTree({1, 2, 3});
  TreeNode* q = createTree({1, 2, 3});

  EXPECT_TRUE(solution.isSameTree(p, q));

  deleteTree(p);
  deleteTree(q);
}

TEST_F(SameTreeTest, TestCase2) {
  TreeNode* p = createTree({1, 2});
  TreeNode* q = createTree({1, std::nullopt, 2});

  EXPECT_FALSE(solution.isSameTree(p, q));

  deleteTree(p);
  deleteTree(q);
}

TEST_F(SameTreeTest, TestCase3) {
  TreeNode* p = createTree({1, 2, 1});
  TreeNode* q = createTree({1, 1, 2});

  EXPECT_FALSE(solution.isSameTree(p, q));

  deleteTree(p);
  deleteTree(q);
}