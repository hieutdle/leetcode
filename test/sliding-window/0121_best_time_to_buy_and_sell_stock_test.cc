#include <gtest/gtest.h>

#include "0121_best_time_to_buy_and_sell_stock.h"

class BestTimeToBuyAndSellStockTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(BestTimeToBuyAndSellStockTest, TestCase1) {
  std::vector<int> prices = {7, 1, 5, 3, 6, 4};
  int expected = 5;

  auto output = solution.maxProfit(prices);
  EXPECT_EQ(output, expected);

  auto output2 = solution.maxProfit2(prices);
  EXPECT_EQ(output2, expected);
}

TEST_F(BestTimeToBuyAndSellStockTest, TestCase2) {
  std::vector<int> prices = {7, 6, 4, 3, 1};
  int expected = 0;

  auto output = solution.maxProfit(prices);
  EXPECT_EQ(output, expected);

  auto output2 = solution.maxProfit2(prices);
  EXPECT_EQ(output2, expected);
}