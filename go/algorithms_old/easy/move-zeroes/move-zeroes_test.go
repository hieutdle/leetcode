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
		[]int{0,1,0,3,12},
		[]int{1,3,12,0,0},
	},
	{
		[]int{0,0,1},
		[]int{1,0,0},
	},
	{
		[]int{1,0,0},
		[]int{1,0,0},
	},
	{
		[]int{0},
		[]int{0},
	},
}

func Test_moveZeroes(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 283. Move Zeroes------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n", tc.nums)
		moveZeroes(tc.nums)
		fmt.Printf("【Output】: %v\n", tc.nums)
		ast.Equal(tc.ans, tc.nums, "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_moveZeroes(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			moveZeroes(tc.nums)
		}
	}
}
