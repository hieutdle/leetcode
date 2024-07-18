package algorithms

import (
	"fmt"
	"github.com/goldennovember/leetcode-go/gods"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	head []int
	ans  []int
}{

	{
		[]int{1, 2, 3, 4, 5},
		[]int{3, 4, 5},
	},

	{
		[]int{1, 2, 3, 4, 5, 6},
		[]int{4, 5, 6},
	},
}

func Test_middleNode(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 876. Middle of the Linked List------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: head = %v\n【Output】: %v\n", tc.head, gods.List2Ints(middleNode(gods.Ints2List(tc.head))))
		ast.Equal(tc.ans, gods.List2Ints(middleNode(gods.Ints2List(tc.head))), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_middleNode(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			middleNode(gods.Ints2List(tc.head))
		}
	}
}
