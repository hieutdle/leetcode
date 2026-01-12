#include <gtest/gtest.h>

#include <unordered_map>
#include <unordered_set>
#include <vector>

#include "0133_clone_graph.h"

class CloneGraphTest : public ::testing::Test {
 protected:
  Solution solution;

  // Helper function to create a graph from adjacency list
  Node* createGraph(const std::vector<std::vector<int>>& adjList) {
    if (adjList.empty()) {
      return nullptr;
    }

    int n = adjList.size();
    std::vector<Node*> nodes(n + 1);

    // Create all nodes
    for (int i = 1; i <= n; ++i) {
      nodes[i] = new Node(i);
    }

    // Connect neighbors
    for (int i = 0; i < n; ++i) {
      for (int neighbor : adjList[i]) {
        nodes[i + 1]->neighbors.push_back(nodes[neighbor]);
      }
    }

    return nodes[1];
  }

  // Helper function to delete a graph
  void deleteGraph(Node* node) {
    if (node == nullptr) {
      return;
    }

    std::unordered_set<Node*> visited;
    std::vector<Node*> stack = {node};

    // Collect all nodes
    while (!stack.empty()) {
      Node* curr = stack.back();
      stack.pop_back();

      if (visited.count(curr)) {
        continue;
      }

      visited.insert(curr);

      for (Node* neighbor : curr->neighbors) {
        if (!visited.count(neighbor)) {
          stack.push_back(neighbor);
        }
      }
    }

    // Delete all nodes
    for (Node* n : visited) {
      delete n;
    }
  }

  // Helper function to compare two graphs
  bool areGraphsEqual(Node* node1, Node* node2) {
    if (node1 == nullptr && node2 == nullptr) {
      return true;
    }

    if (node1 == nullptr || node2 == nullptr) {
      return false;
    }

    // Make sure they're different objects (actual clones)
    if (node1 == node2) {
      return false;
    }

    std::unordered_map<Node*, Node*> visited;
    std::vector<std::pair<Node*, Node*>> stack = {{node1, node2}};

    while (!stack.empty()) {
      auto [n1, n2] = stack.back();
      stack.pop_back();

      // Check if we've already compared these nodes
      if (visited.count(n1)) {
        if (visited[n1] != n2) {
          return false;
        }
        continue;
      }

      visited[n1] = n2;

      // Check values
      if (n1->val != n2->val) {
        return false;
      }

      // Check neighbor count
      if (n1->neighbors.size() != n2->neighbors.size()) {
        return false;
      }

      // Check that they're different objects
      if (n1 == n2) {
        return false;
      }

      // Check neighbors recursively
      for (size_t i = 0; i < n1->neighbors.size(); ++i) {
        Node* neighbor1 = n1->neighbors[i];
        Node* neighbor2 = n2->neighbors[i];

        if (neighbor1->val != neighbor2->val) {
          return false;
        }

        if (!visited.count(neighbor1)) {
          stack.push_back({neighbor1, neighbor2});
        }
      }
    }

    return true;
  }
};

TEST_F(CloneGraphTest, TestCase1) {
  // Graph: [[2,4],[1,3],[2,4],[1,3]]
  Node* original = createGraph({{2, 4}, {1, 3}, {2, 4}, {1, 3}});
  Node* cloned = solution.cloneGraph(original);

  EXPECT_TRUE(areGraphsEqual(original, cloned));

  deleteGraph(original);
  deleteGraph(cloned);
}

TEST_F(CloneGraphTest, TestCase2) {
  // Graph: [[]]
  Node* original = createGraph({{}});
  Node* cloned = solution.cloneGraph(original);

  EXPECT_TRUE(areGraphsEqual(original, cloned));

  deleteGraph(original);
  deleteGraph(cloned);
}

TEST_F(CloneGraphTest, TestCase3) {
  // Graph: []
  Node* original = nullptr;
  Node* cloned = solution.cloneGraph(original);

  EXPECT_EQ(cloned, nullptr);
}

TEST_F(CloneGraphTest, TestCase4) {
  // Graph: [[2],[1]]
  Node* original = createGraph({{2}, {1}});
  Node* cloned = solution.cloneGraph(original);

  EXPECT_TRUE(areGraphsEqual(original, cloned));

  deleteGraph(original);
  deleteGraph(cloned);
}
