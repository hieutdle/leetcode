package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	low  int
	high int
	ans  int
}{
	{
		3,
		7,
		3,
	},
	{
		8,
		10,
		1,
	},
	{
		1,
		1,
		1,
	},
}

func Test_countOdds(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1523. Count Odd Numbers in an Interval Range------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】:low = %v, high = %v\n【Output】: %v\n", tc.low, tc.high, countOdds(tc.low, tc.high))
		ast.Equal(tc.ans, countOdds(tc.low, tc.high), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_countOdds(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			countOdds(tc.low, tc.high)
		}
	}
}
