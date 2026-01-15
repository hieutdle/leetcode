#include <gtest/gtest.h>

#include <vector>

#include "0207_course_schedule.h"

class CourseScheduleTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(CourseScheduleTest, TestCase1) {
  int numCourses = 2;
  vector<vector<int>> prerequisites = {{1, 0}};
  bool expected = true;

  bool output = solution.canFinish(numCourses, prerequisites);
  EXPECT_EQ(output, expected);

  bool output2 = solution.canFinish2(numCourses, prerequisites);
  EXPECT_EQ(output2, expected);
}

TEST_F(CourseScheduleTest, TestCase2) {
  int numCourses = 2;
  vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
  bool expected = false;

  bool output = solution.canFinish(numCourses, prerequisites);
  EXPECT_EQ(output, expected);

  bool output2 = solution.canFinish2(numCourses, prerequisites);
  EXPECT_EQ(output2, expected);
}