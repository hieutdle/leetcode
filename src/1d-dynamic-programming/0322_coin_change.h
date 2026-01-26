#pragma once

#include <algorithm>
#include <vector>

using std::min;
using std::vector;

class Solution {
 public:
  // Time: O(amount * n) | Space: O(amount)
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) {
      return 0;
    }

    // dp[i] represents the minimum number of coins needed to make amount i
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;  // Base case: 0 coins needed to make amount 0

    // For each amount from 1 to target amount
    for (int i = 1; i <= amount; i++) {
      // Try each coin
      for (int coin : coins) {
        if (coin <= i) {
          // If we can use this coin, update dp[i] with minimum
          // dp[i - coin] + 1 means: coins needed for (amount - coin) + this
          // coin
          // coin = 4
          // dp[7] = min(dp[7], dp[7-4] + 1)
          dp[i] = min(dp[i], dp[i - coin] + 1);
        }
      }
    }

    // If dp[amount] is still amount + 1, it means we couldn't make the amount
    if (dp[amount] == amount + 1) {
      return -1;
    }

    return dp[amount];
  }
};
