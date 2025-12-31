#pragma once

#include <vector>

// Forward declaration - ListNode should be defined in the problem file
struct ListNode;

// Helper function to create a linked list from a vector
inline ListNode* createList(const std::vector<int>& values) {
  if (values.empty())
    return nullptr;

  ListNode* head = new ListNode(values[0]);
  ListNode* curr = head;

  for (size_t i = 1; i < values.size(); ++i) {
    curr->next = new ListNode(values[i]);
    curr = curr->next;
  }

  return head;
}

// Helper function to convert linked list to vector for comparison
inline std::vector<int> listToVector(ListNode* head) {
  std::vector<int> result;
  while (head != nullptr) {
    result.push_back(head->val);
    head = head->next;
  }
  return result;
}

// Helper function to delete a linked list
inline void deleteList(ListNode* head) {
  while (head != nullptr) {
    ListNode* temp = head;
    head = head->next;
    delete temp;
  }
}
