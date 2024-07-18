package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	nums   []int
	target int
	ans    int
}{

	{
		[]int{-1, 0, 3, 5, 9, 12},
		9,
		4,
	},

	{
		[]int{-1, 0, 3, 5, 9, 12},
		2,
		-1,
	},
}

func Test_search(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 704. Binary Search------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v, target = %v\n【Output】: %v\n", tc.nums, tc.target, search(tc.nums, tc.target))
		ast.Equal(tc.ans, search(tc.nums, tc.target), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_search(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			search(tc.nums, tc.target)
		}
	}
}
