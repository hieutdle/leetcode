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
	{[]int{2, 2, 1}, 1},
	{[]int{4, 1, 2, 1, 2}, 4},
	{[]int{1}, 1},
}

func Test_singleNumber(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 136. Single Number------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, singleNumber(tc.nums))
		ast.Equal(tc.ans, singleNumber(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_singleNumber(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			singleNumber(tc.nums)
		}
	}
}
