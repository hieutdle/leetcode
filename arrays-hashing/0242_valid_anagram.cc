#include <string>

using std::string;

class Solution {
 public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;

    int counts[26] = {0};
    for (int i = 0; i < s.size(); i++) {
      counts[s[i] - 'a']++;
      counts[t[i] - 'a']--;
    }

    for (auto& count : counts)
      if (count != 0) return false;

    return true;
  }
};
