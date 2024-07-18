#include "two_sum.hpp"
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    for (std::size_t i = 0; i < nums.size() - 1; i++) {
        for (std::size_t j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {static_cast<int>(i), static_cast<int>(j)};
            }
        }
    }
    return {}; // Return empty vector if no pair is found
}
