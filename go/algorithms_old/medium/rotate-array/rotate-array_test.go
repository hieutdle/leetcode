package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	nums []int
	k    int
	ans  []int
}{
	{
		[]int{1, 2, 3, 4, 5, 6, 7},
		3,
		[]int{5, 6, 7, 1, 2, 3, 4},
	},
	{
		[]int{-1, -100, 3, 99},
		2,
		[]int{3, 99, -1, -100},
	},
	{
		[]int{-1},
		2,
		[]int{-1},
	},
	{
		[]int{1, 2},
		3,
		[]int{2, 1},
	},
	{
		[]int{1, 2, 3},
		4,
		[]int{3, 1, 2},
	},
	{
		[]int{1, 2, 3, 4, 5, 6},
		11,
		[]int{2, 3, 4, 5, 6, 1},
	},
}

func Test_rotate(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 189. Rotate Array------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v, k = %v\n【Output】: %v\n", tc.nums, tc.k, rotate(tc.nums, tc.k))
		ast.Equal(tc.ans, rotate(tc.nums, tc.k), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_rotate(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			rotate(tc.nums, tc.k)
		}
	}
}
