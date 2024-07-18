package algorithms

import (
	"fmt"
	"github.com/goldennovember/leetcode-go/gods"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	root []int
	p    int
	q    int
	ans  int
}{
	{
		[]int{6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5},
		2,
		8,
		6,
	},
	{
		[]int{6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5},
		2,
		4,
		2,
	},
	{
		[]int{2, 1},
		2,
		1,
		2,
	},
}

func Test_lowestCommonAncestor(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 235. Lowest Common Ancestor of a Binary Search Tree------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: root = %v, p = %v, q = %v\n【Output】: %v\n", tc.root, tc.p, tc.q, lowestCommonAncestor(gods.Ints2TreeNode(tc.root), &TreeNode{Val: tc.p}, &TreeNode{Val: tc.q}).Val)
		ast.Equal(tc.ans, lowestCommonAncestor(gods.Ints2TreeNode(tc.root), &TreeNode{Val: tc.p}, &TreeNode{Val: tc.q}).Val, "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_lowestCommonAncestor(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			lowestCommonAncestor(gods.Ints2TreeNode(tc.root), &TreeNode{Val: tc.p}, &TreeNode{Val: tc.q})
		}
	}
}
