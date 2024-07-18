package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	s1  string
	s2  string
	ans bool
}{
	{
		"sitting",
		"kitten",
		false,
	},
	{
		"ab",
		"ab",
		true,
	},

	{
		"ab",
		"eidbaooo",
		true,
	},

	{
		"ab",
		"eidboaoo",
		false,
	},
	{
		"adc",
		"dcda",
		true,
	},
}

func Test_checkInclusion(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 567. Permutation in String------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: s1 = %v, s2 = %v\n【Output】: %v\n", tc.s1, tc.s2, checkInclusion(tc.s1, tc.s2))
		ast.Equal(tc.ans, checkInclusion(tc.s1, tc.s2), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_checkInclusion(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			checkInclusion(tc.s1, tc.s2)
		}
	}
}
