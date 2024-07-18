package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// tcs is testcase slice
var tcs = []struct {
	n   int
	ans int
}{
	{
		30,
		832040,
	},
	{
		2,
		1,
	},
	{
		3,
		2,
	},
	{
		0,
		0,
	},
	{
		4,
		3,
	},
}

func Test_fib(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 509. Fibonacci Number------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: n = %v\n【Output】: %v\n", tc.n, fib(tc.n))
		ast.Equal(tc.ans,fib(tc.n), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_fib(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			fib(tc.n)
		}
	}
}