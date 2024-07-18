package algorithms

func firstMissingPositive(nums []int) int {

	// Default value for answer is 1
	ans := 1

	// Default value for max number is 1
	max := 1

	// Create a map to store the numbers
	m := map[int]bool{}

	// Loop through the array
	for _, v := range nums {
		// If the number is greater than 0 (or positive)
		if v > 0 {
			// Add the number to the map
			m[v] = true
			// If the number is greater than the max number
			if v > max {
				// Set the max number to the number
				max = v
			}
		}
	}

	// Loop through the map to the max number
	for ans <= max {
		// If the number is not in the map
		if _, ok := m[ans]; !ok {
			// Return the number
			return ans
		}
		// Increment the answer
		ans++
	}
	return ans
}
