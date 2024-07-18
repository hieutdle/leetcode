package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	n   int
	ans int
}{
	{
		234,
		15,
	},

	{
		4421,
		21,
	},
}

func Test_subtractProductAndSum(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1281. Subtract the Product and Sum of Digits of an Integer------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: n = %v\n【Output】: %v\n", tc.n, subtractProductAndSum(tc.n))
		ast.Equal(tc.ans, subtractProductAndSum(tc.n), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_subtractProductAndSum(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			subtractProductAndSum(tc.n)
		}
	}
}
