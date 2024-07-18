package algorithms

func singleNonDuplicate(nums []int) int {
	for i := 0; i < len(nums)-2; i = i + 2 {
		if nums[i] != nums[i+1] {
			return nums[i]
		}
	}
	return nums[len(nums)-1]
}
