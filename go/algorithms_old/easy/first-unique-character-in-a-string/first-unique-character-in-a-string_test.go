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

	{
		"leetcode",
		0,
	},

	{
		"loveleetcode",
		2,
	},
	{
		"cc",
		-1,
	},
	{
		"aabb",
		-1,
	},
}

func Test_firstUniqChar(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 387. First Unique Character in a String------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v\n【Output】: %v\n", tc.s, firstUniqChar(tc.s))
		ast.Equal(tc.ans, firstUniqChar(tc.s), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_firstUniqChar(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			firstUniqChar(tc.s)
		}
	}
}
