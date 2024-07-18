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
		[]int{2, 1, 2},
		5,
	},

	{
		[]int{1, 2, 1},
		0,
	},

	{
		[]int{3, 2, 3, 4},
		10,
	},

	{
		[]int{3, 6, 2, 3},
		8,
	},
}

func Test_largestPerimeter(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 976. Largest Perimeter Triangle------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, largestPerimeter(tc.nums))
		ast.Equal(tc.ans, largestPerimeter(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_largestPerimeter(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			largestPerimeter(tc.nums)
		}
	}
}
