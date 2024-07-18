package algorithms

import "sort"

func sortedSquares(nums []int) []int {
	res := make([]int, len(nums))

	// Squaring each element
	for i, v := range nums {
		res[i] = v * v
	}

	// Sorting the new array
	sort.Ints(res[:])
	
	return res
}
