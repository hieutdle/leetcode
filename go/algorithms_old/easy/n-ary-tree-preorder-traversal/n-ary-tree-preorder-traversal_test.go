package algorithms

import (
	"fmt"
	"github.com/goldennovember/leetcode-go/gods"
	"github.com/stretchr/testify/assert"
	"testing"
)

var tcs = []struct {
	root []int
	ans  []int
}{
	{
		[]int{1, gods.Null, 3, 2, 4, gods.Null, 5, 6},
		[]int{1, 3, 5, 6, 2, 4},
	},
	{
		[]int{1, gods.Null, 2, 3, 4, 5, gods.Null, gods.Null, 6, 7, gods.Null, 8, gods.Null, 9, 10, gods.Null, gods.Null, 11, gods.Null, 12, gods.Null, 13, gods.Null, gods.Null, 14},
		[]int{1, 2, 3, 6, 7, 11, 14, 4, 8, 12, 5, 9, 13, 10},
	},
}

func Test_preorder(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 589. N-ary Tree Preorder Traversal------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: root = %v\n【Output】: %v\n", tc.root, preorder(gods.Ints2NaryNode(tc.root)))
		ast.Equal(tc.ans, preorder(gods.Ints2NaryNode(tc.root)), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_preorder(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			preorder(gods.Ints2NaryNode(tc.root))
		}
	}
}
