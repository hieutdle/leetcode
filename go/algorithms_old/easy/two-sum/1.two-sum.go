/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

// @lc code=start
func twoSum(nums []int, target int) []int {

	// I used Brute Force before, but I want to try new thing this time.

	// Hashmap to store the number as a key, and store the index as a value
	m := make(map[int]int)

	// Loop through the array
	for i, num := range nums {

		// Check if the corresponding number is already in the map or not.
		if index, ok := m[target-num]; ok {

			// Return the index of corresponding number and the index of the current number
			return []int{index, i}
		}
		// Store the number and the index in the map
		m[num] = i
	}

	return nil
}

// @lc code=end

