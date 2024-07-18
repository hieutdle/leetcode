package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	s       string
	indices []int
	ans     string
}{
	{
		"codeleet",
		[]int{4, 5, 6, 7, 0, 2, 1, 3},
		"leetcode",
	},
	{
		"abc",
		[]int{0, 1, 2},
		"abc",
	},
}

func Test_restoreString(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1528. Shuffle String------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v, indices = %v\n【Output】: %v\n", tc.s, tc.indices, restoreString(tc.s, tc.indices))
		ast.Equal(tc.ans, restoreString(tc.s, tc.indices), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_restoreString(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			restoreString(tc.s, tc.indices)
		}
	}
}
