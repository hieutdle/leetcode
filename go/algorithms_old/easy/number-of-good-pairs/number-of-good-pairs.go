package algorithms

func numIdenticalPairs(nums []int) int {

	count := 0

	// Start from the first number to the number next to the last number.
	for i := 0; i < len(nums)-1; i++ {

		// Check from the second number to the last one
		for j := i + 1; j < len(nums); j++ {
			if nums[i] == nums[j] {
				count++
			}
		}
	}
	return count
}