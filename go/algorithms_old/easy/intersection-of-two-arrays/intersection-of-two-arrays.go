package algorithms

func intersection(nums1 []int, nums2 []int) []int {

	// Create an array to store the result
	res := []int{}

	// Create a map to store set of values from nums1
	m := map[int]bool{}

	// Add value to the map
	for _, v := range nums1 {
		m[v] = true
	}

	// Check if the values from nums2 are in the map
	for _, v := range nums2 {
		// The value is in the map
		if m[v] {
			// Add the value to the result
			res = append(res, v)
			// Delete the value in the map
			delete(m, v)
		}
	}

	return res
}