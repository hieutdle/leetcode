#include <gtest/gtest.h>

#include "0295_find_median_from_data_stream.h"

class FindMedianFromDataStreamTest : public ::testing::Test {
 protected:
  MedianFinder* medianFinder;

  void SetUp() override {
    medianFinder = new MedianFinder();
  }

  void TearDown() override {
    delete medianFinder;
  }
};

TEST_F(FindMedianFromDataStreamTest, TestCase1) {
  medianFinder->addNum(1);
  medianFinder->addNum(2);
  EXPECT_DOUBLE_EQ(medianFinder->findMedian(), 1.5);

  medianFinder->addNum(3);
  EXPECT_DOUBLE_EQ(medianFinder->findMedian(), 2.0);
}