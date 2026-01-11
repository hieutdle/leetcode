#pragma once

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

class WordDictionaryNode {
 public:
  unordered_map<char, WordDictionaryNode*> children;
  bool is_end_of_word;

  WordDictionaryNode() : is_end_of_word(false) {}
};

class WordDictionary {
 public:
  WordDictionary() {
    root = new WordDictionaryNode();
  }

  // Time: O(n) | Space: O(n)
  // Adds a word into the data structure
  void addWord(string word) {
    WordDictionaryNode* node = root;
    for (char c : word) {
      if (!node->children.contains(c)) {
        node->children[c] = new WordDictionaryNode();
      }
      node = node->children[c];
    }
    node->is_end_of_word = true;
  }

  // Time: O(n) | Space: O(n)
  // Returns true if the word is in the data structure.
  // The word can contain '.' which matches any single letter
  bool search(string word) {
    return dfs(word, 0, root);
  }

 private:
  WordDictionaryNode* root;

  bool dfs(const string& word, int index, WordDictionaryNode* node) {
    if (index == word.length()) {
      return node->is_end_of_word;
    }

    char c = word[index];

    if (c == '.') {
      // Wildcard: try all possible children
      for (auto& pair : node->children) {
        if (dfs(word, index + 1, pair.second)) {
          return true;
        }
      }
      return false;
    } else {
      // Regular character: check if it exists
      if (!node->children.contains(c)) {
        return false;
      }
      return dfs(word, index + 1, node->children[c]);
    }
  }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
