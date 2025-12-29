#include <gtest/gtest.h>

#include "0424_longest_repeating_character_replacement.h"

class LongestRepeatingCharacterReplacementTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(LongestRepeatingCharacterReplacementTest, TestCase1) {
  std::string s = "ABAB";
  int k = 2;
  int expected = 4;

  auto output = solution.characterReplacement(s, k);
  EXPECT_EQ(output, expected);

  auto output2 = solution.characterReplacement2(s, k);
  EXPECT_EQ(output2, expected);
}

TEST_F(LongestRepeatingCharacterReplacementTest, TestCase2) {
  std::string s = "AABABBA";
  int k = 1;
  int expected = 4;

  auto output = solution.characterReplacement(s, k);
  EXPECT_EQ(output, expected);

  auto output2 = solution.characterReplacement2(s, k);
  EXPECT_EQ(output2, expected);
}