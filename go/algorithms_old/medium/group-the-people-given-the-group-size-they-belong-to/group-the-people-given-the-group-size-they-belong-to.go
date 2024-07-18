package algorithms

func groupThePeople(groupSizes []int) [][]int {

	ans := [][]int{}

	// Map to store the group size as key and the indexes of the person as values
	m := map[int][]int{}

	// Each group size is a key in the map
	for i, v := range groupSizes {

		// Append the index of the person to the group size key
		m[v] = append(m[v], i)

		// If the group is full (the length of the value is equal to the group size)
		if len(m[v]) == v {
			// Add the group to the answer
			ans = append(ans, m[v])
			// Reset the group
			delete(m, v)
		}
	}

	return ans
}
