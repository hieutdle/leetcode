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
	ans  int
}{
	{[]int{3, 9, 20, -1, -1, 15, 7}, 3},
	{[]int{1, -1, 2}, 2},
	{[]int{}, 0},
	{[]int{0}, 1},
}

func Test_maxDepth(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 104. Maximum Depth of Binary Tree------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【input】:%v       【output】:%v\n", tc.root, maxDepth(gods.Ints2TreeNode(tc.root)))
		ast.Equal(tc.ans, maxDepth(gods.Ints2TreeNode(tc.root)), "输入:%v", tc)
	}
	fmt.Printf("\n\n\n")
}
