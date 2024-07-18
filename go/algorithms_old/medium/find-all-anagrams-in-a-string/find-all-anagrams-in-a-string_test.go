package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	s   string
	p   string
	ans []int
}{

	{
		"abc",
		"cbaebabacd",
		[]int{},
	},

	{
		"cbaebabacd",
		"abc",
		[]int{0, 6},
	},

	{
		"abab",
		"ab",
		[]int{0, 1, 2},
	},
}

func Test_findAnagrams(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 438. Find All Anagrams in a String------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v, p = %v\n【Output】: %v\n", tc.s, tc.p, findAnagrams(tc.s, tc.p))
		ast.ElementsMatchf(tc.ans, findAnagrams(tc.s, tc.p), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_findAnagrams(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			findAnagrams(tc.s, tc.p)
		}
	}
}
