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
		"Let's take LeetCode contest",
		"s'teL ekat edoCteeL tsetnoc",
	},
	{
		"God Ding",
		"doG gniD",
	},
}

func Test_reverseWords(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 557. Reverse Words in a String III------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v\n【Output】: %v\n", tc.s, reverseWords(tc.s))
		ast.Equal(tc.ans, reverseWords(tc.s), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_reverseWords(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			reverseWords(tc.s)
		}
	}
}
