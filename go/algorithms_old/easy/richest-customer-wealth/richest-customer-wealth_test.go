package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	accounts [][]int
	richest  int
}{
	{
		[][]int{{1, 2, 3}, {3, 2, 1}},
		6,
	},

	{
		[][]int{{1, 5}, {7, 3}, {3, 5}},
		10,
	},

	{
		[][]int{{2, 8, 7}, {7, 1, 3}, {1, 9, 5}},
		17,
	},
}

func Test_maximumWealth(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1672. Richest Customer Wealth------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.accounts, maximumWealth(tc.accounts))
		ast.Equal(tc.richest, maximumWealth(tc.accounts), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_maximumWealth(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			maximumWealth(tc.accounts)
		}
	}
}
