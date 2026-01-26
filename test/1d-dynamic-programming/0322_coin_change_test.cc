#include <gtest/gtest.h>

#include "0322_coin_change.h"

class CoinChangeTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(CoinChangeTest, TestCase1) {
  vector<int> coins = {1, 2, 5};
  int amount = 11;
  int expected = 3;  // 11 = 5 + 5 + 1

  int output = solution.coinChange(coins, amount);
  EXPECT_EQ(output, expected);
}

TEST_F(CoinChangeTest, TestCase2) {
  vector<int> coins = {2};
  int amount = 3;
  int expected = -1;  // Cannot make amount 3 with only coin of value 2

  int output = solution.coinChange(coins, amount);
  EXPECT_EQ(output, expected);
}

TEST_F(CoinChangeTest, TestCase3) {
  vector<int> coins = {1};
  int amount = 0;
  int expected = 0;  // 0 coins needed to make amount 0

  int output = solution.coinChange(coins, amount);
  EXPECT_EQ(output, expected);
}