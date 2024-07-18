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
	{"III", 3},
	{"LVIII", 58},
	{"MCMXCIV", 1994},
}

func Test_romanToInt(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 13. Roman to Integer------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v\n【Output】: %v\n", tc.s, romanToInt(tc.s))
		ast.Equal(tc.ans, romanToInt(tc.s), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_romanToInt(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			romanToInt(tc.s)
		}
	}
}
