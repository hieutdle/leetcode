package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	ransomNote string
	magazine   string
	ans        bool
}{

	{"a", "b", false},
	{"aa", "ab", false},
	{"aa", "aab", true},
}

func Test_canConstruct(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 383. Ransom Note------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: ransomNote = %v, magazine = %v\n【Output】: %v\n", tc.ransomNote, tc.magazine, canConstruct(tc.ransomNote, tc.magazine))
		ast.Equal(tc.ans, canConstruct(tc.ransomNote,tc.magazine), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_canConstruct(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			canConstruct(tc.ransomNote, tc.magazine)
		}
	}
}