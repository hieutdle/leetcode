package algorithms

func findDuplicates(nums []int) []int {
	// Map to find duplicates
	m := map[int]bool{}

	// Slice to store the answer
	ans := []int{}

	for _, v := range nums {
		if m[v] {
			// If the number is already in the map, then it is a duplicate, make the value false.
			m[v] = false
		} else {
			// Store if the number is not in the map
			m[v] = true
		}
	}

	for k, v := range m {
		// If the value is false, then it is a duplicate
		if !v {
			ans = append(ans, k)
		}
	}
	return ans
}