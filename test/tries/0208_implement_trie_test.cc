#include <gtest/gtest.h>

#include "0208_implement_trie.h"

class ImplementTrieTest : public ::testing::Test {
 protected:
  Trie* trie;

  void SetUp() override {
    trie = new Trie();
  }

  void TearDown() override {
    delete trie;
  }
};

TEST_F(ImplementTrieTest, TestCase1) {
  trie->insert("apple");
  EXPECT_TRUE(trie->search("apple"));
  EXPECT_FALSE(trie->search("app"));
  EXPECT_TRUE(trie->startsWith("app"));
  trie->insert("app");
  EXPECT_TRUE(trie->search("app"));
}