package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	nums []int
	n    int
	ans  []int
}{
	{[]int{2, 5, 1, 3, 4, 7}, 3, []int{2, 3, 5, 4, 1, 7}},
	{[]int{1, 2, 3, 4, 4, 3, 2, 1}, 4, []int{1, 4, 2, 3, 3, 2, 4, 1}},
	{[]int{1, 1, 2, 2}, 2, []int{1, 2, 1, 2}},
}

func Test_shuffle(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1470. Shuffle the Array------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v, n = %v\n【Output】: %v\n", tc.nums, tc.n, shuffle(tc.nums, tc.n))
		ast.Equal(tc.ans, shuffle(tc.nums, tc.n), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_shuffle(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			shuffle(tc.nums, tc.n)
		}
	}
}
