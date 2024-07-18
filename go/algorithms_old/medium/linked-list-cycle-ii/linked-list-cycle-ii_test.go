package algorithms

import (
	"fmt"
	"github.com/goldennovember/leetcode-go/gods"
	"testing"
)

var tcs = []struct {
	head []int
	pos  int
	ans  string
}{
	{
		[]int{3, 2, 0, -4},
		1,
		"tail connects to node index 1",
	},

	{
		[]int{1, 2},
		0,
		"tail connects to node index 0",
	},
	{
		[]int{1},
		0,
		"no cycle",
	},
}

func Test_detectCycle(t *testing.T) {
	fmt.Printf("------------------------Leetcode Problem 142. Linked List Cycle II------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: head = %v, pos = %v\n【Output】: %v\n", tc.head, tc.pos, tc.ans)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_detectCycle(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			detectCycle(gods.Ints2List(tc.head))
		}
	}
}