package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	jewels string
	stones string
	ans    int
}{
	{
		"aA",
		"aAAbbbb",
		3,
	},

	{
		"z",
		"ZZ",
		0,
	},
}

func Test_numJewelsInStones(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 771. Jewels and Stones------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: jewels = %v, stones = %v\n【Output】: %v\n", tc.jewels, tc.stones, numJewelsInStones(tc.jewels, tc.stones))
		ast.Equal(tc.ans, numJewelsInStones(tc.jewels, tc.stones), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_numJewelsInStones(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			numJewelsInStones(tc.jewels, tc.stones)
		}
	}
}
