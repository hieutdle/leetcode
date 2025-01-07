/*
 * @lc app=leetcode id=1408 lang=cpp
 *
 * [1408] String Matching in an Array
 *
 * https://leetcode.com/problems/string-matching-in-an-array/description/
 *
 * algorithms
 * Easy (64.26%)
 * Likes:    1158
 * Dislikes: 104
 * Total Accepted:    165.4K
 * Total Submissions: 244.4K
 * Testcase Example:  '["mass","as","hero","superhero"]'
 *
 * Given an array of string words, return all strings in words that is a
 * substring of another word. You can return the answer in any order.
 *
 * A substring is a contiguous sequence of characters within a string
 *
 *
 * Example 1:
 *
 *
 * Input: words = ["mass","as","hero","superhero"]
 * Output: ["as","hero"]
 * Explanation: "as" is substring of "mass" and "hero" is substring of
 * "superhero".
 * ["hero","as"] is also a valid answer.
 *
 *
 * Example 2:
 *
 *
 * Input: words = ["leetcode","et","code"]
 * Output: ["et","code"]
 * Explanation: "et", "code" are substring of "leetcode".
 *
 *
 * Example 3:
 *
 *
 * Input: words = ["blue","green","bu"]
 * Output: []
 * Explanation: No string of words is substring of another string.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= words.length <= 100
 * 1 <= words[i].length <= 30
 * words[i] contains only lowercase English letters.
 * All the strings of words are unique.
 *
 *
 */

#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> res;

    // Bruteforce solution
    for (int i = 0; i < words.size(); i++) {
      // Nested loop to compare the current word with every other word in the vector
      for (int j = 0; j < words.size(); j++) {
        // Check if the current word is a substring of any other word, but not the same word
        if (i != j && words[j].find(words[i]) != string::npos) {
          res.push_back(words[i]);
          break;
        }
      }
    }

    // Can not use Trie
    // Can check for ma in mas, but can not check for as in mass

    // We can implement a search method that checks if a node has children,
    // but this doesn't handle the fact that substrings can appear anywhere within the string.

    return res;
  }
};
// @lc code=end
