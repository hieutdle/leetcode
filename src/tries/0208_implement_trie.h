#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

// TrieNode represents a single node in the Trie
class TrieNode {
 public:
  unordered_map<char, TrieNode*> children;
  bool is_end_of_word;

  TrieNode() : is_end_of_word(false) {}
};

// Trie (Prefix Tree) implementation
class Trie {
 private:
  TrieNode* root;

 public:
  // Time: O(1) | Space: O(1)
  Trie() {
    root = new TrieNode();
  }

  // Time: O(n) | Space: O(n)
  // n is the length of the word
  // Inserts a word into the trie
  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      // If character doesn't exist, create a new node
      if (!node->children.contains(c)) {
        node->children[c] = new TrieNode();
      }
      // Move to the next node
      node = node->children[c];
    }
    // Mark the end of the word
    node->is_end_of_word = true;
  }

  // Time: O(n) where n is the length of the word | Space: O(1)
  // Returns true if the word is in the trie
  bool search(string word) {
    TrieNode* node = root;
    for (char c : word) {
      // If character doesn't exist, word is not in trie
      if (node->children.find(c) == node->children.end()) {
        return false;
      }
      // Move to the next node
      node = node->children[c];
    }
    // Check if it's the end of a word
    return node->is_end_of_word;
  }

  // Time: O(n) where n is the length of the prefix | Space: O(1)
  // Returns true if there is any word in the trie that starts with the given
  // prefix
  bool startsWith(string prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
      // If character doesn't exist, no word with this prefix
      if (node->children.find(c) == node->children.end()) {
        return false;
      }
      // Move to the next node
      node = node->children[c];
    }
    // If we've traversed the entire prefix, it exists
    return true;
  }

  // Destructor to free memory
  ~Trie() {
    deleteTrie(root);
  }

 private:
  // Helper function to recursively delete all nodes
  void deleteTrie(TrieNode* node) {
    if (!node)
      return;
    for (auto& pair : node->children) {
      deleteTrie(pair.second);
    }
    delete node;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */