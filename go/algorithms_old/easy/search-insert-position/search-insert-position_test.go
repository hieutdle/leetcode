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
		[]int{1, 3, 5, 6},
		5,
		2,
	},

	{
		[]int{1, 3, 5, 6},
		2,
		1,
	},
	{
		[]int{1, 3, 5, 6},
		7,
		4,
	},
	{
		[]int{1, 3, 5, 6},
		0,
		0,
	},
}

func Test_searchInsert(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 35. Search Insert Position------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v, target = %v\n【Output】: %v\n", tc.nums, tc.target, searchInsert(tc.nums, tc.target))
		ast.Equal(tc.ans, searchInsert(tc.nums, tc.target), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_searchInsert(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			searchInsert(tc.nums, tc.target)
		}
	}
}
