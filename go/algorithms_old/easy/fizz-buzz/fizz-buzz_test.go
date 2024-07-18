package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	n   int
	ans []string
}{
	{
		3,
		[]string{"1", "2", "Fizz"},
	},
	{
		5,
		[]string{"1", "2", "Fizz", "4", "Buzz"},
	},
	{
		15,
		[]string{
			"1",
			"2",
			"Fizz",
			"4",
			"Buzz",
			"Fizz",
			"7",
			"8",
			"Fizz",
			"Buzz",
			"11",
			"Fizz",
			"13",
			"14",
			"FizzBuzz",
		},
	},
}

func Test_fizzBuzz(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 412. Fizz Buzz------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: n = %v\n【Output】: %v\n", tc.n, fizzBuzz(tc.n))
		ast.Equal(tc.ans, fizzBuzz(tc.n), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_fizzBuzz(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			fizzBuzz(tc.n)
		}
	}
}
