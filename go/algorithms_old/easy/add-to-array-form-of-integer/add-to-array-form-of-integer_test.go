package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// tescases
var tcs = []struct {
	num []int
	k   int
	ans []int
}{
	{[]int{1, 2, 0, 0}, 34, []int{1, 2, 3, 4}},
	{[]int{2, 7, 4}, 181, []int{4, 5, 5}},
	{[]int{2, 1, 5}, 806, []int{1, 0, 2, 1}},
	{[]int{9, 9, 9, 9, 9, 9, 9, 9, 9, 9}, 1, []int{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
}

func Test_addToArrayForm(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 989. Add to Array-Form of Integer------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: num = %v, k = %v\n【Output】: %v\n", tc.num, tc.k, addToArrayForm(tc.num, tc.k))
		ast.Equal(tc.ans, addToArrayForm(tc.num, tc.k), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_addToArrayForm(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			addToArrayForm(tc.num, tc.k)
		}
	}
}
