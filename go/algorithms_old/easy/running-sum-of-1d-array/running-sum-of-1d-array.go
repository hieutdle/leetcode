package algorithms

func runningSum(nums []int) []int {

	// Make a slice that has the same length
	sums := make([]int, len(nums))

	// Assign the first number of the array to the sums slice
	sums[0] = nums[0]

	// Current sum is equal to previous sum plus corresponding number in the array
	for i := 1; i < len(nums); i++ {
		sums[i] = nums[i] + sums[i-1]
	}
	return sums
}
