#include <gtest/gtest.h>

#include "0252_meeting_rooms.h"

class MeetingRoomsTest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(MeetingRoomsTest, TestCase1) {
  std::vector<std::vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
  bool expected = false;

  bool output = solution.canAttendMeetings(intervals);
  EXPECT_EQ(output, expected);
}

TEST_F(MeetingRoomsTest, TestCase2) {
  std::vector<std::vector<int>> intervals = {{5, 8}, {9, 15}};
  bool expected = true;

  bool output = solution.canAttendMeetings(intervals);
  EXPECT_EQ(output, expected);
}