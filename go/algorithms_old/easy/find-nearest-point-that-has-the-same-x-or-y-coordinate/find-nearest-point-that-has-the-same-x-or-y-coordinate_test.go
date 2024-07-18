package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	x      int
	y      int
	points [][]int
	ans    int
}{
	{3, 4, [][]int{{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}}, 2},
	{3, 4, [][]int{{3, 4}}, 0},
	{3, 4, [][]int{{2, 3}}, -1},
}

func Test_nearestValidPoint(t *testing.T) {

	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1779. Find Nearest Point That Has the Same X or Y Coordinate------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: x = %v, y = %v, points = %v\n【Output】: %v\n", tc.x, tc.y, tc.points, nearestValidPoint(tc.x, tc.y, tc.points))
		ast.Equal(tc.ans, nearestValidPoint(tc.x, tc.y, tc.points), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_nearestValidPoint(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			nearestValidPoint(tc.x, tc.y, tc.points)
		}
	}
}
