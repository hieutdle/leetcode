#include <gtest/gtest.h>

#include "0019_remove_nth_node_from_end_of_list.h"
#include "linked_list_test_utils.h"

class RemoveNthNodeFromEndTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Test two-pointer solution (removeNthFromEnd)
TEST_F(RemoveNthNodeFromEndTest, TwoPointerTestCase1) {
  ListNode* head = createList({1, 2, 3, 4, 5});
  std::vector<int> expected = {1, 2, 3, 5};

  ListNode* output = solution.removeNthFromEnd(head, 2);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(RemoveNthNodeFromEndTest, TwoPointerTestCase2) {
  ListNode* head = createList({1});
  std::vector<int> expected = {};

  ListNode* output = solution.removeNthFromEnd(head, 1);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(RemoveNthNodeFromEndTest, TwoPointerTestCase3) {
  ListNode* head = createList({1, 2});
  std::vector<int> expected = {1};

  ListNode* output = solution.removeNthFromEnd(head, 1);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

// Test two-pass solution (removeNthFromEnd2)
TEST_F(RemoveNthNodeFromEndTest, TwoPassTestCase1) {
  ListNode* head = createList({1, 2, 3, 4, 5});
  std::vector<int> expected = {1, 2, 3, 5};

  ListNode* output = solution.removeNthFromEnd2(head, 2);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(RemoveNthNodeFromEndTest, TwoPassTestCase2) {
  ListNode* head = createList({1});
  std::vector<int> expected = {};

  ListNode* output = solution.removeNthFromEnd2(head, 1);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(RemoveNthNodeFromEndTest, TwoPassTestCase3) {
  ListNode* head = createList({1, 2});
  std::vector<int> expected = {1};

  ListNode* output = solution.removeNthFromEnd2(head, 1);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}