#pragma once

#include <queue>

using std::priority_queue;

class MedianFinder {
 public:
  MedianFinder() {}

  // Time: O(log n) | Space: O(n)
  void addNum(int num) {
    // Always add the new number to the max heap first (left side - smaller half)
    max_heap.push(num);

    // Move the largest element from max heap to min heap
    // This ensures all elements in max heap are <= all elements in min heap
    min_heap.push(max_heap.top());
    max_heap.pop();

    // Balance the heaps if necessary
    // Min heap should have at most one more element than max heap
    if (min_heap.size() > max_heap.size() + 1) {
      max_heap.push(min_heap.top());
      min_heap.pop();
    }
  }

  // Time: O(1) | Space: O(1)
  double findMedian() {
    // If odd number of elements, return the top of the larger heap (min heap)
    if (min_heap.size() > max_heap.size()) {
      return min_heap.top();
    }
    // If even number of elements, return average of both tops
    return (max_heap.top() + min_heap.top()) / 2.0;
  }

 private:
  // Max heap stores the smaller half of the numbers
  priority_queue<int> max_heap;
  // Min heap stores the larger half of the numbers
  priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
