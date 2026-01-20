#pragma once

#include <functional>
#include <queue>
#include <vector>

using std::function;
using std::queue;
using std::vector;

class Solution {
 public:
  // Time: O(V + E * α(V)) | Space: O(V)
  // Union-Find (Disjoint Set Union) approach
  // α(V) is the inverse Ackermann function, which grows extremely slowly
  // and can be regarded as a very small constant.
  int countComponents(int n, vector<vector<int>>& edges) {
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

    // Union function
    function<void(int, int)> unite = [&](int x, int y) -> void {
      int rootA = find(x);
      int rootB = find(y);

      // If the merge is successful
      // nodes a and b were not in the same connected component before
      // and the number of connected components decreases by one
      if (rootA != rootB) {
        parent[rootA] = rootB;
        --n;  // Decrease count of components
      }
    };

    // Process all edges
    for (const auto& edge : edges) {
      unite(edge[0], edge[1]);
    }

    return n;
  }

  // Time: O(V + E) | Space: O(V + E)
  // DFS approach
  // Each DFS connects all nodes in a connected component
  // If we find an unvisited node, it indicates a new connected component
  int countComponents2(int n, vector<vector<int>>& edges) {
    // Build adjacency list representation of the graph
    vector<int> graph[n];
    for (const auto& edge : edges) {
      // Add bidirectional edges (undirected graph)
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    // Track visited nodes
    vector<bool> visited(n, false);
    // Number of connected components
    int res = 0;

    // DFS to mark all nodes in a component
    function<void(int)> dfs = [&](int node) -> void {
      visited[node] = true;

      for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
          dfs(neighbor);
        }
      }
    };

    // Iterate through all nodes
    for (int i = 0; i < n; ++i) {
      // If node i is not visited before, it's a new component
      if (!visited[i]) {
        ++res;
        dfs(i);
      }
    }

    return res;
  }

  // Time: O(V + E) | Space: O(V + E)
  // BFS approach
  // Each BFS connects all nodes in a connected component
  // If we find an unvisited node, it indicates a new connected component
  int countComponents3(int n, vector<vector<int>>& edges) {
    // Build adjacency list representation of the graph
    vector<int> graph[n];
    for (const auto& edge : edges) {
      // Add bidirectional edges (undirected graph)
      graph[edge[0]].push_back(edge[1]);
      graph[edge[1]].push_back(edge[0]);
    }

    // Track visited nodes
    vector<bool> visited(n, false);
    // Number of connected components
    int res = 0;

    for (int i = 0; i < n; ++i) {
      // Skip already visited nodes
      if (visited[i])
        continue;

      // We found a node that hasn't been touched yet during previous BFS traversals.
      // This indicates the start of a new Connected Component.
      visited[i] = true;
      ++res;

      // Start BFS from node i
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
          if (!visited[neighbor]) {
            visited[neighbor] = true;
            q.push(neighbor);
          }
        }
      }
    }

    return res;
  }
};
