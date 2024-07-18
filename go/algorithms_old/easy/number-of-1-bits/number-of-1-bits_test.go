package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	n   uint32
	ans int
}{
	{
		0, //0b000000000000000
		0,
	},
	{
		11,
		3,
	},

	{
		128,
		1,
	},

	{
		4294967293,
		31,
	},
}

func Test_hammingWeight(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 191. Number of 1 Bits------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: nums = %v\n【Output】: %v\n", tc.n, hammingWeight(tc.n))
		ast.Equal(tc.ans, hammingWeight(tc.n), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_hammingWeight(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			hammingWeight(tc.n)
		}
	}
}
