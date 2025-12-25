#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, 1);

    // Go through the array and calculate the product of all the elements to the
    // left of the current element
    int left = 1;
    for (int i = 0; i < n; i++) {
      res[i] = left;
      left *= nums[i];
    }

    // Go through the array again and calculate the product of all the elements
    // to the right of the current element
    int right = 1;
    for (int i = n - 1; i >= 0; i--) {
      res[i] *= right;
      right *= nums[i];
    }

    // The result is the product of all the elements to the left and right of
    // the current element
    return res;
  }

  // Time: O(n) | Space: O(n)
  // Easier to understand
  vector<int> productExceptSelf2(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n);
    vector<int> prefix(n, 1);  // prefix product
    vector<int> suffix(n, 1);  // suffix product

    for (int i = 1; i < n; ++i)
      prefix[i] = prefix[i - 1] * nums[i - 1];

    for (int i = n - 2; i >= 0; --i)
      suffix[i] = suffix[i + 1] * nums[i + 1];

    for (int i = 0; i < n; ++i)
      res[i] = prefix[i] * suffix[i];

    return res;
  }
};
