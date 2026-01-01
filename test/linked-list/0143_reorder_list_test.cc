#include <gtest/gtest.h>

#include "0143_reorder_list.h"
#include "linked_list_test_utils.h"

class ReorderListTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ReorderListTest, TestCase1) {
  ListNode* head = createList({1, 2, 3, 4});
  std::vector<int> expected = {1, 4, 2, 3};

  solution.reorderList(head);
  EXPECT_EQ(listToVector(head), expected);

  deleteList(head);
}

TEST_F(ReorderListTest, TestCase2) {
  ListNode* head = createList({1, 2, 3, 4, 5});
  std::vector<int> expected = {1, 5, 2, 4, 3};

  solution.reorderList(head);
  EXPECT_EQ(listToVector(head), expected);

  deleteList(head);
}