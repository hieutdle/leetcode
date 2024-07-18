package algorithms

import "github.com/goldennovember/leetcode-go/sort"

func largestPerimeter(nums []int) int {
	sorted := sort.MergeSort(nums)

	for i := len(sorted) - 1; i >= 2; i-- {
		if sorted[i] < sorted[i-1]+sorted[i-2] {
			return sorted[i] + sorted[i-1] + sorted[i-2]
		} else {
			continue
		}
	}
	return 0
}
