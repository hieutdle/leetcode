#include "two_sum.hpp"
#include <gtest/gtest.h>
#include <vector>
using namespace std;


TEST(TwoSumTest, HandlesValidCase1) {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> expected = {0, 1};
    vector<int> result = twoSum(nums, target);
    EXPECT_EQ(result, expected);
}

TEST(TwoSumTest, HandlesValidCase2) {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> expected = {1, 2};
    vector<int> result = twoSum(nums, target);
    EXPECT_EQ(result, expected);
}

TEST(TwoSumTest, HandlesValidCase3) {
    vector<int> nums = {3, 3};
    int target = 6;
    vector<int> expected = {0, 1};
    vector<int> result = twoSum(nums, target);
    EXPECT_EQ(result, expected);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
