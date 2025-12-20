#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // Hashmap to store the number as a key, and store the index as a value
    std::unordered_map<int, int> m;

    for (int idx = 0;; ++idx) {
      int x = nums[idx];
      int y = target - x;
      // Check if the corresponding number is already in the map or not.
      if (m.contains(y)) {
        // Return the index of corresponding number
        // and the index of the current number
        return {m[x], idx};
      }
      // Otherwise store the number and the index in the map
      m.insert({x, idx});
    }

    // This line should never be reached if input guarantees a solution
    return {};
  }
};
