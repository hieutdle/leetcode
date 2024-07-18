package algorithms

func findMaxK(nums []int) int {
	// Map store only positive numbers
	m1 := map[int]bool{}

	// Map store only negative numbers
	m2 := map[int]bool{}

	max := -1

	// Iterate over the array
	for _, v := range nums {
		if v > 0 {
			// Store positive numbers in m1
			m1[v] = true
		} else {
			// Store negative numbers in m2
			m2[v] = true
		}
	}

	// Iterate over m1
	for k := range m1 {
		// Check if the negative of the number is present in m2
		if m2[-k] {
			if k > max {
				max = k
			}
		}
	}

	return max
}