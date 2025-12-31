#include <gtest/gtest.h>

#include <algorithm>

#include "0141_linked_list_cycle.h"
#include "linked_list_test_utils.h"

class LinkedListCycleTest : public ::testing::Test {
 protected:
  Solution solution;

  // Helper function to create a cycle in a linked list
  // pos is the position (0-indexed) of the node to connect the tail to
  // pos = -1 means no cycle
  ListNode* createListWithCycle(const std::vector<int>& values, int pos) {
    if (values.empty())
      return nullptr;

    ListNode* head = new ListNode(values[0]);
    ListNode* curr = head;
    ListNode* cycleNode = nullptr;

    // Track the node at position 'pos'
    if (pos == 0) {
      cycleNode = head;
    }

    // Build the list
    for (size_t i = 1; i < values.size(); ++i) {
      curr->next = new ListNode(values[i]);
      curr = curr->next;

      if (static_cast<int>(i) == pos) {
        cycleNode = curr;
      }
    }

    // Create the cycle if pos is valid
    if (pos != -1 && cycleNode != nullptr) {
      curr->next = cycleNode;
    }

    return head;
  }

  // Helper function to delete a list with a potential cycle
  // We need to break the cycle first to avoid infinite loop
  void deleteListWithCycle(ListNode* head, int pos) {
    if (head == nullptr)
      return;

    // If there's a cycle, break it first
    if (pos != -1) {
      ListNode* curr = head;
      int count = 0;

      // Find the tail node (the node that points back to create the cycle)
      while (curr->next != nullptr) {
        // Check if we've found the node that creates the cycle
        if (count > 0 && static_cast<int>(count) ==
                             static_cast<int>(pos) + static_cast<int>(std::count_if(head, curr, [](const ListNode&) {
                               return true;
                             }))) {
          break;
        }
        curr = curr->next;
        count++;

        // Safety check to avoid infinite loop
        if (count > 10000)
          break;
      }
      // Break the cycle
      if (curr != nullptr && curr->next != nullptr) {
        curr->next = nullptr;
      }
    }

    // Now delete normally
    deleteList(head);
  }

  // Simpler version - just count nodes and break at the right position
  void deleteListWithCycleSafe(ListNode* head, const std::vector<int>& values, int pos) {
    if (head == nullptr || pos == -1) {
      deleteList(head);
      return;
    }

    // Find the last node and break the cycle
    ListNode* curr = head;
    for (size_t i = 1; i < values.size(); ++i) {
      curr = curr->next;
    }
    // Break the cycle
    curr->next = nullptr;

    // Now delete normally
    deleteList(head);
  }
};

TEST_F(LinkedListCycleTest, FastSlowTestCase1) {
  // Input: head = [3,2,0,-4], pos = 1
  // List has a cycle, where tail connects to the 1st node (index 1)
  std::vector<int> values = {3, 2, 0, -4};
  ListNode* head = createListWithCycle(values, 1);

  bool result = solution.hasCycle(head);
  EXPECT_TRUE(result);

  deleteListWithCycleSafe(head, values, 1);
}

TEST_F(LinkedListCycleTest, FastSlowTestCase2) {
  // Input: head = [1,2], pos = 0
  // List has a cycle, where tail connects to the 0th node
  std::vector<int> values = {1, 2};
  ListNode* head = createListWithCycle(values, 0);

  bool result = solution.hasCycle(head);
  EXPECT_TRUE(result);

  deleteListWithCycleSafe(head, values, 0);
}

TEST_F(LinkedListCycleTest, FastSlowTestCase3) {
  // Input: head = [1], pos = -1
  // List has no cycle
  std::vector<int> values = {1};
  ListNode* head = createListWithCycle(values, -1);

  bool result = solution.hasCycle(head);
  EXPECT_FALSE(result);

  deleteListWithCycleSafe(head, values, -1);
}

// Tests for hasCycle2 (hashmap approach)
TEST_F(LinkedListCycleTest, HashMapTestCase1) {
  // Input: head = [3,2,0,-4], pos = 1
  // List has a cycle, where tail connects to the 1st node (index 1)
  std::vector<int> values = {3, 2, 0, -4};
  ListNode* head = createListWithCycle(values, 1);

  bool result = solution.hasCycle2(head);
  EXPECT_TRUE(result);

  deleteListWithCycleSafe(head, values, 1);
}

TEST_F(LinkedListCycleTest, HashMapTestCase2) {
  // Input: head = [1,2], pos = 0
  // List has a cycle, where tail connects to the 0th node
  std::vector<int> values = {1, 2};
  ListNode* head = createListWithCycle(values, 0);

  bool result = solution.hasCycle2(head);
  EXPECT_TRUE(result);

  deleteListWithCycleSafe(head, values, 0);
}

TEST_F(LinkedListCycleTest, HashMapTestCase3) {
  // Input: head = [1], pos = -1
  // List has no cycle
  std::vector<int> values = {1};
  ListNode* head = createListWithCycle(values, -1);

  bool result = solution.hasCycle2(head);
  EXPECT_FALSE(result);

  deleteListWithCycleSafe(head, values, -1);
}