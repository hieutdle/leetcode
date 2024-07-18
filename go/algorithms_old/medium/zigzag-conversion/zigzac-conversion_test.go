package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	s       string
	numRows int
	ans     string
}{
	{
		"PAYPALISHIRING",
		3,
		"PAHNAPLSIIGYIR",
	},
	{
		"PAYPALISHIRING",
		4,
		"PINALSIGYAHRPI",
	},
	{
		"AB",
		1,
		"AB",
	},
}

func Test_convert(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 6. Zigzag Conversion------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v, numRows = %v\n【Output】: %v\n", tc.s, tc.numRows, convert(tc.s, tc.numRows))
		ast.Equal(tc.ans, convert(tc.s, tc.numRows), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_convert(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			convert(tc.s, tc.numRows)
		}
	}
}
