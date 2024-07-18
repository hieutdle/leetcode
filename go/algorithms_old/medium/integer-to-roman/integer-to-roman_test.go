package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	num int
	ans string
}{
	{
		3,
		"III",
	},

	{
		58,
		"LVIII",
	},

	{
		1994,
		"MCMXCIV",
	},
}

func Test_intToRoman(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 12. Integer to Roman------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: num = %v\n【Output】: %v\n", tc.num, intToRoman(tc.num))
		ast.Equal(tc.ans, intToRoman(tc.num), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_intToRoman(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			intToRoman(tc.num)
		}
	}
}
