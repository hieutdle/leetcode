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
	{[]int{2, 3, 1, 1, 4}, 2},
	{[]int{2, 3, 0, 1, 4}, 2},
	{[]int{1, 2, 3}, 2},
	{[]int{1, 2, 1, 1, 1}, 3},
	{[]int{1, 1, 1, 1, 1}, 4},
	{[]int{1, 1, 1, 1, 1, 1}, 5},
}

func Test_jump(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 45. Jump Game II------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, jump(tc.nums))
		ast.Equal(tc.ans, jump(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_jump(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			jump(tc.nums)
		}
	}
}
