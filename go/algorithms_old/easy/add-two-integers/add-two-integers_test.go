package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	num1 int
	num2 int
	sum  int
}{
	{12, 5, 17},
	{-10, 4, -6},
}

func Test_sum(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 2235. Add Two Integers------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: num1 = %v, num2 = %v\n【Output】: %v\n", tc.num1, tc.num2, tc.sum)
		ast.Equal(tc.sum, sum(tc.num1, tc.num2), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_sum(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			sum(tc.num1, tc.num2)
		}
	}
}
