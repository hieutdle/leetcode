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
	nums3 []int
	ans  []int
}{
	{
		[]int{1,1,3,2},
		[]int{2,3},
		[]int{3},
		[]int{3,2},
	},
	{
		[]int{1,1,3,2},
		[]int{2,3},
		[]int{1,2},
		[]int{2,3,1},
	},
	{
		[]int{1,2,2},
		[]int{4,3,3},
		[]int{5},
		[]int{},
	},
}

func Test_twoOutOfThree(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 2032. Two Out of Three------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums1 = %v, nums2 = %v, nums3 = %v\n【Output】: %v\n", tc.nums1,tc.nums2,tc.nums3, twoOutOfThree(tc.nums1,tc.nums2,tc.nums3))
		ast.ElementsMatchf(tc.ans, twoOutOfThree(tc.nums1,tc.nums2,tc.nums3), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_twoOutOfThree(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			twoOutOfThree(tc.nums1,tc.nums2,tc.nums3)
		}
	}
}
