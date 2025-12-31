#include <gtest/gtest.h>

#include "0021_merge_two_sorted_lists.h"
#include "linked_list_test_utils.h"

class MergeTwoSortedListsTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Test recursive solution (mergeTwoLists)
TEST_F(MergeTwoSortedListsTest, RecursiveTestCase1) {
  ListNode* list1 = createList({1, 2, 4});
  ListNode* list2 = createList({1, 3, 4});
  std::vector<int> expected = {1, 1, 2, 3, 4, 4};

  ListNode* output = solution.mergeTwoLists(list1, list2);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(MergeTwoSortedListsTest, RecursiveTestCase2) {
  ListNode* list1 = createList({});
  ListNode* list2 = createList({});
  std::vector<int> expected = {};

  ListNode* output = solution.mergeTwoLists(list1, list2);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(MergeTwoSortedListsTest, RecursiveTestCase3) {
  ListNode* list1 = createList({});
  ListNode* list2 = createList({0});
  std::vector<int> expected = {0};

  ListNode* output = solution.mergeTwoLists(list1, list2);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

// Test iterative solution (mergeTwoLists2)
TEST_F(MergeTwoSortedListsTest, IterativeTestCase1) {
  ListNode* list1 = createList({1, 2, 4});
  ListNode* list2 = createList({1, 3, 4});
  std::vector<int> expected = {1, 1, 2, 3, 4, 4};

  ListNode* output = solution.mergeTwoLists2(list1, list2);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(MergeTwoSortedListsTest, IterativeTestCase2) {
  ListNode* list1 = createList({});
  ListNode* list2 = createList({});
  std::vector<int> expected = {};

  ListNode* output = solution.mergeTwoLists2(list1, list2);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(MergeTwoSortedListsTest, IterativeTestCase3) {
  ListNode* list1 = createList({});
  ListNode* list2 = createList({0});
  std::vector<int> expected = {0};

  ListNode* output = solution.mergeTwoLists2(list1, list2);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}
