package algorithms

func rotate(nums []int, k int) []int {
	l := len(nums)

	if k > l {
		k %= l
	}

	if l == 0 || l == 1 || l == k {
		return nums
	}
	ans := []int{}

	for i := k; i > 0; i-- {
		ans = append(ans, nums[l-i])
	}

	ans = append(ans, nums[:(l-k)]...)

	// copy(nums, ans)

	return ans
}
