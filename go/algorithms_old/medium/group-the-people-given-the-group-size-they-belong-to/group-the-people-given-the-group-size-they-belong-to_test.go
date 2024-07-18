package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	groupSizes []int
	ans        [][]int
}{
	{
		[]int{3, 3, 3, 3, 3, 1, 3},
		[][]int{{5}, {0, 1, 2}, {3, 4, 6}},
	},

	{
		[]int{2, 1, 3, 3, 3, 2},
		[][]int{{1}, {0, 5}, {2, 3, 4}},
	},
}

func Test_groupThePeople(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1282. Group the People Given the Group Size They Belong To------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: groupSizes = %v\n【Output】: %v\n", tc.groupSizes, groupThePeople(tc.groupSizes))
		ast.ElementsMatchf(tc.ans, groupThePeople(tc.groupSizes), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_groupThePeople(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			groupThePeople(tc.groupSizes)
		}
	}
}
