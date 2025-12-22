#include <gtest/gtest.h>

#include "../../src/arrays-hashing/0242_valid_anagram.cc"

class ValidAnagramTest : public ::testing::Test {
protected:
  Solution solution;
};

TEST_F(ValidAnagramTest, ValidAnagram) {
  std::string s = "anagram";
  std::string t = "nagaram";
  EXPECT_TRUE(solution.isAnagram(s, t));
}

TEST_F(ValidAnagramTest, InvalidAnagram) {
  std::string s = "rat";
  std::string t = "car";
  EXPECT_FALSE(solution.isAnagram(s, t));
}

TEST_F(ValidAnagramTest, SameString) {
  std::string s = "listen";
  std::string t = "listen";
  EXPECT_TRUE(solution.isAnagram(s, t));
}

TEST_F(ValidAnagramTest, DifferentLengths) {
  std::string s = "ab";
  std::string t = "a";
  EXPECT_FALSE(solution.isAnagram(s, t));
}

TEST_F(ValidAnagramTest, SingleCharacter) {
  std::string s = "a";
  std::string t = "a";
  EXPECT_TRUE(solution.isAnagram(s, t));
}

TEST_F(ValidAnagramTest, EmptyStrings) {
  std::string s = "";
  std::string t = "";
  EXPECT_TRUE(solution.isAnagram(s, t));
}

TEST_F(ValidAnagramTest, CaseSensitive) {
  std::string s = "abc";
  std::string t = "ABC";
  // Assuming lowercase only based on the implementation
  // If the implementation is case-sensitive, this should be false
  EXPECT_FALSE(solution.isAnagram(s, t));
}
