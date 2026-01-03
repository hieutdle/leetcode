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
  // Time: O(N log k) | Space : O(k)
  // where N is total nodes and k is number of lists
  // Min-heap approach
  ListNode* mergeKLists(std::vector<ListNode*>& lists) {
    // Custom comparator for min-heap (greater -> min-heap)
    auto cmp = [](ListNode* a, ListNode* b) {
      return a->val > b->val;
    };
    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> pq;

    // Add the head of each list to the heap
    for (auto head : lists) {
      if (head != nullptr) {
        pq.push(head);
      }
    }

    // Dummy node to simplify edge cases
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;

    // Keep extracting the minimum node from heap
    while (!pq.empty()) {
      ListNode* node = pq.top();
      pq.pop();

      // Add to result list
      curr->next = node;
      curr = curr->next;

      // Heap: [1(L1), 2(L2), 4(L3)]
      // If there's a next node in the same list, add it to heap
      // Without pushing node->next, L1 would disappear, and you'd lose its remaining nodes.
      if (node->next != nullptr) {
        pq.push(node->next);
      }
    }

    return dummy->next;
  }

  // Time: O(N log k) | Space: O(log k)
  // Divide and conquer approach
  ListNode* mergeKLists2(std::vector<ListNode*>& lists) {
    int n = lists.size();
    if (n == 0) {
      return NULL;
    }

    // Iteratively merge lists in pairs
    while (n > 1) {
      for (int i = 0; i < n / 2; i++) {
        lists[i] = mergeTwoLists(lists[i], lists[n - i - 1]);
      }
      n = (n + 1) / 2;
    }

    return lists[0];
  }

 private:
  // Helper function to merge two sorted lists
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
