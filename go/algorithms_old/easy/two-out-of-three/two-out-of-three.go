package algorithms

func twoOutOfThree(nums1 []int, nums2 []int, nums3 []int) []int {

	// Slice to store the result
	ans := []int{}

	// Using map to store set of values
	m := map[int]bool{}

	// First map to store the unique values from nums1
	m1 := map[int]bool{}

	for _, v := range nums1 {
		m1[v] = true
	}

	// Second map to store the unique values from nums2
	// and check if the value is present in m1 (compare nums1 with nums2)
	m2 := map[int]bool{}

	for _, v := range nums2 {

		// If the value is present in m1, then add it to m
		if m1[v] {
			m[v] = true
		}
		m2[v] = true
	}

	// Loop through nums3 and compare with nums1 and nums2
	for _, v := range nums3 {
		if m1[v] {
			// If the value is present in m1, then add it to m
			m[v] = true
		}
		if m2[v] {
			// If the value is present in m2, then add it to m
			m[v] = true
		}
	}

	// Add the values(key) from m to ans
	for k := range m {
		ans = append(ans, k)
	}
	return ans
}
