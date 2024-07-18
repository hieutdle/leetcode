package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	nums []int
	ans  []int
}{

	{
		[]int{-4, -1, 0, 3, 10},
		[]int{0, 1, 9, 16, 100},
	},

	{
		[]int{-7, -3, 2, 3, 11},
		[]int{4, 9, 9, 49, 121},
	},
}

func Test_sortedSquares(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 977. Squares of a Sorted Array------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, sortedSquares(tc.nums))
		ast.Equal(tc.ans, sortedSquares(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_sortedSquares(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			sortedSquares(tc.nums)
		}
	}
}
