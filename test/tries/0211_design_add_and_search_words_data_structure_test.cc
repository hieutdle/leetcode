#include <gtest/gtest.h>

#include "0211_design_add_and_search_words_data_structure.h"

class DesignAddAndSearchWordsDataStructureTest : public ::testing::Test {
 protected:
  WordDictionary* wordDictionary;

  void SetUp() override {
    wordDictionary = new WordDictionary();
  }

  void TearDown() override {
    delete wordDictionary;
  }
};

TEST_F(DesignAddAndSearchWordsDataStructureTest, TestCase1) {
  wordDictionary->addWord("bad");
  wordDictionary->addWord("dad");
  wordDictionary->addWord("mad");
  EXPECT_FALSE(wordDictionary->search("pad"));
  EXPECT_TRUE(wordDictionary->search("bad"));
  EXPECT_TRUE(wordDictionary->search(".ad"));
  EXPECT_TRUE(wordDictionary->search("b.."));
}