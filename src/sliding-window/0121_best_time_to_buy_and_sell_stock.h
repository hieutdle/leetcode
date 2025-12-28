#pragma once

#include <vector>

using std::vector;

class Solution {
 public:
  // Time: O(n) | Space: O(1)
  // Greedy
  int maxProfit(vector<int>& prices) {
    if (prices.empty())
      return 0;

    int minPrice = prices[0];
    int res = 0;

    // Calculate the difference between current price and minPrice in front of it.
    for (int& price : prices) {
      // price - minPrice is the current profit
      res = std::max(res, price - minPrice);
      // Only update minPrice when we find a new lower price
      minPrice = std::min(minPrice, price);
    }
    return res;
  }

  // Time: O(n) | Space: O(1)
  // Kadane's Algorithm
  int maxProfit2(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) {
      return 0;
    }

    int profit = 0;
    int res = 0;

    // Instead of prices:
    // prices:     [7, 1, 5, 3, 6, 4]
    // diffs:        [ , -6, 4, -2, 3, -2]
    // Find the maximum contiguous subarray sum
    for (int i = 1; i < n; i++) {
      // The profit between two points
      // is equal to the sum of the differences
      // between all the points in between
      profit += prices[i] - prices[i - 1];

      // We should not start to buy profit if it is negative
      if (profit < 0) {
        profit = 0;
      }

      res = std::max(res, profit);
    }

    return res;
  }
};
