package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	nums []int
	sums []int
}{
	{[]int{1, 2, 3, 4}, []int{1, 3, 6, 10}},
	{[]int{1, 1, 1, 1, 1}, []int{1, 2, 3, 4, 5}},
	{[]int{3, 1, 2, 10, 1}, []int{3, 4, 6, 16, 17}},
}

func Test_runningSum(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1480. Running Sum of 1d Array------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, runningSum(tc.nums))
		ast.Equal(tc.sums, runningSum(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_runningSum(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			runningSum(tc.nums)
		}
	}
}
