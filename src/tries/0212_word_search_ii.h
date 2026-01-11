#pragma once

#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class TrieNode {
 public:
  unordered_map<char, TrieNode*> children;
  int ref;  // Index of word in the original words array (-1 if not a word end)

  TrieNode() : ref(-1) {}
};

class Solution {
 public:
  // Time: O(m * n * 4^l) | Space: O(N * K)
  // m*n is board size, l is max word length
  // N is number of words, K is average word length
  // Finds all words from the dictionary that exist in the board
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // Build Trie from words
    build(words);

    int m = board.size();
    int n = board[0].size();

    // DFS + Backtracking to search for words
    std::function<void(int, int, TrieNode*)> dfs = [&](int r, int c, TrieNode* node) {
      // Out of bounds check
      if (r < 0 || r >= m || c < 0 || c >= n) {
        return;
      }

      char temp = board[r][c];

      // If cell is already visited or character doesn't exist in trie
      if (temp == '#' || !node->children.contains(temp)) {
        return;
      }

      // Move to next node in trie
      node = node->children[temp];

      // If we found a complete word, add it to results
      if (node->ref != -1) {
        res.push_back(words[node->ref]);
        node->ref = -1;  // Remove the index marker to avoid duplicates
      }

      // Mark current cell as visited
      board[r][c] = '#';

      // Explore all 4 directions
      dfs(r + 1, c, node);  // down
      dfs(r - 1, c, node);  // up
      dfs(r, c + 1, node);  // right
      dfs(r, c - 1, node);  // left

      // Restore the cell (backtrack)
      board[r][c] = temp;
    };

    // Start DFS from each cell
    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        dfs(r, c, root);
      }
    }

    return res;
  }

 private:
  TrieNode* root;
  vector<string> res;

  // Build Trie from words list
  void build(const vector<string>& words) {
    root = new TrieNode();
    for (int i = 0; i < words.size(); i++) {
      TrieNode* node = root;
      for (char c : words[i]) {
        if (!node->children.contains(c)) {
          node->children[c] = new TrieNode();
        }
        node = node->children[c];
      }
      node->ref = i;  // Mark the end of word with its index
    }
  }
};
