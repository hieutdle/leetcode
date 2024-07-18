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
	{[]int{0, 2, 1, 5, 3, 4},
		[]int{0, 1, 2, 4, 5, 3},
	},

	{[]int{5, 0, 1, 2, 3, 4},
		[]int{4, 5, 0, 1, 2, 3},
	},
}

func Test_buildArray(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1920. Build Array from Permutation------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, buildArray(tc.nums))
		ast.Equal(tc.ans, buildArray(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_buildArray(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			buildArray(tc.nums)
		}
	}
}
