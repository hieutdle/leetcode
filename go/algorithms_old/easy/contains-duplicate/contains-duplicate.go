package algorithms

func containsDuplicate(nums []int) bool {
	// Using map as set to check the slice
	checkMap := make(map[int]bool)

	for _, num := range nums {

		// If the key already exists, return true
		if checkMap[num] {
			return true
		}
		checkMap[num] = true
	}
	return false
}
