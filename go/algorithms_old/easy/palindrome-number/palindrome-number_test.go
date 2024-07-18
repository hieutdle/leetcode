package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	x   int
	ans bool
}{
	{121, true},
	{-121, false},
	{10, false},
}

func Test_isPalindrome(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 9. Palindrome Number------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: x = %v\n【Output】: %v\n", tc.x, isPalindrome(tc.x))
		ast.Equal(tc.ans, isPalindrome(tc.x), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Test_isPalindrome2(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 9. Palindrome Number------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: x = %v\n【Output】: %v\n", tc.x, isPalindrome2(tc.x))
		ast.Equal(tc.ans, isPalindrome2(tc.x), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_isPalindrome(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			isPalindrome(tc.x)
		}
	}
}

func Benchmark_isPalindrome2(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			isPalindrome2(tc.x)
		}
	}
}
