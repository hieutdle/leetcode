package algorithms

import (
	"fmt"
	"github.com/goldennovember/leetcode-go/gods"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases

var tcs = []struct {
	p   []int
	q   []int
	ans bool
}{
	{
		[]int{1, 2, 3},
		[]int{1, 2, 3},
		true,
	},
	{
		[]int{1, 2},
		[]int{1, gods.Null, 2},
		false,
	},
	{
		[]int{1, 2, 1},
		[]int{1, 1, 2},
		false,
	},
}

func Test_isSameTree(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 100. Same Tree------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: p = %v, q = %v\n【Output】: %v\n", tc.p, tc.q, isSameTree(gods.Ints2TreeNode(tc.p), gods.Ints2TreeNode(tc.q)))
		ast.Equal(tc.ans, isSameTree(gods.Ints2TreeNode(tc.p), gods.Ints2TreeNode(tc.q)), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_isSameTree(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			isSameTree(gods.Ints2TreeNode(tc.p), gods.Ints2TreeNode(tc.q))
		}
	}
}
