#include <gtest/gtest.h>

#include "0206_reverse_linked_list.h"
#include "linked_list_test_utils.h"

class ReverseLinkedListTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Test recursive solution (reverseList)
TEST_F(ReverseLinkedListTest, RecursiveTestCase1) {
  ListNode* head = createList({1, 2, 3, 4, 5});
  std::vector<int> expected = {5, 4, 3, 2, 1};

  ListNode* output = solution.reverseList(head);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(ReverseLinkedListTest, RecursiveTestCase2) {
  ListNode* head = createList({1, 2});
  std::vector<int> expected = {2, 1};

  ListNode* output = solution.reverseList(head);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(ReverseLinkedListTest, RecursiveTestCase3) {
  ListNode* head = createList({});
  std::vector<int> expected = {};

  ListNode* output = solution.reverseList(head);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

// Test iterative solution (reverseList2)
TEST_F(ReverseLinkedListTest, IterativeTestCase1) {
  ListNode* head = createList({1, 2, 3, 4, 5});
  std::vector<int> expected = {5, 4, 3, 2, 1};

  ListNode* output = solution.reverseList2(head);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(ReverseLinkedListTest, IterativeTestCase2) {
  ListNode* head = createList({1, 2});
  std::vector<int> expected = {2, 1};

  ListNode* output = solution.reverseList2(head);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(ReverseLinkedListTest, IterativeTestCase3) {
  ListNode* head = createList({});
  std::vector<int> expected = {};

  ListNode* output = solution.reverseList2(head);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}