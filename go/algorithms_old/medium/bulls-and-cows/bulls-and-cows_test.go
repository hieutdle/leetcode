package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	secret string
	guess  string
	ans    string
}{

	{
		"1807",
		"7810",
		"1A3B",
	},
	{
		"1123",
		"0111",
		"1A1B",
	},
	{
		"1123456789",
		"0111111111",
		"1A1B",
	},
}

func Test_getHint(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 299. Bulls and Cows------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: secret = %v, guess = %v\n【Output】: %v\n", tc.secret, tc.guess, getHint(tc.secret, tc.guess))
		ast.Equal(tc.ans, getHint(tc.secret, tc.guess), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_getHint(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			getHint(tc.secret, tc.guess)
		}
	}
}
