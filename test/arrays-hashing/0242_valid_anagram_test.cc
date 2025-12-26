#include <gtest/gtest.h>

#include "0242_valid_anagram.h"

class ValidAnagramTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ValidAnagramTest, TestCase1) {
  std::string s = "anagram";
  std::string t = "nagaram";

  EXPECT_TRUE(solution.isAnagram(s, t));
}

TEST_F(ValidAnagramTest, TestCase2) {
  std::string s = "rat";
  std::string t = "car";

  EXPECT_FALSE(solution.isAnagram(s, t));
}