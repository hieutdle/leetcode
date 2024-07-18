package algorithms

import (
	"fmt"
	"testing"

	"github.com/stretchr/testify/assert"
)

// testcases
var tcs = []struct {
	pattern string
	str     string
	ans     bool
}{
	{"abba", "dog cat cat dog", true},
	{"abba", "dog cat cat fish", false},
	{"aaaa", "dog cat cat dog", false},
	{"abba", "dog dog dog dog", false},
	{"aaa", "aa aa aa aa", false},
}

func Test_wordPattern(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 290. Word Pattern------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: pattern = %v, s = %v\n【Output】: %v\n", tc.pattern, tc.str, wordPattern(tc.pattern, tc.str))
		ast.Equal(tc.ans, wordPattern(tc.pattern, tc.str), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_wordPattern(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			wordPattern(tc.pattern, tc.str)
		}
	}
}
