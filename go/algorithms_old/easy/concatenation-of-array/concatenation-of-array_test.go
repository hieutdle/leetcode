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
	{[]int{1, 2, 1},
		[]int{1, 2, 1, 1, 2, 1},
	},

	{[]int{1, 3, 2, 1},
		[]int{1, 3, 2, 1, 1, 3, 2, 1},
	},
}

func Test_getConcatenation(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1929. Concatenation of Array------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.nums, getConcatenation(tc.nums))
		ast.Equal(tc.ans, getConcatenation(tc.nums), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_getConcatenation(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			getConcatenation(tc.nums)
		}
	}
}
