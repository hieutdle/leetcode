#pragma once

#include <functional>
#include <unordered_set>
#include <vector>

using std::function;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(n)
  // DFS approach
  // A valid tree must satisfy two conditions:
  // 1. All nodes must be connected (no disconnected components)
  // 2. There must be no cycles
  bool validTree(int n, vector<vector<int>>& edges) {
    // A tree with n nodes must have exactly n-1 edges
    // If you have n nodes, n-1 edges, and are fully connected
    // it is mathematically impossible to have a cycle.
    if (edges.size() != n - 1) {
      return false;
    }

    // This declares a C-style array named g of size n.
    // The type of elements in this array is vector<int>.
    vector<int> graph[n];
    // One single vector named visited that initially contains n integers
    vector<int> visited(n);

    // Build the undirected graph (two ways)
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    // DFS to traverse the graph
    function<void(int)> dfs = [&](int node) -> void {
      // We first mark the node as visited
      visited[node] = true;
      --n;

      // Traverse the nodes adjacent to this node
      for (int neighbor : graph[node]) {
        // If neighbor hasn't been visited, continue DFS
        if (!visited[neighbor]) {
          dfs(neighbor);
        }
      }
    };

    // Start DFS from node 0
    dfs(0);

    // If all nodes were visited, n should be 0
    // If there are nodes that have not been visited
    //it means that it cannot form a tree
    return n == 0;
  }

  // Time: O(V + E) | Space: O(V)
  // Union-Find (Disjoint Set Union) approach
  bool validTree2(int n, vector<vector<int>>& edges) {
    // A tree with n nodes must have exactly n-1 edges
    if (edges.size() != n - 1) {
      return false;
    }

    // Initialize parent array for Union-Find (Disjoint Set Union)
    // Each node initially points to itself as its parent
    vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }

    // Find function with path compression
    // Returns the root parent of node x
    // Make every node running this function point to the same root parent
    function<int(int)> find = [&](int x) -> int {
      if (parent[x] != x) {
        // Path compression: make x point directly to root
        parent[x] = find(parent[x]);
      }
      return parent[x];
    };

    // Process each edge
    for (auto& edge : edges) {
      // Find root parents of both nodes
      int rootA = find(edge[0]);
      int rootB = find(edge[1]);

      // If both nodes have the same root, adding this edge creates a cycle
      if (rootA == rootB) {
        return false;
      }

      // Union: connect the two components by making one root point to the other
      parent[rootA] = rootB;

      // Decrease the number of connected components
      --n;
    }

    // A valid tree should have exactly one connected component
    return true;
  }
};
