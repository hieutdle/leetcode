package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	cost []int
	ans  int
}{

	{
		[]int{10, 15, 20},
		15,
	},

	{
		[]int{1, 100, 1, 1, 1, 100, 1, 1, 100, 1},
		6,
	},

}

func Test_minCostClimbingStairs(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 746. Min Cost Climbing Stairs------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: cost = %v\n【Output】: %v\n", tc.cost, minCostClimbingStairs(tc.cost))
		ast.Equal(tc.ans, minCostClimbingStairs(tc.cost), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_minCostClimbingStairs(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			minCostClimbingStairs(tc.cost)
		}
	}
}