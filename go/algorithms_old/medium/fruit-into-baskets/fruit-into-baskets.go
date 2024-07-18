package algorithms

func totalFruit(fruits []int) int {
	m := map[int]int{}

	left, right := 0, 0

	max := 0

	for right < len(fruits) {

		// Count the fruit
		m[fruits[right]]++

		// Move to the next fruit
		right++

		// If we encounter a third fruit or the length of the map is greater than 2
		// We start traveling use the left pointer to remove the fruit
		for len(m) > 2 {

			// Decrement the fruit
			m[fruits[left]]--

			// If the fruit is 0, remove it from the map
			if m[fruits[left]] == 0 {
				delete(m, fruits[left])
			}
			// Move to the next fruit
			left++
		}

		// If the right-left is greater than the max, update the max
		if right-left > max {
			max = right - left
		}
	}

	return max
}
