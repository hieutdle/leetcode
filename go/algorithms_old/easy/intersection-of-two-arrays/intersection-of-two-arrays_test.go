package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	nums1 []int
	nums2 []int
	res   []int
}{
	{
		[]int{1, 2, 2, 1},
		[]int{2, 2},
		[]int{2},
	},
	{
		[]int{4, 9, 5},
		[]int{9, 4, 9, 8, 4},
		[]int{9, 4},
	},
	{
		[]int{1, 2, 3, 4, 5},
		[]int{6, 7, 8, 9, 10},
		[]int{},
	},
}

func Test_intersection(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 349. Intersection of Two Arrays------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums1 = %v, nums2 = %v\n【Output】: %v\n", tc.nums1, tc.nums2, intersection(tc.nums1, tc.nums2))
		ast.Equal(tc.res, intersection(tc.nums1, tc.nums2), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_intersection(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			intersection(tc.nums1, tc.nums2)
		}
	}
}
