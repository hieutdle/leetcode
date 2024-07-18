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
		"#ab#c",
		"#ad#c",
		true,
	},

	{
		"ab#c",
		"ad#c",
		true,
	},

	{
		"ab##",
		"c#d#",
		true,
	},

	{
		"a##c",
		"#a#c",
		true,
	},

	{
		"a#c",
		"b",
		false,
	},
}

func Test_backspaceCompare(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 844. Backspace String Compare------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v, t = %v\n【Output】: %v\n", tc.s, tc.t, backspaceCompare(tc.s, tc.t))
		ast.Equal(tc.ans, backspaceCompare(tc.s, tc.t), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_backspaceCompare(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			backspaceCompare(tc.s, tc.t)
		}
	}
}
