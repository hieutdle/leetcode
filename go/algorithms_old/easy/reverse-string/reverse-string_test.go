package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	s   []byte
	ans []byte
}{
	{[]byte{'h', 'e', 'l', 'l', 'o'}, []byte{'o', 'l', 'l', 'e', 'h'}},
	{[]byte{'H', 'a', 'n', 'n', 'a', 'h'}, []byte{'h', 'a', 'n', 'n', 'a', 'H'}},
}

func Test_reverseString(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 344. Reverse String------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: s = %v\n", tc.s)
		reverseString(tc.s)
		fmt.Printf("【Output】: %v\n", tc.s)
		ast.Equal(tc.ans, tc.s, "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_reverseString(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			reverseString(tc.s)
		}
	}
}
