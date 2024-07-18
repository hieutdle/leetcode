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
	ans  [][]int
}{
	{
		[]int{3, 9, 20, gods.Null, gods.Null, 15, 7},
		[][]int{{3}, {9, 20}, {15, 7}},
	},
	{
		[]int{1},
		[][]int{{1}},
	},
	{
		[]int{},
		[][]int{},
	},
}

func Test_levelOrder(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 102. Binary Tree Level Order Traversal------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: root = %v\n【Output】: %v\n", tc.root, levelOrder(gods.Ints2TreeNode(tc.root)))
		ast.Equal(tc.ans, levelOrder(gods.Ints2TreeNode(tc.root)), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_levelOrder(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			levelOrder(gods.Ints2TreeNode(tc.root))
		}
	}
}
