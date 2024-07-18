package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	candies      []int
	extraCandies int
	result       []bool
}{
	{
		[]int{2, 3, 5, 1, 3},
		3,
		[]bool{true, true, true, false, true},
	},

	{
		[]int{4, 2, 1, 1, 2},
		1,
		[]bool{true, false, false, false, false},
	},

	{
		[]int{12, 1, 12},
		10,
		[]bool{true, false, true},
	},
}

func Test_kidsWithCandies(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1431. Kids With the Greatest Number of Candies------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: candies = %v, extraCandies = %v\n【Output】: %v\n", tc.candies, tc.extraCandies, kidsWithCandies(tc.candies, tc.extraCandies))
		ast.Equal(tc.result, kidsWithCandies(tc.candies, tc.extraCandies), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_kidsWithCandies(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			kidsWithCandies(tc.candies, tc.extraCandies)
		}
	}
}
