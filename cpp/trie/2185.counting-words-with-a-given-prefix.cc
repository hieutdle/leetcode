/*
 * @lc app=leetcode id=2185 lang=cpp
 *
 * [2185] Counting Words With a Given Prefix
 *
 * https://leetcode.com/problems/counting-words-with-a-given-prefix/description/
 *
 * algorithms
 * Easy (78.75%)
 * Likes:    1015
 * Dislikes: 32
 * Total Accepted:    235.9K
 * Total Submissions: 280.1K
 * Testcase Example:  '["pay","attention","practice","attend"]\n"at"'
 *
 * You are given an array of strings words and a string pref.
 *
 * Return the number of strings in words that contain pref as a prefix.
 *
 * A prefix of a string s is any leading contiguous substring of s.
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["pay","attention","practice","attend"], pref = "at"
 * Output: 2
 * Explanation: The 2 strings that contain "at" as a prefix are: "attention"
 * and "attend".
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["leetcode","win","loops","success"], pref = "code"
 * Output: 0
 * Explanation: There are no strings that contain "code" as a prefix.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length, pref.length <= 100
 * words[i] and pref consist of lowercase English letters.
 *
 *
 */

#include <string>
#include <vector>

using namespace std;
// @lc code=start

const int kAlphabetSize = 26;

class Trie {
  struct TrieNode {
    TrieNode* children[kAlphabetSize];
    int count;

    TrieNode() {
      count = 0;
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
      node->count++;
    }
  }

  int count(string prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
      int index = c - 'a';
      if (node->children[index] == nullptr) {
        return 0;
      }
      node = node->children[index];
    }
    return node->count;
  }
};

class Solution {
 public:
  int prefixCount(vector<string>& words, string pref) {
    // Trie
    // Trie trie;
    // for (string word : words) {
    //   trie.insert(word);
    // }
    // return trie.count(pref);

    // Short
    // int res = 0;
    // for (const auto& word : words) {
    //   if (word.find(pref) == 0) {
    //     res++;
    //   }
    // }
    // return res;

    // Brute force
    int res = 0;            // Initialize the answer count to 0
    int n = pref.length();  // Get the length of the prefix

    // Iterate through each word in the words vector
    for (const string& word : words) {
      if (word.length() < n) {
        continue;
      }

      bool match = true;
      for (int i = 0; i < n; ++i) {
        if (word[i] != pref[i]) {
          match = false;
          break;
        }
      }

      if (match) {
        res++;
      }
    }

    return res;
  }
};
// @lc code=end
