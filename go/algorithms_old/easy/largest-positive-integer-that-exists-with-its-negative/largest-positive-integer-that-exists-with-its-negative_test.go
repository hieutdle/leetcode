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
		[]int{-1, 2, -3, 3},
		3,
	},

	{
		[]int{-1, -10, 6, 7, -7, 1},
		7,
	},

	{
		[]int{-10, 8, 6, 7, -2, -3},
		-1,
	},
}

func Test_findMaxK(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 2441. Largest Positive Integer That Exists With Its Negative------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, findMaxK(tc.nums))
		ast.Equal(tc.ans, findMaxK(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_findMaxK(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			findMaxK(tc.nums)
		}
	}
}
