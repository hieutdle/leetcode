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
	{[]int{1, 2, 3, 4, 5}, []int{5, 4, 3, 2, 1}},
	{[]int{1, 2}, []int{2, 1}},
}

func Test_reverseList(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 206. Reverse Linked List------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: head = %v\n【Output】: %v\n", tc.head, gods.List2Ints(reverseList(gods.Ints2List(tc.head))))
		ast.Equal(tc.ans, gods.List2Ints(reverseList(gods.Ints2List(tc.head))), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_reverseList(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			reverseList(gods.Ints2List(tc.head))
		}
	}
}
