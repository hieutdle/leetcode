#include <gtest/gtest.h>

#include "0023_merge_k_sorted_lists.h"
#include "linked_list_test_utils.h"

class MergeKSortedListsTest : public ::testing::Test {
 protected:
  Solution solution;
};

// Test min-heap solution (mergeKLists)
TEST_F(MergeKSortedListsTest, MinHeapTestCase1) {
  std::vector<ListNode*> lists = {createList({1, 4, 5}), createList({1, 3, 4}), createList({2, 6})};
  std::vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};

  ListNode* output = solution.mergeKLists(lists);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(MergeKSortedListsTest, MinHeapTestCase2) {
  std::vector<ListNode*> lists = {};
  std::vector<int> expected = {};

  ListNode* output = solution.mergeKLists(lists);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(MergeKSortedListsTest, MinHeapTestCase3) {
  std::vector<ListNode*> lists = {createList({})};
  std::vector<int> expected = {};

  ListNode* output = solution.mergeKLists(lists);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

// Test divide and conquer solution (mergeKLists2)
TEST_F(MergeKSortedListsTest, DivideConquerTestCase1) {
  std::vector<ListNode*> lists = {createList({1, 4, 5}), createList({1, 3, 4}), createList({2, 6})};
  std::vector<int> expected = {1, 1, 2, 3, 4, 4, 5, 6};

  ListNode* output = solution.mergeKLists2(lists);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(MergeKSortedListsTest, DivideConquerTestCase2) {
  std::vector<ListNode*> lists = {};
  std::vector<int> expected = {};

  ListNode* output = solution.mergeKLists2(lists);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}

TEST_F(MergeKSortedListsTest, DivideConquerTestCase3) {
  std::vector<ListNode*> lists = {createList({})};
  std::vector<int> expected = {};

  ListNode* output = solution.mergeKLists2(lists);
  EXPECT_EQ(listToVector(output), expected);

  deleteList(output);
}