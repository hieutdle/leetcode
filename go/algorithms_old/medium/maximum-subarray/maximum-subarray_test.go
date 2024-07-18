package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	nums []int
	ans  int
}{
	{
		[]int{-2, 1, -3, 4, -1, 2, 1, -5, 4},
		6,
	},

	{
		[]int{1},
		1,
	},

	{
		[]int{5, 4, -1, 7, 8},
		23,
	},
}

func Test_maxSubArray(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 53. Maximum Subarray------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, maxSubArray(tc.nums))
		ast.Equal(tc.ans, maxSubArray(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_maxSubArray(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			maxSubArray(tc.nums)
		}
	}
}
