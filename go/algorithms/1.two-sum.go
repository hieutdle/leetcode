package algorithms

func twoSum(nums []int, target int) []int {

	// Brute Force
	// for i := 0; i < len(nums); i++ {
	// 	for j := i + 1; j < len(nums); j++ {
	// 		if nums[i]+nums[j] == target {
	// 			return []int{i, j}
	// 		}
	// 	}
	// }

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
