package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	s   string
	t   string
	ans bool
}{

	{
		"abc",
		"ahbgdc",
		true,
	},

	{
		"axc",
		"ahbgdc",
		false,
	},
}

func Test_isSubsequence(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 392. Is Subsequence------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: t = %v, s = %v\n【Output】: %v\n", tc.t, tc.s, isSubsequence(tc.s, tc.t))
		ast.Equal(tc.ans, isSubsequence(tc.s, tc.t), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_isSubsequence(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			isSubsequence(tc.s, tc.t)
		}
	}
}
