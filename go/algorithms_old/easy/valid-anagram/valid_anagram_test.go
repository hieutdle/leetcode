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

	{"anagram", "nagaram", true},
	{"rat", "car", false},
	{"love", "evo", false},
}

func Test_isAnagram(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 242. Valid Anagram------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v, t = %v\n【Output】: %v\n", tc.s, tc.t, isAnagram(tc.s, tc.t))
		ast.Equal(tc.ans, isAnagram(tc.s, tc.t), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_isAnagram(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			isAnagram(tc.s, tc.t)
		}
	}
}
