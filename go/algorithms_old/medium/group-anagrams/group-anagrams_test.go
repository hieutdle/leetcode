package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	strs []string
	ans  [][]string
}{
	{
		[]string{"eat", "tea", "tan", "ate", "nat", "bat"},
		[][]string{{"eat", "tea", "ate"}, {"tan", "nat"}, {"bat"}},
	},

	{
		[]string{"", ""},
		[][]string{{"", ""}},
	},

	{[]string{"a"},
		[][]string{{"a"}},
	},
}

func Test_groupAnagrams(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 49. Group Anagrams------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: strs = %v\n【Output】: %v\n", tc.strs, groupAnagrams(tc.strs))
		ast.Equal(tc.ans, groupAnagrams(tc.strs), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_groupAnagrams(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			groupAnagrams(tc.strs)
		}
	}
}
