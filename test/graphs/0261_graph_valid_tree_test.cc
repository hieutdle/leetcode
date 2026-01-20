#include <gtest/gtest.h>

#include <vector>

#include "0261_graph_valid_tree.h"

class GraphValidTreeTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(GraphValidTreeTest, TestCase1) {
  int n = 5;
  vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
  bool expected = true;

  bool output = solution.validTree(n, edges);
  EXPECT_EQ(output, expected);

  bool output2 = solution.validTree2(n, edges);
  EXPECT_EQ(output2, expected);
}

TEST_F(GraphValidTreeTest, TestCase2) {
  int n = 5;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {1, 3}, {1, 4}};
  bool expected = false;

  bool output = solution.validTree(n, edges);
  EXPECT_EQ(output, expected);

  bool output2 = solution.validTree2(n, edges);
  EXPECT_EQ(output2, expected);
}