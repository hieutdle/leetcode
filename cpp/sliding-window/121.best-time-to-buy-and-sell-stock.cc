/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (54.49%)
 * Likes:    32174
 * Dislikes: 1229
 * Total Accepted:    5.7M
 * Total Submissions: 10.4M
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * You are given an array prices where prices[i] is the price of a given stock
 * on the i^th day.
 *
 * You want to maximize your profit by choosing a single day to buy one stock
 * and choosing a different day in the future to sell that stock.
 *
 * Return the maximum profit you can achieve from this transaction. If you
 * cannot achieve any profit, return 0.
 *
 *
 * Example 1:
 *
 *
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit
 * = 6-1 = 5.
 * Note that buying on day 2 and selling on day 1 is not allowed because you
 * must buy before you sell.
 *
 *
 * Example 2:
 *
 *
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transactions are done and the max profit =
 * 0.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= prices.length <= 10^5
 * 0 <= prices[i] <= 10^4
 *
 *
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) {
      return 0;
    }

    // int profit = 0;
    // int res = 0;

    // for (int i = 1; i < n; i++) {
    //   // The profit between two points
    //   // is equal to the sum of the differences
    //   // between all the points in between
    //   profit += prices[i] - prices[i - 1];

    //   // We should not start to buy profit if it is negative
    //   if (profit < 0) {
    //     profit = 0;
    //   }

    //   res = max(res, profit);
    // }

    // return res;
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < n; i++) {
      if (prices[i] < minPrice) {
        minPrice = prices[i];
      } else {
        maxProfit = max(maxProfit, prices[i] - minPrice);
      }
    }

    return maxProfit;
  }
};
// @lc code=end
