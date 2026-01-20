#include <gtest/gtest.h>

#include <vector>

#include "0323_number_of_connected_components_in_an_undirected_graph.h"

class NumberOfConnectedComponentsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(NumberOfConnectedComponentsTest, TestCase1) {
  int n = 3;
  vector<vector<int>> edges = {{0, 1}, {0, 2}};
  int expected = 1;

  int output = solution.countComponents(n, edges);
  EXPECT_EQ(output, expected);

  int output2 = solution.countComponents2(n, edges);
  EXPECT_EQ(output2, expected);

  int output3 = solution.countComponents3(n, edges);
  EXPECT_EQ(output3, expected);
}

TEST_F(NumberOfConnectedComponentsTest, TestCase2) {
  int n = 6;
  vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {4, 5}};
  int expected = 2;

  int output = solution.countComponents(n, edges);
  EXPECT_EQ(output, expected);

  int output2 = solution.countComponents2(n, edges);
  EXPECT_EQ(output2, expected);

  int output3 = solution.countComponents3(n, edges);
  EXPECT_EQ(output3, expected);
}
