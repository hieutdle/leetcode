package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	a   string
	b   string
	ans string
}{
	{"11", "1", "100"},
	{"1010", "1011", "10101"},
}

func Test_addBinary(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 67. Add Binary------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: a = %v, b = %v\n【Output】: %v\n", tc.a, tc.b, addBinary(tc.a, tc.b))
		ast.Equal(tc.ans, addBinary(tc.a, tc.b), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_addBinary(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			addBinary(tc.a, tc.b)
		}
	}
}
