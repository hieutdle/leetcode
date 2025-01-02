/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> result;

    for (string s : strs) {
      string t = s;
      sort(t.begin(), t.end());
      m[t].emplace_back(s);
    }

    for (auto &n : m) {
      result.emplace_back(n.second);
    }

    return result;
  }
};
// @lc code=end
