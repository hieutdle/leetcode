package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	s   string
	ans int
}{

	{
		"zzzzzz",
		6,
	},
	{
		"a",
		1,
	},
	{
		"AAAAAA",
		6,
	},

	{
		"abccccdd",
		7,
	},
}

func Test_longestPalindrome(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 409. Longest Palindrome------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v\n【Output】: %v\n", tc.s, longestPalindrome(tc.s))
		ast.Equal(tc.ans, longestPalindrome(tc.s), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_longestPalindrome(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			longestPalindrome(tc.s)
		}
	}
}
