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
	{5, 10},
	{6, 6},
}

func Test_smallestEvenMultiple(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 2413. Smallest Even Multiple------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: n = %v\n【Output】: %v\n", tc.n, smallestEvenMultiple(tc.n))
		ast.Equal(tc.ans, smallestEvenMultiple(tc.n), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_smallestEvenMultiple(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			smallestEvenMultiple(tc.n)
		}
	}
}
