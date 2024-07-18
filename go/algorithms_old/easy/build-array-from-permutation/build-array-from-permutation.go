package algorithms

func buildArray(nums []int) []int {

	result := []int{}

	for i := range nums {
		result = append(result, nums[nums[i]])
	}

	return result
}
