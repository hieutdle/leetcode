package algorithms

func shuffle(nums []int, n int) []int {

	// Make a slice to store result, 0 avoid default zero values, 2*n cap
	res := make([]int, 0, 2*n)

	for i := 0; i < n; i++ {
		res = append(res, nums[i], nums[i+n])
	}

	return res
}
