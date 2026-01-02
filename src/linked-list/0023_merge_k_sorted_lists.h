#pragma once

#include <queue>
#include <vector>

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
  // Time: O(N log k) where N is total nodes and k is number of lists
  // Space: O(k) for the min heap
  // Min-heap approach
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // Custom comparator for min-heap (greater -> min-heap)
    auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)>
        minHeap(cmp);

    // Add the head of each list to the heap
    for (auto* head : lists) {
      if (head != nullptr) {
        minHeap.push(head);
      }
    }

    // Dummy node to simplify edge cases
    ListNode dummy;
    ListNode* curr = &dummy;

    // Keep extracting the minimum node from heap
    while (!minHeap.empty()) {
      ListNode* node = minHeap.top();
      minHeap.pop();

      // Add to result list
      curr->next = node;
      curr = curr->next;

      // If there's a next node in the same list, add it to heap
      if (node->next != nullptr) {
        minHeap.push(node->next);
      }
    }

    return dummy.next;
  }

  // Time: O(N log k) where N is total nodes and k is number of lists
  // Space: O(log k) for recursion stack
  // Divide and conquer approach
  ListNode* mergeKLists2(std::vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }
    return mergeKListsHelper(lists, 0, lists.size() - 1);
  }

 private:
  ListNode* mergeKListsHelper(std::vector<ListNode*>& lists, int left,
                               int right) {
    if (left == right) {
      return lists[left];
    }

    int mid = left + (right - left) / 2;
    ListNode* l1 = mergeKListsHelper(lists, left, mid);
    ListNode* l2 = mergeKListsHelper(lists, mid + 1, right);

    return mergeTwoLists(l1, l2);
  }

  // Helper function to merge two sorted lists
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
      return l2;
    }
    if (l2 == nullptr) {
      return l1;
    }

    if (l1->val <= l2->val) {
      l1->next = mergeTwoLists(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    }
  }
};
