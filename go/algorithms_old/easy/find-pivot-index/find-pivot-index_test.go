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
		[]int{1, 7, 3, 6, 5, 6},
		3,
	},

	{
		[]int{1, 2, 3},
		-1,
	},
	{
		[]int{2, 1, -1},
		0,
	},
}

func Test_pivotIndex(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 724. Find Pivot Index------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, pivotIndex(tc.nums))
		ast.Equal(tc.ans, pivotIndex(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_pivotIndex(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			pivotIndex(tc.nums)
		}
	}
}
