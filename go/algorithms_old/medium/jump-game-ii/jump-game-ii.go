package algorithms

//https://www.youtube.com/watch?v=dJ7sWiOoK7g

func jump(nums []int) int {
	if len(nums) == 1 {
		return 0
	}
	ans := 0

	// pointer to the left and right of the current sliding window
	// example: [2,3,1,1,4]
	left, right := 0, 0

	for right < len(nums)-1 {
		farthest := 0

		// find the farthest index that can be reached in the next window
		for i := left; i <= right; i++ {
			farthest = max(farthest, i+nums[i])
		}

		// Update the left and right pointers to the next window

		// Example [2,(3,1),1,4]
		left = right + 1
		right = farthest

		// increment the number of jumps
		ans++

		// Next step will be ([2,3,1,(1,4)]
	}
	return ans
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
