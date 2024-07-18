package algorithms

import (
	"fmt"
	"testing"
)

// testcases
var tcs = []struct {
	n   int
	bad int
}{

	{
		5,
		4,
	},

	{
		1,
		1,
	},
	{
		2,
		1,
	},
}

func Test_firstBadVersion(t *testing.T) {

	fmt.Printf("------------------------Leetcode 278. First Bad Version------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: n = %v\n【Output】: %v\n", tc.n, tc.bad)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_firstBadVersion(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			firstBadVersion(tc.n)
		}
	}
}