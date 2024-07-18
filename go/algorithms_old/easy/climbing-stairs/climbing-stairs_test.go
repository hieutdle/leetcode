package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	n   int
	ans int
}{
	{2, 2},
	{3, 3},
	{4, 5},
	{5, 8},
	{10, 89},
	{20, 10946},
	{45, 1836311903},
}

func Test_climbStairs(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 70. Climbing Stairs------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: n = %v\n【Output】: %v\n", tc.n, climbStairs(tc.n))
		ast.Equal(tc.ans, climbStairs(tc.n), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_climbStairs(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			climbStairs(tc.n)
		}
	}
}

