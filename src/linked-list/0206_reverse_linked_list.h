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
  // Time: O(n) | Space: O(n)
  // Recursive
  ListNode* reverseList(ListNode* head) {
    // Base case: empty list or single node
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    // Recursively reverse the rest of the list
    // https://www.youtube.com/watch?v=S92RuTtt9EE
    ListNode* res = reverseList(head->next);

    // Reverse the current node's pointer
    head->next->next = head;
    head->next = nullptr;

    return res;
  }

  // Time: O(n) | Space: O(1)
  // Iterative
  ListNode* reverseList2(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
      // Temporarily store the next node
      ListNode* next = curr->next;
      // Reverse the current node's pointer
      curr->next = prev;
      // Move prev pointers to current node
      prev = curr;
      // Move to the next node in the original list
      curr = next;
    }

    return prev;
  }
};
