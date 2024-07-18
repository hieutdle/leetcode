package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	salary []int
	ans    float64
}{
	{
		[]int{4000, 3000, 1000, 2000},
		2500.00000,
	},
	{
		[]int{1000, 2000, 3000},
		2000.00000,
	},
	{
		[]int{6000, 5000, 4000, 3000, 2000, 1000},
		3500.00000,
	},
	{
		[]int{8000, 9000, 2000, 3000, 6000, 1000},
		4750.00000,
	},
}

func Test_average(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1491. Average Salary Excluding the Minimum and Maximum Salary------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: salary = %v\n【Output】: %v\n", tc.salary, average(tc.salary))
		ast.Equal(tc.ans, average(tc.salary), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_average(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			average(tc.salary)
		}
	}
}
