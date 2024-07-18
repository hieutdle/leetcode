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
		[]int{8, 1, 2, 2, 3},
		[]int{4, 0, 1, 1, 3},
	},
	{
		[]int{6, 5, 4, 8},
		[]int{2, 1, 0, 3},
	},
	{
		[]int{7, 7, 7, 7},
		[]int{0, 0, 0, 0},
	},
}

func Test_smallerNumbersThanCurrent(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1365. How Many Numbers Are Smaller Than the Current Number------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, smallerNumbersThanCurrent(tc.nums))
		ast.Equal(tc.ans, smallerNumbersThanCurrent(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_smallerNumbersThanCurrent(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			smallerNumbersThanCurrent(tc.nums)
		}
	}
}
