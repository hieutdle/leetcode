package algorithms

func search(nums []int, target int) int {
	left, right := 0, len(nums)-1

	for left <= right {
		// Start with the middle element
		mid := (left + right) / 2

		switch {
		// if target is greater than the middle element, search the right half
		case nums[mid] > target:
			right = mid - 1
		// if target is less than the middle element, search the left half
		case nums[mid] < target:
			left = mid + 1
		// if target is equal to the middle element, return the index
		default:
			return mid
		}
	}
	return -1
}
