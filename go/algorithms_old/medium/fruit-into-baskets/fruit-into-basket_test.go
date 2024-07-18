package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	fruits []int
	ans    int
}{

	{
		[]int{0},
		1,
	},

	{
		[]int{1, 2, 1},
		3,
	},

	{
		[]int{0, 1, 2, 2},
		3,
	},

	{
		[]int{1, 2, 3, 2, 2},
		4,
	},

	{
		[]int{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4},
		5,
	},
}

func Test_totalFruit(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 904. Fruit Into Baskets------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: fruits = %v\n【Output】: %v\n", tc.fruits, totalFruit(tc.fruits))
		ast.Equal(tc.ans, totalFruit(tc.fruits), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_totalFruit(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			totalFruit(tc.fruits)
		}
	}
}
