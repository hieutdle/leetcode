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
  // Time: O(n) | Space: O(1)
  // Two-pointer approach (one pass)
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Create a dummy node to handle edge cases (removing head)
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    // Move fast pointer n steps ahead
    while (n > 0 && fast != nullptr) {
      fast = fast->next;
      n--;
    }

    // Move both pointers until right reaches the end
    while (fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next;
    }

    // Remove the nth node from end
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;

    return dummy->next;
  }

  // Time: O(n) | Space: O(1)
  // Two-pass approach
  ListNode* removeNthFromEnd2(ListNode* head, int n) {
    // First pass: count the length
    int length = 0;
    ListNode* curr = head;
    while (curr != nullptr) {
      length++;
      curr = curr->next;
    }

    // Edge case: removing the head
    if (length == n) {
      ListNode* newHead = head->next;
      delete head;
      return newHead;
    }

    // Second pass: find the node before the one to remove
    curr = head;
    for (int i = 0; i < length - n - 1; i++) {
      curr = curr->next;
    }

    // Remove the nth node
    ListNode* toDelete = curr->next;
    curr->next = curr->next->next;
    delete toDelete;

    return head;
  }
};
