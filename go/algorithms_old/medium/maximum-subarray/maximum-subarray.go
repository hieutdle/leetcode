package algorithms

func maxSubArray(nums []int) int {
	right := len(nums) - 1
	left := 0
	return findMaxSubArray(nums, left, right)

}

func findMaxSubArray(num []int, left int, right int) int {
	if left == right {
		return num[left]
	} else {
		mid := (right + left) / 2
		leftMax := findMaxSubArray(num, left, mid)
		rightMax := findMaxSubArray(num, mid+1, right)
		crossMax := findCrossMaxSubArray(num, left, mid, right)

		return max(leftMax, rightMax, crossMax)
	}
}

func findCrossMaxSubArray(nums []int, left, mid, right int) int {
	leftSum := nums[mid]
	sum := nums[mid]
	for i := mid - 1; i >= left; i-- {
		sum += nums[i]
		if sum > leftSum {
			leftSum = sum
		}
	}

	rightSum := nums[mid+1]
	sum = nums[mid+1]
	for i := mid + 2; i <= right; i++ {
		sum += nums[i]
		if sum > rightSum {
			rightSum = sum
		}
	}

	return leftSum + rightSum
}

func max(values ...int) int {
	max := values[0]
	for _, v := range values {
		if v > max {
			max = v
		}
	}
	return max
}
