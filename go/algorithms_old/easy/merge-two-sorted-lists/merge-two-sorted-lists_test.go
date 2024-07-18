package algorithms

import (
	"fmt"
	"github.com/goldennovember/leetcode-go/gods"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	list1 []int
	list2 []int
	ans   []int
}{
	{[]int{1, 2, 4}, []int{1, 3, 4}, []int{1, 1, 2, 3, 4, 4}},
	{[]int{}, []int{}, []int{}},
	{[]int{}, []int{0}, []int{0}},
}

func Test_mergeTwoLists(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 21. Merge Two Sorted Lists------------------------\n")
	for _, tc := range tcs {
		fmt.Printf("【Input】: list1 = %v, list2 = %v\n【Output】: %v\n", tc.list1, tc.list2, gods.List2Ints(mergeTwoLists(gods.Ints2List(tc.list1), gods.Ints2List(tc.list2))))
		ast.Equal(tc.ans, gods.List2Ints(mergeTwoLists(gods.Ints2List(tc.list1), gods.Ints2List(tc.list2))), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_mergeTwoLists(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			mergeTwoLists(gods.Ints2List(tc.list1), gods.Ints2List(tc.list2))
		}
	}
}
