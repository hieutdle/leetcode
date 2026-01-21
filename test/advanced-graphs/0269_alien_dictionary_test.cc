#include <gtest/gtest.h>

#include <string>
#include <unordered_set>
#include <vector>

#include "0269_alien_dictionary.h"

class AlienDictionaryTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(AlienDictionaryTest, TestCase1) {
  vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
  string expected = "wertf";

  string output = solution.alienOrder(words);
  EXPECT_EQ(output, expected);
}

TEST_F(AlienDictionaryTest, TestCase2) {
  vector<string> words = {"z", "x", "z"};
  string expected = "";

  string output = solution.alienOrder(words);
  EXPECT_EQ(output, expected);
}