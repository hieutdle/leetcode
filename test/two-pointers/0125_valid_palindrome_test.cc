#include <gtest/gtest.h>

#include "0125_valid_palindrome.h"

class ValidPalindromeTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(ValidPalindromeTest, TestCase1) {
  std::string s = "A man, a plan, a canal: Panama";
  bool expected = true;

  auto output = solution.isPalindrome(s);
  EXPECT_EQ(output, expected);
}

TEST_F(ValidPalindromeTest, TestCase2) {
  std::string s = "race a car";
  bool expected = false;

  auto output = solution.isPalindrome(s);
  EXPECT_EQ(output, expected);
}

TEST_F(ValidPalindromeTest, TestCase3) {
  std::string s = " ";
  bool expected = true;

  auto output = solution.isPalindrome(s);
  EXPECT_EQ(output, expected);
}
