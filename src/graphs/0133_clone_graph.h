#pragma once

#include <queue>
#include <unordered_map>
#include <vector>

using std::queue;
using std::unordered_map;
using std::vector;

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> neighbors;

  Node() {
    val = 0;
    neighbors = vector<Node*>();
  }

  Node(int _val) {
    val = _val;
    neighbors = vector<Node*>();
  }

  Node(int _val, vector<Node*> _neighbors) {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution {
 public:
  // Time: O(n + e) | Space: O(n)
  // where n is number of nodes, e is number of edges
  // BFS approach with hashmap to track cloned nodes
  Node* cloneGraph(Node* node) {
    if (node == nullptr) {
      return nullptr;
    }

    // Map from original node to cloned node
    unordered_map<Node*, Node*> cloned;

    // Create clone of the starting node
    Node* clone = new Node(node->val);
    cloned[node] = clone;

    // BFS to traverse all nodes
    queue<Node*> q;
    q.push(node);

    while (!q.empty()) {
      Node* curr = q.front();
      q.pop();

      // Process all neighbors
      for (Node* neighbor : curr->neighbors) {
        // If neighbor hasn't been cloned yet, clone it
        if (cloned.find(neighbor) == cloned.end()) {
          cloned[neighbor] = new Node(neighbor->val);
          q.push(neighbor);
        }

        // Add the cloned neighbor to the current cloned node's neighbors
        cloned[curr]->neighbors.push_back(cloned[neighbor]);
      }
    }

    return clone;
  }
};
