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
		[]int{4, 3, 2, 7, 8, 2, 3, 1},
		[]int{2, 3},
	},

	{
		[]int{1, 1, 2},
		[]int{1},
	},

	{
		[]int{1, 1},
		[]int{1},
	},
}

func Test_findDuplicates(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 442. Find All Duplicates in an Array------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, findDuplicates(tc.nums))
		ast.ElementsMatchf(tc.ans, findDuplicates(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_findDuplicates(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			findDuplicates(tc.nums)
		}
	}
}
