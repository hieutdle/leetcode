package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	nums1 []int
	m     int
	nums2 []int
	n     int
	ans   []int
}{
	{
		[]int{1, 2, 3, 0, 0, 0},
		3,
		[]int{2, 5, 6},
		3,
		[]int{1, 2, 2, 3, 5, 6},
	},
	{
		[]int{1},
		1,
		[]int{},
		0,
		[]int{1},
	},
	{
		[]int{0},
		0,
		[]int{1},
		1,
		[]int{1},
	},
}

func Test_merge(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 88. Merge Sorted Array------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums1 = %v, m = %v, nums2 = %v, n = %v\n", tc.nums1, tc.m, tc.nums2, tc.n)
		merge(tc.nums1, tc.m, tc.nums2, tc.n)
		fmt.Printf("【Output】: %v\n", tc.nums1)
		ast.Equal(tc.ans, tc.nums1, "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_merge(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			merge(tc.nums1, tc.m, tc.nums2, tc.n)
		}
	}
}
