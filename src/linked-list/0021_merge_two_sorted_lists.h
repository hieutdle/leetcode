#pragma once

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;

  ListNode() : val(0), next(nullptr) {}

  ListNode(int x) : val(x), next(nullptr) {}

  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  // Time: O(n + m) | Space: O(n + m) due to recursion stack
  // m and n are the lengths of list1 and list2
  // Recursive approach
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    // Base cases
    if (list1 == nullptr) {
      return list2;
    }
    if (list2 == nullptr) {
      return list1;
    }

    // Recursive case: choose smaller node and recurse
    if (list1->val <= list2->val) {
      list1->next = mergeTwoLists(list1->next, list2);
      return list1;
    } else {
      list2->next = mergeTwoLists(list1, list2->next);
      return list2;
    }
  }

  // Time: O(n + m) | Space: O(1)
  // Iterative approach
  ListNode* mergeTwoLists2(ListNode* list1, ListNode* list2) {
    // Create a dummy node to simplify edge cases
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;

    // Merge while both lists have nodes
    while (list1 != nullptr && list2 != nullptr) {
      if (list1->val <= list2->val) {
        curr->next = list1;
        list1 = list1->next;
      } else {
        curr->next = list2;
        list2 = list2->next;
      }
      curr = curr->next;
    }

    // Add all the remaining nodes from either list when one is finished
    curr->next = (list1 != nullptr) ? list1 : list2;

    return dummy->next;
  }
};
