#pragma once

#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::queue;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(26)
  // Topological Sort (BFS - Kahn's Algorithm)
  string alienOrder(vector<string>& words) {
    // Build adjacency list and in-degree map
    unordered_map<char, unordered_set<char>> g;
    unordered_map<char, int> in_degree;

    // Initialize all characters from the words
    for (const auto& word : words) {
      for (char c : word) {
        if (!g.contains(c)) {
          g[c] = {};
          in_degree[c] = 0;
        }
      }
    }

    // Build the graph by comparing adjacent words
    for (size_t i = 0; i < words.size() - 1; ++i) {
      const string& word1 = words[i];
      const string& word2 = words[i + 1];

      // Check for invalid case: prefix is longer than the word it's prefixing
      // e.g., ["abc", "ab"]
      if (word1.length() > word2.length() && word1.substr(0, word2.length()) == word2) {
        return "";
      }

      // Find the first differing character
      // Calculate minimum length to avoid out-of-bounds
      size_t min_len = std::min(word1.length(), word2.length());
      for (size_t j = 0; j < min_len; ++j) {
        if (word1[j] != word2[j]) {
          // Add edge from word1[j] -> word2[j]
          // Only add if not already present (to avoid duplicate edges)
          if (!g[word1[j]].contains(word2[j])) {
            g[word1[j]].insert(word2[j]);
            in_degree[word2[j]]++;
          }
          break;  // Only need the first difference
        }
      }
    }

    // Topological sort using Kahn's algorithm
    // Initialize queue with all characters having indegree 0
    // Problem does not require a unique or specific order
    // If there are multiple valid orders, return any of them
    queue<char> q;
    for (const auto& [node, degree] : in_degree) {
      if (degree == 0) {
        q.push(node);
      }
    }

    // Perform topological sort using Kahn's algorithm
    string res;
    while (!q.empty()) {
      char curr = q.front();
      q.pop();
      res += curr;

      // Decrease in-degree for neighbors
      for (char neighbor : g[curr]) {
        in_degree[neighbor]--;
        if (in_degree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    // If result doesn't contain all characters, there's a cycle
    if (res.length() != in_degree.size()) {
      return "";
    }

    return res;
  }
};
