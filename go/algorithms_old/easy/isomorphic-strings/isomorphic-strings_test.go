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

	{"ba", "a", false},
	{"a", "a", true},
	{"aba", "baa", false},
	{"ab", "aa", false},
	{"egg", "add", true},
	{"foo", "bar", false},
	{"paper", "title", true},
}

func Test_isIsomorphic(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 205. Isomorphic Strings------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: t = %v, s = %v\n【Output】: %v\n", tc.t, tc.s, isIsomorphic(tc.s, tc.t))
		ast.Equal(tc.ans, isIsomorphic(tc.s, tc.t), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_isIsomorphic(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			isIsomorphic(tc.s, tc.t)
		}
	}
}
