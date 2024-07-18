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
		[]int{1, 2, 3, 1, 1, 3},
		4,
	},

	{
		[]int{1, 1, 1, 1},
		6,
	},

	{
		[]int{1, 1, 1, 1},
		6,
	},
}

func Test_numIdenticalPairs(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1512. Number of Good Pairs------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, numIdenticalPairs(tc.nums))
		ast.Equal(tc.ans, numIdenticalPairs(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_numIdenticalPairs(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			numIdenticalPairs(tc.nums)
		}
	}
}
