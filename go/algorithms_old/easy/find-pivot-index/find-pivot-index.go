package algorithms

func pivotIndex(nums []int) int {
	sum := 0

	// Get the sum of the array
	for _, num := range nums {
		sum += num
	}

	// The left sum is 0 at the beginning
	leftSum := 0

	// Iterate through the array
	for i, num := range nums {
		// If the 2x left sum + current number is equal to the sum
		// The right sum will also equal to the left sum
		// Return the index
		if leftSum*2+nums[i] == sum {
			return i
		}
		// Add the current number to the left sum
		leftSum += num
	}
	// If no pivot index is found, return -1
	return -1
}

