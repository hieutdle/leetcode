#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::vector;

class Solution {
public:
  // Time: O(n) | Space: O(n)
  // Hashmap with optimization
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    std::unordered_set<int> s(nums.begin(), nums.end());
    int res = 0;

    for (auto& num : s) {
      // Check if its the start of a sequence
      if (!s.contains(num - 1)) {
        int length = 0;

        while (s.contains(num + length)) {
          length++;
        }

        res = std::max(res, length);
      }
    }

    return res;
  }

  // Time: O(n) | Space: O(n)
  // d[x] = d[y] + y - x
  int longestConsecutive2(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    std::unordered_set<int> s(nums.begin(), nums.end());
    // Map to store the length of consecutive sequence starting from each number
    std::unordered_map<int, int> m;
    int res = 0;

    for (int x : nums) {
      int y = x;

      // Keep incrementing while consecutive numbers exist in the set
      while (s.contains(y)) {
        s.erase(y++);
      }

      // If y (the next number) already has a cached sequence length, add it to current calculation
      m[x] = (m.contains(y) ? m[y] : 0) + y - x;
      res = std::max(res, m[x]);
    }

    return res;
  }
};
