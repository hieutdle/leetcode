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
	ans   []int
}{

	{[]int{1, 2, 2, 1}, []int{2, 2}, []int{2, 2}},
	{[]int{4, 9, 5}, []int{9, 4, 9, 8, 4}, []int{4, 9}},
	{[]int{1, 3, 3, 3, 2, 2, 1}, []int{3, 2, 2}, []int{2, 2, 3}},
}

func Test_intersect(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 350. Intersection of Two Arrays II------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums1 = %v, nums2 = %v\n【Output】: %v\n", tc.nums1, tc.nums2, intersect(tc.nums1, tc.nums2))
		ast.ElementsMatchf(tc.ans, intersect(tc.nums1, tc.nums2), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_intersect(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			intersect(tc.nums1, tc.nums2)
		}
	}
}
