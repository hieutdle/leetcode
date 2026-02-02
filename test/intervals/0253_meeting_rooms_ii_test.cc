#include <gtest/gtest.h>

#include "0253_meeting_rooms_ii.h"

class MeetingRoomsIITest : public ::testing::Test {
 protected:
  Solution solution;
};

TEST_F(MeetingRoomsIITest, TestCase1) {
  std::vector<std::vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
  int expected = 2;

  int output = solution.minMeetingRooms(intervals);
  EXPECT_EQ(output, expected);

  int output2 = solution.minMeetingRooms2(intervals);
  EXPECT_EQ(output2, expected);

  int output3 = solution.minMeetingRooms3(intervals);
  EXPECT_EQ(output3, expected);
}

TEST_F(MeetingRoomsIITest, TestCase2) {
  std::vector<std::vector<int>> intervals = {{4, 9}};
  int expected = 1;

  int output = solution.minMeetingRooms(intervals);
  EXPECT_EQ(output, expected);

  int output2 = solution.minMeetingRooms2(intervals);
  EXPECT_EQ(output2, expected);

  int output3 = solution.minMeetingRooms3(intervals);
  EXPECT_EQ(output3, expected);
}