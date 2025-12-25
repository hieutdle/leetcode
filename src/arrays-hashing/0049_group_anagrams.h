#pragma once

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  // Time: O(n * k log k) | Space: O(n * k)
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;

    for (const string& s : strs) {
      // Create a sorted string as key
      string k = s;
      sort(k.begin(), k.end());
      m[k].emplace_back(s);
    }

    res.reserve(m.size());
    for (auto& n : m) {
      res.emplace_back(n.second);
    }

    return res;
  }

  // Time: O(n * k) | Space: O(n * k)
  vector<vector<string>> groupAnagrams2(vector<string>& strs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;

    for (auto& s : strs) {
      int cnt[26] = {0};
      for (auto& c : s)
        ++cnt[c - 'a'];
      string k;
      // Words that are anagrams produce the same key.
      // "eat" → 'a1e1t1'
      for (int i = 0; i < 26; ++i) {
        if (cnt[i]) {
          k += 'a' + i;
          k += to_string(cnt[i]);
        }
      }
      m[k].emplace_back(s);
    }

    res.reserve(m.size());
    for (auto& n : m) {
      res.push_back(n.second);
    }

    return res;
  }
};
