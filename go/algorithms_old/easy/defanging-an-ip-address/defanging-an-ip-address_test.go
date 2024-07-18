package algorithms

import (
	"fmt"
	"github.com/stretchr/testify/assert"
	"testing"
)

// testcases
var tcs = []struct {
	address  string
	defanged string
}{

	{
		"1.1.1.1",
		"1[.]1[.]1[.]1",
	},

	{
		"255.100.50.0",
		"255[.]100[.]50[.]0",
	},
}

func Test_defangIPaddr(t *testing.T) {
	ast := assert.New(t)

	fmt.Printf("------------------------Leetcode Problem 1108. Defanging an IP Address------------------------\n")

	for _, tc := range tcs {
		fmt.Printf("【Input】: address = %v\n【Output】: %v\n", tc.address, defangIPaddr(tc.address))
		ast.Equal(tc.defanged, defangIPaddr(tc.address), "Case: %v", tc)
	}
	fmt.Printf("\n\n\n")
}

func Benchmark_defangIPaddr(b *testing.B) {
	for i := 0; i < b.N; i++ {
		for _, tc := range tcs {
			defangIPaddr(tc.address)
		}
	}
}
