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
		[]int{1, 2, 0},
		3,
	},
	{
		[]int{3, 4, -1, 1},
		2,
	},
	{
		[]int{7, 8, 9, 11, 12},
		1,
	},
}

func Test_firstMissingPositive(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 41. First Missing Positive------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, firstMissingPositive(tc.nums))
		ast.Equal(tc.ans, firstMissingPositive(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_firstMissingPositive(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			firstMissingPositive(tc.nums)
		}
	}
}
