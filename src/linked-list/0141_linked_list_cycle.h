#pragma once
#include <unordered_set>

using std::unordered_set;

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
  // Fast and Slow Pointer
  // Floyd's Cycle Detection Algorithm (Tortoise and Hare)
  // Uses two pointers: slow moves one step at a time, fast moves two steps
  // If there's a cycle, fast will eventually meet slow
  // If there's no cycle, fast will reach the end (nullptr)
  bool hasCycle(ListNode* head) {
    // Empty list or single node without cycle
    if (head == nullptr || head->next == nullptr) {
      return false;
    }

    ListNode* slow = head;
    ListNode* fast = head;

    // Move pointers until fast reaches end or they meet
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;        // Move slow by 1 step
      fast = fast->next->next;  // Move fast by 2 steps

      // If pointers meet, there's a cycle:
      // Assume the fast pointer need to move 10 steps
      // to go around the cycle and meet the slow pointer
      // After first step the difference is 10 + 1 (slow pointer move) - 2 (fast pointer move)
      // So each step the difference reduce by 1
      // If there is a cycle they will eventually meet
      if (slow == fast) {
        return true;
      }
    }

    // Fast reached the end, no cycle
    return false;
  }

  // Time: O(n) | Space: O(n)
  // Hashmap
  bool hasCycle2(ListNode* head) {
    unordered_set<ListNode*> seen;
    ListNode* curr = head;

    while (curr != nullptr) {
      // If we have seen this node before, there's a cycle
      if (seen.contains(curr)) {
        return true;
      }
      // Mark this node as seen
      seen.insert(curr);
      curr = curr->next;
    }

    // Reached the end, no cycle
    return false;
  }
};
