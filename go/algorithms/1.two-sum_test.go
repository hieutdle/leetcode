package algorithms

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

// testcases
var tcs = []struct {
	nums   []int
	target int
	ans    []int
}{
	{[]int{2, 7, 11, 15},
		9,
		[]int{0, 1}},
	{[]int{3, 2, 4},
		6,
		[]int{1, 2}},
	{[]int{3, 3},
		6,
		[]int{0, 1}},
}

func Test_twoSum(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1. Two Sum------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v, target = %v\n【Output】: %v\n", tc.nums, tc.target, twoSum(tc.nums, tc.target))
		ast.Equal(tc.ans, twoSum(tc.nums, tc.target), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_twoSum(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			twoSum(tc.nums, tc.target)
		}
	}
}
