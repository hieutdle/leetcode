package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	m   int
	n   int
	ans int
}{

	{
		3,
		7,
		28,
	},
	{
		3,
		2,
		3,
	},
}

func Test_uniquePaths(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 62. Unique Paths------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: m = %v, n = %v\n【Output】: %v\n", tc.m, tc.n, uniquePaths(tc.m, tc.n))
		ast.Equal(tc.ans, uniquePaths(tc.m, tc.n), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_uniquePaths(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			uniquePaths(tc.m, tc.n)
		}
	}
}
