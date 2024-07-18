package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	s   string
	ans string
}{
	{
		"aaabcbc",
		"aaabcbc",
	},

	{
		"10[a]2[bc]",
		"aaaaaaaaaabcbc",
	},

	{
		"3[a]2[bc]",
		"aaabcbc",
	},

	{
		"3[a2[c]]",
		"accaccacc",
	},

	{
		"2[abc]3[cd]ef",
		"abcabccdcdcdef",
	},
}

func Test_decodeString(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 394. Decode String------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v\n【Output】: %v\n", tc.s, decodeString(tc.s))
		ast.Equal(tc.ans, decodeString(tc.s), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_decodeString(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			decodeString(tc.s)
		}
	}
}
