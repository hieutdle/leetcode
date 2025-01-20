/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (67.00%)
 * Likes:    11839
 * Dislikes: 146
 * Total Accepted:    1.2M
 * Total Submissions: 1.8M
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */

#include <string>

using namespace std;

// @lc code=start

const int kAlphabetSize = 26;

class Trie {
  struct TrieNode {
    TrieNode* children[kAlphabetSize];
    bool isEnd;

    TrieNode() {
      isEnd = false;
      // Initialize all children to nullptr
      // If not, the children will be garbage values
      // uninitialized memory / Undefined Behavior
      for (int i = 0; i < kAlphabetSize; i++) {
        children[i] = nullptr;
      }
    }
  };

 public:
  TrieNode* root;

  Trie() { root = new TrieNode(); }

  void insert(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int index = c - 'a';  // 'a' = 97. 'b' - 'a' = 1 => a 0 b 1 c 2 ...
      if (node->children[index] == nullptr) {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }
    node->isEnd = true;
  }

  bool search(string word) {
    TrieNode* node = root;
    for (char c : word) {
      int index = c - 'a';
      if (node->children[index] == nullptr) {
        return false;
      }
      node = node->children[index];
    }
    return node->isEnd;
  }

  bool startsWith(string prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
      int index = c - 'a';
      if (node->children[index] == nullptr) {
        return false;
      }
      node = node->children[index];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
