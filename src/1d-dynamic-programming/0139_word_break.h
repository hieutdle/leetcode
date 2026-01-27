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
  bool is_end_of_word;

  TrieNode() : is_end_of_word(false) {}

  void insert(const string& word) {
    TrieNode* node = this;
    for (char c : word) {
      if (!node->children.contains(c)) {
        node->children[c] = new TrieNode();
      }
      node = node->children[c];
    }
    node->is_end_of_word = true;
  }
};

class Solution {
 public:
  // Time: O(n^2 * m) | Space: O(n)
  // Where n is length of s, m is average length of words
  // Dynamic Programming approach
  bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    if (n == 0) {
      return true;
    }

    // Convert wordDict to a set for O(1) lookup
    unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

    // dp[i] := true if s[0..i-1] can be segmented into words from dictionary
    vector<bool> dp(n + 1, false);
    dp[0] = true;  // Empty string can always be segmented

    // To know if s[0:i] can be segmented, we need to find a split point j
    // The prefix s[0:j] can be segmented (we've already computed this)
    // The remaining part s[j:i] is a valid word in our dictionary

    // s = "catdog" and wordDict = ["cat", "dog", "catdo"].
    // i = 2
    // j = 0: Check if f[0] is True AND "ca" is in words
    // f[0] = True, but "ca" ∉ words
    // j = 1: Check if f[1] is True AND "a" is in words
    // f[1] = False, so skip
    // i = 3
    // j = 0: Check if f[0] is True AND "cat" is in words
    // f[0] = True AND "cat" ∈ words → f[3] = True
    // i = 4
    // j = 0: Check if f[0] is True AND "catd" is in words
    // f[0] = True, but "catd" ∉ words
    // j = 1: Check if f[1] is True AND "atd" is in words
    // f[1] = False, so skip
    // j = 2: Check if f[2] is True AND "td" is in words
    // f[2] = False, so skip
    // j = 3: Check if f[3] is True AND "d" is in words
    // f[3] = True, but "d" ∉ words
    // f[4] = False

    // For each position i in the string
    for (int i = 1; i <= n; ++i) {
      // Check all possible split positions before index i
      for (int j = 0; j < i; ++j) {
        // If s[0...j-1] can be segmented (dp[j] is true)
        // AND s[j...i-1] exists in the dictionary
        // Then s[0...i-1] can also be segmented
        if (dp[j] && wordSet.contains(s.substr(j, i - j))) {
          dp[i] = true;
          break;  // Found a valid segmentation, no need to check further
        }
      }
    }

    return dp[n];
  }

  // Time: O(n^2 + N * K) | Space: O(N * K + n)
  // Where n is length of s, N is number of words, K is average word length
  // Trie + Backward DP
  bool wordBreak2(string s, vector<string>& wordDict) {
    // Build Trie from wordDict
    TrieNode* root = new TrieNode();
    for (const string& word : wordDict) {
      root->insert(word);
    }

    int n = s.length();
    // dp[i] := true if s[i..n-1] can be segmented into words from dictionary
    vector<bool> dp(n + 1, false);
    dp[n] = true;  // Empty suffix can always be segmented

    // Iterate backwards from end of string to beginning
    for (int i = n - 1; i >= 0; --i) {
      // Try to match words starting from position i using the Trie
      TrieNode* node = root;
      for (int j = i; j < n; ++j) {
        char c = s[j];
        // If character doesn't exist in trie, no more words to match
        if (!node->children.contains(c)) {
          break;
        }
        // Move to the next node
        node = node->children[c];

        // If we found a complete word and the rest can be segmented
        if (node->is_end_of_word && dp[j + 1]) {
          dp[i] = true;
          break;  // Found a valid segmentation, no need to check further
        }
      }
    }

    return dp[0];
  }
};
