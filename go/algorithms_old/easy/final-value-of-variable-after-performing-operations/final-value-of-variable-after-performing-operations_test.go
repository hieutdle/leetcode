package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	operations []string
	value      int
}{

	{
		[]string{"--X", "X++", "X++"},
		1,
	},
	{
		[]string{"++X", "++X", "X++"},
		3,
	},
	{
		[]string{"X++", "++X", "--X", "X--"},
		0,
	},
}

func Test_finalValueAfterOperations(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------2011. Final Value of Variable After Performing Operations------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: opeartions = %v\n【Output】: %v\n", tc.operations, finalValueAfterOperations(tc.operations))
		ast.Equal(tc.value, finalValueAfterOperations(tc.operations), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_finalValueAfterOperations(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			finalValueAfterOperations(tc.operations)
		}
	}
}
