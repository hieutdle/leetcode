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
  // Three-step approach: find middle, reverse second half, merge
  void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return;
    }

    // Step 1: Find the middle of the list using slow and fast pointers
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    // Step 2: Reverse the second half of the list
    ListNode* curr = slow->next;
    slow->next = nullptr;  // Split the list
    ListNode* prev = nullptr;

    while (curr != nullptr) {
      ListNode* temp = curr->next;  // Store next node
      curr->next = prev;            // Reverse the link
      prev = curr;                  // Move prev forward
      curr = temp;                  // Move curr forward
    }

    // Step 3: Merge the two halves
    ListNode* first = head;
    ListNode* second = prev;

    while (second != nullptr) {
      // Store next nodes to avoid losing references
      ListNode* firstNext = first->next;
      ListNode* secondNext = second->next;

      // first -> second -> original first's next
      first->next = second;
      second->next = firstNext;

      // Move pointers forward
      first = firstNext;
      second = secondNext;
    }
  }
};
