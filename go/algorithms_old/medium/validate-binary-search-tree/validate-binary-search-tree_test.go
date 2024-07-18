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
	ans  bool
}{
	{
		[]int{2, 1, 3},
		true,
	},
	{
		[]int{5, 1, 4, gods.Null, gods.Null, 3, 6},
		false,
	},
}

func Test_isValidBST(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 98. Validate Binary Search Tree------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: root = %v\n【Output】: %v\n", tc.root, isValidBST(gods.Ints2TreeNode(tc.root)))
		ast.Equal(tc.ans, isValidBST(gods.Ints2TreeNode(tc.root)), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_isValidBST(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			isValidBST(gods.Ints2TreeNode(tc.root))
		}
	}
}
