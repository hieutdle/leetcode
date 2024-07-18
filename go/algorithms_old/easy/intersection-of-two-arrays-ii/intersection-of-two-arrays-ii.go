package algorithms

func intersect(nums1 []int, nums2 []int) []int {
	m := make(map[int]int)
	ans := []int{}

	// Count the of occurrences of each number in nums1
	for _, v := range nums1 {
		m[v]++
	}

	for _, v := range nums2 {
		if m[v] > 0 {
			// If the number is in nums2, append it to the answer
			ans = append(ans, v)
			// Decrement the number of occurrences of the number
			m[v]--
		}
	}
	return ans
}
