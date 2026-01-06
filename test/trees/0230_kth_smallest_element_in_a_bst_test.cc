#include <gtest/gtest.h>

#include "0230_kth_smallest_element_in_a_bst.h"
#include "tree_test_utils.h"

class KthSmallestElementInBSTTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(KthSmallestElementInBSTTest, TestCase1) {
  TreeNode* root = createTree({3, 1, 4, std::nullopt, 2});
  int k = 1;
  int expected = 1;

  int output = solution.kthSmallest(root, k);
  EXPECT_EQ(output, expected);

  int output2 = solution.kthSmallest2(root, k);
  EXPECT_EQ(output2, expected);

  int output3 = solution.kthSmallest3(root, k);
  EXPECT_EQ(output3, expected);

  deleteTree(root);
}

TEST_F(KthSmallestElementInBSTTest, TestCase2) {
  TreeNode* root = createTree({5, 3, 6, 2, 4, std::nullopt, std::nullopt, 1});
  int k = 3;
  int expected = 3;

  int output = solution.kthSmallest(root, k);
  EXPECT_EQ(output, expected);

  int output2 = solution.kthSmallest2(root, k);
  EXPECT_EQ(output2, expected);

  int output3 = solution.kthSmallest3(root, k);
  EXPECT_EQ(output3, expected);

  deleteTree(root);
}