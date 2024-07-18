package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	prices []int
	ans    int
}{
	{
		[]int{7, 1, 5, 3, 6, 4},
		5,
	},

	{
		[]int{7, 6, 4, 3, 1},
		0,
	},

	{
		[]int{1, 2},
		1,
	},
}

func Test_maxProfit(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 121. Best Time to Buy and Sell Stock------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: prices = %v\n【Output】: %v\n", tc.prices, maxProfit(tc.prices))
		ast.Equal(tc.ans, maxProfit(tc.prices), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_maxProfit(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			maxProfit(tc.prices)
		}
	}
}
